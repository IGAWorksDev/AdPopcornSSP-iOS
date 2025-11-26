//
//  APSSPRewardAdPlusStatusModel.h
//  AdPopcornSSPLib
//
//  Created by Odin.송황호 on 6/11/25.
//  Copyright © 2025 AdPopcorn. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APSSPRewardAdPlusStatusModel : NSObject

@property (nonatomic, copy) NSString *placementId;
@property (nonatomic, assign) NSInteger current;
@property (nonatomic, assign) NSInteger limit;

- (NSDictionary *)toDictionary;

@end
