/*
    This application is to control a smartbulb that works trough an UDP protocol
 */
/// system headers
#include <iostream>
#include <cstdint>
#include <unistd.h>

/// Project files
#include "UDP/Connection/Connection.h"
#include "Protocol/Color/Color.h"
#include "Protocol/On/On.h"
#include "Protocol/Off/Off.h"
#include "Protocol/Status/Status.h"
#include "Protocol/Sleep/Sleep.h"
#include "Protocol/Random/Random.h"

/// Project namespace
using namespace Lamp;

void printUsage() {
    std::cout << "~/smartbulb/Lamp <command> [argument]" << std::endl
              << "\tcommand:" << std::endl
              << "\t\tcolor RED GREEN BLUE WHITE" << std::endl
              << "\t\ton" << std::endl
              << "\t\toff" << std::endl
              << "\t\trandom" << std::endl
              << "\t\tsleep TIMER" << std::endl;
}

/// Program flow
int main(int argc, char **argv) {
    if (argc == 1) {
        printUsage();
        return 1;
    }

    /// parse command line arguments
    int packet_to_send = 0;
    uint8_t RED_VALUE = 0, GREEN_VALUE = 0, BLUE_VALUE = 0, WHITE_VALUE = 0;
    uint16_t SLEEP_VALUE = 0;

    // check for color
    if (strcmp(argv[1], "color") == 0) {
        packet_to_send = 1;

        if (argc != 6) {
            printUsage();
            return 1;
        }

        RED_VALUE = (uint8_t) atoi(argv[2]);
        GREEN_VALUE = (uint8_t) atoi(argv[3]);
        BLUE_VALUE = (uint8_t) atoi(argv[4]);
        WHITE_VALUE = (uint8_t) atoi(argv[5]);
    }
    // check for on
    else if (strcmp(argv[1], "on") == 0) {
        packet_to_send = 2;
    }
    // check for off
    else if (strcmp(argv[1], "off") == 0) {
        packet_to_send = 3;
    }
    // check for random
    else if(strcmp(argv[1], "random") == 0) {
        packet_to_send = 4;
    }
    // check for sleep
    else if(strcmp(argv[1], "sleep") == 0) {
        packet_to_send = 5;
        if (argc != 3) {
            printUsage();
            return 1;
        }

        SLEEP_VALUE = (uint16_t) atoi(argv[2]);
    }
    // no valid command given
    else {
        printUsage();
        return 1;
    }

    /// Configuration
    // true enables broadcast option
    UDP::Connection connection(true);

    // define connection info
    // the port should not be changed
    const uint16_t port = 5880;
    const char ip[15] = "0.0.0.0";// should be 255.255.255.255 or 0.0.0.0 if broadcast

    // define device info
    // this should not be changed for the current lightbulb
    const uint8_t deviceCode = 0x20;
    const uint8_t deviceMac[] = {0x00, 0x00, 0x00, 0x00, 0xb3, 0xdb, 0xf0, 0x00};
    const uint8_t controllerMac[] = {0xc4, 0x3e, 0x3b, 0x51};

    /// create packet to be sent
    Protocol::Color color_packet;
    Protocol::On on_packet;
    Protocol::Off off_packet;
    Protocol::Random random_packet;
    Protocol::Sleep sleep_packet;
    Protocol::Standard *ptr_packet = nullptr;

    switch (packet_to_send) {
        case 1:
            color_packet.setRed(RED_VALUE);
            color_packet.setGreen(GREEN_VALUE);
            color_packet.setBlue(BLUE_VALUE);
            color_packet.setWhite(WHITE_VALUE);
            ptr_packet = &color_packet;
            break;
        case 2:
            ptr_packet = &on_packet;
            break;
        case 3:
            ptr_packet = &off_packet;
            break;
        case 4:
            random_packet.setRandom(1);
            ptr_packet = &random_packet;
            break;
        case 5:
            sleep_packet.setSleep(SLEEP_VALUE);
            ptr_packet = &sleep_packet;
        default:
            break;
    }

    if (ptr_packet != nullptr) {
        ptr_packet->setDeviceCode(deviceCode);
        ptr_packet->setDeviceMac(deviceMac);
        ptr_packet->setControllerMac(controllerMac);
    } else {
        std::cerr << "Error: ptr_packet was not initialized" << std::endl
                  << "       first argument is probably incorrect" << std::endl;
        return 1;
    }


    /// initialise connection
    connection.setPort(port);
    connection.setIp(ip);
    connection.Connect();

    /// send packet
    // send packet 4 times to increase the chance that the packet gets trough : LONG LIVE UDP
    for(int i = 0; i < 4; i++)
        connection.Send(ptr_packet->getByteStream(), ptr_packet->getLength());

    // exit program
    return 0;
}
