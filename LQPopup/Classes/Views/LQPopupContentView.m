//
//  LQPopupContentView.m
//  LQPopup
//
//  Created by LittleQ on 2019/4/1.
//

#import "LQPopupContentView.h"

@interface LQPopupContentView ()

@property(nonatomic, strong) UIView *contentView;
@property(nonatomic, strong) UILabel *titleLabel;

@property(nonatomic, strong) UIButton *closeButton;

@end

@implementation LQPopupContentView

- (instancetype)initWithFrame:(CGRect)frame {
  self = [super initWithFrame:frame];

  if (self) {
    [self setupViews];
  }

  return self;
}

- (void)closeButtonClicked:(UIButton *)button {
  if (self.delegate && [self.delegate respondsToSelector:@selector(didClickedCloseButton:)]) {
    [self.delegate didClickedCloseButton:button];
  }
}

#pragma mark - Private Methods
- (void)setupViews {
  [self addSubview:self.contentView];
  [self.contentView addSubview:self.titleLabel];
  [self.contentView addSubview:self.closeButton];
  /// Make Constraints
  //  [_contentView mas_makeConstraints:^(MASConstraintMaker *make) {
  //    make.edges.equalTo(self);
  //  }];
  //  [_titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
  //    make.top.equalTo(self.contentView.mas_top).offset(18.0);
  //    make.centerX.equalTo(self.contentView.mas_centerX);
  //  }];
  //  [_closeButton mas_makeConstraints:^(MASConstraintMaker *make) {
  //    make.bottom.equalTo(self.contentView.mas_bottom).offset(-18.0);
  //    make.left.equalTo(self.contentView.mas_left).offset(20.0);
  //    make.right.equalTo(self.contentView.mas_right).offset(-20.0);
  //    make.height.mas_equalTo(44.0);
  //  }];
}

#pragma mark - Properties
- (UIView *)contentView {
  if (!_contentView) {
    _contentView = [UIView new];
    _contentView.backgroundColor =
        [UIColor colorWithRed:251.0 / 255.0 green:251.0 / 255.0 blue:251.0 / 255.0 alpha:1.0];
    _contentView.layer.cornerRadius = 6.0;
    _contentView.layer.masksToBounds = YES;
  }
  return _contentView;
}

- (UILabel *)titleLabel {
  if (!_titleLabel) {
    _titleLabel = [UILabel new];
    _titleLabel.font = [UIFont boldSystemFontOfSize:18.0];
    _titleLabel.textAlignment = NSTextAlignmentCenter;
    _titleLabel.numberOfLines = 0;
    _titleLabel.textColor = [UIColor colorWithRed:84.0 / 255.0 green:92.0 / 255.0 blue:119.0 / 255.0 alpha:1.0];
  }
  return _titleLabel;
}

- (UIButton *)closeButton {
  if (!_closeButton) {
    _closeButton = [UIButton new];
    _closeButton.backgroundColor = [UIColor colorWithRed:0.0 / 255.0 green:111.0 / 255.0 blue:255.0 / 255.0 alpha:1.0];
    _closeButton.titleLabel.textColor = UIColor.whiteColor;
    _closeButton.titleLabel.font = [UIFont boldSystemFontOfSize:16.0];
    [_closeButton setTitle:@"Dismiss Popup" forState:UIControlStateNormal];
    [_closeButton addTarget:self action:@selector(closeButtonClicked:) forControlEvents:UIControlEventTouchUpInside];
    _closeButton.layer.cornerRadius = 22;
    _closeButton.layer.masksToBounds = YES;
  }
  return _closeButton;
}

@end
