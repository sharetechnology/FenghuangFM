//
//  ProgramViewModel.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/24.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ReactiveCocoa.h"
#import "ProgramModel.h"

@interface ProgramViewModel : NSObject

/**
 *  更新数据的信号
 **/
@property (nonatomic, strong) RACSignal *updateContentSignal;

@property (nonatomic, strong) ProgramModel *programModel;

@property (nonatomic, strong) PlayModel *playModel;

@property (nonatomic, strong) NSString *pid;

@property (nonatomic, strong) NSString *rid;

- (void)refreshDataSource;

- (NSInteger)numberOfSections;

- (NSInteger)numberOfItemsInSection:(NSInteger)section;

- (CGFloat)heightForRowAtIndex:(NSIndexPath *)indexPath;

@end
