#include "Color.h"

namespace Lamp {
    namespace Protocol {
        Color::Color() {
            _pointer = (uint8_t *) &_color;
            setLength( (uint8_t) 0x31 );
            setDeviceFunction( (uint8_t) 0x03);
            setExtraDataLength( (uint8_t) 0x0c);
        };

        void Color::setRed(uint8_t value) {
            _pointer[38] = value;
        }

        void Color::setGreen(uint8_t value) {
            _pointer[40] = value;
        }

        void Color::setBlue(uint8_t value) {
            _pointer[42] = value;
        }

        void Color::setWhite(uint8_t value) {
            _pointer[44] = value;
        }
    }
}