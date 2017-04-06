#include "Status.h"

namespace Lamp {
    namespace Protocol {
        Status::Status() {
            setDeviceFunction( (uint8_t) 0xff);
        }
    }
}