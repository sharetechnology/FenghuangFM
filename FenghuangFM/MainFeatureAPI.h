//
//  MainFeatureAPI.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/14.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseAPI.h"

@interface MainFeatureAPI : BaseAPI

/**
 *  请求轮播数据
 **/
+ (void)requestFocus:(BaseAPICompletion)completion;

/**
 *  请求剩余数据
 **/
+ (void)requestRest:(BaseAPICompletion)completion;

@end
