#ifndef LAMP_PROTOCOL_COLOR_H
#define LAMP_PROTOCOL_COLOR_H

#include "../Standard/Standard.h"

namespace Lamp {
    namespace Protocol {
        struct color {
            struct standard c_standard;
            const   uint8_t     fix_red     = 0x00;
                    uint8_t     red         = 0x00;
            const   uint8_t     fix_green   = 0x00;
                    uint8_t     green       = 0x00;
            const   uint8_t     fix_blue    = 0x00;
                    uint8_t     blue        = 0x00;
            const   uint8_t     fix_white   = 0x00;
                    uint8_t     white       = 0x00;
            const   uint8_t     fix_time_1  = 0x00;
            const   uint8_t     fix_time_2  = 0x00;
            const   uint8_t     lux_time_1  = 0x00;
            const   uint8_t     lux_time_2  = 0x00;
        };

        class Color : public Standard {
        private:
            struct color _color;
        public:
            Color();

            void setRed(uint8_t value);
            void setGreen(uint8_t value);
            void setBlue(uint8_t value);
            void setWhite(uint8_t value);
        };
    }
}
#endif //LAMP_PROTOCOL_COLOR_H
