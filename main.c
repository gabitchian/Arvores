/*
Disciplinas : Estruturas de Dados B
Assunto : Exercício Árvore
Professor : Nakamiti
Aluna : Gabriela Tchian (19001239)
Data : 05/04/2020
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct arvore {
    int item;
    struct arvore *dir;
    struct arvore *esq;
};

typedef struct arvore no;

struct arvore *inicio, *aux, *novo, *ant;


int insere_esquerda(int n) {
    novo = (no *) malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro na alocação de memória! \n");
    }
    novo->item = n;
    novo->dir = NULL;
    novo->esq = NULL;
    ant->esq = novo;
}

int insere_igual(int n) {
    novo = (no *) malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro na alocação de memória! \n");
    }
    novo->item = n;
    novo->dir = NULL;
    ant->esq = novo;
    novo->esq = aux;
}


int insere_direita(int n) {
    novo = (no *) malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro na alocação de memória! \n");
    }
    novo->item = n;
    novo->dir = NULL;
    novo->esq = NULL;
    ant->dir = novo;
}


int busca_fim(int n) {
    aux = inicio;
    ant = aux;
    while (aux != NULL) {
        if (n < aux->item) {
            aux = aux->esq;
            if (aux != NULL) {
                ant = aux;
            } else {
                insere_esquerda(n);
            }
        }//if
        else if (n > aux->item) {
            aux = aux->dir;
            if (aux != NULL) {
                ant = aux;
            } else {
                insere_direita(n);
            }
        }//if
        else {
            aux = aux->esq;
            if (aux != NULL) {
                //printf("\n\nAux: %d | Ant: %d | Inicio: %d.\n\n",aux->item,ant->item,inicio->item);
                insere_igual(n);
                break;
            } else {
                insere_esquerda(n);
            }
        }
    }//while
}//busca_fim


int insere_arvore(int n) {
    if (inicio == NULL) {
        inicio = (no *) malloc(sizeof(no));
        if (inicio == NULL) {
            printf("\nErro na alocacao de memoria!\n");
            exit(EXIT_FAILURE);
        }
        inicio->item = n;
        inicio->dir = NULL;
        inicio->esq = NULL;
    } else {
        //verificar menor e maior
        busca_fim(n);
    }
}

int busca_arvore() {
    int valor;
    printf("Digite o valor a ser encontrado: ");
    scanf("%d", &valor);
    printf("\n");
    aux = inicio;
    if (valor == inicio->item) {
        printf("\nElemento encontrado: %d\n", inicio->item);
    } else {
        do {
            if (valor < aux->item) {
                aux = aux->esq;
            } else {
                aux = aux->dir;
            }
        } while ((aux != NULL) && (valor != aux->item));
        if (aux == NULL) {
            printf("\nElemento não encontrado!\n");
        } else {
            printf("\nElemento encontrado: %d\n", aux->item);
        }
    }
}

int busca_menor(no *busca) {
    if (busca == NULL)
        return (-1);
    if (busca->esq == NULL)
        return busca->item;
    busca_menor(busca->esq);
}

void pre_ordem(no *exibe) {
    if (exibe != NULL) {
        printf(" %d |", exibe->item);
        pre_ordem(exibe->esq);
        pre_ordem(exibe->dir);
    }
}

void pos_ordem(no *exibe) {
    if (exibe != NULL) {
        pos_ordem(exibe->esq);
        pos_ordem(exibe->dir);
        printf(" %d |", exibe->item);
    }
}

int qtd(no *primeiro, int quanti) {
    if ((primeiro->dir == NULL) && (primeiro->esq == NULL))
        quanti++;
    if (primeiro->esq != NULL)
        quanti = qtd(primeiro->esq, quanti);
    if (primeiro->dir != NULL)
        quanti = qtd(primeiro->dir, quanti);
    return quanti;
}

void ordem(no *exibe) {
    if (exibe != NULL) {
        ordem(exibe->esq);
        printf(" %d |", exibe->item);
        ordem(exibe->dir);
    }
}

void retorna_numeros_pares(int *qtd, no *elementos) {
    if (elementos != NULL) {
        if (elementos->esq != NULL) {
            retorna_numeros_pares(qtd, elementos->esq);
        }

        if (elementos->dir != NULL) {
            retorna_numeros_pares(qtd, elementos->dir);
        }

        if (elementos->item % 2 == 0) {
            (*qtd)++;
        }
    }
}

int um_filho(no *nos, int qtd){
    if(nos->esq != NULL)
        qtd = um_filho(nos->esq, qtd);
    if(nos->dir != NULL)
        qtd = um_filho(nos->dir, qtd);

    if(nos->esq != NULL && nos->dir == NULL)
        qtd++;
    else if(nos->esq == NULL && nos->dir != NULL)
        qtd++;

    return qtd;
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    int num, resp = 9, quanti = 0, pares = 0;
    while (resp != 0) {
        printf("\n1. Inserir um valor na lista");
        printf("\n2. Buscar um valor na lista");
        printf("\n3. Buscar o menor valor na lista");
        printf("\n4. Exibir lista pré ordem");
        printf("\n5. Exibir lista pós ordem");
        printf("\n6. Exibir lista em ordem");
        printf("\n7. Exibir a quantidade de folhas");
        printf("\n8. Exibir a quantidade de números pares");
        printf("\n10. Exibir a quantidade de nós que possuem UM filho");
        printf("\n0. Terminar Programa");
        printf("\n\n");
        scanf("%d", &resp);
        switch (resp) {
            case 0:
                printf("\nAté logo!\n");
                exit(EXIT_SUCCESS);
                break;
            case 1:
                printf("\nDigite o número: ");
                scanf("%d", &num);
                printf("\n");
                insere_arvore(num);
                break;
            case 2:
                busca_arvore();
                break;
            case 3:
                printf("\nMenor Número: %d\n", busca_menor(inicio));
                break;
            case 4:
                pre_ordem(inicio);
                break;
            case 5:
                pos_ordem(inicio);
                break;
            case 6:
                ordem(inicio);
                break;
            case 7:
                quanti = 0;
                printf("\nQuantidade de folhas: %d\n", qtd(inicio, quanti));
                break;
            case 8:
                retorna_numeros_pares(&pares, inicio);
                printf("\nQuantidade de folhas: %d\n", pares);
                break;
            case 10:
                printf("\nQuantidade de nós que possuem UM filho: %d\n", um_filho(inicio, 0));
        }
        printf("\n");
        system("pause");
        system("cls");
    }


    return 0;
}