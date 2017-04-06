#ifndef LAMP_UDP_CONNECTION_H
#define LAMP_UDP_CONNECTION_H

#include <iostream>

#include <cstdint>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define BUFFER_SIZE 256

namespace Lamp {
    namespace UDP {
        class Connection {
        private:
            int socket_fd;
            struct sockaddr_in socket_address;

            int broadcast;// setsockopt needs a reference to its args so this should always be 1

            uint8_t buffer[BUFFER_SIZE];// TODO: fix to a rational buffer size

            bool isConnected = false;

            void resetSockAddr();

            bool openSocket();
            void closeSocket();
            bool connectSocket();

            bool setBroadcastOption();

            void sendStream(const uint8_t * stream, const uint16_t length);
            void receiveStream();

        protected:

        public:
            Connection(bool enableBroadcast = false);

            void setPort(uint16_t port);
            void setIp(const char * ip);

            bool Connect();
            bool Reconnect();

            bool IsConnected() { return isConnected; }

            // TODO: Make connection able to send and receive in a programmer friendly way
            const uint8_t * Send(const uint8_t * stream, const uint16_t length);
        };
    }
}
#endif //LAMP_UDP_CONNECTION_H
