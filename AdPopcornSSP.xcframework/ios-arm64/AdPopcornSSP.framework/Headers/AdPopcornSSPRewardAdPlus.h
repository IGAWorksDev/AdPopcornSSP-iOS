//
//  AdPopcornSSPRewardAdPlus.h
//  AdPopcornSSP
//
//  Created by Odin.송황호 on 6/9/25.
//

#import <UIKit/UIKit.h>


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

@optional
- (void)rewardAdPlusUserPlacementStatusWithResult:(BOOL)result
                                        placementId:(NSString *)placementId
                                   dailyUserLimit:(NSInteger)dailyUserLimit
                                   dailyUserCount:(NSInteger)dailyUserCount;
@optional
- (void) closedRewardAdPlusPage;

@optional
- (void) eventResult:(int)resultCode resultMessage: (NSString*)message;

@end
