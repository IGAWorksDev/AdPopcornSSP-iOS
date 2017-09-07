//
//  AdPopcornSSPDemo.h
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

@interface AdPopcornSSPDemo : NSObject

@property (nonatomic, unsafe_unretained) SSPGender gender;
@property (nonatomic, unsafe_unretained) NSInteger age;

@property (nonatomic, unsafe_unretained, readonly) double latitude;
@property (nonatomic, unsafe_unretained, readonly) double longitude;
@property (nonatomic, unsafe_unretained, readonly) double accuracyInMeters;

+ (AdPopcornSSPDemo *)sharedInstance;

- (void)setLocationWithLatitude:(double)latitude
                      longitude:(double)longitude
                       accuracy:(double)accuracyInMeters;


@end
