//
//  NHNCloudLoggerDelegate.h
//  NHNCloudLogger
//
//  Created by Hyup on 2018. 4. 5..
//  Copyright © 2018년 NHN. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class NHNCloudInstanceLogger;

@protocol NHNCloudLoggerDelegate <NSObject>

@optional
/**
 Called after the log has been successfully sent.

 @param log The log that sent successfully
 */
- (void)nhnCloudLogDidSuccess:(NHNCloudLog *)log;

/**
 Called after the log fails to send.

 @param log The log that sent failed
 @param error The error about the cause of the failure
 */
- (void)nhnCloudLogDidFail:(NHNCloudLog *)log error:(NSError *)error;

/**
 Called after the log has been successfully saved.

 @param log The log that saved successfully
 */
- (void)nhnCloudLogDidSave:(NHNCloudLog *)log;

/**
 Called after the log has been successfully filtered.

 @param log The log that filtered successfully
 @param logFilter The filter used when filtering log
 */
- (void)nhnCloudLogDidFilter:(NHNCloudLog *)log logFilter:(NHNCloudLogFilter *)logFilter;

@end

NS_ASSUME_NONNULL_END
