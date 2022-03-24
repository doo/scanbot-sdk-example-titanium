//
//  SBSDKUIBarcodeImageStorage.h
//  ScanbotSDKBundle
//
//  Created by Yevgeniy Knizhnik on 05.02.20.
//  Copyright © 2020 doo GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A class to store and remove barcode images from `SBSDKUIBarcodeScannerViewController`.
 */
@interface SBSDKUIBarcodeImageStorage : NSObject

/**
 * Sets base folder for barcode images storing. A separate folder for barcode images will be created in this folder.
 * @param url URL which will be used as a base storage folder. In case of nil - default URL will be used.
 */
+ (void)setBaseStorageURL:(NSURL *_Nullable)url;

/**
 * Removes folder with barcode images. Does not affect base folder.
 */
+ (void)cleanUpStorage;

@end

NS_ASSUME_NONNULL_END
