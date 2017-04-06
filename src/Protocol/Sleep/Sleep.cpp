#include "Sleep.h"

namespace Lamp {
    namespace Protocol {
        Sleep::Sleep() {
            _pointer = (uint8_t *) &_sleep;
            setLength( (uint8_t) 0x27);
            setDeviceFunction( (uint8_t) 0x05);
            setExtraDataLength( (uint8_t) 0x02);
        }

        void Sleep::setSleep(uint8_t sleep) {
            _pointer[38] = sleep;
        }

        void Sleep::setSleep(uint8_t * sleep) {
            for(uint8_t i = 0; i < 2; i++)
                _pointer[37 + i] = sleep[i];
        }

        void Sleep::setSleep(uint16_t sleep) {
            _pointer[37] = (uint8_t) (sleep >> 8);
            _pointer[38] = (uint8_t) sleep;
        }
    }
}