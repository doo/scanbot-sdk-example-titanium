//
//  SBSDKUIBarcodesBatchScannerBehaviorConfiguration.h
//  ScanbotSDK
//
//  Created by Yevgeniy Knizhnik on 12.03.20.
//  Copyright © 2020 doo GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SBSDKBarcodeImageGenerationType.h"
#import "SBSDKBarcodeAdditionalParameters.h"
#import "SBSDKBarcodeScanner.h"
#import "SBSDKZoomRange.h"

/**
 * Configuration for the behavior of  barcodes.
 */
@interface SBSDKUIBarcodesBatchScannerBehaviorConfiguration : NSObject

/** Whether flash is toggled on or off. */
@property (nonatomic, assign, getter=isFlashEnabled) BOOL flashEnabled;

/** Whether scanner screen should make a sound on successful barcode or MRZ detection. */
@property (nonatomic, assign, getter=isSuccessBeepEnabled) BOOL successBeepEnabled;

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
 * The range of valid camera zoom factors. Default value is (1.0; 3.0).
 */
@property (nonatomic, strong, nonnull) SBSDKZoomRange *cameraZoomRange;

/**
 * The relative zoom level of the camera relative to `zoomRange`.
 * The minimum value is 0.0 (zoomed out), the maximum value is 1.0 (zoomed in).
 * The default value is 0.0, zoomed out.
 *
 * You can use this value to zoom the camera programmatically but also to set an initial zoom factor.
 */
@property (nonatomic, assign) CGFloat cameraZoomFactor;

/**
 * When this property is set to YES, the zoom can be activated by double tapping
 * somewhere in the receivers view.
 * The default value is YES.
 */
@property(nonatomic, assign, getter=isDoubleTapToZoomEnabled) BOOL doubleTapToZoomEnabled;

/**
 * When this property is set to YES, the zoom can be activated by a pinch gesture
 * somewhere in the receivers view.
 * The default value is YES.
 */
@property(nonatomic, assign, getter=isPinchToZoomEnabled) BOOL pinchToZoomEnabled;

/**
 * Defines, if zooming in or out should be animated.
 * The default value is YES;
 */
@property (nonatomic, assign) BOOL shouldAnimateZooming;

@end

