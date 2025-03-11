/**
 * \file MyDLL.h
 * \brief This file contains all the structures and functions needed for the database creation.
 *
 * This file provides the necessary structures and functions to work with a doubly linked list-based database.
 * 
 * \author Simão Ribeiro
 * \author Celina Brito
 * \date 10/3/2024
 * \bug There are no known bugs.
 *
 * \defgroup MyDLL MyDLL
 * \brief Functions and structures for working with a doubly linked list-based database.
 * @{
 */
#define MAX_ELEM_SIZE 50
#define MAX_LIST_SIZE 4
#include <stdint.h>


/**
 * @brief brief description of elem typedef struct.
 * 
 *
 * Then it may follow a detailed explanation of the elem structure.
 */
typedef struct MyDLL {
    uint16_t key; /**< The key associated with the element */
    uint8_t data[MAX_ELEM_SIZE]; /**< The data stored in the element */
    struct MyDLL* Next; /**< Pointer to the next element */
    struct MyDLL* Previous; /**< Pointer to the previous element */
} MyDLL;

/**
 * \struct DLL_List
 * \brief A structure representing a DLL.
 */
typedef struct MyDLL_List {
    MyDLL Elements[MAX_LIST_SIZE]; /**< Array of Elements in the list */
    MyDLL* Head; /**< Pointer to the head of the list */
    MyDLL* Tail; /**< Pointer to the tail/END of the list */
    int size; /**< Size of the list real time */
} DLL_List;

/**
 * \brief Initializes a DLL 
 * \param dll Pointer to the DLL
 */
void MyDLLInit();

/**
 * \brief Adds an element to the DLL
 * \param el element to be added
 */
int MyDLLInsert();

/**
 * \brief Removes an element of the DLL
 * \param key key of the element to be removed
 */
int MyDLLRemove(uint16_t key);

/**
 * \brief retutns the data of an element identified by its key, or error if it does not exist
 * \param key key of the element
 */
int MyDLLFind();

/**
 * \brief \brief retutns the data of the next element of the list, or error if it does not exist
 */
int MyDLLFindNext();

/**
 * \brief returns the data of the previous element of the list, or error if it does not exist
 */
int MyDLLFindPrevious();
