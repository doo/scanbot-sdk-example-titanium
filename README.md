# Scanbot SDK Titanium Example (POC)

This very basic project demonstrates how it is possible to integrate Scanbot SDK into a pure Titanium project.

## Requirements

In order to run this project you will need to install Titanium CLI. You can install the latest version by running:

```bash 
npm install -g titanium
```

Now you can install Titanium SDK; you can choose a specific version or just install the latest one:

```bash 

# Install the latest Titanium SDK version
titanium sdk install

# ...or install a specific version
titanium sdk install 10.1.1.GA

```

Titanium SDK also requires a compatible JDK; take note of which version you have installed and check this compatibility table:

| Titanium SDK Version | Min JDK Version | Max JDK version |
|----------------------|-----------------|-----------------|
| 10.1.0 - latest      |              11 |              16 |
| 9.0.2 - 10.0.2       |               8 |              15 |
| 9.0.1                |               8 |              13 |
| 9.0.0                |               8 |              12 |
| 7.5.0 - 8.3.1        |               8 |              14 |
| 7.0.0 - 7.4.2        |               8 |              10 |


Be sure to install a compatible JDK, and to set your JAVA_HOME in `run-android.sh` accordingly.


**Minor note**: if you have a bad experience in downloading, installing and dealing with multiple JDK versions installed on the same machine, we recommend using [sdkman](https://sdkman.io/install), which has a very intuitive command line syntax to list available JDK versions and switch between them.


## Run the demo on an Android Device

To build and run the demo on an Android device, we provided a simple script:

```bash
./run-android.sh
```

Before running it, connect your Android device via USB with debug mode enabled in the developer options.

## Run the demo on an Android Device

To build and run the demo on an iOS device, you can execute:

```bash
./run-ios.sh
```

Before running it, connect your iOS device via USB, and make sure you have authorized your PC for debugging.

## How does it work?
To setup Scanbot SDK you just have to import the module and initialize the SDK, like this:

```javascript
import ScanbotBarcodeSDK from 'io.scanbot.barcode.titaniumsdk';
ScanbotBarcodeSDK.initializeSdk({
    licenseKey: YOUR_LICENSE_KEY // An empty string will trigger the 60 seconds trial mode
});
```

## Using the Barcode Scanner
After you have created your window, through `Ti.UI.createWindow`, you can initialize a proxy, like this:

```javascript
const scanbotRtu = ScanbotBarcodeSDK.createScanbotBarcodeUi({
    lifecycleContainer: YOUR_WINDOW
})
```
And open our Barcode Scanner:
```javascript
let configuration = {}
scanbotRtu.startBarcodeScanner(configuration, (result) => {
  // Parse the result
})
```

The result has the following structure:

- **status** -> OK or CANCELED
- **barcodes** -> The list of detected barcodes
  - **text:** -> The detected barcode text
  - **type:** -> The detected barcode type

## Configuring and Customizing the Barcode Scanner

You can use the configuration object to modify the component UI, Text and Behavior.

Here is a TS definition of the properties, which you can use as a reference:

```typescript
interface BarcodeScannerConfiguration 
{
  /**
  * An optional array of barcode document formats that acts as a detection filter.
  * By default all supported document formats will be detected.
  * Options:
  * - AAMVA
  * - BOARDING_PASS
  * - DE_MEDICAL_PLAN
  * - DISABILITY_CERTIFICATE
  * - ID_CARD_PDF_417
  * - SEPA
  * - SWISS_QR
  * - VCARD
  */
  acceptedDocumentFormats: string; // eg. ['SWISS_QR', 'SEPA']

  /**
  * Accepted barcode formats.
  * By default, all barcode formats are scanned
  * You can use this property to limit the barcode detection to
  * a list of types of your choice.
  * Options:
  * - AZTEC
  * - CODABAR
  * - CODE_39
  * - CODE_93
  * - CODE_128
  * - DATA_MATRIX
  * - EAN_8
  * - EAN_13
  * - ITF
  * - PDF_417
  * - QR_CODE
  * - RSS_14
  * - RSS_EXPANDED
  * - UPC_A
  * - UPC_E
  * - MSI_PLESSEY
  */
  barcodeFormats: string[]; // eg. ['MSI_PLESSEY', 'EAN-13']

  /**
  * The checksum algorithm for MSI Plessey barcodes.
  * The default value is Mod10.
  * Options:
  * - None
  * - Mod10
  * - Mod11IBM
  * - Mod11NCR
  * - Mod1010
  * - Mod1110IBM
  * - Mod1110NCR
  */
  msiPlesseyChecksumAlgorithm: string; // eg. "Mod1010"

  /**
  * Background color of the detection overlay.
  */
  cameraOverlayColor: string; // eg. "#ff0000"

  /**
  * String being displayed on the cancel button.
  */
  cancelButtonTitle: string; // eg. "Exit"

  /**
  * The finder view aspect ratio
  */
  finderAspectRatio: { width: number; height: number }; // eg. { width: 1, height: 1 }
  /**
  * Foreground color of the detection overlay.
  */
  finderLineColor: string; // eg. "#ff0000"

  /**
  * Width of the finder frame border. Default is 2.
  */
  finderLineWidth: string; // eg. 4

  /**
  * String being displayed as the description label.
  */
  finderTextHint: string; // eg. "Align the QR code to the center of the screen"

  /**
  * Foreground color of the description label.
  */
  finderTextHintColor: string; // eg. "#00ff00"

  /**
  * Whether the flash is toggled on or off.
  */
  flashEnabled: string; // eg. true

  /**
  * Optional minimum required text length of the detected barcode.
  * The default is 0 (setting is turned off).
  * NOTE: This feature works on ITF and MSI Plessey barcodes only.
  */
  minimumTextLength: string; // eg. 1

  /**
  * Optional maximum required text length of the detected barcode.
  * The default is 0 (setting is turned off).
  * NOTE: This feature works on ITF and MSI Plessey barcodes only.
  */
  maximumTextLength: string; // eg. 8

  /**
  * Optional minimum required quiet zone on the barcode.
  * Measured in modules (the size of narrowest bar in the barcode).
  * The default is 10.
  * NOTE: This feature works on ITF and MSI Plessey barcodes only.
  */
  minimum1DBarcodesQuietZone: number; // eg. 12

  /**
  * Whether a sound should be played on successful barcode detection.
  */
  successBeepEnabled: boolean; // eg. false

  /**
  * Background color of the top bar.
  */
  topBarBackgroundColor: string; // eg. "#0000ff"

  /**
  * Foreground color of the cancel button.
  */
  topBarButtonsColor: string; // eg. "#ff0000"

  /**
  * Specifies the way a barcode image is generated or disables this generation altogether.
  * Use if you want to receive a full sized image with barcodes. Defaults to NONE.
  * Options:
  * - VIDEO_FRAME
  * - CAPTURED_IMAGE
  * - NONE
  */
  barcodeImageGenerationType: string; // eg. "CAPTURED_IMAGE"

  /**
  * Controls whether buttons should use all capitals style, as defined by the Android Material Design. Defaults to TRUE.
  * Android only.
  */
  useButtonsAllCaps: boolean; // eg. false

  /**
  * The relative initial zoom level of the camera in the range [0,1], where 0 is zoomed out and 1 is zoomed in.
  * The default value is 0.
  */
  cameraZoomFactor: number; // eg. 0.6

  /**
  * The engine mode of the barcode recognizer. Defaults to NEXT_GEN.
  * To use the legacy recognizer, please specify LEGACY.
  */
  engineMode: string; // eg. "LEGACY"

  /**
  * When set to `true`, the scanner assumes that the barcode can be a GS1 barcode.
  * Turn it off if you don't want to see decoded FNC1 characters ("]C1" and ASCII char 29).
  * The default value is `true`.
  * NOTE: Currently works for CODE128 barcodes only!
  */
  gs1DecodingEnabled: boolean;

  /**
  * With this option enabled, the scanner removes check digits for UPC, EAN and MSI Plessey barcodes.
  * Has no effect if both single and double digit MSI Plessey checksums are enabled.
  * The default is `false`.
  */
  stripCheckDigits: string; // eg. true

  /**
  * The preferred camera module (FRONT or BACK)
  */
  cameraModule: string; // eg. "FRONT"

  /**
  * If `true`, enables the mode which slightly decreases the scanning quality and the energy consumption, thus increasing the scanning speed.
  * The default is `false`.
  * Android only.
  */
  lowPowerMode: boolean; // eg. true
}
```

## Please note

The Scanbot SDK will run without a license for one minute per session!

After the trial period has expired all Scanbot SDK functions will stop working or may be terminated.
You have to restart the app to get another trial period.

To get an unrestricted, "no-strings-attached" 30-day trial license, please submit the [Trial License Form](https://scanbot.io/en/sdk/demo/trial) on our website.

