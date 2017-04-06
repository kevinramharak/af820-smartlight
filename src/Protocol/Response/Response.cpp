#include "Response.h"

namespace Lamp {
    namespace Protocol {
        Response::Response() {
            _pointer = (uint8_t *) &_response;
            setLength( (uint8_t) 0x35);
            setDeviceFunction( (uint8_t) 0xfe);
            setExtraDataLength( (uint8_t) 0x10);
        }

        void Response::setIsOn(const uint8_t on) {
            _pointer[37] = on;
        }

        void Response::setIsRandom(const uint8_t random) {
            _pointer[38] = random;
        }

        void Response::setRed(const uint8_t red) {
            _pointer[40] = red;
        }

        void Response::setGreen(const uint8_t green) {
            _pointer[42] = green;
        }

        void Response::setBlue(const uint8_t blue) {
            _pointer[44] = blue;
        }

        void Response::setWhite(const uint8_t white) {
            _pointer[46] = white;
        }

        void Response::setSleep(const uint8_t sleep) {
            _pointer[48] = sleep;
        }

        void Response::setSleep(const uint8_t * sleep) {
            for(uint8_t i = 0; i < 2; i++)
                _pointer[47 + i] = sleep[i];
        }

        void Response::setSleep(const uint16_t sleep) {
            _pointer[47] = (uint8_t) (sleep >> 8);
            _pointer[48] = (uint8_t) sleep;
        }

        bool Response::isOn() const {
            return _pointer[37] == 0x01;
        }

        bool Response::isRandom() const {
            return _pointer[38] == 0x01;
        }

        uint8_t Response::getRed() const {
            return _pointer[40];
        }

        uint8_t Response::getGreen() const {
            return _pointer[42];
        }

        uint8_t Response::getBlue() const {
            return _pointer[44];
        }

        uint8_t Response::getWhite() const {
            return _pointer[46];
        }

        uint16_t Response::getSleep() const {
            uint16_t sleep = _pointer[47] << 8;
            sleep += _pointer[48];
            return sleep;
        }

        void Response::fillWithByteStream(const uint8_t * stream, const uint16_t length) {
            for(uint8_t i = 0; i < length; i++)
                _pointer[i] = stream[i];
        }
    }
}