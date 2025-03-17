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

    return 0;
}
