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

## Please note

The Scanbot SDK will run without a license for one minute per session!

After the trial period has expired all Scanbot SDK functions will stop working or may be terminated.
You have to restart the app to get another trial period.

To get an unrestricted, "no-strings-attached" 30-day trial license, please submit the [Trial License Form](https://scanbot.io/en/sdk/demo/trial) on our website.

