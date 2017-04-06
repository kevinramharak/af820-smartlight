#include "On.h"

namespace Lamp {
    namespace Protocol {
        On::On() {
            setDeviceFunction( (uint8_t) 0x01);
        }
    }
}