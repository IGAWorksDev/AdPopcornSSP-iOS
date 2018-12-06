//
//  AdPopcornSSPBannerView.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "AdPopcornSSPError.h"

@protocol AdPopcornSSPBannerViewDelegate;

typedef enum _SSPBannerViewSizeType
{
    SSPBannerViewSize320x50,
    SSPBannerViewSize300x250,
    SSPBannerViewSize320x100
} SSPBannerViewSizeType;

typedef enum _SSPBannerViewAnimationType
{
    SSPBannerViewAnimNone,
    SSPBannerViewAnimCurlDown,
    SSPBannerViewAnimCurlUp,
    SSPBannerViewAnimFlipFromLeft,
    SSPBannerViewAnimFlipFromRight,
    SSPBannerViewAnimFadeIn
} SSPBannerViewAnimationType;

@interface AdPopcornSSPBannerView : UIView

@property (nonatomic, weak) id<AdPopcornSSPBannerViewDelegate> delegate;

// Default 시간은 60초이며, 30~120초 사이로 설정 가능. 단, -1초로 설정 시, refresh 사용 안함.
@property (nonatomic, unsafe_unretained) NSInteger adRefreshRate;

@property (nonatomic, weak) UIViewController *viewController;

/*!
 @abstract
 banner view instance 생성.
 @param size            banner view size : 현재는 320 * 50만 지원.
 @param origin          banner view를 노출시킬 position(x, y).
 @param appKey          app key
 @param placementId         placement id
 @param viewController  banner view를 노출시킬 view controller
 */
- (instancetype)initWithBannerViewSize:(SSPBannerViewSizeType)size origin:(CGPoint)origin appKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController;

/*!
 @abstract
 banner 광고 요청.
 */
- (void)loadRequest;


/*!
 @abstract
 banner 광고 노출 중지.
 */
- (void)stopAd;

/*!
 @abstract
 banner 광고 노출 중지.
 */
- (void)stopAd:(BOOL)hidden;

/*!
 @abstract
 banner 광고 배경 채우기 설정.
 */
- (void)setAutoBgColor:(BOOL)flag;

/*!
 @abstract
 banner 광고 애니메이션 타입 설정.
 */
- (void)setAnimType:(SSPBannerViewAnimationType)animType;
@end


@protocol AdPopcornSSPBannerViewDelegate <NSObject>

@optional
/*!
 @abstract
 banner 광고 load 완료시(성공시), 호출된다.
 */
- (void)AdPopcornSSPBannerViewDidLoadAd:(AdPopcornSSPBannerView *)bannerView;

/*!
 @abstract
 banner 광고 load 실패시, 호출된다.
 */
- (void)AdPopcornSSPBannerView:(AdPopcornSSPBannerView *)bannerView didFailToReceiveAdWithError:(AdPopcornSSPError *)error;

/*!
 @abstract
 banner 광고 클릭시, 호출된다.
 */
- (void)AdPopcornSSPBannerViewWillLeaveApplication:(AdPopcornSSPBannerView *)bannerView;


@end
