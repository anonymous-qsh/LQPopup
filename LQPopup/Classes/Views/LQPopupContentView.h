//
//  LQPopupContentView.h
//  LQPopup
//
//  Created by LittleQ on 2019/4/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LQPopupContentViewDelegate <NSObject>

- (void)didClickedCloseButton:(UIButton *)button;

@end

@interface LQPopupContentView : UIView

@property(nonatomic, weak) id<LQPopupContentViewDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
