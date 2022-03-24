//
//  SBSDKCameraSession.h
//  ScanbotSDK
//
//  Created by Sebastian Husche on 22.04.15.
//  Copyright (c) 2015 doo GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "SBSDKFeatures.h"
#import "SBSDKCameraExposureSettings.h"
#import "SBSDKCapturePhotoQualityPrioritization.h"

/**
 * A delegate protocol that gathers AVCaptureVideoDataOutputSampleBufferDelegate
 * and AVCaptureMetadataOutputObjectsDelegate protocols.
 */
@protocol SBSDKCameraSessionDelegate <AVCaptureVideoDataOutputSampleBufferDelegate,
AVCaptureMetadataOutputObjectsDelegate>
@end

/**
 * An easy-to-use wrapper around the AVFoundations video capture session. Sets up and configures the
 * camera device and the preview layer. Provides functionality to capture still images.
 */
@interface SBSDKCameraSession : NSObject

/**
 * The preview layer that the camera device uses to output the current video frames.
 * Can be added to any superlayer.
 */
@property (nonatomic, readonly, nonnull) AVCaptureVideoPreviewLayer *previewLayer;

/**
 * Returns the video resolution of the current video output. Orientation is taken into account.
 * Returns CGSizeZero, if the capture session is not running.
 */
@property (nonatomic, readonly) CGSize videoResolution;

/**
 * Sets or gets the current video orientation.
 */
@property (nonatomic, assign) AVCaptureVideoOrientation videoOrientation;

/**
 * The delegate object for camera output.
 * Its receives the video frames, still image captures and meta data capture, like QR code.
 * Delegates can implement all functions from AVCaptureVideoDataOutputSampleBufferDelegate and
 * AVCaptureMetadataOutputObjectsDelegate protocols.
 */
@property (nonatomic, weak, nullable) id<SBSDKCameraSessionDelegate> videoDelegate;

/**
 * Returns YES if the camera is currently in the process of taking a still image, NO otherwise.
 */
@property (nonatomic, readonly) BOOL isCapturingStillImage;

/**
 * Returns YES if the camera device has a torch light and the torch light is available.
 */
@property (nonatomic, readonly) BOOL torchLightAvailable;

/**
 * Turns the torch light on or off.
 */
@property (nonatomic, assign, getter = isTorchLightEnabled) BOOL torchLightEnabled;

/**
 * A block being executed when the torch light status changes (mode or availability).
 */
@property (nonatomic, copy, nullable) void (^updateTorchlightBlock)(void);

/**
 * The AVCaptureSession object.
 */
@property (nonatomic, readonly, nullable) AVCaptureSession* captureSession;

/**
 * Returns the current cameras exposure settings.
 */
@property (nonatomic, readonly, nullable) SBSDKCameraExposureSettings* exposureSettings;

/**
 * The camera devices minimum zoom factor. Readonly.
 */
@property (nonatomic, readonly) CGFloat minZoom;

/**
* The camera devices maximum zoom factor. Readonly.
*/
@property (nonatomic, readonly) CGFloat maxZoom;

/**
 * Sets or gets the camera devices current zoom factor. Zooming is done without animation.
 * If the new value exceeds the minimum or maximum value for zooming it is clamped.
 */
@property (nonatomic, assign) CGFloat zoomValue;

/**
 * YES, if the camera currently is zooming, NO otherwise.
 */
@property (nonatomic, readonly) BOOL isZooming;

/**
 * YES, if zooming is available. No otherwise.
 */
@property (nonatomic, readonly) BOOL isZoomAvailable;

/**
 * The priorization of still image quality and capturing speed.
 * Defaults to SBSDKCapturePhotoQualityPrioritizationBalanced.
 *
 * Note: Has no effect on devices prior to iOS 13.0!
 */
@property (nonatomic, assign) SBSDKCapturePhotoQualityPrioritization photoQualityPriorization;

/**
 * The designated initializer of the class. Does not start the capture session.
 * @param feature The feature you want to use the camera for. Relevant features are Document Detection,
 * Payform Detection and QR Codes.
 * @return Newly created and configured instance.
 */
- (nonnull instancetype)initForFeature:(dooFeature)feature;

/**
 * Extended initializer of the class. Does not start the capture session.
 * @param feature The feature you want to use the camera for.
 * @param preset The camera session preset the receiver wants to use.
 * @return Newly created and configured instance or nil, if preset is not supported or setup failed.
 */
- (nullable instancetype)initForFeature:(dooFeature)feature withPreset:(AVCaptureSessionPreset _Nonnull)preset;

/**
 * Starts the camera capture session. Does nothing if the session is already running.
 */
- (void)startSession;

/**
 * Stops the camera capture session. Does nothing if the session is already stopped.
 */
- (void)stopSession;

/**
 * Returns YES if the camera session has already been started, NO otherwise.
 */
- (BOOL)isSessionRunning;

/** 
 * Pauses the detection of documents and QR codes.
 */
- (void)pauseDetection;

/**
 * Resumes the detection of documents and QR codes.
 */
- (void)resumeDetection;

/**
 * Returns YES, if detection is paused, NO otherwise.
 */
- (BOOL)isDetectionPaused;

/**
 * Captures a still image asynchronously and passes the CMSampleBufferRef and if needed an error to the
 * completion handler. The CMSampleBufferRef can be converted to any image format/object like UIImage.
 * @param completion The completion handler that is called when the still image has been captured.
 */
- (void)captureStillImageWithCompletionHandler:(nullable void (^)(CVPixelBufferRef _Nullable,  NSError* _Nullable))completion;

/**
 * Captures a still image asynchronously and passes the JPEG image data as NSData and if needed an error to the
 * completion handler.
 * @param completion The completion handler that is called when the still image has been captured.
 */
- (void)captureJPEGStillImageWithCompletionHandler:(nullable void (^)(NSData* _Nullable, NSError* _Nullable))completion;

/**
 * Returns YES, if the camera is currently adjusting autofocus, exposure or white balance, NO otherwise.
 */
- (BOOL)isCameraAdjusting;

/**
 * Sets the camera devices current zoom factor.
 * If the new value exceeds the minimum or maximum value for zooming it is clamped.
 * @param zoomValue The new zoom factor to be set.
 * @param animated If YES, the zooming is animated, otherwise the change is applied without an animation.
 */
- (void)setZoomValue:(CGFloat)zoomValue animated:(BOOL) animated;

/**
 * Resets the zoom factor to the minimum zoom value.
 * @param animated If YES, the zooming is animated, otherwise the change is applied without an animation.
 */
- (void)resetZoomAnimated:(BOOL)animated;

@end
