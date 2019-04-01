//
//  LQViewController.m
//  LQPopup
//
//  Created by Little Queen on 04/01/2019.
//  Copyright (c) 2019 Little Queen. All rights reserved.
//

#import "LQViewController.h"

static const CGFloat kDefaultDismissAfterDuration = 2.0;

@interface LQViewController () <LQPopupContentViewDelegate>

@property(nonatomic, strong) LQPopupContentView *contentView;

@end

@implementation LQViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  
  LQPopupHorizontalLayout horizontalLayout = LQPopupHorizontalLayout_Center;
  LQPopupVerticalLayout verticalLayout = LQPopupVerticalLayout_Bottom;
  
  BOOL shouldDismissOnBackgroundTouch = YES;
  BOOL shouldDismissOnContentTouch = NO;
  BOOL shouldDismissOutAfterDuration = NO;

  LQPopupLayout layout = LQPopupLayoutMake(horizontalLayout, verticalLayout);

  _contentView = [[LQPopupContentView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 300)];
  _contentView.backgroundColor = [UIColor redColor];

  UIButton *btn = [[UIButton alloc] initWithFrame:CGRectMake(0, 100, 200, 200)];
  btn.backgroundColor = [UIColor redColor];
  [btn bk_whenTapped:^{
    LQPopup *popup = [LQPopup popupWithContentView:_contentView];
    popup.shouldDismissOnBackgroundTouch = shouldDismissOnBackgroundTouch;
    popup.shouldDismissOnContentTouch = shouldDismissOnContentTouch;
    popup.showType = LQPopupShowType_BounceInFromBottom;
    popup.dismissType = LQPopupDismissType_BounceOutToBottom;
    [popup showWithLayout:layout duration:shouldDismissOutAfterDuration ? kDefaultDismissAfterDuration : 0.0];
  }];
  
  [self.view addSubview:btn];
}

#pragma mark - LQPopupContentViewDelegate
- (void)didClickedCloseButton:(UIButton *)button {
  [LQPopup dismissSuperPopupIn:button animated:YES];
}

- (void)didReceiveMemoryWarning {
  [super didReceiveMemoryWarning];
}

#pragma mark - Properties
- (LQPopupContentView *)contentView {
  if (!_contentView) {
    _contentView = [[LQPopupContentView alloc] initWithFrame:CGRectMake(0, 0, [UIScreen mainScreen].bounds.size.width, 200)];
    _contentView.backgroundColor = [UIColor redColor];
    _contentView.delegate = self;
  }
  return _contentView;
}

@end
