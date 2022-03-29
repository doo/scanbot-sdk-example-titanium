
export const parseLicenseInfo = (licenseInfo) => {
    const expirationDate = new Date(licenseInfo.licenseExpirationDate);
    return (
        `Your license is ${licenseInfo.isLicenseValid ? 'VALID' : 'NOT VALID'}\n` +
        `License Status:\n${licenseInfo.licenseStatus}\n` +
        `- License Expiration Date:\n${expirationDate}`
    );
}

export const parseBarcodeScannerResult = (result) => {
    var outStr = `Detected ${result.barcodes.length} barcodes:`;
    result.barcodes.forEach((barcode, index) => {
        outStr += `\n${index+1}) ${barcode.text} (${barcode.type})`
    })
    return outStr;
}