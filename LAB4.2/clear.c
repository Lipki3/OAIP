
#include "Header.h"


void alignment(struct bank* client) {
	client->surname[strlen(client->surname) - 1] = '\0';
	if (client->flag == 1) 
		client->info.account[strlen(client->info.account) - 1] = '\0';
	client = client->next;
}

void clear(struct bank** client)
{
	while (*client != NULL)
	{
		struct bank* temp;
		temp = *client;
		*client = (*client)->next;
		free(temp);
	}
}
