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

#import "AdPopcornSSPNativeAd.h"

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
    SSPRewardVideoAdType,
    SSPInterstitialVideoAdType
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

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportNativeAd;

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportInterstitialVideoAd;

@property (nonatomic, weak) AdPopcornSSPNativeAd *adpopcornSSPNativeAd;

- (void)setAge:(NSInteger)age;
- (void)setGender:(SSPGender)gender;
- (void)closeAd;

- (void)setViewController:(UIViewController *)viewController origin:(CGPoint)origin size:(CGSize)size bannerView:(AdPopcornSSPBannerView *)bannerView;
- (void)loadRequest;
- (void)setViewController:(UIViewController *)viewController;
- (void)loadAd;
- (void)showAd;
- (void)setRewardVideoViewController:(UIViewController *)viewController;
- (void)setNativeAdViewController:(UIViewController *)viewController nativeAdRenderer:(id)nativeAdRenderer rootNativeAdView:(AdPopcornSSPNativeAd *)adpopcornSSPNativeAd;
- (void)setInterstitialVideoViewController:(UIViewController *)viewController;
- (NSString *)getBiddingToken;
- (void)setBiddingData:(NSString *)biddingData impressionList:(NSMutableArray *)impTrackersListArray clickList: (NSMutableArray *)clickTrackersListArray;
- (void)setMute:(bool)mute;
- (void)setInAppBiddingMode:(bool)isInAppBiddingMode;
@property (NS_NONATOMIC_IOSONLY, readonly) CGSize adSize;
@end

@protocol AdPopcornSSPAdapterDelegate <NSObject>

@optional

// Banner
- (void)AdPopcornSSPAdapterBannerViewLoadSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterBannerViewLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterBannerViewClicked:(AdPopcornSSPAdapter *)adapter;

// Interstitial
- (void)AdPopcornSSPAdapterInterstitialAdLoadSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialAdShowSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialAdShowFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialAdClicked:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialAdClosed:(AdPopcornSSPAdapter *)adapter;

// Native
- (void)AdPopcornSSPAdapterNativeAdLoadSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterNativeAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterNativeAdImpression:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterNativeAdClicked:(AdPopcornSSPAdapter *)adapter;

// Reward Video
- (void)AdPopcornSSPAdapterRewardVideoAdLoadSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterRewardVideoAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterRewardVideoAdShowSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterRewardVideoAdShowFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterRewardVideoAdClose:(AdPopcornSSPAdapter *)adapter;
- (void)onCompleteTrackingEvent:(NSInteger)adNetworkNo isCompleted:(bool)isCompleted;

// Interstitial Video
- (void)AdPopcornSSPAdapterInterstitialVideoAdLoadSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialVideoAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialVideoAdShowSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialVideoAdShowFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterInterstitialVideoAdClose:(AdPopcornSSPAdapter *)adapter;

// Common
- (void)impClickTracking:(NSString *)url;
@end
