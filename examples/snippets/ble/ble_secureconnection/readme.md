# BLE Secure Connection

## 1. Purpose / Scope

This application demonstrates how to configure RS9116W EVK device in peripheral role and how to connect it to a remote device. By default, our module has enable the SMP secure connection is enabled in the module.

In this application, module connects with remote device and initiates SMP pairing process.  After successful SMP pairing, SMP encryption will be enabled in both Central and Peripheral device.


## 2. Prerequisites / Setup Requirements

Before running the application, the user will need the following things to setup.

### 2.1 Hardware Requirements

- Windows PC with Host interface(UART/ SPI).
- Silicon Labs [RS9116 Wi-Fi Evaluation Kit](https://www.silabs.com/development-tools/wireless/wi-fi/rs9116x-sb-evk-development-kit)
- Host MCU Eval Kit. This example has been tested with:
   - Silicon Labs [WSTK + EFR32MG21](https://www.silabs.com/development-tools/wireless/efr32xg21-bluetooth-starter-kit)
   - [STM32F411 Nucleo](https://st.com/)
- BLE peripheral device which supports privacy feature(Generally phones with the BLE Connect application)
- BLE peripheral device which supports SMP pairing(This Application uses TI sensor tag for a remote device)
    
![Setup Diagram For LE Secure Connections Example](resources/readme/image_1.png)
   
### 2.2 Software Requirements

- [WiSeConnect SDK](https://github.com/SiliconLabs/wiseconnect-wifi-bt-sdk/)
    
- Embedded Development Environment

   - For STM32, use licensed [Keil IDE](https://www.keil.com/demo/eval/arm.htm)

   - For Silicon Labs EFx32, use the latest version of [Simplicity Studio](https://www.silabs.com/developers/simplicity-studio)
   
- Download and install the Silicon Labs [EFR Connect App](https://www.silabs.com/developers/efr-connect-mobile-app) in the android smart phones for testing BLE applications. Users can also use their choice of BLE apps available in Android/iOS smart phones.

## 3. Application Build Environment

### 3.1 Platform

The Application can be built and executed on below Host platforms
*	[STM32F411 Nucleo](https://st.com/)
*	[WSTK + EFR32MG21](https://www.silabs.com/development-tools/wireless/efr32xg21-bluetooth-starter-kit) 

### 3.2 Host Interface

* By default, the application is configured to use the SPI bus for interfacing between Host platforms and the RS9116W EVK.
* The SAPI driver provides APIs to enable other host interfaces if SPI is not suitable for your needs.

### 3.3 Project Configuration

The Application is provided with the project folder containing Keil and Simplicity Studio project files.

*	Keil Project
	- The Keil project is used to evaluate the application on STM32.
	- Project path: `<Release_Package>/examples/snippets/ble/ble_secureconnection/projects/ble_secureconnection-nucleo-f411re.uvprojx`

*	Simplicity Studio
	- The Simplicity Studio project is used to evaluate the application on EFR32MG21.
	- Project path: 
		- If the Radio Board is **BRD4180A** or **BRD4181A**, then access the path `<Release_Package>/examples/snippets/ble/ble_secureconnection/projects/ble_secureconnection-brd4180a-mg21.slsproj`
		- If the Radio Board is **BRD4180B** or **BRD4181B**, then access the path `<Release_Package>/examples/snippets/ble/ble_secureconnection/projects/ble_secureconnection-brd4180b-mg21.slsproj`
        - User can find the Radio Board version as given below 

![EFR Radio Boards](resources/readme/image_1a.png)

### 3.4 Bare Metal Support

This application supports only bare metal environment. By default, the application project files (Keil and Simplicity Studio) are provided with bare metal configuration.

## 4. Application Configuration Parameters

The application can be configured to suit your requirements and development environment. Read through the following sections and make any changes needed.

**4.1** Open `rsi_ble_sc.c` file and update/modify following macros,

**4.1.2** The desired parameters are provided below. User can also modify the parameters as per their needs and requirements.

   `RSI_BLE_DEVICE_NAME` refers the name of the WiSeConnect device to appear during scanning by remote devices.

	 #define RSI_BLE_DEVICE_NAME                              "BLE_SMP_SC"
   
   RSI_BLE_SMP_IO_CAPABILITY refers IO capability.

	 #define RSI_BLE_SMP_IO_CAPABILITY                        0x00
   RSI_BLE_SMP_PASSKEY refers SMP Passkey

	 #define RSI_BLE_SMP_PASSKEY                              0
   Following are the non-configurable macros in the application.

	 #define RSI_BLE_CONN_EVENT                               0x01
	 #define RSI_BLE_DISCONN_EVENT                            0x02
	 #define RSI_BLE_SMP_REQ_EVENT                            0x03
	 #define RSI_BLE_SMP_RESP_EVENT                           0x04
	 #define RSI_BLE_SMP_PASSKEY_EVENT                        0x05
	 #define RSI_BLE_SMP_FAILED_EVENT                         0x06
	 #define RSI_BLE_ENCRYPT_STARTED_EVENT                    0x07
	 #define RSI_BLE_SMP_PASSKEY_DISPLAY_EVENT                0x08
	 #define RSI_BLE_SC_PASSKEY_EVENT                         0X09
	 #define RSI_BLE_LTK_REQ_EVENT                            0x0A

   BT_GLOBAL_BUFF_LEN refers Number of bytes required by the application and the driver

	 #define BT_GLOBAL_BUFF_LEN                               15000
	 
   **Power save configuration**

   By default, The Application is configured without power save.
	 
	 #define ENABLE_POWER_SAVE 0

   If user wants to run the application in power save, modify the below configuration. 
	 
	 #define ENABLE_POWER_SAVE 1 
		
**4.2** Open `rsi_wlan_config.h` file and update/modify following macros,

	 #define CONCURRENT_MODE                                 RSI_DISABLE
	 #define RSI_FEATURE_BIT_MAP                            FEAT_SECURITY_OPEN
	 #define RSI_TCP_IP_BYPASS                              RSI_DISABLE
	 #define RSI_TCP_IP_FEATURE_BIT_MAP                     TCP_IP_FEAT_DHCPV4_CLIENT
	 #define RSI_CUSTOM_FEATURE_BIT_MAP                     FEAT_CUSTOM_FEAT_EXTENTION_VALID
	 #define RSI_EXT_CUSTOM_FEATURE_BIT_MAP                  0
	 #define RSI_BAND                                       RSI_BAND_2P4GHZ

## 5. Testing the Application

User has to follow the below steps for the successful execution of the application.

### 5.1 Loading the RS9116W firmware

Refer [Getting started with PC ](https://docs.silabs.com/rs9116/latest/wiseconnect-getting-started) to load the firmware into RS9116W EVK. The firmware binary is located in `<Release_Package>/firmware/`

### 5.2 Building the Application on the Host Platform

### 5.2.1 Using STM32

Refer [STM32 Getting Started](https://docs.silabs.com/rs9116-wiseconnect/latest/wifibt-wc-getting-started-with-efx32/)  

- Open the project `<Release_Package>/examples/snippets/ble/ble_secureconnection/projects/ble_secureconnection-nucleo-f411re.uvprojx` in Keil IDE.
- Build and Debug the project
- Check for the RESET pin:
	- If RESET pin is connected from STM32 to RS9116W EVK, then user need not press the RESET button on RS9116W EVK before free run.
	- If RESET pin is not connected from STM32 to RS9116W EVK, then user need to press the RESET button on RS9116W EVK before free run.
- Free run the project
- Then continue the common steps from **Section 5.3**


#### 5.2.2 Using EFX32

Refer [EFx32 Getting Started](https://docs.silabs.com/rs9116-wiseconnect/latest/wifibt-wc-getting-started-with-efx32/)

- Import the project from `<Release_Package>/examples/snippets/ble/ble_secureconnection/projects`
- Select the appropriate .slsproj as per Radio Board type mentioned in **Section 3.3**
- Compile and flash the project in to Host MCU
- Debug the project
- Check for the RESET pin:
	- If RESET pin is connected from STM32 to RS9116W EVK, then user need not press the RESET button on RS9116W EVK before free run
	- If RESET pin is not connected from STM32 to RS9116W EVK, then user need to press the RESET button on RS9116W EVK before free run
- Free run the project
- Then continue the common steps from **Section 5.3**

### 5.3 Common Steps

1. After the program gets executed, WiseConnect device will be in advertising state.

2. Open a LEApp in the Smartphone and do the scan.Ensure that the device is not bonded prior . Open the bonded tab and if the application name appears
then click on the three dots beside the name and select delete bond information.

3. In the App, RS9116W EVK  will appear with the name configured in the macro "BLE_SMP_SC" or sometimes observed as Silicon Labs device as internal name "SimpleBLEPeripheral".

4. Initiate connection from the App.

5. Observe that the connection is established between the desired device and Silicon Labs device.When application sends a smp request accept it on remote side by clicking ok(pair) and after smp passkey display event .Enter the passkey displayed on the console (host logs) on the remote mobile side

6. After successful connection, application will initiate SMP paring and wait for SMP response event and SMP passkey request event. After receiving SMP response and SMP SC passkey events, application sends SMP response and stores passkey in numeric value and sets SMP Sc Passkey responses event. If SMP is successful, Device sends SMP encrypt started event to host. If not success, Device sends SMP failure event to host.

7. After successful program execution, the prints in teraterm looks as shown below.   
    
![Prints in Teraterm](resources/readme/image1b.png)