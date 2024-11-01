# Projeto_PIF_Jogo

Disciplina: Programação Imperativa e Funcional - 2024.2
Instituição de ensino: CESAR School
Professor: Diogo de Freitas Bezerra

Nome Jogo: Acerte ou Morra

Este projeto visa o desenvolvimento de um jogo utilizando a linguagem C, com o auxílio da
biblioteca CLI-lib.

Escolhemos desenvolver o jogo da forca,  envolve não apenas adivinhar palavras, mas também criar uma estratégia para maximizar as chances de ganhar, não sendo "enforcado".

Integrantes do Grupo: João Lira Github: joaosanli
Priscila Maciel Github: PriscilaMdeLima
Thaissa Fernandes Github: tsfLua

**Jogo da Forca em C**

**Linha de comando para compilar:**

```
gcc main.c CLI.c -o jogo_da_forca
```


   O jogo incorpora estruturas de controle, como laços e condições. O laço `while` controla o andamento do jogo, repetindo até que o jogador ganhe ou perca (quando as tentativas se esgotam).
   Condições como `if (!acertou)` são utilizadas para verificar se a letra inserida pelo jogador está correta, ajustando a quantidade de tentativas restantes em consequência.

3. **Uso de funções e procedimentos:**

   - `limparTela()`: Limpa a tela a cada jogada, garantindo uma interface limpa e interativa.
   - `imprimirMensagem()`: Imprime mensagens no console.
   - `escolherPalavra()`: Seleciona uma palavra aleatória de uma lista.
   - `ganhou()`: Verifica se o jogador completou a palavra.
   - `desenharForca()`: Desenha o estado atual da forca com base nas tentativas restantes.
   - `jogar()`: Função principal que engloba a lógica completa do jogo.

4. **Implementação de tipos estruturados e ponteiros:**

   A estrutura `Jogador` armazena informações sobre o jogador, como nome, número de tentativas e acertos:
   
   ```
   typedef struct {
       char nome[50];
       int tentativas;
       int acertos;
   } Jogador;
   ```

   Ponteiros são utilizados para a alocação dinâmica de memória, tanto para as palavras quanto para suas versões adivinhadas:
   
   ```
   char* palavraSelecionada = (char*)malloc(strlen(palavras[index]) + 1);
   ```

5. **Manipulação de memória através de alocação dinâmica:****Objetivos:**

Desenvolver um jogo baseado em modo texto que atenda aos seguintes requisitos:

1. **Utilização da linguagem C e da biblioteca CLI-lib:**

   O jogo utiliza a CLI-lib para realizar a mudança de cor das letras, proporcionando uma experiência visual mais atrativa.

2. **Implementação de lógica de jogo:**

   
	O código usa a função `malloc()` para alocar dinamicamente a memória necessária para armazenar a palavra secreta e a palavra adivinhada, garantindo que o jogo funcione para qualquer tamanho de palavra. A palavra escolhida aleatoriamente é copiada para um espaço de memória alocado dinamicamente:
   
   ```
   palavraAdivinhada = (char*)malloc(tamanhoPalavra + 1);
   ```

   A memória alocada dinamicamente é liberada ao final do jogo com `free()`:
   
   ```
   free(palavra);
   free(palavraAdivinhada);
   ```
