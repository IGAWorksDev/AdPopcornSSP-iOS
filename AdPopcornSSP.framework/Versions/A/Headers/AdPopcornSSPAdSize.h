//
//  AdPopcornSSPAdSize.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdPopcornSSPBannerView.h"

typedef enum _SSPBannerViewRealSizeType
{
    SSPBannerViewSizeIphonePotriat320x50,
    SSPBannerViewSizeIphonePotriat300x250,
    SSPBannerViewSizeIphonePotriat320x100,
    SSPBannerViewSizeIphonePotriat360x185
} SSPBannerViewRealSizeType;

@interface AdPopcornSSPAdSize : NSObject

+ (CGSize)adSize:(SSPBannerViewSizeType)bannerViewSizeType;

+ (CGSize)adRealSize:(SSPBannerViewRealSizeType)bannerViewRealSizeType;

@end
