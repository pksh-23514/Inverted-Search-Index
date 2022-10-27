#include "inverted_index.h"

int main (int argc, char* argv [])
{
	if (argc < 2)	//The number of Arguments passed in Command Line shall be at least 2 (including the Executable File Name).
	{
		printf (RED "ERROR: Invalid number of Arguments.\n" RESET);
		printf (YELLOW "INFO: Usage ./inverted_index <file.txt> <file1.txt> ...\n" RESET);
	}
	else
	{
		command_handler (argv);	//To perform all the Operations regarding the Inverted Search.
	}

	return 0;
}

/* To Call all the Operations related to the Database
 * Input: Command Line Arguments
 * Output: Depending on the Operation selected
 * Return Value: SUCCESS
 */
int command_handler (char* argv [])
{
	file_node_t* files_H = NULL;		//To store the File Names whose Words are present in the Database.
	main_node_t* HT [SIZE] = {NULL};	//To store the Database.
	int ret, option, flag = 0;
	char choice;

	validate_n_store_filenames (&files_H, argv);	//To Validate the File Names passed as CLA and store them in the File List.

	do
	{
		printf ("-----------------------------------------------------------------------\n");
		printf (GREEN "INFO: The List of Operations are as follows:\n1. Create Database\n2. Display Database\n3. Search Database\n4. Update Database\n5. Save Database\n" RESET);
		printf (BLUE "INPUT: Enter the Operation to be performed: " RESET);
		scanf ("%d", &option);		//Ask the User for Operation to be performed.

		switch (option)
		{
			case 1:		/* Create Database Operation for all the Files passed in the Command Line. */
				{
					if (flag == 0)
					{
						ret = create_DB (files_H, HT);
						if (ret == SUCCESS)
						{
							printf (GREEN "INFO: Database Creation Successful.\n" RESET);
						}
						flag = 1;	//To prevent the User from calling the Create Database Operation again.
					}
					else
					{
						printf (RED "ERROR: Create Database Operation can only be called once while passing the Command Line Arguments.\n" RESET);
					}
				}
				break;
			case 2:		/* Display Database Operation for all the Words present. */
				{
					ret = display_DB (HT);
					if (ret == FAILURE)
					{
						printf (YELLOW "INFO: The Database is Empty.\n" RESET);
					}
				}
				break;
			case 3:		/* Search Database Operation for a given Word entered by the User. */
				{
					char word [BUFF_SIZE];
					printf (PURPLE "INPUT: Enter the word to be searched: " RESET);
					scanf ("%s", word);	//To read the Word to be searched in the Database.

					ret = search_DB (HT, word);
					if (ret == SUCCESS)
					{
						printf (GREEN "INFO: Word Search Successful.\n" RESET);
					}
				}
				break;
			case 4:		/* Update Database Operation to fill the Words of a New File in the Database. */
				{
					char f_name [NAMELENGTH];
					printf (PURPLE "INPUT: Enter the File Name to be Updated in the Database: " RESET);
					scanf ("%s", f_name);	//To read the File Name to be updated in the Database.

					ret = update_DB (&files_H, HT, f_name);
					if (ret == SUCCESS)
					{
						printf (GREEN "INFO: Database Update Successful.\n" RESET);
					}
				}
				break;
			case 5:
				{
					char f_name [NAMELENGTH];
					printf (PURPLE "INPUT: Enter the File Name to which the Database will be stored: " RESET);
					scanf ("%s", f_name);	//To read the File Name in which the Current Database needs to be saved.
					
					ret = save_DB (HT, f_name);
					if (ret == SUCCESS)
					{
						printf (GREEN "INFO: Database Store Successful.\n" RESET);
					}
				}
				break;
			default: printf (RED "ERROR: Invalid Choice. Please enter a number between 1 to 5.\n" RESET);
		}

		printf (CYAN "INPUT: Do you want to Continue? [y / Y]: " RESET);
		scanf (" %c", &choice);		//Ask the User for Choice to Continue or not.
	} while ((choice == 'y') || (choice == 'Y'));

	return SUCCESS;
}
