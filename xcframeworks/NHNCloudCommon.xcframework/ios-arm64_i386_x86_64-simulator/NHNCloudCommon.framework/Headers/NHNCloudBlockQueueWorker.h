//
//  NHNCloudPurchaseBlockQueueWorker.h
//  NHNCloudIAP
//
//  Created by HyupM1 on 2023/07/03.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudBlockQueueWorker : NSObject

@property (nonatomic, readonly, getter=isExecuting) BOOL executing;
@property (nonatomic, readonly) NSTimeInterval lastExecuteTime;

- (instancetype)initWithQueueCapacity:(int)queueCapacity;

- (void)addObject:(id)object;

- (void)resume;
- (void)suspend;

- (void)clear;
- (NSUInteger)count;
@end

NS_ASSUME_NONNULL_END
