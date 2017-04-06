#include "Connection.h"

namespace Lamp {
    namespace UDP {
        Connection::Connection(bool enableBroadcast) {
            memset(&buffer, 0, sizeof(buffer)); //clear buffer
            resetSockAddr();                    //clear socketaddr structure
            socket_address.sin_family = AF_INET;// TODO: make it IPv6 compatible

            broadcast = (enableBroadcast) ? 1 : 0;
        }

        void Connection::resetSockAddr() {
            memset(&socket_address, 0, sizeof(socket_address));
        }

        bool Connection::openSocket() {
            socket_fd = socket(socket_address.sin_family, SOCK_DGRAM, 0);
            return socket_fd != -1;
        }

        void Connection::closeSocket() {
            close(socket_fd);
            isConnected = false;// TODO: fix isConnected to some proper way of knowing the state of the connection
        }

        bool Connection::connectSocket() {
            return connect(socket_fd, (sockaddr *) &socket_address, sizeof(socket_address)) != -1;
        }

        bool Connection::setBroadcastOption() {
            return setsockopt(socket_fd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof(broadcast)) != -1;
        }

        void Connection::sendStream(const uint8_t * stream, const uint16_t length) {
            // TODO: handle cases where send() does not send enough bytes
            if(send(socket_fd, stream, (size_t) length, 0) == -1) {
                std::cerr << "Error: could not send stream" << std::endl;
            }
        }

        void Connection::receiveStream() {
            // TODO: handle cases where recv() does not return enough bytes
            if(recv(socket_fd, buffer, BUFFER_SIZE, 0) == -1) {
                std::cerr << "Error: could not receive stream" << std::endl;
            }
        }

        void Connection::setPort(uint16_t port) {
            socket_address.sin_port = htons(port);
        }

        void Connection::setIp(const char * ip) {
            socket_address.sin_addr.s_addr = inet_addr(ip);
        }

        bool Connection::Connect() {
            // TODO: create a nice interface with error handling to connect
            if(!isConnected) {
                if (openSocket()) {
                    if(broadcast) {
                        if(!setBroadcastOption()) {
                            std::cerr << "Error: could not set broadcast option" << std::endl;
                        }
                    }
                    if (connectSocket()) {
                        isConnected = true;
                    } else {
                        std::cerr << "Error: could not connect" << std::endl;
                    }
                } else {
                    std::cerr << "Error: could not open socket" << std::endl;
                }
            }
            return isConnected;
        }

        bool Connection::Reconnect() {
            closeSocket();
            return Connect();
        }

        const uint8_t * Connection::Send(const uint8_t * stream, const uint16_t length) {
            if(!Connect()) return buffer;

            sendStream(stream, length);
            if(!broadcast) {
                receiveStream();
            }

            return buffer;
        }
    }
}