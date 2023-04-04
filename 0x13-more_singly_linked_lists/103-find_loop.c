#include "lists.h"

/**
 * find_listint_loop - find loop in linked list
 * @head: pointer to head pointer of linked list
 * Return: address of node where loop starts
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *banana, *hare;

	/* determine if loop exists by seeing if banana and hare meets */
	/* start them at head, move banana one node and hare two nodes */
	banana = hare = head;

	while (banana != NULL && hare != NULL)
	{
		banana = banana->next;
		hare = hare->next->next;

		if (banana == hare)
		{
			/* start banana at head and hare at address they met */
			/* move banana and hare one node to find loop origin */
			banana = head;
			while (banana != hare)
			{
				banana = banana->next;
				hare = hare->next;
			}
			return (banana);
		}
	}

	return (NULL);
}
