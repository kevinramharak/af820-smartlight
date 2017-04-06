#ifndef LAMP_PROTOCOL_WIFISET_H
#define LAMP_PROTOCOL_WIFISET_H

#include "../Wifi/Wifi.h"

namespace Lamp {
    namespace Protocol {
        struct wifiset {
            struct wifi w_wifi;
            uint8_t buffer[66];
            wifiset(struct wifi _wifi) : w_wifi(_wifi) {}
        };

        class WifiSet : public Wifi{
        private:
            struct wifiset _wifiset;
            uint8_t _ssid_length = 0x00;
            uint8_t _ssid[32];
            uint8_t _password_length = 0x00;
            uint8_t _password[32];

            void alignBuffer();
            void recalculateLength();
            void recalculateExtraDataLength();

        public:
            WifiSet();

            void setSSID(const char * ssid);
            void setPassword(const char * password);

            const uint8_t * getByteStream() const;
        };
    }
}

#endif //LAMP_PROTOCOL_WIFISET_H
