#ifndef LAMP_PROTOCOL_SLEEP_H
#define LAMP_PROTOCOL_SLEEP_H

#include "../Standard/Standard.h"

namespace Lamp {
    namespace Protocol {
        struct sleep {
            struct standard s_standard;
            uint8_t sleep[2] { 0x00, 0x00 };
        };

        class Sleep : public Standard {
        private:
            sleep _sleep;

        public:
            Sleep();

            void setSleep(uint8_t sleep);
            void setSleep(uint8_t * sleep);
            void setSleep(uint16_t sleep);
        };
    }
}


#endif //LAMP_PROTOCOL_SLEEP_H
