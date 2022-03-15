#!/bin/bash

set -e

DEVELOPER_NAME="Apple Development: Marco Saia (S2GMTP3J5S)"

sh pull-sdk-and-build-ios.sh
ti build -p ios -T device --developer-name $DEVELOPER_NAME