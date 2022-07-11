//
//  NHNCloudCache.h
//  NHNCloudCommon
//
//  Created by JooHyun Lee on 20/03/2020.
//  Copyright © 2020 NHN Corp. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol NHNCloudCacheProtocol <NSObject>

@property (nonatomic, readonly) NSDictionary<NSString *, id> *allObjects;

#pragma mark - set
- (void)setObjects:(nullable NSDictionary<NSString *,id> *)objects;
- (void)setObject:(nullable id)object forKey:(NSString *)key;
- (void)addEntriesFromDictionary:(nullable NSDictionary<NSString *, id> *)otherDictionary;

#pragma mark - get
- (nullable id)objectForKey:(NSString *)key;

#pragma mark - remove
- (void)removeObjectForKey:(NSString *)key;
- (void)removeAllObjects;

@end


// TODO: KVO, Limit cost
@interface NHNCloudCache : NSObject <NHNCloudCacheProtocol>

@property (nonatomic, copy, readonly, nullable) NSString *name;

@property (nonatomic, readonly) NSDictionary<NSString *, id> *allObjects;
@property (nonatomic, readonly) NSArray<NSString *> *allKeys;
@property (nonatomic, readonly) NSArray<id> *allValues;

+ (instancetype)defaultCache;

+ (instancetype)cacheForName:(nullable NSString *)name;

- (instancetype)initWithName:(nullable NSString *)name;

#pragma mark - set
- (void)setObjects:(nullable NSDictionary<NSString *,id> *)objects;
- (void)setObject:(nullable id)object forKey:(NSString *)key;
- (void)setInteger:(NSInteger)value forKey:(NSString *)key;
- (void)setInt:(int)value forKey:(NSString *)key;
- (void)setFloat:(float)value forKey:(NSString *)key;
- (void)setDouble:(double)value forKey:(NSString *)key;
- (void)setBool:(BOOL)value forKey:(NSString *)key;
- (void)addEntriesFromDictionary:(nullable NSDictionary<NSString *, id> *)otherDictionary;

#pragma mark - get
- (nullable id)objectForKey:(NSString *)key;
- (id)objectForKey:(NSString *)key defaultObject:(id)defaultObject;
- (id)objectForKey:(NSString *)key initialObject:(id)initialObject;
- (nullable NSString *)stringForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key;
- (int)intForKey:(NSString *)key;
- (float)floatForKey:(NSString *)key;
- (double)doubleForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key;
- (nullable NSArray<id> *)arrayForKey:(NSString *)key;
- (nullable NSDictionary<id, id> *)dictionaryForKey:(NSString *)key;

#pragma mark - remove
- (void)removeObjectForKey:(NSString *)key;
- (void)removeAllObjects;

@end

NS_ASSUME_NONNULL_END
