#include "WifiSet.h"

namespace Lamp {
    namespace Protocol {
        WifiSet::WifiSet(): _wifiset(_wifi) {
            _pointer = (uint8_t *) &_wifiset;
            setWifiFunction(0x03);
        }

        void WifiSet::setSSID(const char * ssid) {
            int8_t i = -1;
            while( ssid[++i] != 0x00)// this could kill stuff if
                _ssid[i] = (uint8_t) ssid[i];
            _ssid_length = (uint8_t) i;

            alignBuffer();
        }

        void WifiSet::setPassword(const char * password) {
            int8_t i = -1;
            while( password[++i] != 0x00)
                _password[i] = (uint8_t) password[i];
            _password_length = (uint8_t) i;

            alignBuffer();
        }

        void WifiSet::alignBuffer() {
            uint8_t * pointer = _pointer + 0x26;

            * pointer++ = _ssid_length;
            for(uint8_t i = 0; i < _ssid_length; i++)
                * pointer++ = _ssid[i];

            * pointer++ = _password_length;
            for(uint8_t i = 0; i < _password_length; i++)
                * pointer++ = _password[i];

            recalculateLength();
            recalculateExtraDataLength();
        }

        void WifiSet::recalculateLength() {
            // 0x28 => 0x26 for the wifi command length + 0x02 for the string lengths of ssid and password
            setLength( (uint8_t) (0x28 + _ssid_length + _password_length) );
        }

        void WifiSet::recalculateExtraDataLength() {
            // 0x03 => 0x01 for the wifi command + 0x02 for the string lengths of ssid and password
            setExtraDataLength( (uint8_t) (0x03 + _ssid_length + _password_length) );
        }

        const uint8_t * WifiSet::getByteStream() const {
            return _pointer;
        }
    }
}