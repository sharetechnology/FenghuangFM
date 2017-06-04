//
//  MainFeatureHelper.m
//  FenghuangFM
//
//  Created by tom555cat on 2017/6/4.
//  Copyright © 2017年 Hello World Corporation. All rights reserved.
//

#import "MainFeatureHelper.h"
#import "FHNotification.h"

@interface MainFeatureHelper ()

@property (nonatomic, strong) NSTimer *headerTimer;

@end

@implementation MainFeatureHelper

+ (instancetype)helper {
    static MainFeatureHelper *helper = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        helper = [[MainFeatureHelper alloc] init];
    });
    
    return helper;
}
    
- (void)startHeadTimer {
    [self destoryHeaderTimer];
    _headerTimer = [NSTimer scheduledTimerWithTimeInterval:3.0f target:self selector:@selector(headerTimerChanged) userInfo:nil repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:_headerTimer forMode:NSRunLoopCommonModes];
}
    
- (void)destoryHeaderTimer {
    if (self.headerTimer) {
        [self.headerTimer setFireDate:[NSDate distantFuture]];
        [self.headerTimer invalidate];
        self.headerTimer = nil;
    }
}
    
- (void)headerTimerChanged {
    [[NSNotificationCenter defaultCenter] postNotificationName:kNotificationMainFeatureHeaderTimer object:nil];
}
    
@end
