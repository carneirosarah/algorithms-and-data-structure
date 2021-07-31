#include "escalonador.c"
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int option = 0;
    int process_id = 1;
    scheduler* processes = new_scheduler();

    while (1) {

        printf("\n**** Escalonador ****\n");
        printf("\nDigite (1) para inserir um novo processo.");
        printf("\nDigite (2) para remover o processo com o maior tempo de espera.");
        printf("\nDigite (3) para imprimir a lista de processos.");
        printf("\nDigite (4) para sair.\n");

        scanf("%d", &option);

        printf("\n");

        switch (option) {

            case 1:

                processes = insert_process(processes, process_id);
                process_id++;
                break;

            case 2:

                processes = remove_process(processes);
                break;

            case 3:
            
                print(processes);
                break;

            case 4:
                exit(0);
                break;
    
            default:
                printf("\nOpção Inválida.\n");
                break;
        }
    }
}