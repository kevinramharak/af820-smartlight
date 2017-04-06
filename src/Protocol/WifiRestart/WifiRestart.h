#ifndef LAMP_PROTOCOL_WIFIRESTART_H
#define LAMP_PROTOCOL_WIFIRESTART_H

#include "../Wifi/Wifi.h"

namespace Lamp {
    namespace Protocol {
        class WifiRestart : public Wifi {
        public:
            WifiRestart();

            const uint8_t * getByteStream() const;
        };
    }
}
#endif //LAMP_PROTOCOL_WIFIRESTART_H
