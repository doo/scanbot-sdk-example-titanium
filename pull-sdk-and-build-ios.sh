#!/bin/bash

set -e
set -x

BUNDLE_ID=io.scanbot.barcode.titaniumsdk
SDK_VERSION=1.0.0

DEMO_PATH=`pwd`
SDK_PATH=../ScanbotTitaniumBarcodeSDK

cd $SDK_PATH/ios

# Builds the iOS module with verbose logs
ti build -p ios --build-only -l trace

# Move the built package to the example project modules folder
unzip -o ./dist/$BUNDLE_ID-iphone-$SDK_VERSION.zip -d $DEMO_PATH

cd $DEMO_PATH