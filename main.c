#include <stdio.h>

//abre um arquivo
//mostra a data, dias consecutivos e uma quote random

int main(){
    int linhas = 0;
    char frases[300];

    FILE *fh_input;
    
    fh_input = fopen("kbindings.txt", "r");

    char pChar = ' ';
    fscanf(fh_input, "%c", &pChar);
    printf("Primeiro C = %c\n", pChar);

    fclose(fh_input); 

    return 0;
}
