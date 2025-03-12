/**
 * \file MyDLL.h
 * \brief This file contains all the structures and functions needed for the Doubly linked list creation.
 *
 * This module is responsible for the creation and managemente of a Doubly linked list (DLL), it has functions to create the list, to add,
 * remove and locate elements of the list, as well as functions to move through the list.
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
int MyDLLInsert(Element *elem, MyDLL *dll);

/**
 * \brief Removes an element of the DLL
 * \param key key of the element to be removed
 * \param dll list where the element will be removed
 * \return 1 if success, 0 in case of error
 */
int MyDLLRemove(uint16_t key, MyDLL *dll);

/**
 * \brief returns the data of an element identified by its key, or error if it does not exist
 * \param key Key of the element
 * \param dll list to seach
 * \return Data of the element, if error NULL
 */
Element* MyDLLFind(uint16_t key, MyDLL *dll);

/**
 * \brief retutns the data of the next element of the list, or error if it does not exist
 */
Element* MyDLLFindNext();

/**
 * \brief returns the data of the previous element of the list, or error if it does not exist
 */
Element* MyDLLFindPrevious();
