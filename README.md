# FenghuangFM
仿凤凰FM iOS客户端

![image](https://github.com/BJTU-HT.github.io/images/fenghuangFM_01.gif)

仿凤凰FM iOS客户端是出于3个目的 1>理解网络请求 2>理解reactiveCocoa 3>理解MVVM

### 网络请求
凤凰FM的http请求返回数据为JSON格式，可以用Chalse轻松抓取到这些http请求，具体的请求信息在FenghuangFM/HTTPRequest下边。
http请求返回为JSON格式的数据，解析JSON用到了MJExtension库，JSON中有list时，使用如下方式告知JSON中key为"audiolist"的list中每个元素是”Audio“类型。

```
[ActivityModel mj_setupObjectClassInArray:^NSDictionary *{
    return @{
        @"audiolist":@"Audio"
    };
}];
```

另外返回的JSON中key可能会以"new"开头，而我们定义模型时成员变量使用new开头会报错，这时需要将JSON中的key转换成模型中的成员变量名，

```
[LeaderBoardData mj_setupReplacedKeyFromPropertyName:^NSDictionary *{
    return @{
        @"newsList":@"newList"
    };
}];
```

### reactiveCocoa

reactiveCocoa在这里的应用和网络请求结合在了一起，载入主页时，需要发出两个http请求，等待这两个请求都回返结果后再继续下一步，reactiveCocoa可以非常简单地完成这个动作，

MainFeatureViewModel.m
```
- (void)refreshDataSource
{
    @weakify(self);
    RACSignal *signalFocus = [RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
    @strongify(self);
    [self requestFocusList:^{
        [subscriber sendNext:nil];
    }];
        return nil;
    }];

    RACSignal *signalRest = [RACSignal createSignal:^RACDisposable *(id<RACSubscriber> subscriber) {
    @strongify(self);
    [self requestRest:^{
        [subscriber sendNext:nil];
    }];
    return nil;
    }];

    [[RACSignal combineLatest:@[signalFocus,signalRest]] subscribeNext:^(id x) {
    @strongify(self);
    [(RACSubject *)self.updateContentSignal sendNext:nil];
    }];
}
```

### MVVM
...
