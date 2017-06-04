//
//  MainFeatureHelper.h
//  FenghuangFM
//
//  Created by tom555cat on 2017/6/4.
//  Copyright © 2017年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MainFeatureHelper : NSObject

+ (instancetype)helper;
    

/**
 *  开启轮播的定时器
 */
- (void)startHeadTimer;
    
/**
 *  销毁定时器
 */
- (void)destoryHeaderTimer;

    
@end
