#ifndef _SOCK_MACROS_H_
#define _SOCK_MACROS_H_



#if defined(_WIN32)
	#ifndef _WIN32_WINNT
		#define _WIN32_QINNT 0x0600
	#endif
	#include <winsock2.h>
	#include <ws2tcpip.h>
	#pragma comment(lib, "ws2_32.lib")
#else
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	#include <netdb.h>
	#include <unistd.h>
	#include <errno.h>
#endif
#if defined(_WIN32)
	#define ISVALIDSOCKET(s) ((s) != INVALID_SOCKET)
	#define CLOSESOCKET(s) closesocket(s)
	#define GETSOCKETEERRNO() (WSAGetLastError())
#else
	#define ISVALIDSOCKET(s) ((s) >= 0)
	#define CLOSESOCKET(s) close(s)
	#define SOCKET int
	#define GETSOCKETERRNO() (errno)
#endif

#define IP "127.0.0.1"
#define PORT "8080"

#endif
