#ifndef LAMP_PROTOCOL_WIFI_H
#define LAMP_PROTOCOL_WIFI_H

#include "../Standard/Standard.h"

namespace Lamp {
    namespace Protocol {
        struct wifi {
            struct standard w_standard;
            uint8_t wifi_function = 0x00;
        };

        class Wifi : public Standard {
        protected:
            struct wifi _wifi;

        public:
            Wifi();

            void setWifiFunction(uint8_t function);
        };
    }
}
#endif //LAMP_PROTOCOL_WIFI_H
