#!/bin/bash

set -e

# ! IMPORTANT !
# Titanium CLI android build seems to require Java 11 in order to work properly,
# so we override the default JAVA_HOME to reference our local JDK v11
JAVA_HOME=~/.sdkman/candidates/java/11.0.14.9.1-amzn

sh pull-sdk-and-build-android.sh
ti build -p android -T device