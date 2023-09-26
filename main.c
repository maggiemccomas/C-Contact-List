
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
#include "contact_list.h"
#include "contact.h"

/*
* A C program that implements a contact list and associated functions.
* Maggie McComas
*/

// Function prototypes

/*
* Purpose: Opens filename for processing, gets rid of the header, scans each contact
* and returns their info to be placed in contact list. 
* Dependent: contact -> *create_contact(CONTACT_T *contact) and
* contact_list -> insert_contact
* Input: char *filename
* Output: none
*/
void process_file(char *filename);

/*
* Purpose: Prompts user with menu until valid option is entered
* Input: none
* Output: char valid_option
*/
char print_menu(void);

/*
* Purpose: Prompts user with format menu and returns option entered
* Input: none
* Output: char option
*/
char print_format_menu(void);

/*
* Purpose: Prompts for last and first name and finds and prints the contact or
* prints that the contact was not found
* Dependent: contact_list -> *find_contact (NAME_T last_name, NAME_T first_name) and
* contact -> print_contact(CONTACT_T *contact, char mode)
* Input: char mode
* Output: none
*/
void find_individual(char mode);

/*
* Purpose: Prompts for two-letter state and prints the contacts who live in
* the specified state
* Dependent: contact_list -> print_state_contacts (char state [], char mode)
* Input: char mode
* Output: none
*/
void process_state_contacts(char mode);

/*
* Purpose: Prompts for tab letter and either prints all the contacts with the last name begining
* with inputed letter or prints that no contacts were found with given last name
* Dependent: contact_list -> *get_next_contact (char letter) and 
* contact -> print_contact(CONTACT_T *contact, char mode)
* Input: char mode
* Output: none
*/
void print_tab(char mode);


/*
* Purpose: Declares mode, checks command line argument and makes sure file is specified or else
* exits program. If file called inilialized data and prints out all the contacts from the file
* after prints menu and calls the appropriate function for each input until q is entered and 
* then frees contact list and exits program.
* Dependent: exit(), process_file(), print_menu(), contact_list -> init_contact_list (void),
* print_contact_list (char mode), and  and free_contact_list()
* Input: int argc, char *argv []
* Output: none
*/
int main(int argc, char *argv[])
{
    char mode = 'C';
    char option = 'C';

    if (argc != 2)
    {
        printf("\n Error: No file input\n");
        exit(EXIT_FAILURE);
    }

    init_contact_list();
    process_file(argv[1]);
    print_contact_list(mode);

    do
    {
        option = print_menu();

        switch (option)
        {
        case 'C':
            mode = print_format_menu();
            break;
        case 'I':
            find_individual(mode);
            break;
        case 'T':
            print_tab(mode);
            break;
        case 'S':
            process_state_contacts(mode);
            break;
        default:
            option = 'Q';
        }

    } while (option != 'Q');

    free_contact_list();
    exit(EXIT_SUCCESS);
}

void process_file(char *filename)
{

    CONTACT_T local_contact;
    CONTACT_T *contact_pointer;
    FILE *file_pointer;

    file_pointer = fopen(filename, "r");
    fscanf(file_pointer, "%*s ");

    while (fscanf(file_pointer, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%s ", local_contact.first_name, local_contact.last_name, local_contact.co_name, local_contact.addr, local_contact.city, local_contact.county, local_contact.state, local_contact.zip, local_contact.phone1, local_contact.phone2, local_contact.email, local_contact.web) == 12)
    {
        contact_pointer = create_contact(&local_contact);
        insert_contact(contact_pointer);
    }

    fclose(file_pointer);
}

char print_menu(void)
{

    char input_string[10];
    char valid_string[6] = {'C', 'I', 'T', 'S', 'Q', '\0'};
    int i;
    int length_validity = TRUE;
    int letter_validity = FALSE;

    printf("\nPlease select one of the following:\n");
    printf("\n c Change output format\n");
    printf(" i Search for individual\n");
    printf(" t Print tab\n");
    printf(" s Look up by state\n");
    printf(" q Quit\n");
    printf("\nOption: ");
    scanf("%s", input_string);

    char input = input_string[0];
    upper(&input);

    if (strlen(input_string) != 1)
    {
        length_validity = FALSE;
    }

    for (i = 0; i < strlen(valid_string); i++)
    {
        if (valid_string[i] == input)
        {
            letter_validity = TRUE;
        }
    }

    if (length_validity == FALSE || letter_validity == FALSE)
    {
        do
        {

            printf("%s\n", input_string);
            printf("\nInvalid option entered\n");

            printf("\nPlease select one of the following:\n");
            printf("\n c Change output format\n");
            printf(" i Search for individual\n");
            printf(" t Print tab\n");
            printf(" s Look up by state\n");
            printf(" q Quit\n");
            printf("\nOption: ");
            scanf("%s", input_string);

            input = input_string[0];
            upper(&input);

            length_validity = TRUE;
            letter_validity = FALSE;

            if (strlen(input_string) != 1)
            {
                length_validity = FALSE;
            }

            for (i = 0; i < strlen(valid_string); i++)
            {
                if (valid_string[i] == input)
                {
                    letter_validity = TRUE;
                }
            }

        } while (length_validity == FALSE || letter_validity == FALSE);
    }

    switch (input)
    {
    case 'C':
        printf("%c\n", input_string[0]);
        break;
    case 'I':
        printf("%c\n", input_string[0]);
        break;
    case 'T':
        printf("%c\n", input_string[0]);
        break;
    case 'S':
        printf("%c\n", input_string[0]);
        break;
    default:
        printf("%c\n", input_string[0]);
    }
    return input;
}

char print_format_menu(void)
{

    char option;
    char input[2];

    printf("\nPlease select one of the following:\n");
    printf("\n c Condensed output information\n");
    printf(" f Full output information\n");
    printf("\nOption: ");
    scanf("%s", input);

    printf("%s\n", input);
    option = input[0];
    upper(&option);

    return option;
}

void find_individual(char mode)
{
    char last_name[15];
    char first_name[15];
    CONTACT_T *result;

    printf("\nPlease enter last name: ");
    scanf("%s", last_name);
    printf("%s\n", last_name);
    printf("Please enter first name: ");
    scanf("%s", first_name);
    printf("%s\n", first_name);
    
    upper(first_name);
    upper(last_name);

    printf("\n");

    result = find_contact(last_name, first_name);
    
    if (result == NULL)
    {
        printf("Contact not found\n");
    }
    else
    {
        print_contact(result, mode);
    }
}


void print_tab(char mode)
{
    char letter;
    char input[2];
    CONTACT_T *result;

    printf("\nPlease enter last name tab letter: ");
    scanf("%s", input);
    printf("%s\n", input);

    letter = input[0];
    upper(&letter);

    printf("\n");

    result = get_next_contact(letter);

    if (result == NULL)
    {
        printf("No contacts found\n");
    }
    else
    {
        while (result != NULL)
        {
            print_contact(result, mode);
            result = get_next_contact(letter);
        }
    }
}

void process_state_contacts(char mode)
{
    char state[3];

    printf("\nPlease enter two-letter state abbreviation: ");
    scanf("%s", state);
    printf("%s\n", state);
    upper(state);

    printf("\n");

    print_state_contacts(state, mode);
}