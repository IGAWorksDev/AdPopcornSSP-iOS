//
//  AdPopcornSSPInterstitialVideoAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2019. 12. 17..
//  Copyright © 2019년 mick. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"

@protocol APSSPInterstitialVideoAdDelegate;

typedef enum _SSPInterstitialVideoAdStatus
{
    INIT_INTERSTITIAL_VIDEO_AD,
    RUN_INTERSTITIAL_VIDEO_AD,
    STOP_INTERSTITIAL_VIDEO_AD
} SSPInterstitialVideoAdStatus;

@interface AdPopcornSSPInterstitialVideoAd : NSObject

@property (nonatomic, weak) id<APSSPInterstitialVideoAdDelegate> delegate;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, copy) NSString *placementId;

/*!
 @abstract
 interstitial video ad instance 생성.
 @param appKey          app key
 @param placementId    placement id
 @param viewController  interstitial video ad를 노출시킬 view controller
 */
- (instancetype)initWithKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 interstitial video ad 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 interstitial video ad load가 완료되면(성공하면), presentFromViewController 메소드를 호출하여 노출시킨다.
 @param viewController  interstitial video ad를 노출시킬 view controller
 */
- (BOOL)presentFromViewController:(UIViewController *)viewController;
- (BOOL)isReady;
- (long)getCurrentNetwork;
- (void)stopAd;

@end

@protocol APSSPInterstitialVideoAdDelegate <NSObject>
@optional
/*!
 @abstract
 interstitial video 광고 로드에 성공한 경우 호출된다.
 */
- (void)APSSPInterstitialVideoAdLoadSuccess:(AdPopcornSSPInterstitialVideoAd *)interstitialVideoAd;

/*!
 @abstract
 interstitial video 광고 로드에 실패한 경우 호출된다.
 */
- (void)APSSPInterstitialVideoAdLoadFail:(AdPopcornSSPInterstitialVideoAd *)interstitialVideoAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 interstitial video 광고가 정상적으로 노출될 때 호출된다.
 */
- (void)APSSPInterstitialVideoAdShowSuccess:(AdPopcornSSPInterstitialVideoAd *)interstitialVideoAd;

/*!
 @abstract
 interstitial video 광고가 노출에 실패했을 때 호출된다.
 */
- (void)APSSPInterstitialVideoAdShowFail:(AdPopcornSSPInterstitialVideoAd *)interstitialVideoAd;

/*!
 @abstract
 interstitial video 광고가 닫히면 호출된다.
 */
- (void)APSSPInterstitialVideoAdClosed:(AdPopcornSSPInterstitialVideoAd *)interstitialVideoAd;

@end

