//
//  NHNCloudNetworkManager.h
//  NHNCloudCommon
//
//  Created by Hyup on 2017. 8. 25..
//  Copyright © 2017년 NHN. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import "NHNCloudNetworkStatus.h"

NS_ASSUME_NONNULL_BEGIN

@protocol NHNCloudNetworkStatusObserver;

/**
 # Network manager
 
 Monitoring whether the network is connected or not.
 
 */
@interface NHNCloudNetworkManager : NSObject

@property (readonly, getter=isMonitoring) BOOL monitoring;

@property (class, readonly, strong) NHNCloudNetworkManager *defaultManager;
@property (nonatomic, readonly, nullable) NHNCloudNetworkStatus *currentNetworkStatus;

/// ---------------------------------
/// @name Start & Stop monitoring
/// ---------------------------------

/**
 Start monitoring to see if the state of the network changes.
 */
- (void)startMonitoringNetworkStatusChanges;

/**
 Stop monitoring to see if the state of the network changes.
 */
- (void)stopMonitoringNetworkStatusChanges;

/// ---------------------------------
/// @name Add & Remove observer
/// ---------------------------------

/**
 Add observer(NHNCloudNetworkStatusObserver)

 @param observer observer to be added
 */
- (void)addObserver:(id<NHNCloudNetworkStatusObserver>)observer;

/**
 Remove observer

 @param observer observer observer to be removed
 */
- (void)removeObserver:(id<NHNCloudNetworkStatusObserver>)observer;

@end


/**
 # Network status observer
 */
@protocol NHNCloudNetworkStatusObserver <NSObject>

- (void)networkManager:(NHNCloudNetworkManager *)manager didChangeNetworkStatus:(NHNCloudNetworkStatus *)status;

@end

NS_ASSUME_NONNULL_END
