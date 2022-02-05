// Cabecalho

// Bibliotecas
#include <stdio.h>          // define bibliotecas
#include <stdlib.h>         // define bibliotecas
#include <string.h>         // define bibliotecas

// Prototipos
int tipo_fonte(int fonte);              // prototipo de funao para definir o tipo de fonte
float comparador(float c1, float c2, float c3, float c4, float f1, float f2, float f3, float f4);   // prototipo para funcao de comparacao de valores
float subtracao(float c1, float f1);    // prototipo de funcao para subtracao de valores

// Funcao main
int main()                          // inicia funcao main
{
    int decisao;                        // declaracao de variavel
    int fun_comp;                       // declaracao de variavel
    int resposta;                       // declaracao de variavel

    char RS_C[45];                      // declaracao de variavel
    int CNPJ_C;                         // declaracao de variavel
    char nome_contato_C[45];            // declaracao de variavel
    int telefone_C;                     // declaracao de variavel
    float qtd_energia_necessaria_C;     // declaracao de variavel
    float vlr_min_pagar_C;              // declaracao de variavel
    float vlr_max_pagar_C;              // declaracao de variavel
    float praz_min_contr_C;             // declaracao de variavel
    float praz_pag_C;                   // declaracao de variavel

    int F=0;                            // declaracao de variavel
    int t=0;                            // declaracao de variavel
    char RS_F[F][45];                   // declaracao de variavel
    int CNPJ_F[F];                      // declaracao de variavel
    char nome_contato_F[F][45];         // declaracao de variavel
    int telefone_F[F];                  // declaracao de variavel
    float qtd_energia_disp_F[F];        // declaracao de variavel
    float custo_kWm_F[F];               // declaracao de variavel
    float praz_min_contr_F[F];          // declaracao de variavel
    float praz_pag_aceitavel_F[F];      // declaracao de variavel
    int fonte[F];                       // declaracao de variavel

    float qtd_energia_sobrando_F;       // declaracao de variavel


    printf("\nDigite o que se pede a seguir:\n\n");                                 // imprime mensagem na tela

        printf("Razao Social do Consumidor: ");                                     // imprime mensagem na tela
        scanf("%s", &RS_C);                                                         // Salva valor em variavel
        printf("CNPJ(somente numeros, 14 digitos): ");                              // imprime mensagem na tela
        scanf("%d", &CNPJ_C);                                                       // Salva valor em variavel
        printf("Nome para contato: ");                                              // imprime mensagem na tela
        scanf("%s", &nome_contato_C);                                               // Salva valor em variavel
        printf("Telefone para contato: ");                                          // imprime mensagem na tela
        scanf("%d", &telefone_C);                                                   // Salva valor em variavel
        printf("Quantidade de energia que precisa adquirir(MWm): ");                // imprime mensagem na tela
        scanf("%f", &qtd_energia_necessaria_C);                                     // Salva valor em variavel
        printf("Valor minimo que se dispoe a pagar pele enegergia(em kWm): ");      // imprime mensagem na tela
        scanf("%f", &vlr_min_pagar_C);                                              // Salva valor em variavel
        printf("Valor maximo que se dispoe a pagar pele enegergia(em kWm): ");      // imprime mensagem na tela
        scanf("%f", &vlr_max_pagar_C);                                              // Salva valor em variavel
        printf("Prazo minimo do contrato(em meses): ");                             // imprime mensagem na tela
        scanf("%f", &praz_min_contr_C);                                             // Salva valor em variavel
        printf("Prazo para o pagamento(em meses): ");                               // imprime mensagem na tela
        scanf("%f", &praz_pag_C);                                                   // Salva valor em variavel
        printf("\n");                                                               // pula linha de impressao de tela

NEW_DATA:                                                       // ponto de refericia do codigo
    printf("Digite quantidade de Fornecedores: ");              // imprime mensagem na tela
    scanf("%d", &F);                                            // salva valor em variavel

    printf("\nDigite o que se pede:\n");                        // imprime mensagem na tela
    for(t=0; t<F; t++)                                          // inicia um laco for
    {
        printf("Razao Social do Fornecedor %d: ", t+1);         // imprime mensagem na tela
        scanf("%s", &RS_F[t]);                                  // salva valor em variavel
        printf("CNPJ(somente numeros, 14 digitos): ");          // imprime mensagem na tela
        scanf("%d", &CNPJ_F[t]);                                // salva valor em variavel
        printf("Nome para contato: ");                          // imprime mensagem na tela
        scanf("%s", &nome_contato_F[t]);                        // salva valor em variavel
        printf("Telefone: ");                                   // imprime mensagem na tela
        scanf("%d", &telefone_F[t]);                            // salva valor em variavel
        printf("Quantidade de energia disponivel: ");           // imprime mensagem na tela
        scanf("%f", &qtd_energia_disp_F[t]);                    // salva valor em variavel
        printf("Custo do kWm: ");                               // imprime mensagem na tela
        scanf("%f", &custo_kWm_F[t]);                           // salva valor em variavel
        printf("Prazo minimo de contrato(em meses): ");         // imprime mensagem na tela
        scanf("%f", &praz_min_contr_F[t]);                      // salva valor em variavel
        printf("Prazo de pagamente aceitavel(em meses): ");     // imprime mensagem na tela
        scanf("%f", &praz_pag_aceitavel_F[t]);                  // salva valor em variavel
        printf("\nEscolha o tipo da fonte:\n");                 // imprime mensagem na tela
        printf("Eolica = 1\n");                                 // imprime mensagem na tela
        printf("Fotovoltaica = 2\n");                           // imprime mensagem na tela
        printf("Outras = pressione qualquer tecla\n");          // imprime mensagem na tela
        scanf("%d", &fonte[t]);                                 // salva valor em variavel
        printf("\n\n");                                         // pula linhas de impressao de tela
    }

    while(decisao != 0)             // abre laco de repeticao while 
    {
        AGAIN:                      // ponto de referencia do codigo

        for(t=0; t<F; t++)          // inicia laco for
        {
            fun_comp = comparador(qtd_energia_necessaria_C, vlr_max_pagar_C, praz_min_contr_C, praz_pag_C,          // funcao de comparacao
                            qtd_energia_disp_F[t], custo_kWm_F[t],praz_min_contr_F[t], praz_pag_aceitavel_F[t]);    // funcao de comparacao

            if(fun_comp==1)
            {
                printf("\n\n<-->--<-->--<-->--<-->--<-->--<-->--<-->--<-->-->\n\n");                                    // imprime mensagem a fins de estetica de impressao do codigo
                printf("Compra possivel!\n\n");                                                                         // imprime mensagem na tela
                printf("\nFornecedor %d", t+1);                                                                         // imprime mensagem na tela
                printf("\nRazao Social: %s", RS_F[t]);                                                                  // imprime mensagem na tela
                printf("\nCNPJ: %d", CNPJ_F[t]);                                                                        // imprime mensagem na tela
                printf("\nNome para contato: %s", nome_contato_F[t]);                                                   // imprime mensagem na tela
                printf("\nTelefone: %d", telefone_F[t]);                                                                // imprime mensagem na tela
                printf("\nQuantidade de energia disponivel: %.2f", qtd_energia_disp_F[t]);                              // imprime mensagem na tela
                printf("\nCusto do kWm: R$ %.2f", custo_kWm_F[t]);                                                      // imprime mensagem na tela
                printf("\nPrazo minimo de contrato(em meses): %.0f meses", praz_min_contr_F[t]);                        // imprime mensagem na tela
                printf("\nPrazo de pagamento aceitavel(em meses): %.0f meses\n", praz_pag_aceitavel_F[t]);              // imprime mensagem na tela
                printf("Tipo de fonte: ");                                                                              // imprime mensagem na tela
                tipo_fonte(fonte[t]);       // funcao para classificar tipo de fonte

                printf("\n\nDeseja fechar negocio com esse fornecedor? ");              // imprime mensagem na tela
                printf("\n1 = sim \n2 = nao\n");                                        // imprime mensagem na tela
                scanf("%d", &resposta);                                                 // salva valor em variavel

                if(resposta == 1)           // inicia if de comparacao de valor, age se valor 'resposta' for igual a 1
                {
                    qtd_energia_sobrando_F = subtracao(qtd_energia_necessaria_C, qtd_energia_disp_F[t]);                // funcao de subtracao de valor

                    printf("\n\n<-->--<-->--<-->--<-->--<-->--<-->--<-->--<-->-->\n\n");                                // imprime mensagem a fins de estetica de impressao do codigo
                    printf("\n\nCompra efetuada do Fornecedor %d.", t+1);                                               // imprime mensagem na tela
                    printf("\nRazao Social: %s", RS_F[t]);                                                              // imprime mensagem na tela
                    printf("\nCNPJ: %d", CNPJ_F[t]);                                                                    // imprime mensagem na tela
                    printf("\nNome para contato: %s", nome_contato_F[t]);                                               // imprime mensagem na tela
                    printf("\nTelefone: %d", telefone_F[t]);                                                            // imprime mensagem na tela
                    printf("\nTipo de fonte: ");                                                                        // imprime mensagem na tela
                    tipo_fonte(fonte[t]);                                                                               // funcao para classificar tipo de fonte
                    printf("\nFornecedor %d ainda tem disponivel %.2f de energia.\n\n", t+1, qtd_energia_sobrando_F);   // imprime mensagem na tela
                    
                    goto ENDLESS;       // envia o codigo para um ponto de referencia
                }
            }
        }
DENOVO:         // ponto de referencia
    printf("\n\nNao ha mais combinacoes disponives!\n");            // imprime mensagem na tela
    printf("Para ver as combinacoes novamente digite 1:\n");        // imprime mensagem na tela
    printf("Para redigir os dados de fornecedores digite 2:\n");    // imprime mensagem na tela
    printf("Para encerrar o programa digite 0:\n");                 // imprime mensagem na tela
    scanf("%d", &resposta);                                         // salva valor em variavel
    printf("\n\n");                                                 // pula linhas de impressao de tela

    if(resposta==1)         // age se valor 'resposta' for igual a 1
        goto AGAIN;         // envia o codigo para um ponto de referencia
    else if(resposta==2)    // age se valor 'resposta' for igual a 2
        goto NEW_DATA;      // envia o codigo para um ponto de referencia
    else if(resposta==0)    // age se valor 'resposta' for igual a 0
        goto ENDLESS;       // envia o codigo para um ponto de referencia
    else                    // age se nenhuma das alternativas anteriores forem verdadeiras
    {
        printf("Erro\nDigite o que se pede:\n");    // imprime mensagem na tela
        goto DENOVO;                                // envia o codigo para um ponto de referencia
    }


    }

ENDLESS:            // ponto de referencia
    return 0;       // termina a funcao main
}

int tipo_fonte(int fonte)               // incia a funcao que classifica tipo de fonte
{
    if(fonte == 1)                      // age se valor de 'fonte' for igual a 1
        printf("Eolica\n\n");           // imprime mensagem na tela
    else if(fonte == 2)                 // age se valor de 'fonte' for igual a 2
        printf("Fotovoltaica\n\n");     // imprime mensagem na tela
    else                                // age se nenhuma das alternativas anteriores forem verdadeiras
        printf("Outra\n\n");            // imprime mensagem na tela

    return;                             // finaliza funcao tipo_fonte
}

float comparador(float c1, float c2, float c3, float c4, float f1, float f2, float f3, float f4)        //inicia fincao de comparador
{
    if(c1<=f1 && c2>=f2 && c3>=f3 && c4<=f4)    // verifica os dados
        return 1;                               // retorna valor 1
    else                                        // age se nao condizer com a verificacao dos dados
        return 0;                               // retorna 0
}
float subtracao(float c1, float f1)     // inicia funcao de subtracao
{
    float r=0;                          // cria variavel para resultado da subtracao

    r=f1-c1;                            // faz subtracao e salva em r

    return r;                           // retorna r
}