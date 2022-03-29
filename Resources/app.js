
import ScanbotBarcodeSDK from 'io.scanbot.barcode.titaniumsdk';
import Styles from './src/common/styles'
import { parseBarcodeScannerResult, parseLicenseInfo } from './src/utils/results-parser';

/*
* TODO Add the Scanbot SDK license key here.
* Please note: The Scanbot SDK will run without a license key for one minute per session!
* After the trial period is over all Scanbot SDK functions as well as the UI components will stop working
* or may be terminated. You can get an unrestricted "no-strings-attached" 30 day trial license key for free.
* Please submit the trial license form (https://scanbot.io/en/sdk/demo/trial) on our website by using
* the app identifier "io.scanbot.example.sdk.reactnative" of this example app.
*/
const LICENSE_KEY = ''

// Initialize Scanbot SDK
ScanbotBarcodeSDK.initializeSdk({
    licenseKey: LICENSE_KEY,
    useCameraX: true
});

let win = Ti.UI.createWindow({
    title: "Scanbot SDK",
    titleAttributes: {
        color: 'white'
    },
    navTintColor: 'white',
    barColor: Styles.SCANBOT_RED,
    backgroundColor: '#fff',
});

// We use `createScanbotBarcodeUi` to initialize the UI proxy
const scanbotRtu = ScanbotBarcodeSDK.createScanbotBarcodeUi({
    lifecycleContainer: win
})

let listView = Ti.UI.createListView();
let sections = [];

const defaultListItemProps = {
    font: {
        fontSize: 18
    },
    color: '#000000'
}

let actions = [
    {
        properties: { 
            title: 'RTU-UI Barcode Scanner', 
            itemId: 'start-barcode-scanner', 
            ...defaultListItemProps
        }
    },
    {
        properties: { 
            title: 'View Scanbot SDK License Info', 
            itemId: 'get-license-info', 
            ...defaultListItemProps
        }
    },
]

const createHeader = (title) => {
    let view = Ti.UI.createView({
        height: Ti.UI.SIZE,
        backgroundColor:'#fafafa'
    });
    let label = Ti.UI.createLabel({
        color: 'black',
        font: { fontSize: 20 },
        top: 4,
        left: 4,
        text: title
    });
    view.add(label);
    return view;
}

let section = Ti.UI.createListSection({ headerView: createHeader('Features'), items: actions});

sections.push(section);

listView.sections = sections;

listView.addEventListener('itemclick', async (e) => {
    switch(e.itemId) {
        case 'start-barcode-scanner':
            try {
                var configuration = {
                    // We use a square finder view
                    finderAspectRatio: {
                        width: 1,
                        height: 1
                    },
                    
                    // We give it a blue color
                    finderLineColor: '#0000ff',

                    // We also explictly set the barcodes types that we want to detect (optional)
                    barcodeFormats: [
                        'AZTEC',
                        'CODABAR',
                        'CODE_39',
                        'CODE_93',
                        'CODE_128',
                        'DATA_MATRIX',
                        'EAN_8',
                        'EAN_13',
                        'ITF',
                        'PDF_417',
                        'QR_CODE',
                        'RSS_14',
                        'RSS_EXPANDED',
                        'UPC_A',
                        'UPC_E',
                        'MSI_PLESSEY'
                    ]
                }

                // Finally, we start the barcode scanner with the configuration we have just created
                scanbotRtu.startBarcodeScanner(configuration, (result) => {
                    if (result.status !== 'OK') {
                        return;
                    }
                    alert(parseBarcodeScannerResult(result)); 
                })
            } catch(error) {
                Ti.API.error("Barcode Scanner Error: " + error);
            }
            break;
        case 'get-license-info':
            let licenseInfo = ScanbotBarcodeSDK.getLicenseInfo();
            alert(parseLicenseInfo(licenseInfo));
            break;
    }
});

win.add(listView);
win.open();
