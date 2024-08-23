//
//  AdPopcornSSPBannerView.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

#import "AdPopcornSSPError.h"

@protocol APSSPBannerViewDelegate;

typedef enum _SSPBannerViewSizeType
{
    SSPBannerViewSize320x50,
    SSPBannerViewSize300x250,
    SSPBannerViewSize320x100,
    SSPBannerViewSizeAdaptive
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

typedef enum _SSPBannerAdStatus
{
    INIT_BANNER,
    RUN_BANNER,
    STOP_BANNER
} SSPBannerAdStatus;

@interface AdPopcornSSPBannerView : UIView

@property (nonatomic, weak) id<APSSPBannerViewDelegate> delegate;
@property (nonatomic, unsafe_unretained) NSInteger adRefreshRate;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, copy) NSString *placementId;

/*!
 @abstract
 banner view instance 생성.
 @param size            banner view size
 @param origin          banner view를 노출시킬 position(x, y).
 @param appKey          app key
 @param placementId         placement id
 @param viewController  banner view를 노출시킬 view controller
 */
- (instancetype)initWithBannerViewSize:(SSPBannerViewSizeType)size origin:(CGPoint)origin appKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController;

/*!
 @abstract
 banner view instance 생성.
 @param size            banner view size
 @param origin          banner view를 노출시킬 position(x, y).
 @param appKey          app key
 @param placementId         placement id
 @param view  banner view를 노출시킬 UIView
 @param viewController  banner view가 노출 될 UIView의 view controller
 */
- (instancetype)initWithBannerViewSize:(SSPBannerViewSizeType)size origin:(CGPoint)origin appKey:(NSString *)appKey placementId:(NSString *)placementId view:(UIView *)view rootViewController:(UIViewController *)viewController;

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

/*!
 @abstract
 banner 광고 expire 여부 확인.
 */
- (BOOL)isExpired;
@end


@protocol APSSPBannerViewDelegate <NSObject>

@optional
/*!
 @abstract
 banner 광고 load 완료시(성공시), 호출된다.
 */
- (void)APSSPBannerViewLoadSuccess:(AdPopcornSSPBannerView *)bannerView;

/*!
 @abstract
 banner 광고 load 실패시, 호출된다.
 */
- (void)APSSPBannerViewLoadFail:(AdPopcornSSPBannerView *)bannerView error:(AdPopcornSSPError *)error;

/*!
 @abstract
 banner 광고 클릭시, 호출된다.
 */
- (void)APSSPBannerViewClicked:(AdPopcornSSPBannerView *)bannerView;
@end
