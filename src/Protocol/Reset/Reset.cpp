#include "Reset.h"

namespace Lamp {
    namespace Protocol {
        Reset::Reset() {
            setDeviceFunction( (uint8_t) 0xf7);
        }
    }
}