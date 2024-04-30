//
//  AdPopcornSSPModalAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 4/11/24.
//  Copyright © 2024 AdPopcorn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"

@protocol APSSPModalAdDelegate;

typedef enum _SSPModalAdStatus
{
    INIT_MODAL_AD,
    RUN_MODAL_AD,
    STOP_MODAL_AD
} SSPModalAdStatus;

@interface AdPopcornSSPModalAd : NSObject

@property (nonatomic, weak) id<APSSPModalAdDelegate> delegate;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, copy) NSString *placementId;
@property (nonatomic, strong) UIColor *backgroundColor;
@property (nonatomic, unsafe_unretained) int closeBtnType; // 0 : 광고 닫기, 1: 오늘 그만 보기
@property (nonatomic, unsafe_unretained) int adGravity; // 0 : Bottom, 1: Center

/*!
 @abstract
 modal ad instance 생성.
 @param appKey          app key
 @param placementId    placement id
 @param viewController  interstitial ad를 노출시킬 view controller
 */
- (instancetype)initWithKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 modal 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 modal ad load가 완료되면(성공하면), presentFromViewController 메소드를 호출하여 노출시킨다.
 @param viewController  interstitial ad를 노출시킬 view controller
 */
- (BOOL)presentFromViewController:(UIViewController *)viewController;
@end

@protocol APSSPModalAdDelegate <NSObject>

@optional
/*!
 @abstract
 modal 광고 load 완료시(성공시), 호출된다.
 */
- (void)APSSPModalAdLoadSuccess:(AdPopcornSSPModalAd *)modalAd;

/*!
 @abstract
 modal 광고 load 실패시, 호출된다.
 */
- (void)APSSPModalAdLoadFail:(AdPopcornSSPModalAd *)modalAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 modal 광고 close시, 호출된다.
 */
- (void)APSSPModalAdClosed:(AdPopcornSSPModalAd *)modalAd;

/*!
 @abstract
 modal 광고 클릭시, 호출된다.
 */
- (void)APSSPModalAdClicked:(AdPopcornSSPModalAd *)modalAd;

/*!
 @abstract
 modal 광고 show 완료시(성공시), 호출된다.
 */
- (void)APSSPModalAdShowSuccess:(AdPopcornSSPModalAd *)modalAd;

/*!
 @abstract
 modal 광고 show 실패시, 호출된다.
 */
- (void)APSSPModalAdShowFail:(AdPopcornSSPModalAd *)modalAd error:(AdPopcornSSPError *)error;
@end
