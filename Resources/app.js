
import ScanbotBarcodeSDK from 'io.scanbot.barcode.titaniumsdk';
import Styles from './src/common/styles'

// Initialize Scanbot SDK
ScanbotBarcodeSDK.initializeSdk({
    // LICENSE KEY - an empty string activates the 60 seconds trial mode;
    // after that the SDK features will no longer work
    licenseKey: '',
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

Ti.API.info(Object.keys(ScanbotBarcodeSDK))
const uiProxy = ScanbotBarcodeSDK.createScanbotBarcodeUi({
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
                uiProxy.startBarcodeScanner({}, (result) => {
                    alert(JSON.stringify(result)); 
                })
            } catch(error) {
                Ti.API.error("Barcode Scanner Error: " + error);
            }
            break;
        case 'get-license-info':
            let licenseInfo = ScanbotBarcodeSDK.getLicenseInfo();
            alert(JSON.stringify(licenseInfo))
            break;
    }
});

win.add(listView);

win.open();
