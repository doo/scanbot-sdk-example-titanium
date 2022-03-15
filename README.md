# Scanbot SDK Titanium Example (POC)

This very basic project demonstrates how it is possible to integrate Scanbot SDK into a pure Titanium project.

For the purpose of demonstrating the functionalities, only the Android part has been fully integrated and can be tested with this demo.

## Requirements

In order to run this project you will need to install Titanium SDK. You can install the latest version by running:

```bash 
npm install -g titanium
```

Titanium SDK also requires a compatible JDK:

| Titanium SDK Version | Min JDK Version | Max JDK version |
|----------------------|-----------------|-----------------|
| 10.1.0 - latest      |              11 |              16 |
| 9.0.2 - 10.0.2       |               8 |              15 |
| 9.0.1                |               8 |              13 |
| 9.0.0                |               8 |              12 |
| 7.5.0 - 8.3.1        |               8 |              14 |
| 7.0.0 - 7.4.2        |               8 |              10 |

Be sure to install a compatible JDK, and to set your JAVA_HOME in `run-android.sh` accordingly.

## Run the demo on an Android Device

To build and run the demo on an Android device, we provided a simple script:

```bash
./run-android.sh
```

Before running it, connect your Android device via USB with debug mode enabled in the developer options.
