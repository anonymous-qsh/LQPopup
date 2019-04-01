//
//  LQPopup.h
//  LQPopup
//
//  Created by LittleQ on 2019/4/1.
//

#import <UIKit/UIKit.h>

/**
 LQPopupShowType
 Controlled how the popup will be presented.
 */
typedef NS_ENUM(NSUInteger, LQPopupShowType) {
  LQPopupShowType_None,
  LQPopupShowType_FadeIn,
  LQPopupShowType_GrowIn,
  LQPopupShowType_ShrinkIn,
  LQPopupShowType_SlideInFromTop,
  LQPopupShowType_SlideInFromBottom,
  LQPopupShowType_SlideInFromLeft,
  LQPopupShowType_SlideInFromRight,
  LQPopupShowType_BounceIn,
  LQPopupShowType_BounceInFromTop,
  LQPopupShowType_BounceInFromBottom,
  LQPopupShowType_BounceInFromLeft,
  LQPopupShowType_BounceInFromRight
};

/**
 LQPopupDismissType
 Controlled how the popup will be dismissed.
 */
typedef NS_ENUM(NSUInteger, LQPopupDismissType) {
  LQPopupDismissType_None,
  LQPopupDismissType_FadeOut,
  LQPopupDismissType_GrowOut,
  LQPopupDismissType_ShrinkOut,
  LQPopupDismissType_SlideOutToTop,
  LQPopupDismissType_SlideOutToBottom,
  LQPopupDismissType_SlideOutToLeft,
  LQPopupDismissType_SlideOutToRight,
  LQPopupDismissType_BounceOut,
  LQPopupDismissType_BounceOutToTop,
  LQPopupDismissType_BounceOutToBottom,
  LQPopupDismissType_BounceOutToLeft,
  LQPopupDismissType_BounceOutToRight
};

/**
 LQPopupHorizontalLayout
 Controlled the layout of the popup in the horizontal direction.
 */
typedef NS_ENUM(NSUInteger, LQPopupHorizontalLayout) {
  LQPopupHorizontalLayout_Custom,
  LQPopupHorizontalLayout_Left,
  LQPopupHorizontalLayout_LeftOfCenter,
  LQPopupHorizontalLayout_Center,
  LQPopupHorizontalLayout_RightOfCenter,
  LQPopupHoricontalLayout_Right
};

/**
 LQPopupVerticalLayout
 Controlled the layout of the popup in the vertical direction.
 */
typedef NS_ENUM(NSUInteger, LQPopupVerticalLayout) {
  LQPopupVerticalLayout_Custom,
  LQPopupVerticalLayout_Top,
  LQPopupVerticalLayout_AboveCenter,
  LQPopupVerticalLayout_Center,
  LQPopupVerticalLayout_BelowCenter,
  LQPopupVerticalLayout_Bottom
};

/**
 LQPopupMaskType
 Controlled whether to allow interaction with the underlying view.
 */
typedef NS_ENUM(NSUInteger, LQPopupMaskType) {
  /// Allow interaction with underlying view.
  LQPopupMaskType_None,
  /// Don't allow interaction with underlying view.
  LQPopupMaskType_Clear,
  /// Don't allow interaction with underlying view, dim background.
  LQPopupMaskType_Dimmed
};

/** LQPopupLayout */
struct LQPopupLayout {
  LQPopupHorizontalLayout horizontal;
  LQPopupVerticalLayout vertical;
};

typedef struct LQPopupLayout LQPopupLayout;

extern LQPopupLayout LQPopupLayoutMake(LQPopupHorizontalLayout horizontal, LQPopupVerticalLayout vertical);

extern const LQPopupLayout LQPopupLayout_Center;

NS_ASSUME_NONNULL_BEGIN

@interface LQPopup : UIView

/**
 The view you want to appear in popup.
 
 Must provide contentView before or in `-willStartShowing`.
 Must set size of contentView before or in `-willStartShowing`.
 */
@property (nonatomic, strong) UIView *contentView;

/**
 Animation transition for presenting contentView.
 
 @discussion The default value is `LQPopupShowType_BounceInFromTop`.
 */
@property (nonatomic, assign) LQPopupShowType showType;

/**
 Animation transition for dismissing contentView.
 
 @discussion The default value is `LQPopupDismissType_BounceOutToBottom`.
 */
@property (nonatomic, assign) LQPopupDismissType dismissType;

/**
 Mask prevents background touches from passing to underlying views.
 
 @discussion The default value is `LQPopupMaskType_Dimmed`.
 */
@property (nonatomic, assign) LQPopupMaskType maskType;

