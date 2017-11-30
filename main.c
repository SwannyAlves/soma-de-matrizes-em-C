#include<stdio.h>
#define tam 50
#include<conio.h>
#include <windows.h>
#include<time.h>
#include<stdlib.h>

/*FUNÇÃO QUE EXECUTA A OPERAÇÃO DE ADIÇÃO, ELA RECEBE O TAMANHO DA MATRIZ 'A' QUE É IGUAL AO DA MATRIZ 'B' (POR DEFINIÇÃO MATEMATICA)
E AS MATRIZES 'A' E 'B', COM ISSO A MATRIZ 'C' RECEBE A ADIÇÃO DESSAS DUAS MATRIZES VINDAS LÁ DA MAIN*/
void somaDeMatrizes(int la, int ca, int lb, int cb, float a[][tam], float b[][tam] ){

    int i, j ;
    float c[tam][tam];
    if((la==lb) && (ca == cb)){
        printf("Matriz de soma >> \n");
        for (i=0; i<la; i++){
            for (j = 0; j < ca; j ++){
                c[i][j] = a[i][j] + b[i][j];
                printf("  %.0f ", c[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("\n A operacao nao pode ser realizada, pois, a soma de 2 matriz so pode ser feita com matrizes de mesmo tamanho \n");
    }

}

/*FUNÇÃO QUE EXECUTA A OPERAÇÃO DE SUBTRAÇÃO, ELA RECEBE O TAMANHO DA MATRIZ 'A' QUE É IGUAL AO DA MATRIZ 'B' (POR DEFINIÇÃO MATEMATICA)
E AS MATRIZES 'A' E 'B', COM ISSO A MATRIZ 'C' RECEBE A SUBTRAÇÃO DESSAS DUAS MATRIZES VINDAS LÁ DA MAIN*/
void SubtracaoDeMatrizes(int la, int ca, int lb, int cb, float a[][tam], float b[][tam] ){
    int i, j ;
    float sub[tam][tam];
    if((la == lb) && (ca == cb)){
        printf("Matriz da subtracao >> \n");
        for (i=0; i<la; i++){
            for (j = 0; j < ca; j ++){
                sub[i][j] = a[i][j] - b[i][j];
                printf("  %.0f ",sub[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("\n A operacao nao pode ser realizada, pois, a subtracao de 2 matriz só pode ser feita com matrizes de mesmo tamanho \n");
    }
}

void MultiplicacaoDeMatrizes(int la, int cb, float a[][tam], float b[][tam], int lb, int ca ){
    int i, j,x;
    float c[tam][tam];
    float aux=0;
    if(ca == lb){
        for(i=0; i<la; i++){
            for(j=0; j<cb; j++){
                for(x=0; x<lb; x++){
                    aux += a[i][x] * b[x][j];
                }
                c[i][j]=aux;
                aux=0;
            }
        }
        for(i=0; i<la; i++){
            for(j=0; j<cb; j++){
                printf("%2.f", c[i][j]);
            }
            printf("\n\n");
        }
    }
    else{
        printf(" Nao eh possivel multiplicar as matrizes dadas, lembre-se: a quantidade de linhas da matriz A deve ser igual a quantidade de colunas da matriz B \n");
    }


}

/* FUNÇÃO QUE VERIFICA SE A QUANTIDADE DE LINHAS DIGITADA PELO USARIO É MAIOR QUE O LIMITE MAXIMO PRÉ DETERMINADO, SE
FOR MAIOR ENTÃO A FUNÇÃO IRÁ PEDIR UM NOVO VALOR ATÉ QUE ESSE VALOR SEJA MENOR QUE O LIMITE MAXIMO*/
void VerificaSeAlinhaDaMatrizEValida (int *L){
    while(tam <*L){
        printf("Valor inserido eh maior que o maximo pre-determinado (50), por favor tente novamente >> \n ");
        printf("Insira a quantidade de linhas >> ");
        scanf("%d", L);
    }

}

/* FUNÇÃO QUE VERIFICA SE A QUANTIDADE DE COLUNA DIGITADA PELO USARIO É MAIOR QUE O LIMITE MAXIMO PRÉ DETERMINADO, SE
 FOR MAIOR ENTÃO A FUNÇÃO IRÁ PEDIR UM NOVO VALOR ATÉ QUE ESSE VALOR SEJA MENOR QUE O LIMITE MAXIMO*/
void VerificaSeAColunaDaMatrizEValida (int *C){
    while(tam < *C ){
        printf("Valor inserido eh maior que o maximo pre-determinado (50), por favor tente novamente >> \n ");
        printf("Insira a quantidade de colunas >> ");
        scanf("%d", C);
    }
}

/*FUNÇÃO QUE EXIBI O MENU PRINICPAL E QUE EXECUTA A CHAMADA DAS FUNÇÕES QUE EXECUTAM AS OPERAÇÕES ENTRE AS MATRIZES, ELA ENVIA 'OPCAO' POR REFERENCIA
PARA A MAIN, QUE POR SUA VEZ FICA CHAMANDO A FUNCAO ENQUANTO 'OPCAO' FOR DIFERENTE DE '13'*/
int exibirMenur( int *opcao){

    float a[tam][tam], b[tam][tam];
    int limite1, limite2;
    int ca, la, cb, lb, i,j;
    if(*opcao == 1){
        printf("\n\n  | 1 |  Definir o tamanho da matriz A \n\n");
        printf("\n\n\n=================MATRIZ A======================\n\n\n");

        printf("Insira a quantidade de linhas >> ");
        scanf("%d", &la);
        VerificaSeAlinhaDaMatrizEValida(&la);

        printf("\n");

        printf("Insira a quantidade de  da coluna >> ");
        scanf("%d", &ca);
        VerificaSeAColunaDaMatrizEValida(&ca);
        system("cls");
    }
    else if(*opcao == 2){
        printf("\n\n | 2 |  Definir o tamanho da matriz B \n\n");
        printf("\n\n\n=================MATRIZ B======================\n\n\n");

        printf("Insira a quantidade de linhas >> ");
        scanf("%d", &lb);
        VerificaSeAlinhaDaMatrizEValida(&lb);

        printf("\n");
        printf("Insira a quantidade de colunas >> ");
        scanf("%d", &cb);
        VerificaSeAColunaDaMatrizEValida(&cb);
        system("cls");
    }
    else if(*opcao == 3){
        printf("\n\n  | 3 |  Preencher a matriz A com valores aleatorios \n\n");
        printf(" Insira um intervalo para os numeros aleatorios >> ");
        scanf("%d", &limite1);
        scanf("%d", &limite2);

        for(i=0; i<la ; i++){
            for(j=0 ; j<ca; j++){
                a[i][j]=(limite1 + ( rand() % (limite2-limite1)));
            }
        }
        system("cls");
    }
    else if(*opcao == 4){
        printf("\n\n  | 4 |  Preencher a matriz B com valores aleatorios \n\n");
        printf(" Insira um intervalo para os numeros aleatorios >> ");
        scanf("%d", &limite1);
        scanf("%d", &limite2);

        for(i=0; i<lb ; i++){
            for(j=0 ; j<cb; j++){
                b[i][j]=(limite1 + ( rand() % (limite2-limite1)));
            }
        }
        system("cls");
    }
    else if(*opcao == 5){
        printf("\n\n  | 5 |  Atribuir valor para um elemento da matriz A \n\n");
        for(i=0; i<la ; i++){
            for(j=0 ; j<ca ; j++){
                scanf("%f", &a[i][j]);
            }
        }
        system("cls");
    }
    else if(*opcao == 6){
        printf("\n\n  | 6 |  Atribuir valor para um elemento da matriz B \n\n");
        for(i=0; i<lb ; i++){
            for(j=0 ; j<cb ; j++){
                scanf("%f", &b[i][j]);
            }
        }
        system("cls");
    }
    else if(*opcao == 7){
        printf("\n\n  | 7 |  Calcular A+B \n\n");
        somaDeMatrizes(la, ca, lb, cb, a, b);
    }
    else if(*opcao == 8){
        printf("\n\n  | 8 |  Calcular A-B \n\n");
        SubtracaoDeMatrizes(la, ca,lb, cb, a, b);
    }
    else if(*opcao == 9){
        printf("\n\n  | 9 |  Calcular A*B \n\n");
        MultiplicacaoDeMatrizes(la, cb, a, b, lb, ca);
    }
    else if(*opcao == 10){
        printf("\n\n  |10 |  Imprimir matriz A \n\n");
        for(i=0; i<la ; i++){
            for(j=0 ; j<ca ; j++){
                printf(" %.0f ", a[i][j]);
            }
            printf("\n");
        }
    }
    else if(*opcao == 11){
        printf("\n\n  |11 |  Imprimir matriz B \n\n");
        for(i=0; i<lb ; i++){
            for(j=0 ; j<cb ; j++){
                printf(" %.0f ", b[i][j]);
            }
            printf("\n");
        }
    }
    else if(*opcao==12){
        return 0;
    }

    printf("\n\n\n       ESCOLHA UMA DAS OPCOES A BAIXO :       \n\n\n");

    printf("  | 1 |  Definir o tamanho da matriz A \n");
    printf("  | 2 |  Definir o tamanho da matriz B \n");
    printf("  | 3 |  Preencher a matriz A com valores aleatorios \n");
    printf("  | 4 |  Preencher a matriz B com valores aleatorios \n");
    printf("  | 5 |  Atribuir valores para a matriz A \n");
    printf("  | 6 |  Atribuir valores para a matriz B \n");
    printf("  | 7 |  Calcular A+B \n");
    printf("  | 8 |  Calcular A-B \n");
    printf("  | 9 |  Calcular A*B \n");
    printf("  |10 |  Imprimir matriz A \n");
    printf("  |11 |  Imprimir matriz B \n");
    printf("  |12 |  Sair \n");
    scanf("%d", &*opcao);

    while(*opcao < 1 || *opcao > 13){
        printf("        OPCAO INVALIDA! TENTE NOVAMENTE:       \n\n");
        printf("  | 1 |  Definir o tamanho da matriz A \n");
        printf("  | 2 |  Definir o tamanho da matriz B \n");
        printf("  | 3 |  Preencher a matriz A com valores aleatorios \n");
        printf("  | 4 |  Preencher a matriz B com valores aleatorios \n");
        printf("  | 5 |  Atribuir valores para a matriz A \n");
        printf("  | 6 |  Atribuir valores para a matriz B \n");
        printf("  | 7 |  Calcular A+B \n");
        printf("  | 8 |  Calcular A-B \n");
        printf("  | 9 |  Calcular A*B \n");
        printf("  |10 |  Imprimir matriz A \n");
        printf("  |11 |  Imprimir matriz B \n");
        printf("  |12 |  Sair \n");
        scanf("%d", &*opcao);
    }
    system("cls");
}

/*FUNÇÃO PRINICIPAL*/
int main()
{
    int opcao=0;

    printf( "                       __        __   _______   __________   ______    __   _______             \n");
    printf( "                      |  |      |  | |   _   | |          | |   _  |  |  | |___    |            \n");
    printf( "                      |   |    |   | |  | |  | |___   ____| |  | |  | |  |     |  |             \n");
    printf( "                      |    |__|    | |  |_|  |     |  |     |  |_|  | |  |    |  |              \n");
    printf( "                      |            | |       |     |  |     |   __ |  |  |   |  |               \n");
    printf( "                      |   _     _  | |   _   |     |  |     |  |  | | |  |  |  |___             \n");
    printf( "                      |__| |__| |__| |__| |__|     |__|     |__|  |_| |__| |_______|            \n");

    Sleep(4000); //TEMPORIZADOR PARA EXIBIR MATRIZ
    system("cls"); // LIMPAR A TELA

    while(opcao != 12)
    {
        exibirMenur(&opcao);
        if(opcao == 12)
        {
            printf("\n\nDesenvolvido por Swanny Alves, aluna do curso: Algoritmos e Logica de Programacao (DCA0800)- UFRN \n\n");
        }
    }
    return 0;
}
