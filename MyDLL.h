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

typedef struct MyDLL{
    uint16_t key;
    

}MyDLL;

void MyDLLInit();

int MyDLLInsert();

int MyDLLRemove();

int MyDLLFind();

int MyDLLFindNext();

int MyDLLFindPevious();
