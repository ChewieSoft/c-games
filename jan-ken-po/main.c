#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void jogarJokenpo() {
    int escolha_usuario, escolha_maquina, pausa;
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
        #ifdef _WIN32
            Sleep(1000);
        #else
            sleep(1);
        #endif
    }
    printf("\n");
    escolha_maquina = rand() % 3;
    printf("A máquina escolheu: %s\n", opcoes[escolha_maquina]);
    #ifdef _WIN32
        Sleep(1000);
    #else
        sleep(1);
    #endif

    if (escolha_usuario == escolha_maquina) {
        printf("Empate ._.\n");
    } else if ((escolha_usuario == 0 && escolha_maquina == 2) || (escolha_usuario == 1 && escolha_maquina == 0) || (escolha_usuario == 2 && escolha_maquina == 1)) {
        printf("Vitória! :D\n");
    } else {
        printf("Você perdeu :(\n");
    }
}

int main() {
    int jogarNovamente;

    srand(time(NULL));
    
    printf("Bem-vindo ao Jokenpô contra o rand (heheh)!\n");

    do {
        jogarJokenpo();
        printf("\nDeseja jogar novamente? (1 - Sim / 0 - Não): ");
        scanf("%d", &jogarNovamente);
    } while (jogarNovamente == 1);

    printf("\nValeu por jogar!\n");
    return 0;
}
