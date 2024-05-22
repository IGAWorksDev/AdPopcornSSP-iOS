//
//  AdPopcornSSPContentsAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 5/15/24.
//  Copyright © 2024 AdPopcorn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"

@protocol APSSPContentsAdDelegate;

@interface AdPopcornSSPContentsAd : NSObject

@property (nonatomic, weak) id<APSSPContentsAdDelegate> delegate;
@property (nonatomic, weak) UIViewController *viewController;

/*!
 @abstract
 contents ad instance 생성.
 @param appKey          app appKey
 @param contentsPlacementId    contentsPlacementId
 @param viewController  current view controller
 */

- (instancetype)initWithAppKey:(NSString *)appKey contentsPlacementId:(NSString *)contentsPlacementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;
- (void)openContents;
@end

@protocol APSSPContentsAdDelegate <NSObject>
/*!
 @abstract
  컨텐츠 페이지 로딩 성공한 경우 호출된다.
 */
- (void)APSSPContentsAdOpenSuccess:(AdPopcornSSPContentsAd *)contentsAd;

/*!
 @abstract
 컨텐츠 페이지 로딩 실패한 경우 호출된다.
 */
- (void)APSSPContentsAdOpenFail:(AdPopcornSSPContentsAd *)contentsAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 컨텐츠 페이지가 종료 될 때 호출된다.
 */
- (void)APSSPContentsAdClosed:(AdPopcornSSPContentsAd *)contentsAd;

/*!
 @abstract
 컨텐츠 페이지 내 광고 참여 완료 시 호출된다.
 */
- (void)APSSPContentsAdComplete:(AdPopcornSSPContentsAd *)contentsAd reward:(NSInteger)reward;

@end
