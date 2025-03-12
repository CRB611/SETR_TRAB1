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
#include <stdio.h>


/**
 * \struct Element 
 * \brief Struct for elements
 */
typedef struct Element {
    uint16_t key; /**< The key associated with the element */
    uint8_t data[MAX_ELEM_SIZE]; /**< The data stored in the element */
    struct Element* Next; /**< Pointer to the next element */
    struct Element* Previous; /**< Pointer to the previous element */
} Element;

/**
 * \struct MyDLL
 * \brief A structure representing a DLL.
 */
typedef struct MyDLL {
    Element Elements[MAX_LIST_SIZE]; /**< Array of Elements in the list */
    Element* Head; /**< Pointer to the head of the list */
    Element* Tail; /**< Pointer to the tail/END of the list */
    int size; /**< Size of the list real time */
} MyDLL;

/**
 * \brief Initializes a DLL 
 * \param dll Pointer to the DLL
 */
void MyDLLInit();

/**
 * \brief Adds an element to the DLL
 * \param elem element to be added
 * \param dll list where the element will be added
 * \return 1 if success, 0 in case of error
 */
int MyDLLInsert(Element elem,MyDLL *dll);

/**
 * \brief Removes an element of the DLL
 * \param key key of the element to be removed
 */
int MyDLLRemove(uint16_t key);

/**
 * \brief returns the data of an element identified by its key, or error if it does not exist
 * \param key key of the element
 */
Element* MyDLLFind(uint16_t key);

/**
 * \brief retutns the data of the next element of the list, or error if it does not exist
 */
Element* MyDLLFindNext();

/**
 * \brief returns the data of the previous element of the list, or error if it does not exist
 */
Element* MyDLLFindPrevious();
