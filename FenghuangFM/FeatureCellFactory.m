//
//  FeatureCellFactory.m
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/17.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import "FeatureCellFactory.h"
#import "FeatureNormalCell.h"
#import "FeatureSpecialCell.h"

@implementation FeatureCellFactory

+ (FeatureBaseCell *)createCellByFactory:(UITableView *)tableView style:(FeatureCellStyle)style
{
    FeatureBaseCell *baseCell;
    if (style == FeatureCellNormalStyle) {
        baseCell = [FeatureNormalCell featureCell:tableView];
    } else if (style == FeatureCellSpecialStyle) {
        baseCell = [FeatureSpecialCell featureCell:tableView];
    }
    
    return baseCell;
}

@end
