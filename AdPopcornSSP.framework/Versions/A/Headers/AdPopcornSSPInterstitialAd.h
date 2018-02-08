//
//  AdPopcornSSPInterstitialAd.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"


@protocol AdPopcornSSPInterstitialAdDelegate;

@interface AdPopcornSSPInterstitialAd : NSObject

@property (nonatomic, weak) id<AdPopcornSSPInterstitialAdDelegate> delegate;
@property (nonatomic, unsafe_unretained, getter = isInterstitialAdIsVisible) BOOL interstitialAdIsVisible;
@property (nonatomic, weak) UIViewController *viewController;

/*!
 @abstract
 interstitial ad instance 생성.
 @param appKey          app key
 @param placementId    placement id
 @param viewController  interstitial ad를 노출시킬 view controller
 */
- (instancetype)initWithKey:(NSString *)appKey placementId:(NSString *)placementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;

/*!
 @abstract
 interstitial 광고 요청.
 */
- (void)loadRequest;

/*!
 @abstract
 interstitial ad load가 완료되면(성공하면), presentFromViewController 메소드를 호출하여 노출시킨다.
 @param viewController  interstitial ad를 노출시킬 view controller
 */
- (BOOL)presentFromViewController:(UIViewController *)viewController;
@end

@protocol AdPopcornSSPInterstitialAdDelegate <NSObject>

/*!
 @abstract
 intersitial 광고 load 실패시, 호출된다.
 */
- (void)AdPopcornSSPInterstitialAd:(AdPopcornSSPInterstitialAd *)interstitialAd didFailToReceiveAdWithError:(AdPopcornSSPError *)error;

@optional
/*!
 @abstract
 intersitial 광고 load 완료시(성공시), 호출된다.
 */
- (void)AdPopcornSSPInterstitialAdDidLoad:(AdPopcornSSPInterstitialAd *)interstitialAd;

/*!
 @abstract
 intersitial 광고 클릭시, 호출된다.
 */
- (void)AdPopcornSSPInterstitialAdWillLeaveApplication:(AdPopcornSSPInterstitialAd *)interstitialAd;

/*!
 @abstract
 intersitial 광고 open 직전에 호출된다.
 */
- (void)willOpenAdPopcornSSPInterstitialAd;

/*!
 @abstract
 intersitial 광고 open 직후에 호출된다.
 */
- (void)didOpenAdPopcornSSPInterstitialAd;

/*!
 @abstract
 intersitial 광고 close 직전에 호출된다.
 */
- (void)willCloseAdPopcornSSPInterstitialAd;

/*!
 @abstract
 intersitial 광고 close 직후에 호출된다.
 */
- (void)didCloseAdPopcornSSPInterstitialAd;


@end
