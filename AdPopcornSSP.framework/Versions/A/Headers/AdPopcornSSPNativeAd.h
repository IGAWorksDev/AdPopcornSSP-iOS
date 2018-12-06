//
//  AdPopcornSSPNativeAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2018. 10. 12..
//  Copyright © 2018년 mick. All rights reserved.
//


#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"


@protocol AdPopcornSSPNativeAdDelegate;

@interface AdPopcornSSPNativeAd : NSObject

@property (nonatomic, weak) id<AdPopcornSSPNativeAdDelegate> delegate;
@property (strong, nonatomic) UIView *nativeAdView;
@property (strong, nonatomic) UILabel *titleLabel;
@property (strong, nonatomic) UILabel *descLabel;
@property (strong, nonatomic) UIImageView *iconImageView;
@property (strong, nonatomic) UIImageView *mainImageView;

/*!
 @abstract
 native ad instance 생성.
 @param appKey          app key
 @param placementId    placement id
 */
- (instancetype)initWithKey:(NSString *)appKey placementId:(NSString *)placementId NS_DESIGNATED_INITIALIZER;

- (void)setNativeAdView:(UIView *)nativeAdView;
- (void)setIconImageView:(UIImageView *)iconImageView;
- (void)setMainImageView:(UIImageView *)mainImageView;
- (void)setTitleLabel:(UILabel *)titleLabel;
- (void)setDescLabel:(UILabel *)descLabel;

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
@end

@protocol AdPopcornSSPNativeAdDelegate <NSObject>

/*!
 @abstract
 native 광고 로드에 성공한 경우 호출된다.
 */
- (void)AdPopcornSSPLoadNativeAdSuccess;

/*!
 @abstract
 native 광고 로드에 실패한 경우 호출된다.
 */
- (void)AdPopcornSSPLoadNativeAdFailedWithError:(AdPopcornSSPError *)error;

/*!
 @abstract
 native 광고가 노출 될 때 호출된다.
 */
- (void)AdPopcornSSPNativeAdImpression;

/*!
 @abstract
 native 광고가 클릭 시 호출 된다.
 */
- (void)AdPopcornSSPNativeAdClicked;
@end

