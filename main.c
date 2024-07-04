#include <stdio.h>
#include <string.h>

//abre um arquivo
//mostra a data, dias consecutivos e uma quote random

void detectaCAPS(char frase[]);

int main(){
    int linhas = 0;
    char frase[300];

    FILE *fh_input;
    
    fh_input = fopen("kbindings.txt", "r");

    fgets(frase, 300, fh_input);
    printf("%s", frase);

    detectaCAPS(frase);

    //TODO detectar se a senteça é caps

    fclose(fh_input); 

    return 0;
}

void detectaCAPS(char frase[])
{
    int fraseLen = 0;

    fraseLen = strlen(frase);
    printf("LEN = %d \n", fraseLen);
    for(int l = 0; l < fraseLen; l++)
    {
        if(frase[l] < 91 && frase[l] > 64)
        {
            printf("Essa frase contem CAPS. \n");
        }
        else
        {
            printf("Essa frase não contem CAPS. \n");
        }
    }
}
