/*
    This application is to control a smartbulb that works trough an UDP protocol
 */
/// system headers
#include <iostream>
#include <cstdint>
#include <unistd.h>

#include "helper.h"

/// Project files
#include "UDP/Connection/Connection.h"
#include "Protocol/WifiSet/WifiSet.h"
#include "Protocol/WifiRestart/WifiRestart.h"


/// Project namespace
using namespace Lamp;

/// Program flow
int main(int argc, char **argv) {
    /// Configuration
    // true enables broadcast option
    UDP::Connection connection(true);

    // define connection info
    // the port should not be changed
    const uint16_t port = 5880;
    const char ip[16] = "0.0.0.0";// should be 255.255.255.255 or 0.0.0.0 if broadcast

    // define device info
    // this should not be changed for the current lightbulb
    const uint8_t deviceCode = 0x20;
    const uint8_t deviceMac[] = {0x00, 0x00, 0x00, 0x00, 0xb3, 0xdb, 0xf0, 0x00};
    const uint8_t controllerMac[] = {0xc4, 0x3e, 0x3b, 0x51};

    /// create packet to be sent
    Protocol::WifiSet wifi;
    Protocol::WifiRestart restart;

    wifi.setDeviceCode(deviceCode);
    wifi.setDeviceMac(deviceMac);
    wifi.setControllerMac(controllerMac);

    wifi.setSSID("<SSID>");
    wifi.setPassword("<PASSWORD>");

    restart.setDeviceCode(deviceCode);
    restart.setDeviceMac(deviceMac);
    restart.setControllerMac(controllerMac);

    connection.Send(wifi.getByteStream(), wifi.getLength());

    print(wifi.getByteStream(), wifi.getLength());

    sleep(2);

    for(int i = 0; i < 4; i++) {
        connection.Send(restart.getByteStream(), restart.getLength());
        sleep(2);
    }
    print(restart.getByteStream(), restart.getLength());

    // exit program
    return 0;
}
