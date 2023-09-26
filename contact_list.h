
# include "contact.h"

/*
* A header file that includes function prototypes for contact_list.c
* Maggie McComas
*/

# ifndef CONTACT_LIST_H

//  Function prototypes

/*
* Purpose: initializes each list in the bucket list to NULL
* Input: none
* Output: none
*/
void init_contact_list (void);

/*
* Purpose: inserts a contact to correct position in array of linked list
* Input: CONTACT_T *contact
* Output: none
*/
void insert_contact (CONTACT_T *contact);

/*
* Purpose: uses given input last_name to find correct bucket and 
* returns pointer to correct node
* Input: NAME_T last_name and NAME_T first_name
* Output: CONTACT_T *contact_pointer
*/
CONTACT_T *find_contact (NAME_T last_name, NAME_T first_name);

/*
* Purpose: if the current pointer is NULL it will set the pointer to 
* first element in correct bucket and returns the next element in the list 
* from the array
* Input: char letter
* Output: CONTACT_T *contact_pointer
*/
CONTACT_T *get_next_contact (char letter);

/*
* Purpose: prints the contacts in the bucket list until reaches no node
* Input: char mode
* Output: none
*/
void print_contact_list (char mode);

/*
* Purpose: Prints all contacts with matching state in the given mode
* Input: char state [] and char mode
* Output: none
*/
void print_state_contacts (char state [], char mode);

/*
* Purpose: deallocates space for all nodes in each bucket list
* Input: none
* Output: none
*/
void free_contact_list (void);

# endif
