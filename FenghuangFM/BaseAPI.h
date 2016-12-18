//
//  BaseAPI.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/14.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BaseRequest.h"

typedef void(^BaseAPICompletion)(id response, NSString *message, BOOL success);

@interface BaseAPI : NSObject

+ (NSMutableDictionary *)params;

@end
