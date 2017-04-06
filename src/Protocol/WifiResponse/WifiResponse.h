#ifndef LAMP_PROTOCOL_WIFIRESPONSE_H
#define LAMP_PROTOCOL_WIFIRESPONSE_H

#include "../Wifi/Wifi.h"

namespace Lamp {
    namespace Protocol {
        class WifiResponse : public Wifi {
        private:

        public:
            WifiResponse();

            void fillWithByteStream(const uint8_t * stream, const uint16_t length);
        };
    }
}

#endif //LAMP_PROTOCOL_WIFIRESPONSE_H
