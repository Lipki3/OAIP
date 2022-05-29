#include "Header.h"


void clear(struct bank** head, struct bank** tail)
{
	while (*head != NULL)
	{
		struct bank* temp;
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*tail = *head;
}

void alignment(struct bank* client) {
	client->surname[strlen(client->surname) - 1] = '\0';
	if (client->flag == 1)
		client->info.account[strlen(client->info.account) - 1] = '\0';
	client = client->next;
}