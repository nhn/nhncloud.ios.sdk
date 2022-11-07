//
//  NHNCloudPushMedia.h
//  NHNCloudPush
//
//  Created by JooHyun Lee on 2018. 11. 30..
//  Copyright © 2018년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, NHNCloudPushMediaType) {
    NHNCloudPushMediaTypeImage NS_SWIFT_NAME(image) = 0,
    NHNCloudPushMediaTypeVideo NS_SWIFT_NAME(video) = 1,
    NHNCloudPushMediaTypeAudio NS_SWIFT_NAME(audio) = 2,
};

/**
# NHNCloudPushMedia

A class that has information about media.
*/
@interface NHNCloudPushMedia : NSObject <NSCoding, NSCopying>

/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** Type of media. */
@property (nonatomic, readonly) NHNCloudPushMediaType mediaType;

/** Source information of media. */
@property (nonatomic, readonly) NSString *source;

@end

NS_ASSUME_NONNULL_END
