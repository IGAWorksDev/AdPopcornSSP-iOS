//
//  AdPopcornSSPReactNativeAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2023/11/17.
//  Copyright © 2023 AdPopcorn. All rights reserved.
//

#ifndef AdPopcornSSPReactNativeAd_h
#define AdPopcornSSPReactNativeAd_h


#endif /* AdPopcornSSPReactNativeAd_h */
#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"

@protocol APSSPReactNativeAdDelegate;

typedef enum _SSPReactNativeAdStatus
{
    INIT_REACTNATIVE,
    RUN_REACTNATIVE,
    STOP_REACTNATIVE
} SSPReactNativeAdStatus;

@interface AdPopcornSSPReactNativeAd : UIView

@property (nonatomic, weak) id<APSSPReactNativeAdDelegate> delegate;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, copy) NSString *placementId;

/*!
 @abstract
 react native ad instance 생성.
 @param frame       native frame
 @param appKey         app key
 @param placementId    placement id
 @param viewController viewController
 */
- (instancetype)initWithFrame:(CGRect)frame appKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 react native ad 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 react native ad 광고 중단.
 */
- (void)stopAd;
@end

@protocol APSSPReactNativeAdDelegate <NSObject>
@optional
/*!
 @abstract
 react native 광고 로드에 성공한 경우 호출된다.
 */
- (void)APSSPReactNativeAdLoadSuccess:(AdPopcornSSPReactNativeAd *)reactNativeAd adSize:(CGSize)adSize networkNo:(NSInteger)networkNo;

/*!
 @abstract
 react native 광고 로드에 실패한 경우 호출된다.
 */
- (void)APSSPReactNativeAdLoadFail:(AdPopcornSSPReactNativeAd *)reactNativeAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 react native 광고가 노출 될 때 호출된다.
 */
- (void)APSSPReactNativeAdImpression:(AdPopcornSSPReactNativeAd *)reactNativeAd;
/*!
 @abstract
 react native 광고가 클릭 시 호출 된다.
 */
- (void)APSSPReactNativeAdClicked:(AdPopcornSSPReactNativeAd *)reactNativeAd;
/*!
 @abstract
 react native 광고 사이즈 변경 시 호출(NAM)
 */
- (void)APSSPReactNativeAdSizeChanged:(AdPopcornSSPReactNativeAd *)reactNativeAd adSize:(CGSize)adSize;
@end
