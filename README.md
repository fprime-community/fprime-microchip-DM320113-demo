# fprime-microchip-DM320113-demo

This project is a demo application running the native F' reference topology with FreeRTOS on Microchip's DM320113 evaluation board.

## Overview

The `fprime-microchip-DM320113-demo` repository showcases a functioning F' (F Prime) application integrated with FreeRTOS, specifically tailored for the Microchip DM320113 evaluation board. This demo highlights the interaction between F' components and FreeRTOS, demonstrating serial communication via a custom UART driver.

## Subrepositories

This project includes two key subrepositories:

### [FreeRTOS F' Port](https://github.com/fprime-community/fprime-microchip-DM320113)

- **Description**: Contains the FreeRTOS source code tailored for the DM320113 evaluation board.
- **Features**:
  - FreeRTOS source for the selected board.
  - CMake files for FreeRTOS and the `xc32_toolchain` (compiler used by DM320113).

### [Main F'](https://github.com/nasa/fprime)

- **Description**: Houses all the native F' components and directories.
- **Features**:
  - Native F' components.
  - Directory structure supporting F' applications.

## Custom Configuration

The project includes custom configuration files and directories to ensure compatibility with the subrepositories:

- **Config Directory**: Contains the `settings.ini` and `project.cmake` files required for configuring the project.
- **Settings.ini**: Configuration settings for the project.
- **Project.cmake**: CMake configuration for building the project with the specified subrepositories.

## Components

- **Custom UART Driver Component**: Located within the `Components` directory, this driver facilitates serial communication between the FreeRTOS port and F' Ground Station (GS).

## Build Information

The following directories contain essential build information for the DM320113 evaluation board:

- **ATSAME70Q21B**: Contains device-specific information and configurations.
- **ATSAME70Q21B_DFP**: Device Family Pack for ATSAME70Q21B.
- **CMSIS**: Cortex Microcontroller Software Interface Standard files necessary for the build process.
