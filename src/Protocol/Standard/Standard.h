#ifndef LAMP_PROTOCOL_STANDARD_H
#define LAMP_PROTOCOL_STANDARD_H

#include <cstdint>

namespace Lamp {
    namespace Protocol {
        struct standard {
                    uint8_t     header              [2] { 0x55, 0xAA };
                    uint8_t     length              [2] { 0x00, 0x25 };
            const   uint8_t     fix_1               [3] { 0x01, 0x00, 0x00 };
                    uint8_t     device_mac          [8] { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
            const   uint8_t     fix_2               [3] { 0x00, 0x00, 0x00 };
                    uint8_t     device_code             = 0x00;
                    uint8_t     device_version          = 0x00;
                    uint8_t     device_function         = 0x00;
            const   uint8_t     type_big                = 0x00;
            const   uint8_t     type_small              = 0x00;
                    uint8_t     controller_mac      [4] { 0x00, 0x00, 0x00, 0x00 };
            const   uint8_t     fix_3               [4] { 0x00, 0x00, 0x00, 0x00 };
                    uint8_t     sequence_number     [2] { 0x00, 0x01 };
                    uint8_t     extra_data_length   [2] { 0x00, 0x00 };
            const   uint8_t     fix_4               [2] { 0x00, 0x00 };
        };

        class Standard {
        protected:
            struct standard _standard;
            uint8_t * _pointer;

        public:
            Standard();

            void setLength(const uint8_t length);
            void setLength(const uint8_t * length);
            void setLength(const uint16_t length);
            void setDeviceMac(const uint8_t * mac);
            void setDeviceCode(const uint8_t code);
            void setDeviceVersion(const uint8_t version);
            void setDeviceFunction(const uint8_t function);
            void setControllerMac(const uint8_t * mac);
            void setSequenceNumber(const uint8_t number);
            void setSequenceNumber(const uint8_t * number);
            void setSequenceNumber(const uint16_t number);
            void setExtraDataLength(const uint8_t length);
            void setExtraDataLength(const uint8_t * length);
            void setExtraDataLength(const uint16_t length);

            virtual const uint8_t * getByteStream() const;
            const uint16_t getLength() const;
            const uint16_t getExtraDataLength() const;
        };

    }
}

#endif //LAMP_PROTOCOL_STANDARD_H
