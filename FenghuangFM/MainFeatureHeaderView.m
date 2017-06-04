//
//  MainFeatureHeaderView.m
//  FenghuangFM
//
//  Created by tom555cat on 2016/11/14.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import "MainFeatureHeaderView.h"
#import "UIImageView+YYWebImage.h"
#import "FHNotification.h"
#import "MainFeatureHelper.h"

@interface MainFeatureHeaderView () <UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView  *scrollView;
    
@property (nonatomic, assign) double headerWith;
    
@end

@implementation MainFeatureHeaderView

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self addSubview:self.scrollView];
        //[self addTimer];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(timerChanged) name:kNotificationMainFeatureHeaderTimer object:nil];
        
        _headerWith = screenWidthPCH - 20;
    }
    return self;
}
    
- (void)timerChanged {
    if (!_model) {
        return;
    }
    
    NSInteger curIndex = self.scrollView.contentOffset.x / (_headerWith);
    [self.scrollView setContentOffset:CGPointMake((curIndex + 1)* _headerWith, 0) animated:YES];
}

#pragma mark - Private

- (void)scrollToNext
{
    if (!_model) {
        return;
    }
    NSInteger curIndex = self.scrollView.contentOffset.x / _headerWith;
    [self.scrollView setContentOffset:CGPointMake((curIndex +1) * _headerWith, 0) animated:YES];
}

#pragma mark - ScrollViewDelegate
- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    NSInteger curPage = self.scrollView.contentOffset.x / _headerWith;
    if(curPage == self.model.data.count) {
        [self.scrollView setContentOffset:CGPointMake(0, 0) animated:NO];
    }
}

- (void)scrollViewWillBeginDragging:(UIScrollView *)scrollView
{
    [[MainFeatureHelper helper] destoryHeaderTimer];
}

- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate
{
    [[MainFeatureHelper helper] startHeadTimer];
}

#pragma mark - Getter & Setter
- (UIScrollView *)scrollView
{
    if (!_scrollView) {
        _scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(10, 10, self.frame.size.width - 20, self.frame.size.height - 20)];
        _scrollView.delegate = self;
        _scrollView.showsVerticalScrollIndicator = YES;
        _scrollView.showsVerticalScrollIndicator = YES;
        _scrollView.scrollEnabled = YES;
        _scrollView.bounces = YES;
        _scrollView.pagingEnabled = YES;
        _scrollView.bouncesZoom = YES;
        _scrollView.delaysContentTouches = YES;
        _scrollView.canCancelContentTouches = YES;
    }
    return _scrollView;
}

- (void)setModel:(MainFeatureModel *)model
{
    _model = model;
    
    for (UIView *view in self.scrollView.subviews) {
        [view removeFromSuperview];
    }
    
    _scrollView.contentSize = CGSizeMake(_headerWith * _model.data.count, 150);
    for (NSInteger index = 0; index <= _model.data.count; index++) {
        
        ActivityModel *activityModel = index == _model.data.count ? _model.data.firstObject : [_model.data objectAtIndex:index];
        
        UIImageView *imageView = [[UIImageView alloc] init];
        imageView.frame = CGRectMake(_headerWith * index, 0, _headerWith, self.frame.size.height);
        [imageView yy_setImageWithURL:[NSURL URLWithString:activityModel.img640_292] options:YYWebImageOptionSetImageWithFadeAnimation];
        
        [_scrollView addSubview:imageView];
    }
}

@end
