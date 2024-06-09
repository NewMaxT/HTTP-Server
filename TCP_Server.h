/* Maxence Goutteratel
 * GitHub: @NewMaxT
 * 
 * 6/9/2024
 * 
 * TCP_Server.h
 */

#ifndef HTTP_SERVER_TCP_SERVER_H
#define HTTP_SERVER_TCP_SERVER_H

#ifdef __linux__
    #include "socket.h"
    //TODO: Linux support needs to be implemented
#elif _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <cstdio>
    #include <stdexcept>
    #pragma comment(lib, "ws2_32.lib")
#endif

#define DEFAULT_PORT "80"

namespace server {
    class TCP {
    public:
        TCP() = default;
        ~TCP() = default;
        void Start();
        void Close();
    private:
        struct addrinfo *addr_info_result = nullptr, *ptr = nullptr, addr = addrinfo();
        SOCKET m_socket = INVALID_SOCKET;
        WSAData m_wsaData = WSAData();
    };
}

#endif //HTTP_SERVER_TCP_SERVER_H
