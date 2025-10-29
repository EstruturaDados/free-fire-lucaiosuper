#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

void cadastrarItem(struct Item mochila[], int *numItens);
void removerItem(struct Item mochila[], int *numItens);
void listarItens(struct Item mochila[], int numItens);
void buscarItem(struct Item mochila[], int numItens);

int main() {
    struct Item mochilaDoJogador[MAX_ITENS];
    int numItens = 0;
    int opcao;

    do {
        printf("\n--- Mochila de Loot Inicial ---\n");
        printf("1. Cadastrar novo item\n");
        printf("2. Remover item\n");
        printf("3. Listar todos os itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("-------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarItem(mochilaDoJogador, &numItens);
                break;
            case 2:
                removerItem(mochilaDoJogador, &numItens);
                break;
            case 3:
                listarItens(mochilaDoJogador, numItens);
                break;
            case 4:
                buscarItem(mochilaDoJogador, numItens);
                break;
            case 0:
                printf("\nFechando a mochila. Ate a proxima!\n");
                break;
            default:
                printf("\nOpcao invalida! Por favor, escolha um numero do menu.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}

void cadastrarItem(struct Item mochila[], int *numItens) {
    if (*numItens >= MAX_ITENS) {
        printf("\nErro: A mochila esta cheia! Nao e possivel carregar mais itens.\n");
        return;
    }

    printf("\n--- Cadastro de Item ---\n");
    printf("Nome do item: ");
    scanf("%s", mochila[*numItens].nome);

    printf("Tipo do item (ex: arma, municao, cura): ");
    scanf("%s", mochila[*numItens].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*numItens].quantidade);

    (*numItens)++;
    printf("\nItem cadastrado com sucesso!\n");
}

void removerItem(struct Item mochila[], int *numItens) {
    char nomeParaRemover[30];
    int indiceParaRemover = -1;

    if (*numItens == 0) {
        printf("\nA mochila esta vazia. Nada para remover.\n");
        return;
    }

    printf("\n--- Remocao de Item ---\n");
    printf("Digite o nome do item que deseja remover: ");
    scanf("%s", nomeParaRemover);

    for (int i = 0; i < *numItens; i++) {
        if (strcmp(mochila[i].nome, nomeParaRemover) == 0) {
            indiceParaRemover = i;
            break;
        }
    }

    if (indiceParaRemover != -1) {
        for (int i = indiceParaRemover; i < *numItens - 1; i++) {
            mochila[i] = mochila[i + 1];
        }
        (*numItens)--;
        printf("\nItem '%s' removido com sucesso!\n", nomeParaRemover);
    } else {
        printf("\nErro: Item '%s' nao encontrado na mochila.\n", nomeParaRemover);
    }
}

void listarItens(struct Item mochila[], int numItens) {
    if (numItens == 0) {
        printf("\nA mochila esta vazia. Nada para exibir.\n");
        return;
    }

    printf("\n--- Conteudo da Mochila (%d de %d) ---\n", numItens, MAX_ITENS);
    for (int i = 0; i < numItens; i++) {
        printf("---------------------------\n");
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
    printf("---------------------------\n");
}

void buscarItem(struct Item mochila[], int numItens) {
    char nomeParaBuscar[30];
    int encontrado = 0;

    if (numItens == 0) {
        printf("\nA mochila esta vazia. Nao ha itens para buscar.\n");
        return;
    }
    
    printf("\n--- Busca de Item ---\n");
    printf("Digite o nome do item que deseja buscar: ");
    scanf("%s", nomeParaBuscar);

    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nomeParaBuscar) == 0) {
            printf("\nItem encontrado!\n");
            printf("---------------------------\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            printf("---------------------------\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nItem '%s' nao foi encontrado na mochila.\n", nomeParaBuscar);
    }
}
