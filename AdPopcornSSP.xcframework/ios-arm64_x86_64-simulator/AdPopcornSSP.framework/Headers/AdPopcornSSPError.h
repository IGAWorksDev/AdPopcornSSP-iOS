//
//  AdPopcornSSPError.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>

/// AdPopcornSSP error domain.
extern NSString *const kAdPopcornSSPErrorDomain;

/// NSError codes for GAD error domain.
typedef NS_ENUM(NSInteger, SSPErrorCode) {
    AdPopcornSSPSuccess = 1,
    AdPopcornSSPException = 200,
    AdPopcornSSPInvalidParameter = 1000,
    AdPopcornSSPUnknownServerError = 9999,
    AdPopcornSSPInvalidMediaKey = 2000,
    AdPopcornSSPInvalidPlacementId = 2030,
    AdPopcornSSPEmptyCampaign = 2100,
    AdPopcornSSPInvalidNativeAssetsConfig = 3300,
    AdPopcornSSPNativePlacementDoesNotInitialized = 3200,
    AdPopcornSSPMediationInvalidIntegrationKey = 4000,
    AdPopcornSSPMediationAdapterNotInitialized = 4001,
    AdPopcornSSPServerTimeout = 5000,
    AdPopcornSSPLoadAdFailed = 5001,
    AdPopcornSSPNoAd = 5002,
    AdPopcornSSPNoInterstitialLoaded = 5003,
    AdPopcornSSPNoRewardVideoAdLoaded = 5005,
    AdPopcornSSPGdprConsentUnavailable = 5008,
    AdPopcornSSPNoInterstitialVideoAdLoaded = 5009,
    AdPopcornSSPNoSplashAdLoaded = 5010,
    AdPopcornSSPNoModalAdLoaded = 5011,
    AdPopcornSSPNoVideoMixAdLoaded = 5012,
    AdPopcornRewardPlusDailyUserLimitExceeded = 6001,
    AdPopcornRewardPlusDailySSPLimitExceeded = 6002,
    AdPopcornRewardPlusUserNotRegistered = 6003,
    AdPopcornRewardPlusNPayMemberInfoNotFound = 6004,
    AdPopcornRewardPlusDuplicatePointAddRequest = 6005,
    AdPopcornRewardPlusFailedToAddPoint = 6006,
    AdPopcornRewardPlusUserAlreadyRegistered = 6007,
};

@interface AdPopcornSSPError : NSError


@end
