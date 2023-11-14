//
//  NHNCloudFileCache.h
//  NHNCloudCommon
//
//  Created by JooHyun Lee on 20/03/2020.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudMemoryCache.h"

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudFileCache : NHNCloudMemoryCache <NHNCloudCacheProtocol>

@property (nonatomic) NSURL *fileURL;
@property (nonatomic) BOOL iCloudBackupEnabled;

@end

NS_ASSUME_NONNULL_END
