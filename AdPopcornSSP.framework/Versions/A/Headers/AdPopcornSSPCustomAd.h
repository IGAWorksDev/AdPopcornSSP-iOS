//
//  AdPopcornSSPCustomAd.h
//  AdPopcornSSPLib
//
//  Created by mick on 2020. 2. 18..
//  Copyright (c) 2020년 igaworks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

#import "AdPopcornSSPError.h"

@protocol APSSPCustomAdDelegate;

typedef enum _SSPCustomAdType
{
    SSPCustomAd320x50,
    SSPCustomAd300x250,
    SSPCustomAd320x100,
    SSPCustomAdInterstitial,
    SSPCustomAdNativeAd
} SSPCustomAdType;

typedef enum _SSPCustomAdStatus
{
    INIT_AD,
    RUN_AD,
    STOP_AD
} SSPCustomAdStatus;

@interface AdPopcornSSPCustomAd : NSObject
@property (nonatomic, weak) id<APSSPCustomAdDelegate> delegate;
@property (nonatomic, copy) NSString *placementId;

- (instancetype)initWithAppKey:(NSString *)appKey placementId:(NSString *)placementId adType:(SSPCustomAdType)adType;
- (void)loadAd;
- (void)stopAd;
- (void)reportImpression;
- (void)reportClick;
- (NSMutableArray *)getImpTrackersList;
- (NSMutableArray *)getClickTrackersList;

@end

@protocol APSSPCustomAdDelegate <NSObject>
@optional
/*!
 @abstract
 CustomAd load 완료시(성공시), 호출된다.
 */
- (void)APSSPCustomAdLoadSuccess:(AdPopcornSSPCustomAd *)customAd adData:(NSString *)adData;

/*!
 @abstract
 CustomAd load 실패시, 호출된다.
 */
- (void)APSSPCustomAdLoadFail:(AdPopcornSSPCustomAd *)customAd error:(AdPopcornSSPError *)error;

@end
