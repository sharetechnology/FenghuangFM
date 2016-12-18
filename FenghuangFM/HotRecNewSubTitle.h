//
//  HotRecNewSubTitle.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/20.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <UIKit/UIKit.h>

@class HotRecNewSubTitle;

@protocol HotRecNewSubTitleDelegate <NSObject>

- (void)hotRecNewDidSelected:(HotRecNewSubTitle *)titleView atIndex:(NSInteger)index title:(NSString *)title;

@end

@interface HotRecNewSubTitle : UIView

@property (nonatomic, weak) id <HotRecNewSubTitleDelegate> delegate;

@end
