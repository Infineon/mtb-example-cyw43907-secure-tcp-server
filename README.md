# AIROC&trade; CYW43907 Secure TCP server

This code example demonstrates the implementation of a Secure TCP server with AIROC™ CYW43907 Wi-Fi connectivity processor.

In this example, the TCP server establishes a secure connection with a TCP client through SSL handshake. Once the SSL handshake completes successfully, the server allows the user to send LED ON or OFF command to the TCP client; the client responds by sending an acknowledgement message to the server. The Wi-Fi device can be brought up in either STA interface or soft AP interface mode. Additionally, this code example can be configured to work with IPv4 or link-local IPv6 addressing mode.
This example uses the Wi-Fi middleware core library of the SDK. This library enables application development-based on Wi-Fi by bundling together various other libraries - FreeRTOS, Wi-Fi host driver (WHD), lwIP TCP/IP stack, Mbed TLS, and Secure sockets. The Secure sockets library provides an easy-to-use API by abstracting the network stack (lwIP) and the security stack (Mbed TLS).

[View this README on GitHub.](https://github.com/Infineon/mtb-example-cyw43907-secure-tcp-server)

[Provide feedback on this code example.](https://cypress.co1.qualtrics.com/jfe/form/SV_1NTns53sK2yiljn?Q_EED=eyJVbmlxdWUgRG9jIElkIjoiQ0UyMzQxMDIiLCJTcGVjIE51bWJlciI6IjAwMi0zNDEwMiIsIkRvYyBUaXRsZSI6IkFJUk9DJnRyYWRlOyBDWVc0MzkwNyBTZWN1cmUgVENQIHNlcnZlciIsInJpZCI6ImpydGgiLCJEb2MgdmVyc2lvbiI6IjIuMC4wIiwiRG9jIExhbmd1YWdlIjoiRW5nbGlzaCIsIkRvYyBEaXZpc2lvbiI6Ik1DRCIsIkRvYyBCVSI6IklDVyIsIkRvYyBGYW1pbHkiOiJXSUZJIn0=)



## Requirements

- [ModusToolbox&trade; software](https://www.infineon.com/modustoolbox) v3.1 or later (tested with v3.1)
- Board support package (BSP) minimum required version: 1.0.0
- Programming language: C
- Associated parts: [AIROC&trade; CYW43907 embedded wireless SoC ](https://www.infineon.com/cms/en/product/wireless-connectivity/airoc-connected-mcu/cyw43907)


## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm&reg; embedded compiler v11.3.1 (`GCC_ARM`) - Default value of `TOOLCHAIN`

## Supported kits (make variable 'TARGET')

- [AIROC&trade; CYW43907 embedded wireless SoC kit](https://www.infineon.com/cms/en/product/evaluation-boards/cyw943907aeval1f) (`CYW943907AEVAL1F`) – Default value of `TARGET`

## Hardware setup


This example uses the board's default configuration. See the kit user guide to ensure that the board is configured correctly.



## Software setup

Install a terminal emulator if you don't have one. Instructions in this document use [PuTTY](https://www.putty.org/).

- Install a Python interpreter if you don't have one. This code example is tested using [Python 3.7.7](https://www.python.org/downloads/release/python-377/).

This example requires no additional software or tools.


## Using the code example

Create the project and open it using one of the following:

<details><summary><b>In Eclipse IDE for ModusToolbox&trade; software</b></summary>

1. Click the **New Application** link in the **Quick Panel** (or, use **File** > **New** > **ModusToolbox&trade; Application**). This launches the [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool.

2. Pick a kit supported by the code example from the list shown in the **Project Creator - Choose Board Support Package (BSP)** dialog.

   When you select a supported kit, the example is reconfigured automatically to work with the kit. To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can use the Library Manager to select or update the BSP and firmware libraries used in this application. To access the Library Manager, click the link from the **Quick Panel**.

   You can also just start the application creation process again and select a different kit.

   If you want to use the application for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. In the **Project Creator - Select Application** dialog, choose the example by enabling the checkbox.

4. (Optional) Change the suggested **New Application Name**.

5. The **Application(s) Root Path** defaults to the Eclipse workspace which is usually the desired location for the application. If you want to store the application in a different location, you can change the *Application(s) Root Path* value. Applications that share libraries should be in the same root path.

6. Click **Create** to complete the application creation process.

For more details, see the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.infineon.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mt_ide_user_guide.pdf*).

</details>

<details><summary><b>In command-line interface (CLI)</b></summary>

ModusToolbox&trade; software provides the Project Creator as both a GUI tool and the command line tool, "project-creator-cli". The CLI tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the "project-creator-cli" tool. On Windows, use the command line "modus-shell" program provided in the ModusToolbox&trade; software installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; software tools. You can access it by typing `modus-shell` in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

The "project-creator-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the `<id>` field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the `<id>` field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional

<br>

The following example will clone the "[mtb-example-cyw43907-secure-tcp-server](https://github.com/Infineon/mtb-example-cyw43907-secure-tcp-server)" application with the desired name "SecureTcpServer" configured for the *CYW943907AEVAL1F* BSP into the specified working directory, *C:/mtb_projects*:

   ```
   project-creator-cli --board-id CYW943907AEVAL1F --app-id mtb-example-cyw43907-secure-tcp-server --user-app-name SecureTcpServer --target-dir "C:/mtb_projects"
   ```

**Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; software user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can invoke the Library Manager GUI tool from the terminal using `make library-manager` command or use the Library Manager CLI tool "library-manager-cli" to change the BSP.

The "library-manager-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--add-bsp-name` | Name of the BSP that should be added to the application | Required
`--set-active-bsp` | Name of the BSP that should be as active BSP for the application | Required
`--add-bsp-version`| Specify the version of the BSP that should be added to the application if you do not wish to use the latest from manifest | Optional
`--add-bsp-location`| Specify the location of the BSP (local/shared) if you prefer to add the BSP in a shared path | Optional

<br />

Following example adds the CYW943907AEVAL1F BSP to the already created application and makes it the active BSP for the app:

   ```
   ~/ModusToolbox/tools_{3.1}/library-manager/library-manager-cli --project "C:/mtb-example-cyw43907-secure-tcp-server" --add-bsp-name CYW943907AEVAL1F --add-bsp-version "latest-v1.X" --add-bsp-location "local"

   ~/ModusToolbox/tools_{3.1}/library-manager/library-manager-cli --project "C:/mtb-example-cyw43907-secure-tcp-server" --set-active-bsp APP_CYW943907AEVAL1F
   ```

</details>

<details><summary><b>In third-party IDEs</b></summary>

Use one of the following options:

- **Use the standalone [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool:**

   1. Launch Project Creator from the Windows Start menu or from *{ModusToolbox&trade; software install directory}/tools_{version}/project-creator/project-creator.exe*.

   2. In the initial **Choose Board Support Package** screen, select the BSP, and click **Next**.

   3. In the **Select Application** screen, select the appropriate IDE from the **Target IDE** drop-down menu.

   4. Click **Create** and follow the instructions printed in the bottom pane to import or open the exported project in the respective IDE.

<br />

- **Use command-line interface (CLI):**

   1. Follow the instructions from the **In command-line interface (CLI)** section to create the application, and then import the libraries using the `make getlibs` command.

   2. Export the application to a supported IDE using the `make <ide>` command.

   3. Follow the instructions displayed in the terminal to create or import the application as an IDE project.

For a list of supported IDEs and more details, see the "Exporting to IDEs" section of the [ModusToolbox&trade; software user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; software install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>


## Operation

1. Connect the board to your PC using the provided USB cable.

2. The kit can be configured to run either as Wi-Fi STA interface mode or in AP interface mode. The interface mode is configured using the `USE_AP_INTERFACE` macro defined in the *network_credentials.h* file. Based on the desired interface mode, do the following:

   **Kit in STA mode (default interface):**

   1. Set the `USE_AP_INTERFACE` macro to '0'. This is the default mode.

   2. Modify the `WIFI_SSID`, `WIFI_PASSWORD`, and `WIFI_SECURITY_TYPE` macros to match with that of the Wi-Fi network credentials. These macros are defined in the *network_credentials.h* file. Ensure that the Wi-Fi network that you are connecting to is configured as a private network for the proper functioning of this example.
   
   **Note:** The maximum length of the `WIFI_SSID` and `WIFI_PASSWORD` values should not exceed `CY_WCM_MAX_SSID_LEN` (32) and `CY_WCM_MAX_PASSPHRASE_LEN` (64) macros respectively.

   **Kit in AP mode:**

   1. Set the `USE_AP_INTERFACE` macro to '1'.

   2. Update the `SOFTAP_SSID`, `SOFTAP_PASSWORD`, and `SOFTAP_SECURITY_TYPE` macros as desired. This step is optional.

3. Configure the IP addressing mode. By default, IPv4-based addressing is used. To use IPv6 addressing mode, set the `USE_IPV6_ADDRESS` macro defined in the *secure_tcp_server.h* file as shown below:

   ```
   #define USE_IPV6_ADDRESS				      (1)
   ```

4. Open a terminal program and select the COM port. Set the serial port parameters to 8N1 and 115200 baud.

5. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE for ModusToolbox&trade; software</b></summary>

      1. Select the application project in the Project Explorer.

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (FTDI)**.
      </details>

   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The default toolchain and target are specified in the application's Makefile but you can override these values manually:
      ```
      make program TARGET=<BSP> TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program TARGET=CYW943907AEVAL1F TOOLCHAIN=GCC_ARM
      ```
   </details>


6. After programming, the application starts automatically. Confirm that the text as shown in either one of the following figures is displayed on the UART terminal. Note that the Wi-Fi SSID and the IP address assigned will be different based on the network that you have connected to; in AP mode, the AP credentials will be different based on your configuration in **Step 2**.

   **Figure 1. UART terminal showing the Wi-Fi connection status (IPv4 address and STA mode)**

   ![](images/wifi-conn-status-ipv4-sta-mode.png)

   <br>

   **Figure 2. UART terminal showing the Wi-Fi connection status (IPv6 address and STA mode)**

   ![](images/wifi-conn-status-ipv6-sta-mode.png)

   <br>

   **Figure 3. UART terminal showing the Wi-Fi connection status (IPv4 address and AP mode)**

   ![](images/wifi-conn-status-ipv4-ap-mode.png)

   Similarly, when the CE is configured for IPv6 and AP mode, the IPv4 address displayed in **Figure 3** will be replaced by the IPv6 address.

7. Connect the PC to the Wi-Fi AP that is configured in **Step 2**:

   - **In STA mode:** Connect the computer to the same AP to which the kit is connected.

   - **In AP mode:** Connect the computer to the kit's AP.

   Make a note of the IP address assigned to the kit. Note that the type of IP address (IPv4 or IPv6) assigned will be based on the IP addressing mode configured in **Step 3**.

8. From the project directory (*{project directory}/python-tcp-secure-client* folder), open a command shell and run the Python TCP secure client (*tcp_secure_client.py*). In the command shell opened in the project directory, type in the following command based on the IP addressing mode configuration:

     **For IPv4-based addressing:**

   ```
   python tcp_secure_client.py ipv4 <IPv4 address of the kit>
   ```

   **For IPv6-based addressing:**

   ```
   python tcp_secure_client.py ipv6 <IPv6 address of the kit>
   ```

   **Note:** Ensure that the firewall settings of your computer allow access to the Python software so that it can communicate with the TCP server. For more details on enabling Python access, refer to this [community thread](https://community.infineon.com/t5/ModusToolbox-General/CE229112-Enable-Python-access-to-your-WiFi/td-p/214654).


8. Press the user button (CYBSP_USER_BTN) to send LED ON or OFF command to the Python TgCP client.

   Each user button press will issue the LED ON or OFF commands alternately. The client in turn sends an acknowledgement message back to the server.

   **Figure 4** and **Figure 5** show the TCP server output in IPv4 addressing mode, when the CE is configured in STA and AP mode respectively. **Figure 6** shows the TCP client output in IPv4 addressing mode for both AP and STA mode. When the CE is configured in STA mode, **Figure 7** and **Figure 8** show the TCP server and TCP client outputs respectively in IPv6 addressing mode.

   When the CE is configured in AP and IPv6 mode, the only change from the **Figure 4** will be the IPv6 address being displayed instead of IPv4.

   **Figure 4. TCP server output - STA mode (IPv4 addressing mode)**

   ![](images/tcp-server-ipv4-output-sta-mode.png)

   <br>

   **Figure 5. TCP server output - AP mode (IPv4 addressing mode)**

   ![](images/tcp-server-ipv4-output-ap-mode.png)

   <br>

   **Figure 6. TCP client output (IPv4 addressing mode)**

   ![](images/tcp-client-ipv4-output.png)

   <br>

   **Figure 7. TCP server output (IPv6 addressing mode)**

   ![](images/tcp-server-ipv6-output-sta-mode.png)

   <br>

   **Figure 8. TCP client output (IPv6 addressing mode)**

   ![](images/tcp-client-ipv6-output.png)

      **Note:** Instead of using the Python TCP client (*tcp_secure_client.py*), alternatively you can use the example [mtb-example-secure-tcp-client](https://github.com/Infineon/mtb-example-cyw43907-secure-tcp-client) to run as TCP client on a second kit. See the code example documentation for more details.

## Debugging

You can debug the example to step through the code. In the IDE, use the **\<Application Name> Debug (FTDI)** configuration in the **Quick Panel**. For more details, see the "Program and debug" section in the [Eclipse IDE for ModusToolbox&trade; software user guide](https://www.infineon.com/MTBEclipseIDEUserGuide).


## Design and implementation

### Resources and settings



In this example, the TCP server establishes a secure connection with a TCP client through SSL handshake. During the SSL handshake, the server presents its SSL certificate for verification, and verifies the incoming client identity. The server's SSL certificate used in this example is a self-signed SSL certificate. See [Creating a self-signed certificate](#Creating-a-self-signed-SSL-certificate) for more details.

Once the SSL handshake completes successfully, the server allows the user to send LED ON/OFF commands to the TCP client; the client responds by sending an acknowledgement message to the server.

**Table 1. Application resources**

 Resource  |  Alias/object     |    Purpose
 :-------- | :-------------    | :------------
 M2M (HAL)  | m2m_obj         | M2M interface for Wi-Fi connectivity
 UART (HAL) |cy_retarget_io_uart_obj| UART HAL object used by retarget-io for debug UART port
 LED (BSP) | CYBSP_USER_LED2 | User LED to show output


<br>

### Creating a self-signed SSL certificate

The TCP server demonstrated in this example uses a self-signed SSL certificate. This requires **OpenSSL** which is already preloaded in the ModusToolbox&trade; software installation. Self-signed SSL certificate means that there is no third-party certificate issuing authority, commonly referred to as CA, involved in the authentication of the server. Clients connecting to the server must have an exact copy of the SSL certificate to verify the server's identity.
 
Do the following to generate a self-signed SSL certificate:

#### **Generate SSL certificate and private key**

1. Run the following command with a CLI (on Windows, use the command line "modus-shell" program provided in the ModusToolbox&trade; software installation instead of a standard windows command-line application) to generate the SSL certificate and private key.

   ```
   openssl req -new -newkey rsa:2048 -days 365 -nodes -x509 -keyout server.key -out server.crt
   ```

2. Follow the instructions in the command window to provide the details required for creating the SSL certificate and private key.

   The *server.crt* file is your server's certificate and *server.key* is your server's private key.

## Related resources

Resources  | Links
-----------|----------------------------------
Code examples  | [Using ModusToolbox&trade; software](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software) on GitHub <br>
Device documentation | [AIROC&trade; CYW43907 datasheet](https://www.infineon.com/dgdl/Infineon-CYW43907-WICED-IEEE-802.11-a-b-g-n-SoC-with-an-Embedded-Applications-Processor-AdditionalTechnicalInformation-v13_00-EN.pdf?fileId=8ac78c8c7d0d8da4017d0ee1fbda682d) <br>
Development kits | Select your kits from the [evaluation board finder](https://www.infineon.com/cms/en/design-support/finder-selection-tools/product-finder/evaluation-board)
Libraries on GitHub  | [mtb-hal-cat4](https://github.com/Infineon/mtb-hal-cat4) – AIROC&trade; CYW43907 Hardware abstraction layer (HAL) library <br> [retarget-io](https://github.com/Infineon/retarget-io) – Utility library to retarget STDIO messages to a UART port <br>
Middlewares on GitHub  | [ModusToolbox™ software](https://github.com/Infineon/modustoolbox-software) – Links to all ModusToolbox™ middlewares, libraries and documents<br>
Tools  | [Eclipse IDE for ModusToolbox&trade; software](https://www.infineon.com/modustoolbox) – ModusToolbox&trade; software is a collection of easy-to-use software and tools enabling rapid development with Infineon MCUs, covering applications from embedded sense and control to wireless and cloud-connected systems using AIROC&trade; Wi-Fi and Bluetooth&reg; connectivity devices

<br />

## Other resources

Infineon provides a wealth of data at [www.infineon.com](https://www.infineon.com) to help you select the right device, and quickly and effectively integrate it into your design.

## Document history

Document title: *CE234102* – *AIROC&trade; CYW43907 Secure TCP server*


 Version | Description of change
 ------- | ---------------------
 1.0.0   | New code example
 2.0.0   | Major update to support ModusToolbox™ v3.1 and BSPs v1.0.0 <br /> This version is not backward compatible with previous versions (below ModusToolbox™ v3.0) of ModusToolbox&trade; software 

---------------------------------------------------------

© Cypress Semiconductor Corporation, 2020-2023. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress’s patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br />
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress’s published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br />
Cypress, the Cypress logo, and combinations thereof, WICED, ModusToolbox, PSoC, CapSense, EZ-USB, F-RAM, and Traveo are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit www.infineon.com. Other names and brands may be claimed as property of their respective owners.
