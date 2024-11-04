#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void pausa1Segundo() {
    #ifdef _WIN32
        Sleep(1000); 
    #else
        sleep(1);  
    #endif	
}

void jogarJokenpo(int *ponto_usuario, int *ponto_maquina) {
    int escolha_usuario, escolha_maquina;
    char *opcoes[] = {"Pedra", "Papel", "Tesoura"};

    printf("\nEscolha entre Pedra (0), Papel (1) ou Tesoura (2)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha_usuario);

    if (escolha_usuario < 0 || escolha_usuario > 2) {
        printf("Escolha inválida! Tente novamente.\n");
        return;
    }

    printf("\nVocê escolheu: %s\n", opcoes[escolha_usuario]);
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        pausa1Segundo();
    }
    printf("\n");
    escolha_maquina = rand() % 3;
    printf("A máquina escolheu: %s\n", opcoes[escolha_maquina]);
    pausa1Segundo();

    if (escolha_usuario == escolha_maquina) {
        printf("Empate ._.\n");
    } else if ((escolha_usuario == 0 && escolha_maquina == 2) ||
               (escolha_usuario == 1 && escolha_maquina == 0) ||
               (escolha_usuario == 2 && escolha_maquina == 1)) {
        printf("Vitória! :D\n");
        (*ponto_usuario)++;
    } else {
        printf("Você perdeu :(\n");
        (*ponto_maquina)++;
    }
}

void menuPrincipal() {
    int selecModo;
    int ponto_usuario, ponto_maquina;

    while (1) {
        ponto_usuario = 0;
        ponto_maquina = 0;

        printf("\nEscolha o modo de jogo:\n");
        printf("(1) Torneio (3 rodadas)\n");
        printf("(2) Combate (5 rodadas)\n");
        printf("(3) Escolha quantas rodadas\n");
        printf("(4) Infinitas rodadas\n");
        printf("(5) Sair do jogo\n");
        printf("\nDigite sua opção: ");
        scanf("%d", &selecModo);

        if (selecModo == 1) {
            for (int i = 0; i < 3; i++) {
                jogarJokenpo(&ponto_usuario, &ponto_maquina);
            }
        } else if (selecModo == 2) {
            for (int i = 0; i < 5; i++) {
                jogarJokenpo(&ponto_usuario, &ponto_maquina);
            }
        } else if (selecModo == 3) {
            int quant_rodadas;
            printf("\nDigite a quantidade de rodadas que deseja jogar: ");
            scanf("%d", &quant_rodadas);
            for (int i = 0; i < quant_rodadas; i++) {
                jogarJokenpo(&ponto_usuario, &ponto_maquina);
            }
        } else if (selecModo == 4) {
            int jogarNovamente;
            do {
                jogarJokenpo(&ponto_usuario, &ponto_maquina);
                printf("\nDeseja jogar novamente? (1 - Sim / 0 - Não): ");
                scanf("%d", &jogarNovamente);
            } while (jogarNovamente == 1);
        } else if (selecModo == 5) {
            printf("\nObrigado por jogar!\n");
            break;
        } else {
            printf("\nOpção Inválida! Tente novamente.\n");
            continue;  
        }

        printf("\nUsuário - %d ponto(s).\nRand - %d ponto(s).\n", ponto_usuario, ponto_maquina);
        if (ponto_usuario > ponto_maquina) {
            printf("\n\nVITÓRIA DO USUÁRIO!! :DDD\n\n");
            pausa1Segundo();
        } else if (ponto_usuario < ponto_maquina) {
            printf("\n\nDerrota, vitória do RAND D:\n\n");
            pausa1Segundo();
        } else {
            printf("\n\nEmpate ._.\n\n");
            pausa1Segundo();
        }
    }
}

int main() {
    srand(time(NULL)); 
    printf("Bem-vindo ao Jokenpô contra o rand (heheh)!\n");
    menuPrincipal();   
    return 0;
}
