#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int val;
    struct n *left;
    struct n *right;
} nodo;

typedef nodo *albero;

albero createVal(int val);

albero creaAlbero1();

albero creaAlbero2();

albero creaAlbero3();

void print(albero t);

void stampa(albero T);

int f(albero t);

int depth(albero t);

int max(int a, int b);

void inizializza(albero t, int v[], int liv);

void verifica(albero t, int elem[], int v[], int liv);

/* Funzioni da noi implementate */
int f_rec(albero cur, albero radice, int livello);

int iso_livello(albero t, int d, int valore, int livello);

int main() {
    int ris = 0;
    albero T1, T2, T3;
    T1 = creaAlbero1();
    T2 = creaAlbero2();
    T3 = creaAlbero3();
    printf("\nT1: ");
    stampa(T1);
    printf("\nT2: ");
    stampa(T2);
    printf("\nT3: ");
    stampa(T3);

    //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI

    printf("T1: %d\n", f(T1));
    printf("T2: %d\n", f(T2));
    printf("T3: %d\n", f(T3));

    return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
int f(albero t) {
    if (t == NULL) { return 0; }
    if (f_rec(t->left, t, 1) == 1) { return 1; }
    return f_rec(t->right, t, 1);
}

int f_rec(albero cur, albero radice, int livello) {
    // Caso base: albero vuoto o fuori dai confini dell'albero.
    if (cur == NULL) { return 0; }
    // Caso base: il livello corrente dell'albero soddisfa la condizione.
    if (iso_livello(radice, 0, cur->val, livello) == 1) { return 1; }

    // -----------------------------------------------------------------------------------------------------------------
    if (f_rec(cur->left, radice, livello + 1) == 1) { return 1; }
    return f_rec(cur->right, radice, livello + 1);
}

/**
 * Funzione restituisce 1 se i nodi a 'livello' contengono tutti lo stesso 'valore'
 * Inizialmente, t è la radice dell'albero e d è la profondità corrente di t, ovvero 0
 */
int iso_livello(albero t, int d, int valore, int livello) {
    // Caso base: fuori dai 'confini' dell'albero
    if (t == NULL) { return 1; }
    // Caso base: siamo al livello target, controlliamo la corrispondenza di valori.
    if (d == livello) {
        if (t->val != valore) {
            return 0;
        }
    }

    // -----------------------------------------------------------------------------------------------------------------
    if (iso_livello(t->left, d + 1, valore, livello) == 0) { return 0; }
    if (iso_livello(t->right, d + 1,  valore, livello) == 0) { return 0; }
    return 1;
}

albero creaAlbero1() {
    albero tmp = createVal(7);
    tmp->left = createVal(3);
    tmp->left->left = createVal(9);
    tmp->left->right = createVal(9);
    tmp->right = createVal(8);
    tmp->right->left = createVal(9);
    tmp->right->right = createVal(9);
    tmp->right->right->left = createVal(11);
    tmp->right->right->right = createVal(6);
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);
    tmp->right->right = createVal(9);
    tmp->right->left = createVal(10);
    tmp->left = createVal(1);
    tmp->left->right = createVal(5);
    tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);
    tmp->left->left->left = createVal(6);
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);
    tmp->right->right = createVal(9);
    tmp->right->left = createVal(10);
    tmp->left = createVal(4);
    tmp->left->right = createVal(5);
    tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(2);
    tmp->left->left->left = createVal(6);
    return tmp;
}

void print(albero t) {
    if (t == NULL)return;
    else {
        printf(" (");
        print(t->left);
        printf(" %d ", t->val);
        print(t->right);
        printf(") ");
    }
}

void stampa(albero T) {
    print(T);
    printf("\n");
}

albero createVal(int val) {
    albero tmp = malloc(sizeof(nodo));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
