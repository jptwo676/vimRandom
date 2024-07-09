#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//abre um arquivo
//mostra um comando random

//se retorna 0 = header
int detectaHeader(char frase[]);

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
                break;
            }
            else
            {
                continue;
            }
        }
        linha++;
    }

    fclose(fh_input); 
            
    printf("Comando aleatório:\n \t %s \n", frase);

    return 0;
}

//0 sucesso em achar o header
//1 falha
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

