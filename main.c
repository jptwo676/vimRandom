#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//abre um arquivo
//mostra a data, dias consecutivos e uma quote random

int detectaHeader(char frase[]);

//TODO reação pra quando a linha selecionada for vazia
//TODO descobrir como pegar uma linha em especifico
int main(){

    srand(time(NULL));
    
    //o arquivo tem 228 linhas
    int linhaEscolhida = rand() % 228;
    int linha = 0;
    char frase[300];

    FILE *fh_input;
    
    fh_input = fopen("kbindings.txt", "r");
    fgets(frase, 300, fh_input);

    printf("linhaEscolhida = %d \n", linhaEscolhida);
    if(detectaHeader(frase) == 0)
    {
        printf("%s", frase);
    }

    //TODO varrer por todas as linhas e parar no momento certo
    for(int f = 0; f < 228; f++)
    {
        if(linhaEscolhida == f){
            printf("linhaEscolhida = %d, f = %d \n", linhaEscolhida, f);

    }

    fclose(fh_input); 

    return 0;
}

int detectaHeader(char frase[])
{
    int fraseLen = 0;
    int CAPS = 0;

    fraseLen = strlen(frase);
    printf("LEN = %d \n", fraseLen);
    for(int l = 0; l < fraseLen; l++)
    {
        if(frase[l] < 91 && frase[l] > 64)
        {
            CAPS++;
        }
        if(CAPS > 4)
        {
            printf("Esse é um Header. \n");
            return 0;
        }
    }
    return 1;
}
