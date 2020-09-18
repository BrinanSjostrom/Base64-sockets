#include "b64_socket.h"

char *b64_recv(SOCKET s, size_t buffer_size, size_t *out_size)
{
	int size = 1;
	char *recved_str = (char*)malloc(size);

	while( 1 )
	{
		int break_from_while = 0;
		char buffer[buffer_size];
		recv(s, buffer, buffer_size, 0);
		for(int i = 0; i < buffer_size; i++)
		{
			if( buffer[i] == '\0' )
			{
				size++;
				recved_str = (char*)realloc(recved_str, size);
				recved_str[size - 1] = '\0';
				break_from_while = 1;
				break;
			}
			size++;
			recved_str = (char*)realloc(recved_str, size);
			recved_str[size - 2] = buffer[i];
		}
		if(break_from_while)
			break;
	}
	char *decoded_recved_str = b64_decode(recved_str, strlen(recved_str), out_size);
return decoded_recved_str;
}


int b64_send(SOCKET s, char *sent_str, size_t in_size)
{
	size_t out_size;
	char *encoded_sent_str = b64_encode(sent_str, in_size, &out_size);
	send(s, encoded_sent_str, out_size + 1, 0);
return 0;
}
