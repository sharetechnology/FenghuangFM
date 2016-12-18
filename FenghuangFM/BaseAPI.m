//
//  BaseAPI.m
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/14.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import "BaseAPI.h"

@implementation BaseAPI

+ (NSMutableDictionary *)params
{
    NSMutableDictionary *dic = [[NSMutableDictionary alloc] init];
    [dic setObject:@"iPhone" forKey:@"device"];
    return dic;
}

@end
