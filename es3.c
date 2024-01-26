#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura Nodo
typedef struct N {
    int valore;
    struct N *left;
    struct N *right;
} Nodo;

typedef Nodo *Albero;

Albero nuovoNodo(int valore);

void stampaAlbero(Albero t);

void print(Albero t);

/* Funzioni da noi implementate */
int numeroFoglie(Albero t);

void f(Albero t, int **vec, int *len);

void f_rec(Albero t, int *vec, int somma, int *k);


int main() {
    // Creazione dell'albero
    Albero radice = nuovoNodo(3);
    radice->left = nuovoNodo(4);
    radice->right = nuovoNodo(9);
    radice->left->left = nuovoNodo(2);
    radice->left->right = nuovoNodo(7);
    radice->right->left = nuovoNodo(8);
    radice->left->left->left = nuovoNodo(1);
    radice->left->left->right = nuovoNodo(3);

    // Stampa dell'albero
    printf("Stampa dell'albero in ordine antecedente (radice, left, right):\n");
    stampaAlbero(radice);

    // Invocazione
    int *vec = NULL;
    int len;

    f(radice, &vec, &len);
    if (vec != NULL) {
        for (int i = 0; i < numeroFoglie(radice); i++) {
            if (i > 0) { printf(", "); }
            printf("%d", vec[i]);
        }
        free(vec);
    }

    return 0;
}

/* Funzioni da noi implementate */
int numeroFoglie(Albero t) {
    if (t == NULL) { return 0; }
    if (t->left == NULL && t->right == NULL) { return 1; }

    return numeroFoglie(t->left) + numeroFoglie(t->right);
}

void f(Albero t, int **vec, int *len) {
    if (t == NULL) {
        *vec = NULL;
        *len = 0;
        return;
    }

    *vec = malloc(numeroFoglie(t) * sizeof(int));
    *len = 0;
    f_rec(t, *vec, 0, len);
}

void f_rec(Albero t, int *vec, int somma, int *k) {
    somma += t->valore;

    // Caso base: nodo foglia
    if (t->left == NULL && t->right == NULL) {
        vec[*k] = somma;
        *k += 1;
        return;
    }

    if (t->left != NULL) {
        f_rec(t->left, vec, somma, k);
    }

    if (t->right != NULL) {
        f_rec(t->right, vec, somma, k);
    }
}


// Funzione per creare un nuovo nodo
Albero nuovoNodo(int valore) {
    Albero nodo = (Albero) malloc(sizeof(Nodo));
    nodo->valore = valore;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}

// Funzione per stampare l'albero
void stampaAlbero(Albero t) {
    print(t);
    printf("\n");
}

void print(Albero t) {
    if (t == NULL)return;
    else {
        printf(" (");
        print(t->left);
        printf(" %d ", t->valore);
        print(t->right);
        printf(") ");
    }
}
