#include "WifiRestart.h"

namespace Lamp {
    namespace Protocol {
        WifiRestart::WifiRestart() {
            setWifiFunction(0x05);
        }

        const uint8_t * WifiRestart::getByteStream() const {
            return _pointer;
        };
    }
}