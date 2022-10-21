#include "inverted_index.h"

/* */
int insert_at_last_file (file_node_t** head, char* f_name)
{
	file_node_t* new = (file_node_t*) malloc (sizeof (file_node_t));	//Dynamic Memory allocation for adding the new File name into the File LL.
	if (new == NULL)	//Error Handling.
		return FAILURE;

	strncpy (new->f_name, f_name, (strlen (f_name) + 1));	//Copy the File name into the New node Data.
	new->link = NULL;	//Update the New node Link as NULL.

	if (*head == NULL)	//If the File LL is empty, make the New node as the Head of the File LL.
	{
		*head = new;
		return SUCCESS;
	}

	file_node_t* temp = *head;
	while (temp->link != NULL)	//Traverse to insert the New node at the end of LL.
	{
		temp = temp->link;	//Update the 'temp' to point to the Next node.
	}

	temp->link = new;	//Update the Last node pointer to point to the New node.

	return SUCCESS;
}

/* */
int insert_at_last_main (main_node_t** head, char* word, char* f_name)
{
	main_node_t* new = (main_node_t*) malloc (sizeof (main_node_t));
	if (new == NULL)
		return FAILURE;

	strncpy (new->word, word, (strlen (word) + 1));
	new->link = NULL;
	new->sub_link = create_sub_node (f_name);
	new->f_count = 1;

	if (*head == NULL)
	{
		*head = new;
		return SUCCESS;
	}

	main_node_t* temp = *head;
	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	temp->link = new;

	return SUCCESS;
}

/* */
sub_node_t* create_sub_node (char* f_name)
{
	sub_node_t* new = (sub_node_t*) malloc (sizeof (sub_node_t));
	strncpy (new->f_name, f_name, (strlen (f_name) + 1));
	new->w_count = 1;
	new->link = NULL;
	return new;
}
