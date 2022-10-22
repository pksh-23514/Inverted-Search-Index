#include "inverted_index.h"

int display_DB (main_node_t** head)
{
	int i = 0;

	while (i < SIZE)	//The loop shall run to go through the Complete Database and print each Word in each File.
	{
		if (head [i] != NULL)	//If the particular Key has no words, then that Key shall be ignored.
		{
			display (head [i], i);
		}

		i += 1; //Update the Key value to go to the next Word in the List.
	}

	return SUCCESS;
}

void display (main_node_t* temp1, int index)
{
	while (temp1 != NULL)	//The loop shall run till we reach the end of the Word List.
	{
		printf ("[%d]\t", index);
		printf ("[%-10s]\t", temp1->word);
		printf ("%d File(s):\t", temp1->f_count);
				
		sub_node_t* temp2 = temp1->sub_link;
		while (temp2 != NULL)	//The loop shall run till we reach the end of the Sub-List.
		{
			printf ("File: %s\t", temp2->f_name);
			printf ("%d time(s)\t", temp2->w_count);

			temp2 = temp2->link;	//Update the 'temp2' to point to the Next node.

			if (temp2 != NULL)	//If we have not reached the end of the List, then print the Separator.
			printf (":\t");
		}
		
		printf ("-> NULL\n");	//Signifies the end of the Sub-List.
		temp1 = temp1->link;	//Update the 'temp1' to point to the Next node.
	}
}
