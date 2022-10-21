#include "inverted_index.h"

/* */
void validate_n_store_filenames (file_node_t** files_h, char* filenames[])
{
	int i = 1, ret;	

	while (filenames [i] != NULL)	//The loop shall run to Validate each File name passed in the Command Line.
	{
		ret = IsFileValid (filenames [i]);
		if (ret == SUCCESS)		//If the File name is valid, proceed to check if it is repeated or not.
		{
			ret = IsFileDuplicate (filenames [i], files_h);
			if (ret == FAILURE)		//If the File name is not present in the File List; proceed to add it into the File List.
			{
				ret = store_filenames_to_list (filenames [i], files_h);
				if (ret == SUCCESS)		//If the File name is added to the File List successfully, print a confirmation message.
				{
					printf ("Validation of File %s successful\n", filenames [i]);
				}
			}
		}
		i += 1;		//Move to the next File name passed in the Command Line.
	}

	if (*files_h == NULL)	//If no File is added to the File Name List; print an error message and terminate the Operation.
	{
		printf ("ERROR: There is no Valid File passed as Input.\nPlease enter names of Valid Files only.\n");
	}

	return;
}

/* */
int IsFileValid (char* filename)
{
	FILE* fptr = fopen (filename, "r");
	if (fptr == NULL)	//If there is an error in Opening the File or if the File doesn't exists, the particular File cannot be added to the Database.
	{
		printf ("ERROR: The File %s is not present.\nSo, this File cannot be added into the Database.\n", filename);
		return NOT_PRESENT;
	}
	else	//The File is Opened successfully.
	{
		fseek (fptr, 0L, SEEK_END);
		int pos = ftell (fptr);

		if (pos == 0)	//If the File is Empty i.e. the end position of the File is '0'; the particular File cannot be added to the Database.
		{
			printf ("ERROR: The File %s is an Empty File.\nSo, this File cannot be added into the Database.\n", filename);
			return FILE_EMPTY;
		}
		else
		{
			fclose (fptr);		//Close the opened File.
			return SUCCESS;
		}
	}
}

/* */
int IsFileDuplicate (char* filename, file_node_t** head)
{
	file_node_t* temp = *head;

	while (temp != NULL)	//The loop shall run till the end of the File List and compare each File name with the given 'filename'.
	{
		if ((strncmp (filename, temp->f_name, NAMELENGTH)) == 0)	//If the File Name in File List matches with the given 'filename'; it is not required to insert it again.
		{
			printf ("ERROR: The File %s is repeated\nSo, this File cannot be added into the Database.\n", filename);
			return REPEATED;
		}
		
		temp = temp->link;
	}

	return FAILURE;
}

/* */
int store_filenames_to_list (char* f_name, file_node_t** head)
{
	int ret = insert_at_last_file (head, f_name);
	if (ret == FAILURE)		//If the File Name is not added, the process shall terminate.
	{
		printf ("ERROR: Unable to add the File %s into the File List.\n", f_name);
		return FAILURE;
	}
	
	return SUCCESS;
}
