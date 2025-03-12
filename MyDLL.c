#include "MyDLL.h"


void MyDLLInit(){


    
}

int MyDLLInsert(MyDLL *elem, MyDLL_List *dll){
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

    MyDLL *curr = dll->Head;

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


int MyDLLRemove(uint16_t key){

}


MyDLL* MyDLLFind(uint16_t key){

}


MyDLL*MyDLLFindNext(){

}


MyDLL* MyDLLFindPrevious(){

}
