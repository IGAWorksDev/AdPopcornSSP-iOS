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

#import "AdPopcornSSPDemo.h"

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
    SSPNativeAdType
} SSPAdType;

// Set Logging Component
#undef AdPopcornLogComponent
#define AdPopcornLogComponent lcl_cAdPopcorn

@interface AdPopcornSSPAdapter : NSObject
{
    UIViewController *_viewController;
    CGPoint _origin;
    CGSize _size;
    SSPAdType _adType;
    AdPopcornSSPBannerView *_bannerView;
}

@property (nonatomic, unsafe_unretained) id<AdPopcornSSPAdapterDelegate> delegate;

@property (nonatomic, strong) NSDictionary *integrationKey;

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportInterstitialAd;

- (void)setViewController:(UIViewController *)viewController origin:(CGPoint)origin size:(CGSize)size bannerView:(AdPopcornSSPBannerView *)bannerView;
- (void)setViewController:(UIViewController *)viewController;
- (void)setNativeAdType;
- (void)loadAd;
- (void)showAd;
- (void)closeAd;
- (void)loadRequest;

@property (NS_NONATOMIC_IOSONLY, readonly) CGSize adSize;

- (void)setAge:(NSInteger)age;
- (void)setGender:(SSPGender)gender;

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

@end
