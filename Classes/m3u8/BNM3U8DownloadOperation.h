//
//  BNM3U8DownloadOperation.h
//  m3u8Demo
//
//  Created by liangzeng on 6/14/19.
//  Copyright © 2019 liangzeng. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BNM3U8DownloadConfig.h"
#import "AFNetworking.h"
NS_ASSUME_NONNULL_BEGIN


typedef void(^BNM3U8DownloadOperationResultBlock)( NSError * _Nullable error, NSString * _Nullable relativeUrl, NSString * _Nullable localFilePath);
typedef void(^BNM3U8DownloadOperationProgressBlock)(CGFloat progress);
typedef void(^BNM3U8DownloadOperationHomeDirCreated)(NSString *_Nullable fileHomePath);
/*
 继承 NSOperation 需实相关方法，包括状态控制
 
 上层使用NSOperationQueue去控制并发，全局控制
 */
@interface BNM3U8DownloadOperation : NSOperation
- (instancetype)initWithConfig:(BNM3U8DownloadConfig *)config homeDirCreated:(BNM3U8DownloadOperationHomeDirCreated)homeCreated downloadDstRootPath:(NSString *)path sessionManager:(AFURLSessionManager *)sessionManager progressBlock:(BNM3U8DownloadOperationProgressBlock)progressBlock resultBlock:(BNM3U8DownloadOperationResultBlock)resultBlock;
- (void)suspend;
- (void)resume;
@end

NS_ASSUME_NONNULL_END
