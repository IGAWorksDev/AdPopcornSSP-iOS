//
//  AdPopcornSSP.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol APSSPMediationLogDelegate;
@protocol APSSPSDKInitializeDelegate;
@protocol APSSPRewardPlusSettingDelegate;

typedef enum _SSPGender
{
    SSPGenderFemale = 1,
    SSPGenderMale = 2,
    SSPGenderUnknown = 3
} SSPGender;

typedef enum _AdPopcornSSPLogLevel
{
    /*! log off  */
    AdPopcornSSPLogOff,
    /*! only critical logging  */
    AdPopcornSSPLogCritical,
    /*! critical, error logging  */
    AdPopcornSSPLogError,
    /*! critical, error, warning logging  */
    AdPopcornSSPLogWarning,
    /*! critical, error, warning, info logging  */
    AdPopcornSSPLogInfo,
    /*! critical, error, warning, info, debug logging  */
    AdPopcornSSPLogDebug,
    /*! all logging */
    AdPopcornSSPLogTrace
} AdPopcornSSPLogLevel;

@interface AdPopcornSSP : NSObject

+ (NSString *)getSDKVersion;
+ (NSString *)getSDKVersionNum;
+ (NSString *)frameworkName;

@property (nonatomic, unsafe_unretained) SSPGender gender;
@property (nonatomic, unsafe_unretained) NSInteger age;
@property (nonatomic, unsafe_unretained) BOOL gdprAvailable;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, unsafe_unretained) int uidIdentityType;
@property (nonatomic, copy) NSString *uidIdentifier;
@property (nonatomic, copy) NSString *uidToken;
@property (nonatomic, weak) id<APSSPMediationLogDelegate> mediationLogDelegate;
@property (nonatomic, weak) id<APSSPSDKInitializeDelegate> initializeDelegate;
@property (nonatomic, weak) id<APSSPRewardPlusSettingDelegate> rewardPlusDelegate;

+ (AdPopcornSSP *)sharedInstance;
/*!
 @abstract
 로그를 level를 설정한다.
 
 @discussion
 보고자 하는 로그 level을 info, debug, trace으로 설정한다.
 
 @param logLevel log level
 */
+ (void)setLogLevel:(AdPopcornSSPLogLevel)logLevel;
+ (void)gdprConsentAvailable:(BOOL)available;
+ (NSString *)getIDFA;
+ (void)openCSViewController:(UIViewController *)vController appKey:(NSString *)appKey userId:(NSString *)userId;
+ (void)setUserId:(NSString *)userId;

/*!
 @abstract
 SDK 초기화를 진행한다
 
 @discussion
 인앱 비딩을 사용하고자 하는 매체는 반드시 초기화 작업이 필요하다.
 */

+ (void)initializeSDK:(NSString *)appKey;
+ (void)setUIDIdentifier:(int)identityType identifier:(NSString *)identifier;
+ (void)openRewardPlusSettingViewController:(NSString *)appKey viewCotroller:(UIViewController *)vController;
+ (void)getRewardPlusUserSetting:(NSString *)appKey;
+ (void)tagForChildDirectedTreatment:(BOOL)tag;

@end

@protocol APSSPMediationLogDelegate <NSObject>
/*!
 @abstract
  특정 네트워크 광고 로드 요청 시작 시 호출된다.
 */
- (void)APSSPMediationLoadStart:(NSString *)placementId networkId:(NSInteger)networkId;

/*!
 @abstract
  특정 네트워크 광고 로드에 성공한 경우 호출된다.
 */
- (void)APSSPMediationLoadSuccess:(NSString *)placementId networkId:(NSInteger)networkId;

/*!
 @abstract
 특정 네트워크  광고 로드에 실패한 경우 호출된다.
 */
- (void)APSSPMediationLoadFailed:(NSString *)placementId networkId:(NSInteger)networkId;

@end

@protocol APSSPSDKInitializeDelegate <NSObject>
- (void)AdPopcornSSPSDKDidInitialize;
@end

@protocol APSSPRewardPlusSettingDelegate <NSObject>
- (void)APSSPRewardPlusSettingInfo:(NSString *)connectedId dailyUserLimit:(int)dailyUserLimit dailyUserCount:(int)dailyUserCount;
- (void)APSSPRewardPlusSettingPageClosed;
@end
