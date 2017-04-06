#include "Random.h"

namespace Lamp {
    namespace Protocol {
        Random::Random() {
            _pointer = (uint8_t *) &_random;
            setLength( (uint8_t) 0x26);
            setDeviceFunction( (uint8_t) 0x04);
            setExtraDataLength( (uint8_t) 0x01);
        }

        void Random::setRandom(uint8_t random){
            _pointer[37] = random;
        }
    }
}