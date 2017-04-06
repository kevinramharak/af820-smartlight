#ifndef LAMP_RANDOM_H
#define LAMP_RANDOM_H

#include "../Standard/Standard.h"

namespace Lamp {
    namespace Protocol {
        struct random {
            struct standard r_standard;
            uint8_t random = 0x00;
        };

        class Random : public Standard {
        private:
            struct random _random;

        public:
            Random();

            void setRandom(uint8_t random);
        };
    }
}

#endif //LAMP_RANDOM_H
