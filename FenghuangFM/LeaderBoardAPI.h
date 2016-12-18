//
//  LeaderBoardAPI.h
//  FenghuangFM
//
//  Created by tom555cat on 2016/12/8.
//  Copyright © 2016年 Hello World Corporation. All rights reserved.
//

#import "BaseAPI.h"

@interface LeaderBoardAPI : BaseAPI

+ (void)requestLeaderBoard:(BaseAPICompletion)completion;

@end
