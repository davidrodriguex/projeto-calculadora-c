#include <stdio.h>
#include <stdlib.h>

void menu(){ // Exibe o menu de opções para o usuário

    printf("\n");
    printf("=============================\n");
    printf("     Calculadora Simples     \n");
    printf("=============================\n");
    printf("Selecione uma operacao:\n");
    printf("[ 1 ] Adicao\n");
    printf("[ 2 ] Subtracao\n");
    printf("[ 3 ] Multiplicacao\n");
    printf("[ 4 ] Divisao\n");
    printf("[ 5 ] Sair\n");
}

void receber_valores(float *N1, float *N2){ // Procedimento para receber os valores do usuário
    
    printf("Digite o primeiro numero: ");
    scanf("%f", N1);
    printf("Digite o segundo numero: ");
    scanf("%f", N2);
}

void operacao(int a){ // Realiza a operação escolhida pelo usuário

    float N1, N2, resultado;

    
    switch (a){
        

        case 1: // Adicao
            
            system("cls"); // Limpa a tela para melhor visualização do resultado
            printf("------- Adicao -------\n");
            receber_valores(&N1, &N2);
            resultado = N1 + N2;
            printf("Resultado: %.2f + %.2f = %.2f\n", N1, N2, resultado);
            break;

        case 2: // Subtracao
            
            system("cls");
            printf("------- Subtracao -------\n");
            receber_valores(&N1, &N2);
            resultado = N1 - N2;
            printf("Resultado: %.2f - %.2f = %.2f\n", N1, N2, resultado);
            break;

        case 3: // Multiplicacao
            
            system("cls");
            printf("------- Multiplicacao -------\n");
            receber_valores(&N1, &N2);
            resultado = N1 * N2;
            printf("Resultado: %.2f * %.2f = %.2f\n", N1, N2, resultado);
            break;
                
        case 4: // Divisao
            
            system("cls");
            printf("------- Divisao -------\n");
            receber_valores(&N1, &N2);

            while(N2 == 0.00000){
                printf("Erro: Divisao por zero nao e permitida.\n");
                printf("Digite o segundo numero novamente: ");
                scanf("%f", &N2);
            }
            resultado = N1 / N2;
            printf("Resultado: %.2f / %.2f = %.2f\n", N1, N2, resultado);
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
            printf("Opcao: ");
            resultado_scanf = scanf("%d", &op);

            // Verifica se a opção é um número
            if(resultado_scanf != 1){
                menu();
                printf("Opcao invalida. Tente novamente\n");
                while (getchar() != '\n');
                continue;
            }

            // Verifica se a opção é válida (entre 1 e 5)
            if(op < 1 || op > 5){
                system("cls");
                menu();
                printf("Opcao invalida. Tente novamente\n");
                continue;
            }
            break;
        }

        // Pergunta ao usuário se deseja realizar outra operação, mas apenas se a opção escolhida for entre 1 e 4
        if(op >= 1 && op <= 4){
            
            operacao(op); // chama o procedimento operacao para realizar a operação escolhida pelo usuário

            printf("Deseja realizar outra operacao? [S/N]: ");
            scanf(" %c", &resp);
                
            // Valida a resposta do usuário, considerando apenas 'S', 's', 'N' ou 'n'. Caso contrário, considera como 'N'.
            while(resp != 'S' && resp != 's' && resp != 'N' && resp != 'n'){
                printf("Resposta invalida. Por favor, digite 'S' para sim ou 'N' para nao.\n");
                printf("Deseja realizar outra operacao? [S/N]: ");
                scanf(" %c", &resp);
            }

            // Opção de saída do programa
            if(resp == 'N' || resp == 'n'){
                printf("Obrigado por usar a calculadora! Ate a proxima.");
            }

        }else if(op == 5){
            resp = 'N';
            printf("Obrigado por usar a calculadora! Ate a proxima.");
            
        }

    } // Continua o loop enquanto o usuário desejar realizar outra operação
}
