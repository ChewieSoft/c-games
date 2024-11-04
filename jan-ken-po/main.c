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

		#ifdef _WIN32
        system("CLS");
        #else
        system("clear");  
        #endif	
		printf("\nEscolha o modo de jogo:\n");
        printf("(1) Torneio (3 rodadas)\n");
        printf("(2) Combate (5 rodadas)\n");
        printf("(3) Escolha quantas rodadas\n");
        printf("(4) Infinitas rodadas\n");
        printf("(5) Sair do jogo\n");
        printf("\nDigite sua opção: ");
        scanf("%d", &selecModo);
		//printf("\n<------------------------------------------------->\n");
		#ifdef _WIN32
        system("CLS");
        #else
        system("clear");  
        #endif

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
            printf("\nObrigado por jogar! :DDDDDDDDDDD\n\n");
			#ifdef _WIN32
                Sleep(2000);
                system("CLS");				
            #else
                sleep(2);
                system("clear"); 			
            #endif
            break;
        } else {
            printf("\nOpção Inválida! Tente novamente.\n");
            continue;  
        }

        printf("\n<------------------------------------------------->\n");
		printf("\nUsuário - %d ponto(s).\nRand - %d ponto(s).\n", ponto_usuario, ponto_maquina);
        if (ponto_usuario > ponto_maquina) {
			char m;
            printf("\n\nVITÓRIA DO USUÁRIO!! :DDD\n\n");
			printf("<------------------------------------------------->\n");
			#ifdef _WIN32
                Sleep(5000); 
            #else
                sleep(5);  
            #endif	
        } else if (ponto_usuario < ponto_maquina) {
			char m;
            printf("\n\nDerrota, vitória do RAND D:\n\n");
			printf("<------------------------------------------------->\n");
			#ifdef _WIN32
                Sleep(5000); 
            #else
                sleep(5);  
            #endif
        } else {
			char m;
            printf("\n\nEmpate .-.\n\n");
			printf("<------------------------------------------------->\n");
			#ifdef _WIN32
                Sleep(5000); 
            #else
                sleep(5);  
            #endif
        }
    }
}

int main() {
    srand(time(NULL)); 
    printf("Bem-vindo ao Jokenpô contra o rand (heheh)!\n");
    menuPrincipal();   
    return 0;
}
