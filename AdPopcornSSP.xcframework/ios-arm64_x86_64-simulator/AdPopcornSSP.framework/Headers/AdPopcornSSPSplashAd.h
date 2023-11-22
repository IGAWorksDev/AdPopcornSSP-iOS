//
//  AdPopcornSSPSplashAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2023/11/17.
//  Copyright © 2023 AdPopcorn. All rights reserved.
//

#ifndef AdPopcornSSPSplashAd_h
#define AdPopcornSSPSplashAd_h

#endif /* AdPopcornSSPSplashAd_h */

#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"

@protocol APSSPSplashAdDelegate;

typedef enum _SSPSplashAdStatus
{
    INIT_SPLASH,
    RUN_SPLASH,
    STOP_SPLASH
} SSPSplashAdStatus;

@interface AdPopcornSSPSplashAd : UIView

@property (nonatomic, weak) id<APSSPSplashAdDelegate> delegate;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, copy) NSString *placementId;

/*!
 @abstract
 splash ad instance 생성.
 @param frame       native frame
 @param appKey         app key
 @param placementId    placement id
 @param viewController viewController
 */
- (instancetype)initWithFrame:(CGRect)frame Key:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 splash ad 광고 연결
 */
- (void)setPlacementInfoWithAppKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController;

/*!
 @abstract
 splash ad 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 splash ad 광고 중단.
 */
- (void)stopAd;

/*!
 @abstract
 splash ad 풀스크린 설정
 */
- (void)setFullScreenSplash:(BOOL)fullscreen;
@end

@protocol APSSPSplashAdDelegate <NSObject>
@optional
/*!
 @abstract
 splash 광고 로드에 성공한 경우 호출된다.
 */
- (void)APSSPSplashAdLoadSuccess:(AdPopcornSSPSplashAd *)splashAd;

/*!
 @abstract
 splash 광고 로드에 실패한 경우 호출된다.
 */
- (void)APSSPSplashAdLoadFail:(AdPopcornSSPSplashAd *)splashAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 splash 광고가 노출 될 때 호출된다.
 */
- (void)APSSPSplashAdImpression:(AdPopcornSSPSplashAd *)splashAd;
@end

