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
    SSPBannerViewSize300x250
} SSPBannerViewSizeType;

@interface AdPopcornSSPBannerView : UIView


@property (nonatomic, weak) id<AdPopcornSSPBannerViewDelegate> delegate;

// 최소 30초에서 최대 120초로 설정.
@property (nonatomic, unsafe_unretained) NSInteger adRefreshRate;

/*!
 @abstract
 banner view instance 생성.
 @param size            banner view size : 현재는 320 * 50만 지원.
 @param origin          banner view를 노출시킬 position(x, y).
 @param appKey          app key
 @param placementId         placement id
 @param viewController  banner view를 노출시킬 view controller
 */
- (instancetype)initWithBannerViewSize:(SSPBannerViewSizeType)size origin:(CGPoint)origin appKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 banner 광고 요청.
 rotation 변경시, 화면에 맞는 banner 광고 요청시 사용.
 */
- (void)loadRequest;


/*!
 @abstract
 banner 스케쥴 정지.
 */
- (void)stopAd;

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
