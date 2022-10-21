#include "inverted_index.h"

/* */
int create_DB (file_node_t* file_head, main_node_t** head)
{
	while (file_head != NULL)	//The loop shall run till all the Files in the File List are read.
	{
		read_datafile (head, file_head->f_name);	//The function call to read all the Words in the particular File.

		file_head = file_head->link;	//Update the 'file_head' to point to the Next node.
	}

	return SUCCESS;
}

/* */
void read_datafile (main_node_t** head, char* f_name)
{
	FILE* fptr = fopen (f_name, "r");
	if (fptr == NULL)	//Error Handling.
		return;

	fseek (fptr, 0L, SEEK_SET);	//To start reading the File from the Beginning.

	char buffer [BUFF_SIZE];	//To store the string read from the File.
	int val;	//To store the return value from the 'fscanf()'.
	int key;	//To store the Key for a particular string.
	int ret;
	
	do
	{
		memset (buffer, '\0', BUFF_SIZE);	//To reset the Buffer with '\0' before reading the next string from the File.
		val = fscanf (fptr, "%s", buffer);

		key = get_key (buffer [0]);		//To calculate the Index in the Hash Table where this string shall be inserted.

		ret = check_word (buffer, head [key]);		//To check if the Word is already present in the Database.
		if (ret == FAILURE)
		{
			ret = insert_at_last_main (&head [key], buffer, f_name);	//To insert the Word in the Database.
			if (ret == FAILURE)		//If the Word is not added, the process shall terminate.
			{
				printf ("ERROR: Unable to add the Word \"%s\" in the Database.\n", buffer);
				return;
			}
		}
		else
		{
			printf ("Repeated Word: %s\n", buffer);
		}
	} while (val != EOF);	//The loop shall run till we reach the End of the File.

	return;
}

int get_key (char f_char)
{
	/* Hash Function for the Hash Table = Data % {65 (Upper-case) or 97 (Lower-case)}
	   If the string is a Special character or Digits; store in the separate Key.
	 */

	if (isalpha (f_char))	//If the First character is an Alphabet; the Key will have a value between 0 to 25.
	{
		f_char = (char) toupper (f_char);
		return (f_char % 65);
	}
	else if (isdigit (f_char))	//If the First character is a Digit; the Key will have a value of 26.
	{
		return 26;
	}
	else	//If the First character is a Special Character; the Key will have a value of 27.
	{
		return 27;
	}
}

/* */
int check_word (char* word, main_node_t* head)
{
	while (head != NULL)	//The loop shall run till all the Words in the List of the Key are compared with 'word'.
	{
		if (strncmp (head->word, word, (strlen (word))) == 0)	//If the Word matches with the exisiting words stored in the List of the Key, it is not required to insert it again.
			return REPEATED;

		head = head->link;	//Update the 'head' to point to the Next node.
	}

	return FAILURE;
}
