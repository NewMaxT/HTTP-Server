/* Maxence Goutteratel
 * GitHub: @NewMaxT
 * 
 * 6/9/2024
 * 
 * TCP_Server.cpp
 */

#include "TCP_Server.h"

void server::TCP::Start() {
    if (WSAStartup(MAKEWORD(2,2), &m_wsaData) != 0) {
        printf("Error at socket(): %d\n", WSAGetLastError());
        Close();
        throw std::runtime_error("Error starting WinSock2 API");
    }

    ZeroMemory(&addr, sizeof (addr));
    addr.ai_family = AF_INET;
    addr.ai_socktype = SOCK_STREAM;
    addr.ai_protocol = IPPROTO_IP;
    addr.ai_flags = AI_PASSIVE;

    if (getaddrinfo(nullptr, DEFAULT_PORT, &addr, &addr_info_result) != 0) {
        Close();
        throw std::runtime_error("getaddrinfo error");
    }

    m_socket = socket(addr_info_result->ai_family, addr_info_result->ai_socktype, addr_info_result->ai_protocol);
    if(m_socket == INVALID_SOCKET) {
        printf("Error at socket(): %d\n", WSAGetLastError());
        Close();
        throw std::runtime_error("Invalid socket");
    }

    if(bind(m_socket, addr_info_result->ai_addr, (int) addr_info_result->ai_addrlen) == SOCKET_ERROR) {
        printf("Bind failed with error: %d\n", WSAGetLastError());
        Close();
        throw std::runtime_error("Error binding the socket");
    }

    freeaddrinfo(addr_info_result);
}

void server::TCP::Close() {
    freeaddrinfo(addr_info_result);
    closesocket(m_socket);
    WSACleanup();
}