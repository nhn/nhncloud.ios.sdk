//
//  NHNCloudTaskQueue.h
//  NHNCloudCommon
//
//  Created by JooHyun Lee on 2020/07/02.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudAsyncTask.h"

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudTaskQueue : NSObject

- (void)addTask:(NHNCloudAsyncTask *)task;

- (void)removeTask:(NHNCloudAsyncTask *)task;

@end

NS_ASSUME_NONNULL_END
