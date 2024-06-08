#include <stdio.h>

//abre um arquivo
//mostra a data, dias consecutivos e uma quote random

int main(){

    FILE *fh_output;
    
    fh_output = fopen("kbindings.txt", "r");

    fclose(fh_output);

    return 0;
}
