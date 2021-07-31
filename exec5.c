#include <stdio.h>
#include <stdlib.h>

/*
ASCII Reference
A - 65, E - 69, I - 73, O - 79, U - 85
a - 97, e - 101, i - 105, o - 111, u - 117
*/

int main (void) {

    FILE *file = fopen("in_exec5.txt", "r");
    char character;
    int vogals_count = 0;


    if (file == NULL) {
        printf("Erro ao abrir o arquivo");
        exit(1);
    }
    
    do {

        character = fgetc(file);

        if (character == 65 || character == 69 || character == 73 || character == 79 || character == 85 ||
            character == 97 || character == 101 || character == 105 || character == 111 || character == 117) {
            
            //printf("%c\n" , character);
            vogals_count++;       
        }  
    } while (character != EOF);

    printf("Número de vogais = %d\n" , vogals_count);

    fclose(file);
    return 0;
}