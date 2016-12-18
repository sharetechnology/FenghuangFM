//
//  SubMainFactory.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/13.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MainBaseController.h"

typedef NS_ENUM(NSInteger, SubMainType) {
    SubMainTypeFeature  =   0,  // 精选
    SubMainTypeTrend    =   1,  // 动态
    SubMainTypeRank     =   2,  // 榜单
    SubMainTypeCategory =   3,  // 分类
    SubMainTypeUnKnown  =   4,  // 未知
};

@interface SubMainFactory : NSObject

/**
 *  生成自控制器
 *  @param identifier 控制器的唯一标识
 **/
+ (MainBaseController *)subControllerWithIdentifier:(NSString *)identifier;

@end
