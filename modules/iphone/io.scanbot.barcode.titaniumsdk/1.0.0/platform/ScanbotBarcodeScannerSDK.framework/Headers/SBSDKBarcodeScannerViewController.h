//
//  SBSDKBarcodeScannerViewController.h
//  ScanbotSDK
//
//  Created by Yevgeniy Knizhnik on 29.11.19.
//  Copyright © 2019 doo GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SBSDKBarcodeScanner.h"
#import "SBSDKBarcodeScannerResult.h"
#import "SBSDKBarcodeImageGenerationType.h"
#import "SBSDKAspectRatio.h"
#import "SBSDKCameraSession.h"
#import "SBSDKBaseCameraViewController.h"
#import "SBSDKBarcodeAdditionalParameters.h"
#import "SBSDKZoomRange.h"

@class SBSDKBarcodeScannerViewController;
/**
* A delegate protocol to customize the behavior, look and feel of the SBSDKBarcodeScannerViewControllerDelegate.
*/
@protocol SBSDKBarcodeScannerViewControllerDelegate <NSObject>
@optional
/**
 * Asks the delegate if the receiver should detect barcodes.
 * Optional.
 * @param controller The calling SBSDKBarcodeScannerViewController.
 */
- (BOOL)barcodeScannerControllerShouldDetectBarcodes:(nonnull SBSDKBarcodeScannerViewController *)controller;

/**
 * Informs the delegate that the receiver has detected some barcodes.
 * Optional.
 * @param controller The calling SBSDKBarcodeScannerViewController.
 * @param codes Array of SBSDKBarcodeScannerResult containing the detected barcodes.
 */
- (void)barcodeScannerController:(nonnull SBSDKBarcodeScannerViewController *)controller
didDetectBarcodes:(nonnull NSArray<SBSDKBarcodeScannerResult *> *)codes;


/**
 * Returns captured barcode image. Will fire only if `barcodeImageGenerationType` parameter is not `SBSDKBarcodeImageGenerationTypeNone`.
 * Optional.
 * @param controller The calling SBSDKBarcodeScannerViewController.
 * @param barcodeImage A captured device-orientation-corrected barcode image.
 */
- (void)barcodeScannerController:(nonnull SBSDKBarcodeScannerViewController *)controller
didCaptureBarcodeImage:(nonnull UIImage *)barcodeImage;

/**
 * Informs the delegate that the receiver did change the rect of the view finder.
 * @param controller The calling SBSDKBarcodeScannerViewController.
 * @param rect The new rectangle of the view finder in the controllers view space.
 * Equals to CGRectZero when the view finder is not visible.
 */
- (void)barcodeScannerController:(nonnull SBSDKBarcodeScannerViewController *)controller didChangeViewFinderRect:(CGRect)rect;

@end

NS_ASSUME_NONNULL_BEGIN


/**
* A UIViewController subclass to show a camera screen with the barcode detector.
* This class cannot be instanced from a storyboard.
* Instead it is installing itself as a child view controller onto a given parent view controller.
*/
@interface SBSDKBarcodeScannerViewController : SBSDKBaseCameraViewController
/**
 * The delegate. See SBSDKBarcodeScannerViewControllerDelegate protocol. Weak.
 */
@property (nonatomic, weak, nullable) id<SBSDKBarcodeScannerViewControllerDelegate> delegate;

/**
Specifies the way of barcode images generation or disables this generation at all.
Use, if you want to receive a full sized image with barcodes.
Defaults to SBSDKBarcodeImageGenerationTypeNone.
*/
@property (nonatomic, assign) SBSDKBarcodeImageGenerationType barcodeImageGenerationType;

/**
 * Machine code types (EAN, DataMatrix, Aztec, QR, etc) that can be returned in `didDetectBarcodes`
 * delegate method. When nil or empty - all codes can be returned.
 * Default is nil.
 */
@property (nonatomic, strong, nullable) NSArray<SBSDKBarcodeType *> *acceptedBarcodeTypes;

/**
 * Additional parameters for tweaking the detection of barcodes.
 */
@property (nonatomic, strong, nonnull) SBSDKBarcodeAdditionalParameters *additionalDetectionParameters;

/**
 * The barcode detectors engine mode.
 * The default value is SBSDKBarcodeEngineModeNextGen.
 */
@property (nonatomic, assign) SBSDKBarcodeEngineMode engineMode;

/**
 * Bar code document types to limit detection results to. When nil or empty - all document can be returned.
 * Default is nil.
 */
@property (nonatomic, strong, nullable) NSArray<SBSDKBarcodeDocumentType *> *acceptedDocumentTypes;

/**
 * Specifies the amount of frames barcode scanner takes before detecting. Uses the sharpest frame.
 * So setting more frames generally improves recognition quality, but reduces recognition speed.
 * Keep in mind, that `detectionRate` also has influence on recognition speed, as it determines
 * the amount of frames that can be read  per second.
 * Default to 5.
*/
@property (nonatomic, assign) NSInteger barcodeAccumulatedFramesCount;

