//
//  LeaderBoardViewModel.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/12/8.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReactiveCocoa.h"
#import "LeaderBoardModel.h"

@interface LeaderBoardViewModel : NSObject

@property (nonatomic, readonly) RACSignal *updateContentSignal;

@property (nonatomic, strong) LeaderBoardModel *model;

- (NSInteger)numberOfSections;
- (NSInteger)numberOfItemsInSection:(NSInteger)section;
- (CGFloat)heightForRowAtIndex:(NSIndexPath *)indexPath;

@end
