//
//  NHNCloudPushRichMessage.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 25/06/2019.
//  Copyright © 2019 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NHNCloudPushMedia.h"
#import "NHNCloudPushButton.h"

NS_ASSUME_NONNULL_BEGIN

/**
# NHNCloudPushRichMessage

A class that has information about rich message.
*/
@interface NHNCloudPushRichMessage : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Media information for rich message notification. */
@property (nonatomic, readonly, nullable) NHNCloudPushMedia *media;

/** Button information for rich message notification. */
@property (nonatomic, readonly, nullable) NSArray<NHNCloudPushButton *> *buttons;

@end

NS_ASSUME_NONNULL_END
