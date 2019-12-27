//
//  AdPopcornSSPRewardVideoAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2018. 10. 12..
//  Copyright © 2018년 mick. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"


@protocol APSSPRewardVideoAdDelegate;

typedef enum _SSPRewardVideoAdStatus
{
    INIT_REWARD_VIDEO_AD,
    RUN_REWARD_VIDEO_AD,
    STOP_REWARD_VIDEO_AD
} SSPRewardVideoAdStatus;

@interface AdPopcornSSPRewardVideoAd : NSObject

@property (nonatomic, weak) id<APSSPRewardVideoAdDelegate> delegate;
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
- (NSInteger)getCurrentNetwork;
- (void)stopAd;

@end

@protocol APSSPRewardVideoAdDelegate <NSObject>

/*!
 @abstract
 video 광고 로드에 성공한 경우 호출된다.
 */
- (void)APSSPRewardVideoAdLoadSuccess:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 video 광고 로드에 실패한 경우 호출된다.
 */
- (void)APSSPRewardVideoAdLoadFail:(AdPopcornSSPRewardVideoAd *)rewardVideoAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 video 광고가 정상적으로 노출될 때 호출된다.
 */
- (void)APSSPRewardVideoAdShowSuccess:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 video 광고가 노출에 실패했을 때 호출된다.
 */
- (void)APSSPRewardVideoAdShowFail:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 video 광고가 닫히면 호출된다.
 */
- (void)APSSPRewardVideoAdClosed:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 AP SSP reward video 재생 완료 시 호출된다.
 */
- (void)APSSPRewardVideoAdPlayCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd quantity:(long) quantity currency:(NSString *)currency;

/*!
 @abstract
 Mintegral reward video 재생 완료 시 호출된다.
 */
-(void)APSSPRewardVideoAdMintegralVideoCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd rewardAmount:(NSInteger)rewardAmount;

/*!
 @abstract
 UnityAds reward video 재생 완료 시 호출된다.
 */
- (void)APSSPRewardVideoAdUnityAdsVideoCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 AdMob reward video 재생 완료 시 호출된다.
 */
- (void)APSSPRewardVideoAdAdMobVideoCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd rewardAmount:(double)rewardAmount;

/*!
 @abstract
 AppNext reward video 재생 완료 시 호출된다.
 */
- (void)APSSPRewardVideoAdAppNextAdsVideoCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 AdColony reward video 재생 완료 시 호출된다.
 */
- (void)APSSPRewardVideoAdAdColonyVideoCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 Vungle reward video 재생 완료 시 호출된다.
 */
- (void)APSSPRewardVideoAdVungleVideoCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;

/*!
 @abstract
 AppLovin reward video 재생 완료 시 호출된다.
 */
- (void)APSSPRewardVideoAdAppLovinVideoCompleted:(AdPopcornSSPRewardVideoAd *)rewardVideoAd;
@end

