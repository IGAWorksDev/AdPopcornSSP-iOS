//
//  AdPopcornSSPAdapter.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import "AdPopcornSSPBannerView.h"

#import "AdPopcornSSP.h"

@protocol AdPopcornSSPAdapterDelegate;

typedef enum _SSPMediationGender
{
    SSPMediationGenderMale,
    SSPMediationGenderFemale
} SSPMediationGender;

typedef enum _SSPAdType
{
    SSPAdBannerType,
    SSPAdInterstitialType,
    SSPNativeAdType,
    SSPRewardVideoAdType
} SSPAdType;

@interface AdPopcornSSPAdapter : NSObject
{
    CGPoint _origin;
    CGSize _size;
    SSPAdType _adType;
}

@property (nonatomic, weak) id<AdPopcornSSPAdapterDelegate> delegate;

@property (nonatomic, strong) NSDictionary *integrationKey;

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportInterstitialAd;

@property (nonatomic, weak) UIViewController *viewController;

@property (nonatomic, weak) AdPopcornSSPBannerView *bannerView;

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportRewardVideoAd;

- (void)setAge:(NSInteger)age;
- (void)setGender:(SSPGender)gender;
- (void)closeAd;

- (void)setViewController:(UIViewController *)viewController origin:(CGPoint)origin size:(CGSize)size bannerView:(AdPopcornSSPBannerView *)bannerView;
- (void)loadRequest;
- (void)setViewController:(UIViewController *)viewController;
- (void)loadAd;
- (void)showAd;
- (void)setRewardVideoViewController:(UIViewController *)viewController;

@property (NS_NONATOMIC_IOSONLY, readonly) CGSize adSize;
@end

@protocol AdPopcornSSPAdapterDelegate <NSObject>

@optional

- (void)AdPopcornSSPAdapterBannerViewDidLoadAd:(UIView *)bannerView adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterBannerView:(UIView *)bannerView didFailToReceiveAdWithError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;

- (void)AdPopcornSSPAdapterBannerViewWillLeaveApplication:(UIView *)bannerView;

- (void)AdPopcornSSPAdapterInterstitialAdDidLoadAd:(NSObject *)interstitialAd;

- (void)AdPopcornSSPAdapterInterstitial:(NSObject *)interstitialAd didFailToReceiveAdWithError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;

- (void)AdPopcornSSPAdapterInterstitialWillLeaveApplication:(NSObject *)interstitialAd;

- (void)AdPopcornSSPAdapterNativeAdDidLoadAd:(NSObject *)nativeAd networkName:(NSString *)networkName;
- (void)AdPopcornSSPAdapterNativeAd:(NSObject *)nativeAd didFailToReceiveAdWithError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;


- (void)AdPopcornSSPAdapterRewardVideoAdLoadSuccess;
- (void)AdPopcornSSPAdapterRewardVideoAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterRewardVideoAdShowSuccess;
- (void)AdPopcornSSPAdapterRewardVideoAdShowFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterRewardVideoAdClose;
- (void)AdPopcornSSPAdapterOnMintegralVideoCompleted:(NSInteger) RewardAmount;
- (void)AdPopcornSSPAdapterOnUnityAdsVideoCompleted;
- (void)AdPopcornSSPAdapterOnAdMobVideoCompleted:(double) RewardAmount;
@end
