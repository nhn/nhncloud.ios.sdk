//
//  NHNCloudLog.h
//  NHNCloudLogger
//
//  Created by Hyup on 2017. 10. 16..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NHNCloudCore/NHNCloudCore.h>

NS_ASSUME_NONNULL_BEGIN

/**
 # NHNCloudLog
 
 The information of log.
 
 There are methods to create a log.
 */
@interface NHNCloudLog : NSObject <NSCoding, NSCopying>


/// ---------------------------------
/// @name Properties
/// ---------------------------------

/** unique number of log */
@property (nonatomic, copy, readonly) NSString *transactionID;
/** level of log (debug, info, warn, error, fatal) */
@property (nonatomic, readonly) NHNCloudLogLevel level;
/** type of log*/
@property (nonatomic, copy, readonly) NSString *type;
/** message of log */
@property (nonatomic, copy, readonly) NSString *message;
/** created time of log (unix epoch) */
@property (nonatomic, copy, readonly) NSNumber *createTime;
/** additional fileds(key, value) of log */
@property (nonatomic, copy, readonly) NSDictionary<NSString *, NSString *> *userFields;



/// ---------------------------------
/// @name Craete NHNCloudLog
/// ---------------------------------


/**
 Create NHNCloudLog instance with the given level, type, message and userFields.

 @param level The level of log
 @param type The type of log
 @param message The message of log
 @param userFields The userFields of log
 @return The instance of a NHNCloudLog
 */
+ (instancetype)logWithLevel:(NHNCloudLogLevel)level
                        type:(NSString *)type
                     message:(NSString *)message
                  userFields:(nullable NSDictionary<NSString *, NSString *> *)userFields;



/// ---------------------------------
/// @name Initialize with parameters
/// ---------------------------------

/**
 Initialize log with the given level, type, message and userFields.
 
 @param level The level of log
 @param type The type of log
 @param message The message of log
 @param userFields The userFields of log
 @return The instance of a NHNCloudLog
 */
- (instancetype)initWithLevel:(NHNCloudLogLevel)level
                         type:(NSString *)type
                      message:(NSString *)message
                   userFields:(nullable NSDictionary<NSString *, NSString *> *)userFields;

@end

NS_ASSUME_NONNULL_END
