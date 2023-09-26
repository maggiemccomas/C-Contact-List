
/*
* A header file that defines types NAME_T and CONTACT_T and includes 
* function prototypes for contact.c
* Maggie McComas
*/

# ifndef CONTACT_H
# define CONTACT_H

// Structure types

typedef char NAME_T[15];

typedef struct CONTACT_T{
    NAME_T first_name;
    NAME_T last_name;
    char co_name[35];
    char addr[35];
    char city[20];
    char county[25];
    char state[3];
    char zip[6];
    char phone1[15];
    char phone2[15];
    char email[35];
    char web[45];
    struct CONTACT_T *next;
} CONTACT_T;

//  Function prototypes

/*
* Purpose: Dynamically allocates memory for new contact node and copies all 
* field data from input contact to newly allocated node
* Input: CONTACT_T *contact
* Output: returns *contact_ptr
*/
CONTACT_T *create_contact (CONTACT_T *contact);

/*
* Purpose: print contact information in condensed or full mode
* Input: CONTACT_T *contact and char mode
* Output: none
*/
void print_contact (CONTACT_T *contact, char mode);

# endif