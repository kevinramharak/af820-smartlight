#include "Standard.h"

namespace Lamp {
    namespace Protocol {
        Standard::Standard() {
            _pointer = (uint8_t *) &_standard;
        }

        void Standard::setLength(const uint8_t length) {
            _pointer[3] = length;
        }

        void Standard::setLength(const uint8_t * length) {
            for(uint8_t i = 0; i < 2; i++)
                _pointer[2 + i] = length[i];
        }

        void Standard::setLength(const uint16_t length) {
            _pointer[2] = (uint8_t) (length >> 8);
            _pointer[3] = (uint8_t) length;
        }

        void Standard::setDeviceMac(const uint8_t * mac) {
            for(uint8_t i = 0; i < 8; i++)
                _pointer[7 + i] = mac[i];
        }

        void Standard::setDeviceCode(const uint8_t code) {
            _pointer[18] = code;
        }

        void Standard::setDeviceVersion(const uint8_t version) {
            _pointer[19] = version;
        }

        void Standard::setDeviceFunction(const uint8_t function) {
            _pointer[20] = function;
        }

        void Standard::setControllerMac(const uint8_t * mac) {
            for(uint8_t i = 0; i < 4; i++)
                _pointer[23 + i] = mac[i];
        }

        void Standard::setSequenceNumber(const uint8_t number) {
            _pointer[32] = number;
        }

        void Standard::setSequenceNumber(const uint8_t * number) {
            for(uint8_t i = 0; i < 2; i++)
                _pointer[31 + i] = number[i];
        }

        void Standard::setSequenceNumber(const uint16_t number) {
            _pointer[31] = (uint8_t) (number >> 8);
            _pointer[32] = (uint8_t) number;
        }

        void Standard::setExtraDataLength(const uint8_t length) {
            _pointer[34] = length;
        }

        void Standard::setExtraDataLength(const uint8_t * length) {
            for(uint8_t i = 0; i < 2; i++)
                _pointer[33 + i] = length[i];
        }

        void Standard::setExtraDataLength(const uint16_t length) {
            _pointer[33] = (uint8_t) (length >> 8);
            _pointer[34] = (uint8_t) length;
        }

        const uint8_t * Standard::getByteStream() const {
            return _pointer;
        }

        const uint16_t Standard::getLength() const {
            uint16_t length = _pointer[2] << 2;
            length += _pointer[3];
            return length;
        }

        const uint16_t Standard::getExtraDataLength() const {
            uint16_t length = _pointer[33] << 2;
            length += _pointer[34];
            return length;
        }
    }
}