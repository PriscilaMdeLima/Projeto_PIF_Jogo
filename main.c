#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "screen.h"

// Estrutura de jogador
typedef struct {
    char nome[50];
    int tentativas;
    int acertos;
} Jogador;

void limparTela() {
    screenClear(); // Limpa a tela usando a função da biblioteca screen
}

// Imprimir mensagem com cor e estilo
void imprimirMensagem(char* mensagem, screenColor cor) {
    screenSetColor(cor, BLACK); // Define a cor do texto
    printf("%s\n", mensagem);
    screenSetColor(LIGHTGRAY, BLACK); // Reseta para as cores padrão
}

// Escolher uma palavra aleatória
char* escolherPalavra() {
    char* palavras[] = {
        "programacao", "computador", "teclado", "mouse", "internet", 
        "software", "hardware", "rede", "algoritmo", "dados", 
        "sistema", "aplicativo", "nuvem", "codigo", "desenvolvimento", "tecnologia"
    };
    int index = rand() % 16; // Seleciona uma palavra aleatória
    char* palavraSelecionada = (char*)malloc(strlen(palavras[index]) + 1); // Aloca memória para a palavra
    strcpy(palavraSelecionada, palavras[index]);
    return palavraSelecionada;
}

// Verificar se o jogador ganhou
int ganhou(char* palavra, char* palavraAdivinhada) {
    return strcmp(palavra, palavraAdivinhada) == 0;
}

// Desenhar a forca com estilos
void desenharForca(int tentativasRestantes) {
    screenSetColor(LIGHTRED, BLACK);
    printf("\nTentativas Restantes: %d\n", tentativasRestantes);
    switch (tentativasRestantes) {
        case 6: printf("\n\n\n\n\n=====\n"); break;
        case 5: printf("  O  \n\n\n\n\n=====\n"); break;
        case 4: printf("  O  \n  |  \n\n\n\n=====\n"); break;
        case 3: printf("  O  \n /|  \n\n\n\n=====\n"); break;
        case 2: printf("  O  \n /|\\ \n\n\n\n=====\n"); break;
        case 1: printf("  O  \n /|\\ \n /   \n\n\n=====\n"); break;
        case 0: printf("  O  \n /|\\ \n / \\ \n\n=====\n"); break;
    }
    screenSetColor(LIGHTGRAY, BLACK); // Reseta para as cores padrão
}

// Função principal do jogo
void jogar(Jogador* jogador) {
    char* palavra = escolherPalavra(); // Escolhe uma palavra aleatória
    int tamanhoPalavra = strlen(palavra);
    char* palavraAdivinhada = (char*)malloc(tamanhoPalavra + 1); // Aloca espaço para a palavra oculta
    memset(palavraAdivinhada, '_', tamanhoPalavra); // Preenche com '_'
    palavraAdivinhada[tamanhoPalavra] = '\0';

    int tentativasRestantes = 6;
    char letra;

    while (tentativasRestantes > 0 && !ganhou(palavra, palavraAdivinhada)) {
        limparTela(); 
        screenSetColor(LIGHTCYAN, BLACK);
        printf("=== Bem-vindo ao Jogo da Forca! ===\n");
        screenSetColor(LIGHTGRAY, BLACK);
        desenharForca(tentativasRestantes); // Desenha a forca conforme as tentativas restantes
        printf("Palavra: ");
        screenSetColor(YELLOW, BLACK);
        printf("%s\n", palavraAdivinhada); // Exibe a palavra adivinhada com uma cor diferente
        screenSetColor(LIGHTGRAY, BLACK);
        printf("Tentativas restantes: %d\n", tentativasRestantes);
        screenSetColor(LIGHTGREEN, BLACK);
        printf("Digite uma letra: ");
        screenSetColor(LIGHTGRAY, BLACK);
        scanf(" %c", &letra);
        letra = tolower(letra);

        int acertou = 0;
        for (int i = 0; i < tamanhoPalavra; i++) {
            if (palavra[i] == letra && palavraAdivinhada[i] == '_') {
                palavraAdivinhada[i] = letra;
                acertou = 1;
            }
        }

        if (!acertou) {
            tentativasRestantes--;
        }

        jogador->tentativas++; // Contador de tentativas
    }

    limparTela();
    if (ganhou(palavra, palavraAdivinhada)) {
        jogador->acertos++; // Contador de acertos
        imprimirMensagem("Parabéns! Você ganhou!", LIGHTGREEN);
    } else {
        imprimirMensagem("Você perdeu!", RED); 
        printf("A palavra era: %s\n", palavra);
    }

    free(palavra); // Libera a memória alocada
    free(palavraAdivinhada); // Libera a memória alocada
}

int main() {
    Jogador jogador;
    jogador.tentativas = 0;
    jogador.acertos = 0;

    printf("Digite seu nome: ");
    fgets(jogador.nome, 50, stdin);
    jogador.nome[strcspn(jogador.nome, "\n")] = '\0';

    char jogarNovamente;
    do {
        jogar(&jogador);
        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);
    } while (tolower(jogarNovamente) == 's');

    printf("Obrigado por jogar, %s! Tentativas: %d, Acertos: %d\n", jogador.nome, jogador.tentativas, jogador.acertos);

    return 0;
}
