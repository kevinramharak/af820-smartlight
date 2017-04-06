#include "WifiCheck.h"

namespace Lamp {
    namespace Protocol {
        WifiCheck::WifiCheck() {
            setWifiFunction(0x01);
        }
    }
}