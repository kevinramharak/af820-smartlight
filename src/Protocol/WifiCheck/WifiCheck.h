#ifndef LAMP_PROTOCOL_WIFICHECK_H
#define LAMP_PROTOCOL_WIFICHECK_H

#include "../Wifi/Wifi.h"

namespace Lamp {
    namespace Protocol {
        class WifiCheck : public Wifi {
        public:
            WifiCheck();
        };
    }
}
#endif //LAMP_PROTOCOL_WIFICHECK_H
