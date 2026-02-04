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
#import "AdPopcornSSPReactNativeAd.h"

@protocol AdPopcornSSPAdapterDelegate;

typedef enum _SSPMediationGender
{
    SSPMediationGenderMale,
    SSPMediationGenderFemale
} SSPMediationGender;

typedef enum _SSPAdType
{
    SSPAdBannerType = 1,
    SSPAdInterstitialType = 2,
    SSPNativeAdType = 3,
    SSPRewardVideoAdType = 4,
    SSPInterstitialVideoAdType = 6,
    SSPModalAdType = 8,
    SSPVideoMixAdType = 13,
    SSPReactNativeAdType = 99,
} SSPAdType;

typedef enum _VideoMixAdType {
    VideoMix_InterstitialType = 2,
    VideoMix_RewardVideoType = 4,
    VideoMix_InterstitialVideoType = 6
} VideoMixAdType;

VideoMixAdType SSPVideoMixAdTypeFromInteger(NSInteger value);

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

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportVideoMixAd;

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportNativeAd;

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportInterstitialVideoAd;

@property (nonatomic, weak) AdPopcornSSPNativeAd *adpopcornSSPNativeAd;

@property (nonatomic, weak) AdPopcornSSPReactNativeAd *adpopcornSSPReactNativeAd;

@property (nonatomic, unsafe_unretained, readonly) BOOL isSupportModalAd;

@property (nonatomic, weak) UIView *modalRootView;

- (void)setAge:(NSInteger)age;
- (void)setGender:(SSPGender)gender;
- (void)closeAd;

- (void)setViewController:(UIViewController *)viewController origin:(CGPoint)origin size:(CGSize)size bannerView:(AdPopcornSSPBannerView *)bannerView;
- (void)loadRequest;
- (void)setViewController:(UIViewController *)viewController;
- (void)loadAd;
- (void)showAd;
- (void)setRewardVideoViewController:(UIViewController *)viewController;
- (void)setVideoMixAdViewController:(UIViewController *)viewController;
- (void)setNativeAdViewController:(UIViewController *)viewController nativeAdRenderer:(id)nativeAdRenderer rootNativeAdView:(AdPopcornSSPNativeAd *)adpopcornSSPNativeAd;
- (void)setInterstitialVideoViewController:(UIViewController *)viewController;
- (NSString *)getBiddingToken;
- (void)setBiddingData:(NSString *)biddingData impressionList:(NSMutableArray *)impTrackersListArray clickList: (NSMutableArray *)clickTrackersListArray;
- (void)setMute:(bool)mute;
- (void)setInAppBiddingMode:(bool)isInAppBiddingMode;
- (void)setViewController:(UIViewController *)viewController reactNativeAd:(AdPopcornSSPReactNativeAd *)reactNativeAd;
- (void)setModalAdViewController:(UIViewController *)viewController rootView:(UIView *)modalRootView gravity:(int)adGravity closeBtnType:(int)closeBtnType;

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
- (void)AdPopcornSSPAdapterNativeAdHidden:(AdPopcornSSPAdapter *)adapter;

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

// ReactNative
- (void)AdPopcornSSPAdapterReactNativeAdLoadSuccess:(AdPopcornSSPAdapter *)adapter adSize:(CGSize)adSize;
- (void)AdPopcornSSPAdapterReactNativeAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterReactNativeAdImpression:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterReactNativeAdClicked:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterReactNativeAdSizeChanged:(AdPopcornSSPAdapter *)adapter adSize:(CGSize)adSize;

// Modal Ad
- (void)AdPopcornSSPAdapterModalAdLoadSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterModalAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterModalAdShowSuccess:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterModalAdShowFailError:(NSError *)error;
- (void)AdPopcornSSPAdapterModalAdClicked:(AdPopcornSSPAdapter *)adapter;
- (void)AdPopcornSSPAdapterModalAdClosed:(AdPopcornSSPAdapter *)adapter;
// Common
- (void)impClickTracking:(NSString *)url;

// Video Mix
- (void)AdPopcornSSPAdapterVideoMixAdLoadSuccess:(AdPopcornSSPAdapter *)adapter videoMixType: (VideoMixAdType) type;
- (void)AdPopcornSSPAdapterVideoMixAdLoadFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter videoMixType: (VideoMixAdType) type;
- (void)AdPopcornSSPAdapterVideoMixAdShowSuccess:(AdPopcornSSPAdapter *)adapter videoMixType: (VideoMixAdType) type;
- (void)AdPopcornSSPAdapterVideoMixAdShowFailError:(NSError *)error adapter:(AdPopcornSSPAdapter *)adapter videoMixType: (VideoMixAdType) type;
- (void)AdPopcornSSPAdapterVideoMixAdClicked:(AdPopcornSSPAdapter *)adapter videoMixType: (VideoMixAdType) type;
- (void)AdPopcornSSPAdapterVideoMixAdClose:(AdPopcornSSPAdapter *)adapter videoMixType: (VideoMixAdType) type;
- (void)AdPopcornSSPAdapterVideoMixAdCompleteTrackingEvent:(NSInteger)adNetworkNo isCompleted:(bool)isCompleted videoMixType: (VideoMixAdType) type;

@end
