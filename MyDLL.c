#include "MyDLL.h"


void MyDLLInit(){


    
}

int MyDLLInsert(Element *elem, MyDLL *dll){
    //insert in beginning
    if (elem->key == 1){
        elem->Next= dll->Head;

        //DLL not empty
        if(dll->Head != NULL){
            dll->Head->Previous =elem;
        }

        dll->Head=elem;
        return 0;
    }

    //insert in the middle of the list

    Element *curr = dll->Head;

    //go through the list
    for (int i; i < elem->key - 1 && curr != NULL; i++){
        curr=curr->Next;
    }

    //if position out of bounds -> error
    if(curr == NULL){
        printf("Position out of bounds.\n");
        //talvez por um free aqui?
        return 0;
    }

    elem->Previous=curr;

    elem->Next= curr->Next;

    curr->Next = elem;

    // if new elem is not the last, update the prev of the next
    if (elem->Next != NULL){
        elem->Next->Previous=elem->Next;
    }
    
    return 1;
}


int MyDLLRemove(uint16_t key, MyDLL *dll){

    if( dll->Head == NULL){
        printf("The list is already empty");
        return 0;
    }

    //temporary element
    Element *curr= dll->Head;

    //go through the list
    for (int i; 1 > key && curr != NULL; i++){
        curr=curr->Next;
    }
    
    //key out of bounds
    if (curr=NULL){
        printf("The given key is out of bounds");
        return 0;
    }

    //update prev element next pointer
    if (curr->Previous !=NULL){
        curr->Previous->Next = curr->Next;
    }

     //update next element prev pointer
    if (curr->Next !=NULL){
        curr->Next->Previous = curr->Previous;
    }

    //if the element is the head
    if (dll->Head =curr){
        dll->Head=curr->Next;
    }
    
    return 1;
}


MyDLL* MyDLLFind(uint16_t key){

}


MyDLL*MyDLLFindNext(){

}


MyDLL* MyDLLFindPrevious(){

}
