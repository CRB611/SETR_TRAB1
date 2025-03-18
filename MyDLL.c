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
        printf("Error: The max number of elements (%d) was exceeded, so the element \"%s\", %d wasn't added\n",MAX_LIST_SIZE,data,key);
        return 0;
    }
       
    Element* elem =NULL;

    for (int i = 0; i < MAX_LIST_SIZE; i++)
    {
        if (dll->Elements[i].key==key)
        {
            printf("Error: The chosen key (%d) already exists, so the element \"%s\" wasn't added\n",key,data);
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
    printf("The element \"%s\" with the key %d was inserted.\n",data,key);
    return 1;
}

int MyDLLRemove(uint16_t key, MyDLL* dll){

    if( dll->Head == NULL){
        printf("Error: The list is already empty.\n");
        return 0;
    }

    //temporary element
    Element *curr= dll->Head;
    uint8_t tempdata[MAX_ELEM_SIZE];
    //go through the list
    for (int i = 1; curr !=NULL; i++){
        
        if (curr->key==key){
            curr->key=0;
            for (int i = 0; i < MAX_ELEM_SIZE; i++){
                tempdata[i]=curr->data[i];
                }
            break;
        }
        curr=curr->Next;
    }

    //key not on list
    if(curr == NULL){  
        printf("Error: The given key(%d) isn't on the list\n",key);
        return 0;
    }

    //update prev element next pointer
    if(curr->Previous !=NULL){
        curr->Previous->Next = curr->Next;
    }

     //update next element prev pointer
    if(curr->Next !=NULL){
        curr->Next->Previous = curr->Previous;
    }

    //if the element is the head
    if(dll->Head == curr){
        dll->Head=curr->Next;
    }
    dll->size--;
    printf("The element \"%s\" with the key %d was deleted\n",tempdata,key);
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
    if(curr == NULL || curr->key != key){
        printf("Error: The element with the key %d was not found\n",key);
        return NULL;
    }
    return curr;    
}


Element*MyDLLFindNext(MyDLL* dll, uint16_t key){
Element* curr = MyDLLFind(key,dll);
    if (curr == NULL )
    {
        printf("Error: Element with key %d not valid \n",key);
        return NULL;
    }else if(curr->Next == NULL){
        printf("Error: Element with key %d is the last one \n",key);
    }

    
    return curr->Next;
}


Element* MyDLLFindPrevious(MyDLL* dll, uint16_t key){
Element* curr = MyDLLFind(key,dll);
    if (curr == NULL)
    {
        printf("Error: Element with key %d not valide \n",key);
        return NULL ; 
    }else if(curr->Previous == NULL){
        printf("Error: Element with key %d is the first one \n",key);
    }

    return curr->Previous;    

}

void MyDLLPrint(MyDLL* dll){

    Element* curr = dll->Head;

    if (curr==NULL)
    {
        printf("the list is empty\n");
    }else{
        printf("\nDLL start-----\n");
        //go through the list
        while (curr!=NULL){
            printf("%d\n%s\n---------------\n",curr->key,curr->data);
            curr=curr->Next;
        }
        printf("DLL end-----\n\n");
    }
}


void MyDLLClear(MyDLL* dll){
    dll->size=0;
    dll->Tail=NULL;
    dll->Head=NULL;
    for (int i = 0; i < MAX_LIST_SIZE; i++)
    {
        dll->Elements[i].key = 0;
    }  
}