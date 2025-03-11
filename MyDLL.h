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

#include <stdint.h>


/**
 * @brief brief description of elem typedef struct.
 * 
 *
 * Then it may follow a detailed explanation of the elem structure.
 */
typedef struct MyDLL{
    uint16_t key;


}MyDLL;

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
