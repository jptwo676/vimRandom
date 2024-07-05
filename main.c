#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//abre um arquivo
//mostra a data, dias consecutivos e uma quote random

//se retorna 0 = header
int detectaHeader(char frase[]);

//TODO reação pra quando a linha selecionada for vazia
//TODO descobrir como pegar uma linha em especifico
int main(){

    srand(time(NULL));
    
    //o arquivo tem 228 linhas
    int linhaEscolhida = rand() % 228;
    int linha = 0;
    int headerCheck;
    char frase[300];

    FILE *fh_input;
    
    fh_input = fopen("kbindings.txt", "r");

    if(fh_input == NULL)
    {
        printf("Não foi possivel abrir o arquivo. \n");
        return 1;
    }


    //repete a selecao ate que encontre uma frase valida
    do
    {
        for(int l = 0; l < 228; l++)
        {
            fgets(frase, 300, fh_input);
            if(linhaEscolhida == l)
            {
                printf("linhaEscolhida = %d, l = %d \n", linhaEscolhida, l);
            }
        }
        headerCheck = detectaHeader(frase);
        printf("headerCheck %d \n", headerCheck);
        printf("Esse é um header, selecionando outra sentença... \n");
        printf("linhaEscolhida = %d \n", linhaEscolhida);
        printf("frase = %s \n", frase);
        linhaEscolhida = rand() % 228;
        
    }
    while(headerCheck == 0);

    //TODO exibit dia e horario
    printf("Hoje é dia: \n");
    printf("O comando do dia é: %s \n", frase);

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
        else
        {
            CAPS = 0;
        }

        if(CAPS > 5)
        {
            printf("Esse é um Header. \n");
            return 0;
        }
    }
    return 1;
}
