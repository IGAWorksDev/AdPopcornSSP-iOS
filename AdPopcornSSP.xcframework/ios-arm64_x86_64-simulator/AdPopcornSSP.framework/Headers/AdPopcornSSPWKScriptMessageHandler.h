//
//  AdPopcornSSPWKScriptMessageHandler.h
//  AdPopcornSSPLib
//
//  Created by 김민석 on 2023/04/24.
//  Copyright © 2023 AdPopcorn. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@interface AdPopcornSSPWKScriptMessageHandler : NSObject<WKScriptMessageHandler>

@property (nonatomic, weak) id<WKScriptMessageHandler> scriptDelegate;
@property (nonatomic, weak) WKWebView *webView;

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate;

@end
