#include "MyDLL.h"


int main(){

    MyDLL DLL;

    MyDLLInit(&DLL); 

    printf("\n>>> Removal of elements whilst the list is empty <<<\n");
    MyDLLRemove(567,&DLL);

    printf("\n>>> Insertion of elements <<<\n");
    
    uint8_t nomes[8][MAX_ELEM_SIZE]={"Ana,987654","Miguel,654321","Beatriz,123987","Rui,741852","Maria,435253","Eduardo,345253","João,159753","Sofia,852963"};
    MyDLLInsert(201, nomes[0], &DLL);
    MyDLLInsert(305, nomes[1], &DLL);
    MyDLLInsert(789, nomes[2], &DLL);
    MyDLLInsert(201, nomes[4], &DLL);
    MyDLLInsert(410, nomes[3], &DLL);
    MyDLLInsert(123, nomes[4], &DLL);

    MyDLLPrint(&DLL);

    printf("\n>>> Removal of elements <<<\n");
    
    MyDLLRemove(567,&DLL);
    MyDLLRemove(123,&DLL);

    MyDLLPrint(&DLL);

    printf("\n>>> Search Test <<<\n");
    Element* encontrado = MyDLLFind(305, &DLL);
    if (encontrado) {
        printf("Found Element -> Key: %d, Data: %s\n", encontrado->key, encontrado->data);
    } 
    encontrado=MyDLLFind(304,&DLL);
    if (encontrado) {
       printf("Found Element -> Key: %d, Data: %s\n", encontrado->key, encontrado->data);
    } 
    
    printf("\n>>>  Next and previous search text <<<\n");
    printf("Next\n");
    Element* next = MyDLLFindNext(&DLL, 410);
    if (next) {
        printf("Element next to key 410 -> Key: %d, Data: %s\n", next->key, next->data);
    } 
    next=MyDLLFindNext(&DLL, 201);
    if (next) {
        printf("Element next to key 201 -> Key: %d, Data: %s\n", next->key, next->data);
    } 

    printf("Previous\n");
    Element* previous = MyDLLFindPrevious(&DLL, 789);
    if (previous) {
        printf("Element  previous to key 789 -> Key: %d, Dados: %s\n", previous->key, previous->data);
    }
    previous = MyDLLFindPrevious(&DLL, 201);
    if (previous) {
        printf("Element  previous to key 201 -> Key: %d, Dados: %s\n", previous->key, previous->data);
    }

    printf("\n>>> Clear Test <<<\n");

    MyDLLPrint(&DLL);
    
    MyDLLClear(&DLL);

    MyDLLPrint(&DLL);

    return 0;
}