/**
 Overrides alpha value for dimmed mask.
 
 @discussion The default value is `0.5`.
 */
@property (nonatomic, assign) CGFloat dimmedMaskAlpha;

/**
 Overrides animation duration for show in.
 
 @discussion The default value is `0.15`.
 */
@property (nonatomic, assign) CGFloat showInDuration;

/**
 Overrides animation duration for dismiss out.
 
 @discussion The default value is `0.15`.
 */
@property (nonatomic, assign) CGFloat dismissOutDuration;

/**
 If `YES`, the popup will dismiss when background is touched.
 
 @discussion The default value is `YES`.
 */
@property (nonatomic, assign) BOOL shouldDismissOnBackgroundTouch;

/**
 If `YES`, the popup will dismiss when content view is touched.
 
 @discussion The default value is `NO`.
 */
@property (nonatomic, assign) BOOL shouldDismissOnContentTouch;

/**
 A block to be executed when showing animation started.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^willStartShowingBlock)(void);

/**
 A block to be executed when showing animation finished.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^didFinishShowingBlock)(void);

/**
 A block to be executed when dismissing animation started.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^willStartDismissingBlock)(void);

/**
 A block to be executed when dismissing animation finished.
 The default value is nil.
 */
@property (nonatomic, copy, nullable) void(^didFinishDismissingBlock)(void);

/**
 Convenience Initializers
 Create a new popup with `contentView`.
 */
+ (LQPopup *)popupWithContentView:(UIView *)contentView;

/**
 Convenience Initializers
 Create a new popup with custom values.
 
 @param contentView The view you want to appear in popup.
 @param showType    The default value is `LQPopupShowType_BounceInFromTop`.
 @param dismissType The default value is `LQPopupDismissType_BounceOutToBottom`.
 @param maskType    The default value is `LQPopupMaskType_Dimmed`.
 @param shouldDismissOnBackgroundTouch  The default value is `YES`.
 @param shouldDismissOnContentTouch     The default value is `NO`.
 */
+ (LQPopup *)popupWithContentView:(UIView *)contentView
                         showType:(LQPopupShowType)showType
                      dismissType:(LQPopupDismissType)dismissType
                         maskType:(LQPopupMaskType)maskType
         dismissOnBackgroundTouch:(BOOL)shouldDismissOnBackgroundTouch
            dismissOnContentTouch:(BOOL)shouldDismissOnContentTouch;

/**
 Dismiss all the popups in the app.
 */
+ (void)dismissAllPopups;

/**
 Dismiss the popup for contentView.
 */
+ (void)dismissPopupForView:(UIView *)view animated:(BOOL)animated;

/**
 Dismiss super popup.
 Iterate over superviews until you find a `LQPopup` and dismiss it.
 */
+ (void)dismissSuperPopupIn:(UIView *)view animated:(BOOL)animated;

/**
 Show popup with center layout.
 `LQPopupVerticalLayout_Center` & `LQPopupHorizontalLayout_Center`
 Showing animation is determined by `showType`.
 */
- (void)show;

/**
 Show popup with specified layout.
 Showing animation is determined by `showType`.
 */
- (void)showWithLayout:(LQPopupLayout)layout;

/**
 Show and then dismiss popup after `duration`.
 If duration is `0.0` or `less`, it will be considered infinity.
 */
- (void)showWithDuration:(NSTimeInterval)duration;

/**
 Show popup with specified `layout` and then dismissed after `duration`.
 If duration is `0.0` or `less`, it will be considered infinity.
 */
- (void)showWithLayout:(LQPopupLayout)layout duration:(NSTimeInterval)duration;

/**
 Show popup at point in view's coordinate system.
 If view is nil, will use screen base coordinates.
 */
- (void)showAtCenterPoint:(CGPoint)point inView:(UIView *)view;

/**
 Show popup at point in view's coordinate system and then dismissed after duration.
 If view is nil, will use screen base coordinates.
 If duration is `0.0` or `less`, it will be considered infinity.
 */
- (void)showAtCenterPoint:(CGPoint)point inView:(UIView *)view duration:(NSTimeInterval)duration;

/**
 Dismiss popup.
 Use `dismissType` if animated is `YES`.
 */
- (void)dismissAnimated:(BOOL)animated;

#pragma mark - ReadOnly Properties
@property (nonatomic, strong, readonly) UIView *backgroundView;
@property (nonatomic, strong, readonly) UIView *containerView;
@property (nonatomic, assign, readonly) BOOL isBeingShown;
@property (nonatomic, assign, readonly) BOOL isShowing;
@property (nonatomic, assign, readonly) BOOL isBeingDismissed;

@end

NS_ASSUME_NONNULL_END
