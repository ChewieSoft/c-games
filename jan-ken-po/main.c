#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jogarJokenpo() {
    int escolha_usuario, escolha_maquina;
    char *opcoes[] = {"Pedra", "Papel", "Tesoura"};

    printf("\nEscolha entre Pedra (0), Papel (1) ou Tesoura (2)\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha_usuario);

    // Validação da entrada do usuário
    if (escolha_usuario < 0 || escolha_usuario > 2) {
        printf("Escolha inválida! Tente novamente.\n");
        return;
    }

    // Gera escolha aleatória da máquina
    escolha_maquina = rand() % 3;
    printf("\nVocê escolheu: %s\n", opcoes[escolha_usuario]);
    printf("A máquina escolheu: %s\n", opcoes[escolha_maquina]);

    // Determina o resultado
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

    // Inicializa o gerador de números aleatórios
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
