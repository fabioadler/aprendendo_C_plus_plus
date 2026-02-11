#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

    int v1 = 45;
    int v2 = 25;
    int resultado;

    asm volatile(

        "mov %1, %%eax\n"    //Move 'a' para EAX
        "mov %2, %%ebx\n"    //move 'b' para EBX
        "add %%ebx, %%eax\n" //Soma EAX com EBX
        "mov %%eax, %0"      //Copia o resultado para a output(saida)
        : "=r" (resultado)   //Saida
        : "r" (v1), "r" (v2) //Passa as entradas
        : "eax", "ebx"       //Registadores

    );

    cout << "O resultado da soma de " << v1 << " + " << v2 << " = " << resultado << endl;
    return 0;

}