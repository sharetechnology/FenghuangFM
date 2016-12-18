//
//  MainFeatureViewModel.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/14.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReactiveCocoa.h"
#import "MainFeatureModel.h"

@interface MainFeatureViewModel : NSObject

/**
 *  更新数据的信号
 **/
@property (nonatomic, readonly) RACSignal                   *updateContentSignal;

@property (nonatomic, strong)   MainFeatureModel            *featureModel;

@property (nonatomic, strong)   RecommendModel              *recommendModel;

- (void)refreshDataSource;

- (NSInteger)numberOfSections;
- (NSInteger)numberOfItemsInSection:(NSInteger)section;
- (CGFloat)heightForRowAtIndex:(NSIndexPath *)indexPath;

@end
