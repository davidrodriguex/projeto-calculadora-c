#include <stdio.h>
#include <stdlib.h>

void menu(){ // Exibe o menu de opções para o usuário

    printf("\n");
    printf("=============================\n");
    printf("     Calculadora Simples     \n");
    printf("=============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
}

void operacao(int a){ // Realiza a operação escolhida pelo usuário

    float N1, N2, resultado;

    switch (a){

        case 1: // Adicao

            printf("Digite o primeiro número: ");
            scanf("%f", &N1);
            printf("Digite o segundo número: ");
            scanf("%f", &N2);
            resultado = N1 + N2;
            printf("Resultado: %.2f + %.2f = %.2f\n", N1, N2, resultado);
            break;

        case 2: // Subtracao

            printf("Digite o primeiro número: ");
            scanf("%f", &N1);
            printf("Digite o segundo número: ");
            scanf("%f", &N2);
            resultado = N1 - N2;
            printf("Resultado: %.2f - %.2f = %.2f\n", N1, N2, resultado);
            break;

        case 3: // Multiplicacao

            printf("Digite o primeiro número: ");
            scanf("%f", &N1);
            printf("Digite o segundo número: ");
            scanf("%f", &N2);
            resultado = N1 * N2;
            printf("Resultado: %.2f * %.2f = %.2f\n", N1, N2, resultado);
            break;

        case 4: // Divisao

            printf("Digite o primeiro número: ");
            scanf("%f", &N1);
            printf("Digite o segundo número: ");
            scanf("%f", &N2);

            if(N2 == 0){
                printf("Erro: Divisão por zero não é permitida.\n");
                break;
            }else{
                resultado = N1 / N2;
                printf("Resultado: %.2f / %.2f = %.2f\n", N1, N2, resultado);
            }
            break;
    }
}

int main(){ // Função principal que controla o fluxo do programa
    
    // Variáveis utilizadas
    char resp = 'S';
    int op;
    int resultado_scanf;

    while(resp == 'S' || resp == 's'){

        system("cls");

        menu(); // chama o procedimento menu para o usuário

        // Solicita ao usuário que escolha uma opção e valida a entrada
        while(1){

            printf("Opção: ");
            resultado_scanf = scanf("%d", &op);

            // Verifica se a opção é um número
            if(resultado_scanf != 1){
                printf("Opção inválida. Tente novamente\n");
                while (getchar() != '\n');
                continue;
            }

            // Verifica se a opção é válida (entre 1 e 5)
            if(op < 1 || op > 5){
                printf("Opção inválida. Tente novamente\n");
                continue;
            }
            break;
        }

        // Pergunta ao usuário se deseja realizar outra operação, mas apenas se a opção escolhida for entre 1 e 4
        if(op >= 1 && op <= 4){
            
            operacao(op); // chama o procedimento operacao para realizar a operação escolhida pelo usuário

            printf("Deseja realizar outra operação? (y/n): ");
            scanf(" %c", &resp);
                
            // Valida a resposta do usuário, considerando apenas 'S', 's', 'N' ou 'n'. Caso contrário, considera como 'N'.
            while(resp != 'Y' && resp != 'y' && resp != 'N' && resp != 'n'){
                printf("Resposta inválida. Por favor, digite 'y' para sim ou 'n' para não.\n");
                printf("Deseja realizar outra operação? (y/n): ");
                scanf(" %c", &resp);
            }

            // Opção de saída do programa
            if(resp == 'N' || resp == 'n'){
                printf("Obrigado por usar a calculadora! Até a próxima.");
            }

        }else if(op == 5){

            resp = 'N';
            printf("Obrigado por usar a calculadora! Até a próxima.");
            
        }

    } // Continua o loop enquanto o usuário desejar realizar outra operação
}
