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
    MyDLLRemove(789,&DLL);

    MyDLLPrint(&DLL);

    printf("\n>>> Teste de busca <<<\n");
    Element* encontrado = MyDLLFind(305, &DLL);
    if (encontrado) {
        printf("Elemento encontrado -> Chave: %d, Dados: %s\n", encontrado->key, encontrado->data);
    } 
    encontrado=MyDLLFind(304,&DLL);
    if (encontrado) {
        printf("Elemento encontrado -> Chave: %d, Dados: %s\n", encontrado->key, encontrado->data);
    } 
    
    
    printf("\n>>> Teste de busca do próximo e anterior <<<\n");
    Element* next = MyDLLFindNext(&DLL, 410);
    if (next) {
        printf("Próximo elemento após chave 410 -> Chave: %d, Dados: %s\n", next->key, next->data);
    } 

    Element* previous = MyDLLFindPrevious(&DLL, 789);
    if (previous) {
        printf("Elemento anterior à chave 789 -> Chave: %d, Dados: %s\n", previous->key, previous->data);
    }

    printf("\n>>> Inserção adicional e estado final da lista <<<\n");
    MyDLLInsert(512, nomes[6], &DLL);
    MyDLLInsert(634, nomes[7], &DLL);
    MyDLLPrint(&DLL);

    MyDLLClear(&DLL);

    MyDLLPrint(&DLL);

    return 0;
}
