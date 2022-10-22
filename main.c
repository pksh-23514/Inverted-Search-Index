#include "inverted_index.h"

int main (int argc, char* argv [])
{	
	file_node_t* files_H = NULL;
	main_node_t* HT [SIZE] = {NULL};
	int ret;

	if (argc < 2)
	{
		printf ("ERROR: Invalid number of Arguments.\n");
		printf ("INFO: Usage ./inverted_index <file.txt> <file1.txt> ...\n");
	}
	else
	{
		validate_n_store_filenames (&files_H, argv);

		file_node_t* temp = files_H;
		while (temp != NULL)
		{
			printf ("File: %s\n", temp->f_name);
			temp = temp->link;
		}

		ret = create_DB (files_H, HT);
		if (ret == SUCCESS)
		{
			ret = display_DB (HT);
			printf ("INFO: Successful Creation.\n");
		}
/*
		char word [BUFF_SIZE];
		printf ("Enter the word to be searched: ");
		scanf ("%s", word);
		ret = search_DB (HT, word);
		if (ret == SUCCESS)
		{
			printf ("INFO: Search Successful.\n");
		}
*/
		char f_name [NAMELENGTH];
		printf ("Enter the File Name to be Updated in the Database: ");
		scanf ("%s", f_name);
		ret = update_DB (&files_H, HT, f_name);
		if (ret == SUCCESS)
		{
			ret = display_DB (HT);
			printf ("INFO: Update Successful.\n");
		}
		//Call the process function.
	}

	return 0;
}


