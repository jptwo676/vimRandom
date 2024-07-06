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
    char frase[300];

    FILE *fh_input;
    
    fh_input = fopen("kbindings.txt", "r");

    if(fh_input == NULL)
    {
        printf("Não foi possivel abrir o arquivo. \n");
        return 1;
    }


    //repete a selecao ate que encontre uma frase na linha certa
    while(fgets(frase, sizeof frase, fh_input))
    {
        if(linha == linhaEscolhida)
        {
            //detecta se a frase se trata de um titulo
            if(detectaHeader(frase) == 1)
            {
                printf("break \n");
                break;
            }
            else
            {
                printf("continue \n");
                continue;
            }
        }
        linha++;
    }

    fclose(fh_input); 
            

    printf("Hoje é dia: \n");
    printf("Na linha %d \n", linha);
    printf("Comando do dia é:\n \t %s \n", frase);


    return 0;
}

int detectaHeader(char frase[])
{
    int fraseLen = 0;
    int CAPS = 0;

    fraseLen = strlen(frase);
    for(int l = 0; l < fraseLen; l++)
    {
        //usa ascii p detectar se existem letras em caps seguidas
        //todos os titulos do arquivo estao em caps
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
