//
//  AdPopcornSSPAdSize.h
//  AdPopcornSSPLib
//
//  Created by mick on 2017. 7. 25..
//  Copyright (c) 2017년 igaworks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdPopcornSSPBannerView.h"

@interface AdPopcornSSPAdSize : NSObject

+ (CGSize)adSize:(SSPBannerViewSizeType)bannerViewSizeType;
@end
