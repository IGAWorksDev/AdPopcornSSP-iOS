//
//  AdPopcornSSPWKScriptMessageHandler.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2023/04/24.
//  Copyright © 2023 AdPopcorn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

#import "AdPopcornSSPInterstitialAd.h"
@protocol AdPopcornSSPWKScriptNativeEventDelegate;

@interface AdPopcornSSPWKScriptMessageHandler : NSObject<WKScriptMessageHandler>

@property (nonatomic, weak) id<AdPopcornSSPWKScriptNativeEventDelegate> nativeEventDelegate;
@property (nonatomic, weak) id<WKScriptMessageHandler> scriptDelegate;
@property (nonatomic, weak) WKWebView *webView;
@property (nonatomic, weak) UIViewController *viewController;

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate;


@end


@protocol AdPopcornSSPWKScriptNativeEventDelegate <NSObject>
@optional
/*!
 @abstract
 Onnative Event 관련 호출시.
 */
- (void)APSSPOnNativeEvent:(NSString *)data;

@end
