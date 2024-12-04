//
//  AdPopcornSSPPopContentsAd.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 11/26/24.
//  Copyright © 2024 AdPopcorn. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdPopcornSSPError.h"

@protocol APSSPPopContentsAdDelegate;

@interface AdPopcornSSPPopContentsAd : NSObject

@property (nonatomic, weak) id<APSSPPopContentsAdDelegate> delegate;
@property (nonatomic, weak) UIViewController *viewController;

/*!
 @abstract
 pop contents ad instance 생성.
 @param appKey          app appKey
 @param popContentsPlacementId    popContentsPlacementId
 @param viewController  current view controller
 */

- (instancetype)initWithAppKey:(NSString *)appKey popContentsPlacementId:(NSString *)popContentsPlacementId viewController:(UIViewController *)viewController NS_DESIGNATED_INITIALIZER;
- (void)openPopContents;
@end

@protocol APSSPPopContentsAdDelegate <NSObject>
/*!
 @abstract
 팝콘텐츠 페이지 로딩 성공한 경우 호출된다.
 */
- (void)APSSPPopContentsAdOpenSuccess:(AdPopcornSSPPopContentsAd *)contentsAd;

/*!
 @abstract
 팝콘텐츠 페이지 로딩 실패한 경우 호출된다.
 */
- (void)APSSPPopContentsAdOpenFail:(AdPopcornSSPPopContentsAd *)contentsAd error:(AdPopcornSSPError *)error;

/*!
 @abstract
 팝콘텐츠 페이지가 종료 될 때 호출된다.
 */
- (void)APSSPPopContentsAdClosed:(AdPopcornSSPPopContentsAd *)contentsAd;
@end

