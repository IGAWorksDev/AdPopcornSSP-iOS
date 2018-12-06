//
//  AdPopcornSSPVastAdapter.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2018. 6. 28..
//  Copyright © 2018년 mick. All rights reserved.
//


#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

@protocol AdPopcornSSPVastAdapterDelegate;

// Set Logging Component
#undef AdPopcornLogComponent
#define AdPopcornLogComponent lcl_cAdPopcorn

@interface AdPopcornSSPVastAdapter : NSObject
{
}

@property (nonatomic, strong) NSString *campaignWebData;
@property (nonatomic, weak) id<AdPopcornSSPVastAdapterDelegate> delegate;

- (void)showVastAdWithViewController:(UIViewController *)viewController;

@end

@protocol AdPopcornSSPVastAdapterDelegate <NSObject>

@optional
- (void)AdPopcornSSPVastAdsLoadedWithData;
- (void)AdPoopcornSSPVastAdsFailedWithErrorData;
- (void)AdPopcornSSPVastAdsCompleted;
@end
