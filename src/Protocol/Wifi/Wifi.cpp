#include "Wifi.h"

namespace Lamp {
    namespace Protocol {
        Wifi::Wifi() {
            _pointer = (uint8_t *) &_wifi;
            setLength( (uint8_t) 0x26);
            setDeviceFunction( (uint8_t) 0xf0);
            setExtraDataLength( (uint8_t) 0x01);
        }

        void Wifi::setWifiFunction(uint8_t function) {
            _pointer[37] = function;
        }
    }
}