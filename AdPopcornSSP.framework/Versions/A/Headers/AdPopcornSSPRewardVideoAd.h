//
//  AdPopcornSSPRewardVideoAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2018. 10. 12..
//  Copyright © 2018년 mick. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"


@protocol AdPopcornSSPRewardVideoAdDelegate;

@interface AdPopcornSSPRewardVideoAd : NSObject

@property (nonatomic, weak) id<AdPopcornSSPRewardVideoAdDelegate> delegate;
@property (nonatomic, unsafe_unretained, getter = isRewardVideoAdIsVisible) BOOL rewardVideoAdIsVisible;
@property (nonatomic, weak) UIViewController *viewController;

/*!
 @abstract
 reward video ad instance 생성.
 @param appKey          app key
 @param placementId    placement id
 @param viewController  reward video ad를 노출시킬 view controller
 */
- (instancetype)initWithKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 reward video ad 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 reward video ad load가 완료되면(성공하면), presentFromViewController 메소드를 호출하여 노출시킨다.
 @param viewController  reward video ad를 노출시킬 view controller
 */
- (BOOL)presentFromViewController:(UIViewController *)viewController;
- (BOOL)isReady;
- (void)setManualMediationSchedule:(NSArray *)mediationSchedule;
- (int)getCurrentNetwork;

@end

@protocol AdPopcornSSPRewardVideoAdDelegate <NSObject>

/*!
 @abstract
 video 광고 로드에 성공한 경우 호출된다.
 */
- (void)AdPopcornSSPLoadRewardVideoAdSuccess;

/*!
 @abstract
 video 광고 로드에 실패한 경우 호출된다.
 */
- (void)AdPopcornSSPLoadRewardVideoAdFailedWithError:(AdPopcornSSPError *)error;

/*!
 @abstract
 video 광고가 열리기 전에 호출된다.
 */
- (void)AdPopcornSSPShowRewardVideoAdSuccess;

/*!
 @abstract
 video 광고가 열린직 후 호출된다.
 */
- (void)AdPopcornSSPShowRewardVideoAdFailed;

/*!
 @abstract
 video 광고가 닫히기 전에 호출된다.
 */
- (void)AdPopcornSSPRewardVideoAdClosed;

/*!
 @abstract
 AP SSP reward video 재생 완료 시 호출된다.
 */
- (void)AdPopcornSSPRewardVideoAdPlayCompletedWithQuantity:(long) quantity Currency:(NSString *)currency;

/*!
 @abstract
 Mintegral reward video 재생 완료 시 호출된다.
 */
- (void)AdPopcornSSPRewardVideoAdMintegralVideoCompleted:(NSInteger)RewardAmount;

/*!
 @abstract
 UnityAds reward video 재생 완료 시 호출된다.
 */
- (void)AdPopcornSSPRewardVideoAdUnityAdsVideoCompleted;

/*!
 @abstract
 AdMob reward video 재생 완료 시 호출된다.
 */
- (void)AdPopcornSSPRewardVideoAdAdMobVideoCompleted:(double)RewardAmount;
@end

