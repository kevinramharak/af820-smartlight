#include "Off.h"

namespace Lamp {
    namespace Protocol {
        Off::Off() {
            setDeviceFunction( (uint8_t) 0x02);
        }
    }
}