/**
 * A transparent view that lies over the preview layer. You can add custom UI here. Read-only.
 */
@property (nonatomic, strong, readonly, nonnull) UIView *HUDView;

/** The range of valid camera zoom factors. Default value is (1.0; 3.0). */
@property (nonatomic, strong) SBSDKZoomRange *cameraZoomRange;

/**
 * The zoom level of the camera relative to `zoomRange`.
 * The minimum value is 0.0 and corresponds to the cameraZoomRange.minZoom value (zoomed out).
 * The maximum value is 1.0 and corresponds to the cameraZoomRange.maxZoom value (zoomed in).
 * The default value is 0.0.
 *
 * You can use this value to zoom the camera programmatically but also to set an initial zoom factor.
 */
@property (nonatomic, assign) CGFloat cameraZoomFactor;

/**
 * When this property is set to YES, the default, the zoom can be activated by double tapping
 * somewhere on the receivers view.
 */
@property(nonatomic, assign, getter=isDoubleTapToZoomEnabled) BOOL doubleTapToZoomEnabled;

/**
 * When this property is set to YES, the default, the zoom can be activated by executing a pinch gesture
 * somewhere on the receivers view.
 */
@property(nonatomic, assign, getter=isPinchToZoomEnabled) BOOL pinchToZoomEnabled;

/**
 * Defines, if a zooming in\out should be animated. Default is YES;
 */
@property (nonatomic) BOOL shouldAnimateZooming;

/**
 * Defines if barcodeScanner should use limiting frame for detection. Alternatively all camera frame will be used. Default is NO.
 */
@property (nonatomic, assign) BOOL shouldUseFinderFrame;

/**
 * Defines the region of interest when scanning barcodes or other machine readable codes.
 * Machine readable codes found outside this region of interest are discarded and ignored during detection.
 * The property describes the aspect ratio (width / height) of the region of
 * interest. This aspect ratio, in conjunction with the screen size and `finderMinimumInset` parameter, is used to create an absolute region of
 * interest and render a view finder like rounded rectangle on screen.
 * The 0 aspect ratio effectively disables the region of interest.
 *
 * Note: Only effective if `shouldUseFinderFrame` is set to `YES`.
 */
@property (nonatomic, strong) SBSDKAspectRatio *finderAspectRatio;

/**
 * Defines a minimum inset for capturing frame. Default is 32 for all parameters.
 *
 * Note: Only effective if `shouldUseFinderFrame` is set to `YES`.
*/
@property (nonatomic, assign) UIEdgeInsets finderMinimumInset;

/**
 * Background color of camera preview. Default is black. Can be nil.
 */
@property (nonatomic, strong, nullable) UIColor *previewBackgroundColor;

/**
 * Background color of the view finder. Default is white with 0.66 alpha. Must not be nil.
 */
@property (nonatomic, strong, nonnull) UIColor *viewFinderBackgroundColor;

/**
 * Line color of the view finder. Default is nil, which draws no border line for the view finder.
 */
@property (nonatomic, strong, nullable) UIColor *viewFinderLineColor;

/**
 * Line width of the view finder. Default is 2.
 */
@property (nonatomic, assign) CGFloat viewFinderLineWidth;

/**
 * The current rectangle of the view finder if displayed, CGRectZero otherwise.
 */
@property(nonatomic, readonly) CGRect currentViewFinderRect;

/**
 * Set to YES to toggle on the video light. Defaults to NO.
 */
@property (nonatomic, assign) BOOL flashLightEnabled;

/**
 * An IB action to toggle the zoom. Connect to a UIButton instance if needed.
 * @param sender The object that sent the event. Can be nil.
 */
- (IBAction)toggleZoom:(nullable id)sender;

/**
 * An IB action to engage the zoom. Connect to a UIButton instance if needed.
 * @param sender The object that sent the event. Can be nil.
*/
- (IBAction)zoomIn:(nullable id)sender;

/**
 * An IB action to disengage the zoom. Connect to a UIButton instance if needed.
 * @param sender The object that sent the event. Can be nil.
*/
- (IBAction)zoomOut:(nullable id)sender;


/** Not available. */
- (nonnull instancetype)init NS_UNAVAILABLE;

/** Not available. */
+ (nonnull instancetype)new NS_UNAVAILABLE;

/**
* Designated initializer. Installs the receiver as child view controller onto the parent view controllers
* view using its entire bounds area.
* @param parentViewController The view controller the newly created instance is embedded into.
* If parentViewController conforms to SBSDKBarcodeScannerViewControllerDelegate, it is automatically set as delegate.
*/
- (nullable instancetype)initWithParentViewController:(nonnull UIViewController *)parentViewController
                                           parentView:(nullable UIView *)containerView;

@end

NS_ASSUME_NONNULL_END
