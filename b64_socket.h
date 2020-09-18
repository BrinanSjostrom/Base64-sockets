#ifndef _B64_SOCKET_H_
#define _B64_SOCKET_H_

#include <stdlib.h>
#include <string.h>
#include "sock_macros.h"
#include "base64.h"

char *b64_recv(SOCKET s, size_t, size_t*);
int b64_send(SOCKET s, char*, size_t);

#endif
