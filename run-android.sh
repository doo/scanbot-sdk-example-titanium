#!/bin/bash
set -e

# ! IMPORTANT !
# If the build is failing it may be because of this:
# +======================+=================+=================+
# | Titanium SDK Version | Min JDK Version | Max JDK version |
# +======================+=================+=================+
# | 10.1.0 - latest      |              11 |              16 |
# +----------------------+-----------------+-----------------+
# | 9.0.2 - 10.0.2       |               8 |              15 |
# +----------------------+-----------------+-----------------+
# | 9.0.1                |               8 |              13 |
# +----------------------+-----------------+-----------------+
# | 9.0.0                |               8 |              12 |
# +----------------------+-----------------+-----------------+
# | 7.5.0 - 8.3.1        |               8 |              14 |
# +----------------------+-----------------+-----------------+
# | 7.0.0 - 7.4.2        |               8 |              10 |
# +----------------------+-----------------+-----------------+

# Check your Titanium SDK version and be sure to set JAVA_HOME accordingly
# The project has been tested with Titanium SDK version 10.1.1 and JDK 11

# JAVA_HOME=~/.sdkman/candidates/java/11.0.14.9.1-amzn


ti build -p android -T device