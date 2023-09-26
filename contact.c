
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "contact.h"

/*
* A C program that includes functions to create contacts in the linked list and 
* print contacts in either condensed or full mode from the linked list.
* Maggie McComas
*/

/*
* Purpose: Dynamically allocates memory for new contact node and copies all 
* field data from input contact to newly allocated node
* Input: CONTACT_T *contact
* Output: returns *contact_ptr
*/
CONTACT_T *create_contact(CONTACT_T *contact)
{

    CONTACT_T *contact_ptr;

    contact_ptr = malloc(sizeof(CONTACT_T));

    strcpy(contact_ptr->first_name, contact->first_name);
    strcpy(contact_ptr->last_name, contact->last_name);
    strcpy(contact_ptr->co_name, contact->co_name);
    strcpy(contact_ptr->addr, contact->addr);
    strcpy(contact_ptr->city, contact->city);
    strcpy(contact_ptr->county, contact->county);
    strcpy(contact_ptr->state, contact->state);
    strcpy(contact_ptr->zip, contact->zip);
    strcpy(contact_ptr->phone1, contact->phone1);
    strcpy(contact_ptr->phone2, contact->phone2);
    strcpy(contact_ptr->email, contact->email);
    strcpy(contact_ptr->web, contact->web);
    contact_ptr->next = NULL;

    return contact_ptr;
}

/*
* Purpose: print contact information in condensed or full mode
* Input: CONTACT_T *contact and char mode
* Output: none
*/
void print_contact(CONTACT_T *contact, char mode)
{
    if (mode == 'C')
    {
        printf("%-15s        %-15s              %-15s   %-35s\n", contact->last_name, contact->first_name, contact->phone1, contact->email);
    }

    else
    {
        printf("Name:    %s %s\n", contact->first_name, contact->last_name);
        printf("Address: %s, %s, %s %s  (%s County)\n", contact->addr, contact->city, contact->state, contact->zip, contact->county);
        printf("Phone:   %s (primary)  %s\n", contact->phone1, contact->phone2);
        printf("email:   %s\n", contact->email);
        printf("web:     %s\n", contact->web);
        printf("\n");
    }
}
