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

@property (nonatomic, unsafe_unretained) SSPGender gender;
@property (nonatomic, unsafe_unretained) NSInteger age;

@property (nonatomic, unsafe_unretained, readonly) double latitude;
@property (nonatomic, unsafe_unretained, readonly) double longitude;
@property (nonatomic, unsafe_unretained, readonly) double accuracyInMeters;
@property (nonatomic, unsafe_unretained) BOOL gdprAvailable;
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, weak) id<APSSPMediationLogDelegate> mediationLogDelegate;

+ (AdPopcornSSP *)sharedInstance;

- (void)setLocationWithLatitude:(double)latitude
                      longitude:(double)longitude
                       accuracy:(double)accuracyInMeters;

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

@end

@protocol APSSPMediationLogDelegate <NSObject>
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
