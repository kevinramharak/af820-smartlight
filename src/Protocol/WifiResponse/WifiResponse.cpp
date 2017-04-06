#include "WifiResponse.h"

namespace Lamp {
    namespace Protocol {
        WifiResponse::WifiResponse() {
            setWifiFunction(0x04);
        }

        void WifiResponse::fillWithByteStream(const uint8_t * stream, const uint16_t length) {
            for(uint8_t i = 0; i < length; i++)
                _pointer[i] = stream[i];
        }
    }
}