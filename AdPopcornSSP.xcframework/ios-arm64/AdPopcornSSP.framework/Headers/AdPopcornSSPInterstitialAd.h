//
//  AdPopcornSSPInterstitialAd.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"

@protocol APSSPInterstitialAdDelegate;

typedef enum _SSPInterstitialAdStatus
{
    INIT_INTERSTITIAL,
    RUN_INTERSTITIAL,
    STOP_INTERSTITIAL
} SSPInterstitialAdStatus;

@interface AdPopcornSSPInterstitialAd : NSObject

@property (nonatomic, weak) id<APSSPInterstitialAdDelegate> delegate;
@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, copy) NSString *placementId;
@property (nonatomic, strong) UIColor *backgroundColor;

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

@protocol APSSPInterstitialAdDelegate <NSObject>

@optional
/*!
 @abstract
 intersitial 광고 load 완료시(성공시), 호출된다.
 */
- (void)APSSPInterstitialAdLoadSuccess:(AdPopcornSSPInterstitialAd *)interstitialAd;

/*!
 @abstract
 intersitial 광고 load 실패시, 호출된다.
 */
- (void)APSSPInterstitialAdLoadFail:(AdPopcornSSPInterstitialAd *)interstitialAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 intersitial 광고 close시, 호출된다.
 */
- (void)APSSPInterstitialAdClosed:(AdPopcornSSPInterstitialAd *)interstitialAd;

/*!
 @abstract
 intersitial 광고 클릭시, 호출된다.
 */
- (void)APSSPInterstitialAdClicked:(AdPopcornSSPInterstitialAd *)interstitialAd;

/*!
 @abstract
 intersitial 광고 show 완료시(성공시), 호출된다.
 */
- (void)APSSPInterstitialAdShowSuccess:(AdPopcornSSPInterstitialAd *)interstitialAd;

/*!
 @abstract
 intersitial 광고 show 실패시, 호출된다.
 */
- (void)APSSPInterstitialAdShowFail:(AdPopcornSSPInterstitialAd *)interstitialAd error:(AdPopcornSSPError *)error;
@end
