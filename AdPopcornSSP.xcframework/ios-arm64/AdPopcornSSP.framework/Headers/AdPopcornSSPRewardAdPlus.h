//
//  AdPopcornSSPRewardAdPlus.h
//  AdPopcornSSP
//
//  Created by Odin.송황호 on 6/9/25.
//

#import <UIKit/UIKit.h>

// pointbox 지급 관련 message
typedef enum {
    AdPopcornRewardPlusClaimPointBoxSuccess = 1,
    AdPopcornRewardPlusClaimPointBoxFail = 2,
    AdPopcornRewardPlusClaimPointBoxFail_6108 = 6108,
    AdPopcornRewardPlusClaimPointBoxFail_6109 = 6109,
} _SSPRewardPlusClaimBoxErrorCode;

typedef signed short SSPRewardPlusClaimBoxErrorCode;


static inline NSString * SSPRewardPlusClaimBoxString(SSPRewardPlusClaimBoxErrorCode state) {
    switch (state) {
        case AdPopcornRewardPlusClaimPointBoxSuccess:
            return @"포인트 박스 적립 성공";
        case AdPopcornRewardPlusClaimPointBoxFail:
            return @"포인트박스 적립에 실패하였습니다.";
        case AdPopcornRewardPlusClaimPointBoxFail_6108:
            return @"포인트박스 일 적립 한도를 달성했습니다.";
        case AdPopcornRewardPlusClaimPointBoxFail_6109:
            return @"포인트박스 최대 적립 한도를 달성했습니다.";
        default:
            return @"state";
    }
}


@protocol APSSPRewardAdPlusEventDelegate;

@interface AdPopcornSSPRewardAdPlus : NSObject

@property (nonatomic, weak) id<APSSPRewardAdPlusEventDelegate> delegate;

+ (NSString *)getVersion;

+ (AdPopcornSSPRewardAdPlus *)sharedInstance;

/*!
 @abstract
 RewardAdPlus를 open 하고자 할 경우
 */
+ (void)openRewardAdPlusViewController:(NSString *)appKey viewCotroller:(UIViewController *)vController;

/*!
 @abstract
 RewardAdPlus 특정 지면에 대한 정보
 */
+(void)getRewardAdPlusUserPlacementStatus:(NSString *)appKey placementId:(NSString *)placementId;

/*!
 @abstract
 RewardAdPlus 매체에 활성화된 전체 리워드 애드 플러스 지면에 대한 정보
 */
+(void)getRewardAdPlusUserMediaStatus:(NSString *)appKey;

@end


@protocol APSSPRewardAdPlusEventDelegate <NSObject>

@optional
- (void)rewardAdPlusUserMediaStatusWithResult:(BOOL)result
                                   totalBoxCount:(NSInteger)totalBoxCount
                           placementStatusList:(NSArray*)placementStatusList;

- (void)rewardAdPlusUserPlacementStatusWithResult:(BOOL)result
                                        placementId:(NSString *)placementId
                                   dailyUserLimit:(NSInteger)dailyUserLimit
                                   dailyUserCount:(NSInteger)dailyUserCount;
- (void) closedRewardAdPlusPage;

- (void) eventResult:(int)resultCode resultMessage: (NSString*)message;
@end
