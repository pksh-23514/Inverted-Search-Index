#include "inverted_index.h"

int display_DB (main_node_t **head)
{
	int i = 0;

	while (i < SIZE)
	{
		main_node_t* temp1 = head [i];
		if (temp1 != NULL)
		{
			while (temp1 != NULL)
			{
				printf ("[%d]\t", i);
				printf ("[%s]\t", temp1->word);
				printf ("%d File(s):\t", temp1->f_count);
				
				sub_node_t* temp2 = temp1->sub_link;
				while (temp2 != NULL)
				{
					printf ("File: %s\t", temp2->f_name);
					printf ("%d time(s) ", temp2->w_count);

					temp2 = temp2->link;

					if (temp2 != NULL)
						printf (": ");
				}

				printf ("-> NULL\n");

				temp1 = temp1->link;
			}
		}

		i += 1;
	}

	return SUCCESS;
}
