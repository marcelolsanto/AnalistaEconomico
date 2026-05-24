#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int jogar_novamente;

    // Inicializa a semente do gerador de numeros aleatorios apenas uma vez no programa
    srand(time(NULL));

    // Laco externo: controla se o jogador quer iniciar uma nova partida (Participacao Voluntaria)
    do {
        // Configuracoes e variaveis iniciais (sao resetadas a cada novo jogo)
        float saldo = 10000.0;
        int rodada = 1;
        float meta = 15000.0;
        int escolha, cenario;
        float lucro, perda;

        printf("==================================================\n");
        printf("       BEM-VINDO AO DESAFIO DO ANALISTA           \n");
        printf("==================================================\n");
        printf("Objetivo: Atingir a meta de R$ 15000.00 em 5 meses.\n");
        printf("Capital Inicial: R$ 10000.00\n");
        printf("--------------------------------------------------\n\n");

        // Laco interno: estrutura de repeticao que limita o jogo a 5 meses
        while (rodada <= 5) {
            printf("--- MES %d ---\n", rodada);
            printf("Saldo atual: R$ %.2f\n", saldo);
            printf("Onde voce deseja alocar seus recursos este mes?\n");
            printf("1 - Renda Variavel (Alto Risco / Alta Recompensa)\n");
            printf("2 - Renda Fixa (Baixo Risco / Retorno Seguro)\n");

            // Interacao com o usuario: coleta de dados
            printf("Digite 1 ou 2: ");
            scanf("%d", &escolha);

            // Sorteio do cenario economico usando randomize
            // 1 = Mercado em Alta | 2 = Mercado em Crise | 3 = Mercado Estavel
            cenario = (rand() % 3) + 1;

            printf("\n[GIRO DE MERCADO]\n");

            // Estruturas condicionais avaliando o cenario e a escolha (Sistema de Feedback)
            if (cenario == 1) {
                printf("Noticia: A economia esta bombando! O mercado esta em ALTA.\n");
                if (escolha == 1) {
                    lucro = saldo * 0.20;
                    saldo = saldo + lucro;
                    printf("Resultado: Excelente escolha! A Renda Variavel rendeu 20%%.\n\n");
                } else if (escolha == 2) {
                    lucro = saldo * 0.05;
                    saldo = saldo + lucro;
                    printf("Resultado: Seguro. A Renda Fixa rendeu 5%%.\n\n");
                } else {
                    printf("Opcao invalida! Voce guardou o dinheiro no colchao e nao rendeu nada.\n\n");
                }

            } else if (cenario == 2) {
                printf("Noticia: Crise a vista! O mercado esta em BAIXA.\n");
                if (escolha == 1) {
                    perda = saldo * 0.15;
                    saldo = saldo - perda;
                    printf("Resultado: Pessimo negocio! A Renda Variavel despencou 15%%.\n\n");
                } else if (escolha == 2) {
                    lucro = saldo * 0.02;
                    saldo = saldo + lucro;
                    printf("Resultado: Ufa! A Renda Fixa protegeu seu capital e rendeu 2%%.\n\n");
                } else {
                    printf("Opcao invalida! Voce guardou o dinheiro no colchao e nao rendeu nada.\n\n");
                }

            } else if (cenario == 3) {
                printf("Noticia: O mercado operou de forma ESTAVEL este mes.\n");
                if (escolha == 1) {
                    lucro = saldo * 0.02;
                    saldo = saldo + lucro;
                    printf("Resultado: A Renda Variavel andou de lado, rendendo apenas 2%%.\n\n");
                } else if (escolha == 2) {
                    lucro = saldo * 0.04;
                    saldo = saldo + lucro;
                    printf("Resultado: A Renda Fixa garantiu um ganho solido de 4%%.\n\n");
                } else {
                    printf("Opcao invalida! Voce guardou o dinheiro no colchao e nao rendeu nada.\n\n");
                }
            }

            // Incremento do controle da estrutura de repeticao
            rodada = rodada + 1;
        }

        // Fim do laco interno e apuracao do Estado de Vitoria/Derrota
        printf("==================================================\n");
        printf("                 FIM DO JOGO                      \n");
        printf("==================================================\n");
        printf("Seu saldo final foi de: R$ %.2f\n", saldo);

        // Estrutura condicional final para verificar se a Meta foi atingida
        if (saldo >= meta) {
            printf("PARABENS! Voce superou o mercado, bateu a meta e se provou um excelente analista!\n");
        } else {
            printf("FIM DE JOGO. Voce nao atingiu a meta de R$ 15000.00. Revise sua estrategia.\n");
        }

        // Pergunta se deseja reiniciar o laco externo (do-while)
        printf("\n==================================================\n");
        printf("Deseja tentar mais uma rodada?\n");
        printf("1 - Sim\n");
        printf("0 - Nao, sair do jogo\n");
        printf("Escolha: ");
        scanf("%d", &jogar_novamente);
        printf("\n\n");

    } while (jogar_novamente == 1);

    printf("Obrigado por jogar! Encerrando o programa...\n");

    return 0;
}