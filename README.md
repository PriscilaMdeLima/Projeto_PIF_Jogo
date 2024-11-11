/Jogo-Da-Forca            
├── Makefile                
├── build/                 
│   ├── main.o             
│   ├── screen.o           
│   ├── timer.o            
│   ├── keyboard.o         
│   └── Jogo-Da-Forca      
├── include/               
│   ├── screen.h           
│   ├── timer.h            
│   ├── keyboard.h         
│   └── main.h             
└── src/                   
    ├── main.c             
    ├── screen.c           
    ├── timer.c            
    └── keyboard.c 


**Jogo da Forca em C**

Grupo: 
Priscila Maciel(github: PriscilaMdeLima)
Thaissa Fernandes(github:)
João Lucas Lira(github:)

**Linha de comando para compilar:**

```
gcc main.c CLI.c -o jogo_da_forca
```

**Objetivos:**

Desenvolver um jogo baseado em modo texto que atenda aos seguintes requisitos:

1. **Utilização da linguagem C e da biblioteca CLI-lib:**

O jogo utiliza a biblioteca CLI-lib para alterar a cor das letras, proporcionando uma experiência visual mais atraente. Fizemos uma adaptação que utiliza apenas as funcionalidades necessárias para a nossa ideia, focando especificamente nas mudanças de cor do texto exibido ao usuário.

2. **Implementação de lógica de jogo:**

   O jogo incorpora estruturas de controle, como laços e condições. O laço `while` controla o andamento do jogo, repetindo até que o jogador ganhe ou perca (quando as tentativas se esgotam). Condições como `if (!acertou)` são utilizadas para verificar se a letra inserida pelo jogador está correta, ajustando a quantidade de tentativas restantes em consequência.

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

5. **Manipulação de memória através de alocação dinâmica:**
   
	O código usa a função `malloc()` para alocar dinamicamente a memória necessária para armazenar a palavra secreta e a palavra adivinhada, garantindo que o jogo funcione para qualquer tamanho de palavra. A palavra escolhida aleatoriamente é copiada para um espaço de memória alocado dinamicamente:
   
   ```
   palavraAdivinhada = (char*)malloc(tamanhoPalavra + 1);
   ```

   A memória alocada dinamicamente é liberada ao final do jogo com `free()`:
   
   ```
   free(palavra);
   free(palavraAdivinhada);
   ```
