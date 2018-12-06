//
//  AdPopcornSSP.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>

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

+ (AdPopcornSSP *)sharedInstance;

- (void)setLocationWithLatitude:(double)latitude
                      longitude:(double)longitude
                       accuracy:(double)accuracyInMeters;


/*!
 @abstract
 로그를 level를 설정한다.
 
 @discussion
 보고자 하는 로그 level을 info, debug, trace으로 설정한다.
 
 @param LogLevel log level
 */
+ (void)setLogLevel:(AdPopcornSSPLogLevel)logLevel;

@end
