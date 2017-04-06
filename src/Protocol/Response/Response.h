#ifndef LAMP_PROTOCOL_RESPONSE_H
#define LAMP_PROTOCOL_RESPONSE_H

#include "../Standard/Standard.h"

namespace Lamp {
    namespace Protocol {
        struct response {
            struct standard r_standard;
                    uint8_t     is_on       = 0x00;
                    uint8_t     is_random   = 0x00;
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
                    uint8_t     sleep_1     = 0x00;
                    uint8_t     sleep_2     = 0x00;
        };

        class Response : public Standard {
        private:
            struct response _response;

            void setIsOn(const uint8_t on);
            void setIsRandom(const uint8_t random);

            void setRed(const uint8_t red);
            void setGreen(const uint8_t green);
            void setBlue(const uint8_t blue);
            void setWhite(const uint8_t white);
            void setSleep(const uint8_t sleep);
            void setSleep(const uint8_t * sleep);
            void setSleep(const uint16_t sleep);

        public:
            Response();

            bool isOn() const;
            bool isRandom() const;
            uint8_t getRed() const;
            uint8_t getGreen() const;
            uint8_t getBlue() const;
            uint8_t getWhite() const;
            uint16_t getSleep() const;

            void fillWithByteStream(const uint8_t * stream, const uint16_t length);
        };
    }
}

#endif //LAMP_PROTOCOL_RESPONSE_H
