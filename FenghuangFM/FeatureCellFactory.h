//
//  FeatureCellFactory.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/17.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FeatureBaseCell.h"

typedef NS_ENUM(NSInteger, FeatureCellStyle) {
    FeatureCellNormalStyle      = 0,    // 3格图片cell
    FeatureCellSpecialStyle     = 1,    // 2格图片cell
    FeatureCellManageStyle      = 2,    // 管理首页cell
};

@interface FeatureCellFactory : NSObject

/**
 *  传入要创建的样式，由工厂类生成特定样式的cell
 **/
+ (FeatureBaseCell *)createCellByFactory:(UITableView *)tableView style:(FeatureCellStyle)style;

@end
