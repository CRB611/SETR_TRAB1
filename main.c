#include "MyDLL.h"


int main(){

    MyDLL DLL;

    MyDLLInit(&DLL); 

    MyDLLPrint(&DLL);
   
    MyDLLRemove(1,&DLL);

    MyDLLInsert(2,&"hello",&DLL);

    MyDLLInsert(1,&"ola",&DLL);

    MyDLLInsert(1,&"lalal",&DLL);
   
    MyDLLInsert(4,&"abacate",&DLL);
 
    MyDLLInsert(3,&"abcde",&DLL);

    MyDLLInsert(5,&"super",&DLL);
    
    MyDLLPrint(&DLL);

    MyDLLRemove(3,&DLL);

    MyDLLPrint(&DLL);

    printf("\nTesteSimao\n");
    printf("\n>>> Inserção de elementos <<<\n");
    MyDLLInsert(201, "Ana,987654", &DLL);
    MyDLLInsert(305, "Miguel,654321", &DLL);
    MyDLLInsert(789, "Beatriz,123987", &DLL);
    MyDLLInsert(410, "Rui,741852", &DLL);

    MyDLLPrint(&DLL);

    printf("\n>>> Teste de busca <<<\n");
    Element* encontrado = MyDLLFind(305, &DLL);
    if (encontrado) {
        printf("Elemento encontrado -> Chave: %d, Dados: %s\n", encontrado->key, encontrado->data);
    } else {
        printf("Elemento com chave 305 não encontrado.\n");
    }

    printf("\n>>> Teste de remoção <<<\n");
    MyDLLRemove(305, &DLL);
    MyDLLPrint(&DLL);

    printf("\n>>> Teste de busca do próximo e anterior <<<\n");
    Element* next = MyDLLFindNext(&DLL, 410);
    if (next) {
        printf("Próximo elemento após chave 410 -> Chave: %d, Dados: %s\n", next->key, next->data);
    } else {
        printf("Não há próximo elemento após a chave 410.\n");
    }

    Element* previous = MyDLLFindPrevious(&DLL, 789);
    if (previous) {
        printf("Elemento anterior à chave 789 -> Chave: %d, Dados: %s\n", previous->key, previous->data);
    } else {
        printf("Não há elemento anterior à chave 789.\n");
    }

    printf("\n>>> Inserção adicional e estado final da lista <<<\n");
    MyDLLInsert(512, "João,159753", &DLL);
    MyDLLInsert(634, "Sofia,852963", &DLL);
    MyDLLPrint(&DLL);

    return 0;
}
