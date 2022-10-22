#include "inverted_index.h"

int search_DB (main_node_t **head, char *word)
{
	int index = get_key (word [0]);	//To get the Key for the given 'word'.

	int ret = check_word (word, head [index]);	//To check if the given 'word' is present at the calculated Key in the Database.
	if (ret == REPEATED)	//If the Word is present in the Database, the 'ret' will have the value of REPEATED.
	{
		printf ("Word \"%s\" is present in the Database:\n", word);
		display (head [index], index);	//Display the Word & File details stored in the Database for the given 'word'.
		return SUCCESS;
	}
	else	//If the Word is not present in the Database, the 'ret' will have the value of FAILURE.
	{
		printf ("Word \"%s\" is not present in the Database.\n", word);
		return FAILURE;
	}
}
