//
//  AdPopcornSSPNativeAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2018. 10. 12..
//  Copyright © 2018년 mick. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"


@protocol APSSPNativeAdDelegate;

typedef enum _SSPNativeAdStatus
{
    INIT_NATIVE,
    RUN_NATIVE,
    STOP_NATIVE
} SSPNativeAdStatus;

@interface APSSPNativeAdRenderer : NSObject

@property (strong, nonatomic) UIView *apSSPNativeAdView;
@property (strong, nonatomic) UILabel *titleLabel;
@property (strong, nonatomic) UILabel *descLabel;
@property (strong, nonatomic) UIImageView *iconImageView;
@property (strong, nonatomic) UIImageView *mainImageView;
@property (strong, nonatomic) UILabel *ctaLabel;
@end

@interface AdPopcornSSPNativeAd : UIView

@property (nonatomic, weak) id<APSSPNativeAdDelegate> delegate;

/*!
 @abstract
 native ad instance 생성.
 @param frame       native frame
 @param appKey         app key
 @param placementId    placement id
 @param viewController viewController
 */
- (instancetype)initWithFrame:(CGRect)frame Key:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 native ad 광고 요청.
 */
- (void)setPlacementInfoWithAppKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController;

/*!
 @abstract
 native ad 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 native ad 광고 중단.
 */
- (void)stopAd;

/*!
@abstract
placementId 가져오기
*/
- (NSString *)getPlacementId;

/*!
 @abstract
 apssp renderer 및 super view 설정
 */
- (void)setApSSPRenderer:(id)apSSPNativeAdRenderer superView:(UIView *)uiView;

/*!
 @abstract
 admob renderer 및 super view 설정
 */
- (void)setAdMobRenderer:(id)admobNativeAdRenderer superView:(UIView *)uiView;

/*!
 @abstract
 mopub renderer 및 super view 설정
 */
- (void)setMopubRenderer:(id)mopubNativeAdRenderer superView:(UIView *)uiView;

/*!
 @abstract
 fan renderer 및 super view 설정
 */
- (void)setFANNativeRenderer:(id)fanNativeAdRenderer superView:(UIView *)uiView;

/*!
 @abstract
 fan native banner renderer 및 super view 설정
 */
- (void)setFANNativeBannerRenderer:(id)fanNativeBannerAdRenderer superView:(UIView *)uiView;
@end

@protocol APSSPNativeAdDelegate <NSObject>

/*!
 @abstract
 native 광고 로드에 성공한 경우 호출된다.
 */
- (void)APSSPNativeAdLoadSuccess:(AdPopcornSSPNativeAd *)nativeAd;

/*!
 @abstract
 native 광고 로드에 실패한 경우 호출된다.
 */
- (void)APSSPNativeAdLoadFail:(AdPopcornSSPNativeAd *)nativeAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 native 광고가 노출 될 때 호출된다.
 */
- (void)APSSPNativeAdImpression:(AdPopcornSSPNativeAd *)nativeAd;

/*!
 @abstract
 native 광고가 클릭 시 호출 된다.
 */
- (void)APSSPNativeAdClicked:(AdPopcornSSPNativeAd *)nativeAd;
@end

