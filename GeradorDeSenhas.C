#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SENHAS 5
#define MAX_CARACTERES 128
#define MAX_NOME 50

//estrutura pra armazenar senha e o nome
typedef struct {
    char nome[MAX_NOME];
    char senha[MAX_CARACTERES];
} Senha;

//funcao para gerar uma senha aleatoria
void gerarSenha(char *senha, int tamanho, int incluirNumeros, int incluirLetras, int incluirEspeciais) {
    char numeros[] = "0123456789";
    char letras[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char especiais[] = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    char caracteresDisponiveis[MAX_CARACTERES] = "";

    //add caracteres de acordo com a escolha do usuario
    if (incluirNumeros) strcat(caracteresDisponiveis, numeros);
    if (incluirLetras) strcat(caracteresDisponiveis, letras);
    if (incluirEspeciais) strcat(caracteresDisponiveis, especiais);

    int len = strlen(caracteresDisponiveis);

    //gera a senha aleatoria
    for (int i = 0; i < tamanho; i++) {
        senha[i] = caracteresDisponiveis[rand() % len];
    }
    senha[tamanho] = '\0'; //seta o fim da string
}

//menu
void menu() {
    printf("\n=== Gerador de Senhas ===\n");
    printf("1. Gerar senha com apenas numeros\n");
    printf("2. Gerar senha com apenas letras\n");
    printf("3. Gerar senha com numeros e letras\n");
    printf("4. Gerar senha com numeros, letras e caracteres especiais\n");
    printf("5. Exibir as senhas geradas\n");
    printf("6. Apagar uma senha\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
}

//apagador de senha
void apagarSenha(Senha senhas[], int *senhaCount) {
    if (*senhaCount == 0) {
        printf("Nenhuma senha foi gerada ainda.\n");
        return;
    }

    //mostra as senhas disponiveis
    printf("Senhas disponiveis:\n");
    for (int i = 0; i < *senhaCount; i++) {
        printf("%d. Nome: %s | Senha: %s\n", i + 1, senhas[i].nome, senhas[i].senha);
    }

    //seleciona a senha
    printf("Digite o numero da senha que deseja apagar: ");
    int escolha;
    scanf("%d", &escolha);

    //entrada
    if (escolha < 1 || escolha > *senhaCount) {
        printf("Opcao invalida.\n");
        return;
    }

    //remove a senha selecionada
    for (int i = escolha - 1; i < *senhaCount - 1; i++) {
        senhas[i] = senhas[i + 1];
    }
    (*senhaCount)--;

    printf("Senha apagada com maestria.\n");
}

int main() {
    srand(time(NULL)); //inicializador
    Senha senhas[MAX_SENHAS]; //vetor das senhas e nomes
    int senhaCount = 0;       //contador de senhas guardadas
    int opcao, tamanho;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: //apenas numeros
            case 2: //apenas letras
            case 3: //numeros e letras
            case 4: //numeros, letras e caracteres especiais
                if (senhaCount < MAX_SENHAS) {
                    printf("Informe o tamanho da senha: ");
                    scanf("%d", &tamanho);

                    //nome da senha
                    printf("Informe o nome para esta senha: ");
                    getchar(); //apaga o buffer
                    fgets(senhas[senhaCount].nome, MAX_NOME, stdin);
                    senhas[senhaCount].nome[strcspn(senhas[senhaCount].nome, "\n")] = '\0'; // Remove o '\n'

                    //gera a senha
                    if (opcao == 1) {
                        gerarSenha(senhas[senhaCount].senha, tamanho, 1, 0, 0);
                    } else if (opcao == 2) {
                        gerarSenha(senhas[senhaCount].senha, tamanho, 0, 1, 0);
                    } else if (opcao == 3) {
                        gerarSenha(senhas[senhaCount].senha, tamanho, 1, 1, 0);
                    } else if (opcao == 4) {
                        gerarSenha(senhas[senhaCount].senha, tamanho, 1, 1, 1);
                    }

                    printf("Senha gerada: %s\n", senhas[senhaCount].senha);
                    senhaCount++;
                } else {
                    printf("Limite de senhas armazenadas atingido.\n");
                }
                break;

            case 5: //view das senhas
                if (senhaCount == 0) {
                    printf("Nenhuma senha foi gerada ainda.\n");
                } else {
                    printf("\nSenhas geradas:\n");
                    for (int i = 0; i < senhaCount; i++) {
                        printf("%d. Nome: %s | Senha: %s\n", i + 1, senhas[i].nome, senhas[i].senha);
                    }
                }
                break;

            case 6: //apagar uma senha
                apagarSenha(senhas, &senhaCount);
                break;

            case 7: //exit
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 7);

return 0; 
}
