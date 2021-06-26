#pragma once

#ifdef __WIN32

#ifndef WINVER
#define WINVER 0x0A00                   //  for example inet_ntop and inet_pton requires windows version > 0x0600
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0A00
#endif

#include <winsock2.h>                   //  Base windows network lib
#include <ws2tcpip.h>                   //  tcp/ip lib
#include <iphlpapi.h>               

#pragma comment(lib, "ws2_32.lib")     // In MinGW use -lws2_32
#pragma comment(lib, "iphlpapi.lib")   // In MinGW use -lws2_32

#define WSA_VERSION MAKEWORD(2, 2)      //  Wsa dll version

#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
#define CLOSESOCKET(s) closesocket(s)
#define GETSOCKETERRNO() (WSAGetLastError())

#else

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define ISVALIDSOCKET(s) ((s) >= 0)
#define CLOSESOCKET(s) close(s)
#define GETSOCKETERRNO() (errno)
#define SOCKET int

#endif

#include <stdlib.h>                     //  I/O
#include <stdio.h>


