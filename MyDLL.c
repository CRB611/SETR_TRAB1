#include "MyDLL.h"


void MyDLLInit(MyDLL* dll){
    dll->size=0;
    dll->Tail=NULL;
    dll->Head=NULL;
    for (int i = 0; i < MAX_LIST_SIZE; i++)
    {
        dll->Elements[i].key = 0;
    }  
}


int MyDLLInsert(Element *elem, MyDLL *dll){
    //insert in beginning
    if (elem->key == 1){
        elem->Next= dll->Head;

        //DLL not empty
        if(dll->Head != NULL){
            
            //verify if the key is unique
            if (dll->Head->key == 1){
                perror("that key is already exists");
                return 0;
            }

            dll->Head->Previous =elem;
            
        }

        dll->Head=elem;
        return 1 ;
    }

    //insert in the middle of the list

    Element *curr = dll->Head;

    //go through the list
    for (int i; i < elem->key - 1 && curr != NULL; i++){
        curr=curr->Next;
    }

    //if position out of bounds -> error
    if(curr == NULL){
        perror("Position out of bounds.\n");
        return 0;
    }else if (curr->key == elem->key){  //checking overlapping keys
        perror("that key is already exists");
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
        perror("The list is already empty");
        return 0;
    }

    //temporary element
    Element *curr= dll->Head;

    //go through the list
    int i=0;
    while (i > key && curr != NULL){
        curr=curr->Next;
        i++;
    }
    
    //key out of bounds
    if (curr == NULL){
        perror("The given key is out of bounds");
        return 0;
    }else if( i != key){    //key not on list
        perror("The given key isn't on the list");
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
    if (dll->Head == curr){
        dll->Head=curr->Next;
    }
    
    return 1;
}

Element* MyDLLFind(uint16_t key, MyDLL *dll){
    Element *curr = dll->Head;
    int pos = 0;

    //go through the list
    while (curr != NULL && curr->key != key){
        pos++;
        curr = curr->Next;
    }
    
    //if not present
    if(curr == NULL || curr->key != key)
        return NULL;

    return curr;    
}


Element*MyDLLFindNext(MyDLL* dll, uint16_t key){
Element* curr = MyDLLFind(dll,key);
    if (curr == NULL || curr->Next == NULL )
    {
        printf("Error: Elemnt with key %d not valide or is the last element in the list\n",key);
        return NULL;
    }

    
    return curr->Next;
}


Element* MyDLLFindPrevious(MyDLL* dll, uint16_t key){
Element* curr = MyDLLFind(dll,key);
    if (curr == NULL || curr->Previous == NULL)
    {
        printf("Error: Elemnt with key %d not valide or is the first element in the list\n");
        return NULL; 
    }

    return curr->Previous;    

}
