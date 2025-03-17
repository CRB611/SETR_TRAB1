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


int MyDLLInsert(uint16_t key, uint8_t* data, MyDLL *dll){
    
    //check if size doesnt exceed
    if (dll->size >= MAX_LIST_SIZE)
    {
        printf("The max number of elements (%d) was exceeded.\n",MAX_LIST_SIZE);
        return 0;
    }
       
    Element* elem =NULL;

    for (int i = 0; i < MAX_LIST_SIZE; i++)
    {
        if (dll->Elements[i].key==key)
        {
            printf("The chosen key(%d) already exists.\n",key);
            return 0;
        }else if (dll->Elements[i].key==0){
            elem =&dll->Elements[i];
        }
    }  

    elem->key=key;
    for (int i = 0; i < MAX_ELEM_SIZE; i++)
    {
        elem->data[i]=data[i];
    }

    if (dll->size == 0){
        dll->Head = elem;
        dll->Tail =elem; 
    }else{
        dll->Tail->Next = elem;
        elem->Previous =dll->Tail;
        elem->Next =NULL;
        dll->Tail= elem;
    }
    dll->size++;
    return 1;
}

int MyDLLRemove(uint16_t key, MyDLL* dll){

    if( dll->Head == NULL){
        printf("The list is already empty\n");
        return 0;
    }

    //temporary element
    Element *curr= dll->Head;

    //go through the list
    int i=0;
    for (int i = 1; curr !=NULL; i++)
    {
        curr=curr->Next;
    }
    
    
    //key out of bounds
    if (curr == NULL){
        printf("The given key(%d) is out of bounds\n",key);
        return 0;
    }else if( i != key){    //key not on list
        printf("The given key(%d) isn't on the list\n",key);
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
        return NULL ; 
    }

    return curr->Previous;    

}

void MyDLLPrint(MyDLL* dll){

    Element* curr = dll->Head;

    if (curr==NULL)
    {
        printf("the list is empty\n");
    }else{
        printf("DLL start\n");
        //go through the list
        while (curr!=NULL){
            printf("%d\n%s\n---------------\n",curr->key,curr->data);
            curr=curr->Next;
        }
        printf("DLL end\n");
    }
}