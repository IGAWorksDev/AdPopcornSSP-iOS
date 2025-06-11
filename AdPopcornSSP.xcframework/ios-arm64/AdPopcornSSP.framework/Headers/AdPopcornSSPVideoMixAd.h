//
//  AdPopcornSSPVideoMixAd.h
//  AdPopcornSSPLib
//
//  Created by Odin.송황호 on 5/7/25.
//  Copyright © 2025 AdPopcorn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"
#import "AdPopcornSSPAdapter.h"

@protocol APSSPVideoMixAdDelegate;

typedef enum _SSPVideoMixAdStatus
{
    INIT_VIDEO_MIX_AD,
    RUN_VIDEO_MIX_AD,
    STOP_VIDEO_MIX_AD
} _SSPVideoMixAdStatus;

@interface AdPopcornSSPVideoMixAd : NSObject

@property (nonatomic, weak) id<APSSPVideoMixAdDelegate> delegate;
@property (nonatomic, unsafe_unretained, getter = isVideoMixAdIsVisible) BOOL VideoMixAdIsVisible;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, copy) NSString *placementId;
@property (nonatomic, copy) NSString *adRequestNo;

/*!
 @abstract
 VideoMixAd instance 생성.
 @param appKey          app key
 @param placementId    placement id
 @param viewController  VideoMixAd를 노출시킬 view controller
 */
- (instancetype)initWithKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 VideoMixAd 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 VideoMixAd load가 완료되면(성공하면), presentFromViewController 메소드를 호출하여 노출시킨다.
 @param viewController  VideoMixAd를 노출시킬 view controller
 */
- (BOOL)presentFromViewController:(UIViewController *)viewController;
- (BOOL)isReady;
- (long)getCurrentNetwork;
- (void)stopAd;

@end

@protocol APSSPVideoMixAdDelegate <NSObject>
@optional
/*!
 @abstract
 VideoMixAd 광고 로드에 성공한 경우 호출된다.
 */
- (void)APSSPVideoMixAdLoadSuccess:(AdPopcornSSPVideoMixAd *)VideoMixAd videoMixAdType: (int) type;

/*!
 @abstract
 VideoMixAd 광고 로드에 실패한 경우 호출된다.
 */
- (void)APSSPVideoMixAdLoadFail:(AdPopcornSSPVideoMixAd *)VideoMixAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 VideoMixAd 광고가 정상적으로 노출될 때 호출된다.
 */
- (void)APSSPVideoMixAdShowSuccess:(AdPopcornSSPVideoMixAd *)VideoMixAd;

/*!
 @abstract
 VideoMixAd 광고가 노출에 실패했을 때 호출된다.
 */
- (void)APSSPVideoMixAdShowFail:(AdPopcornSSPVideoMixAd *)VideoMixAd;

/*!
 @abstract
 VideoMixAd 광고가 닫히면 호출된다. (Interstitial, InterstitialVideo)
 */
- (void)APSSPVideoMixAdClosed:(AdPopcornSSPVideoMixAd *)VideoMixAd videoMixAdType: (int) type;

/*!
@abstract
AP SSP VideoMixAd 재생 완료 시 호출된다. (rewardVideo)
*/
- (void)APSSPVideoMixAdPlayCompleted:(AdPopcornSSPVideoMixAd *)VideoMixAd adNetworkNo:(long) adNetworkNo completed:(BOOL)completed;

@end
