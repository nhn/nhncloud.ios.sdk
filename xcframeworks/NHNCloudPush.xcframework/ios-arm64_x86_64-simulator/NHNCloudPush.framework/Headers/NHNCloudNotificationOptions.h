//
//  NHNCloudNotificationOptions.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 03/03/2020.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NHNCloudNotificationOptions : NSObject <NSCoding, NSCopying>

@property (nonatomic) BOOL badgeEnabled;
@property (nonatomic) BOOL soundEnabled;
@property (nonatomic) BOOL foregroundEnabled;

- (instancetype)init;

- (instancetype)initWithOptions:(NSUInteger)options;

@end

NS_ASSUME_NONNULL_END
