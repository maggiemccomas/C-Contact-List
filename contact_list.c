
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "contact_list.h"
# include "utils.h"

/*
* A C program that implements an array of linked lists making up the contacts
* for each letter of the alphabet and the associated functions for the list.
* Maggie McComas
*/

static CONTACT_T *linked_list[26]; 

/*
* Purpose: initializes each list in the bucket list to NULL
* Input: none
* Output: none
*/
void init_contact_list (void){
    int i;

    for (i = 0; i < 26; i++)
    {
        linked_list[i] = NULL;
    }
}

/*
* Purpose: inserts a contact to correct position in array of linked list
* Input: CONTACT_T *contact
* Output: none
*/
void insert_contact (CONTACT_T *contact){
    char lastname_letter = contact->last_name[0];
    int index = lastname_letter - 'A';
    
    if (linked_list[index] == NULL)
    {
        linked_list[index] = contact;
    }
    else
    {
        CONTACT_T *current = linked_list[index];
        CONTACT_T *next = current->next;
        int inserted = FALSE;

        if (strcmp(current->last_name, contact->last_name) > 0)
        {
            contact->next = current;
            linked_list[index] = contact;
            inserted = TRUE;
        }

        while (next != NULL && inserted == FALSE)
        {
            if (strcmp(next->last_name, contact ->last_name) > 0)
            {
                contact->next = next;
                current->next = contact;
                inserted = TRUE;
            }

            current = next;
            next = current->next;
        }

        if (inserted == FALSE)
        {
            current->next = contact;
            inserted = TRUE;
        }
    }
}

/*
* Purpose: prints the contacts in the bucket list until reaches no node
* Input: char mode
* Output: none
*/
void print_contact_list (char mode){
    int i;
    CONTACT_T *current; 

    for (i = 0; i < 26; i++)
    {
        current = linked_list[i];

        while (current != NULL)
        {
            print_contact(current, mode);
            current = current->next;
        }
    }

    printf("\n");
}

/*
* Purpose: uses given input last_name to find correct bucket and 
* returns pointer to correct node
* Input: NAME_T last_name and NAME_T first_name
* Output: CONTACT_T *result
*/
CONTACT_T *find_contact (NAME_T last_name, NAME_T first_name){
    char lastname_letter = last_name[0];
    int index = lastname_letter - 'A';
    char copy_first[15];
    char copy_last[15];

    CONTACT_T *current = linked_list[index];
    CONTACT_T *result = NULL;

    while (current != NULL && result == NULL)
    {
        strcpy(copy_last, current->last_name);
        upper(copy_last);

        strcpy(copy_first, current->first_name);
        upper(copy_first);

        if (strcmp(copy_first, first_name) == 0 && strcmp(copy_last, last_name) == 0)
        {
            result = current;
        }

        current = current->next;
    }

    return result;
}

/*
* Purpose: if the current pointer is NULL it will set the pointer to 
* first element in correct bucket and returns the next element in the list 
* from the array
* Input: char letter
* Output: CONTACT_T *curr
*/
CONTACT_T *get_next_contact (char letter){
    static CONTACT_T *curr = NULL;

    int index = letter - 'A';
    
    if(curr == NULL)
    {
        curr = linked_list[index];
    }

    else
    {
        curr = curr->next; 
    }

    return curr; 
}

/*
* Purpose: Prints all contacts with matching state in the given mode
* Input: char state [] and char mode
* Output: none
*/
void print_state_contacts (char state [], char mode){
    int i;
    CONTACT_T *current; 

    char copy_state[3];
    int printed = FALSE;

    for (i = 0; i < 26; i++)
    {
        current = linked_list[i];
        while (current != NULL)
        {
            strcpy(copy_state, current->state);
            upper(copy_state);
            if (strcmp(copy_state, state) == 0)
            {
                print_contact(current, mode);
                printed = TRUE;
            }
            current = current->next;
        }
    }

    if (printed == FALSE)
    {
        printf("No contacts found\n");
    }
}

/*
* Purpose: deallocates space for all nodes in each bucket list
* Input: none
* Output: none
*/
void free_contact_list (void){
    int i;
    CONTACT_T *current; 
    CONTACT_T *next;

    for (i = 0; i < 26; i++)
    {
        current = linked_list[i];
       
        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }
    }
}
