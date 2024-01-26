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

void print(albero t);

void stampa(albero T);

void f(albero input, albero risultato);

int depth(albero t);

int max(int a, int b);

void inizializza(albero t, int v[], int liv);

void verifica(albero t, int elem[], int v[], int liv);

/* Funzioni da noi implementate */
void f_rec(albero input, albero risultato);

int calcolaPunteggio(albero nodo1, albero nodo2);


int main() {
    int ris = 0;
    albero input, risultato;
    input = creaAlbero1();
    risultato = creaAlbero2();
    printf("\nalberi in input: ");
    stampa(input);
    printf("\nalbero risultato con solo 0: ");
    stampa(risultato);

    //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI
    f(input, risultato);

    printf("\nalbero risultato dopo esecuzione della funzione\n");
    stampa(risultato);

    return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
void f(albero input, albero risultato) {
    if (input == NULL || risultato == NULL) {
        return;
    }

    // Radice ha sempre punteggio 0.
    risultato->val = 0;

    f_rec(input, risultato);
}

void f_rec(albero input, albero risultato) {
    // Caso base: siamo in un nodo foglia, non dobbiamo assegnare più valori all'albero 'risultato'
    if (input->left == NULL && input->right == NULL) {
        return;
    }

    // Nodo corrente è il nodo genitore, input->left e input-right sono i nodi figli (se esistono)
    if (input->left != NULL) {
        risultato->left->val = calcolaPunteggio(input, input->left);
        f_rec(input->left, risultato->left);
    }

    if (input->right != NULL) {
        risultato->right->val = calcolaPunteggio(input, input->right);
        f_rec(input->right, risultato->right);
    }
}

int calcolaPunteggio(albero nodo1, albero nodo2) {
    int delta = nodo1->val - nodo2->val;
    int abs;
    if (delta < 0) {
        abs = -delta;
    } else {
        abs = delta;
    }
    // abs = delta < 0 ? -delta : delta;

    if (abs <= 3) {
        return 1;
    }
    if (abs <= 5) {
        return 2;
    }
    if (abs <= 8) {
        return 3;
    }
    return 4;
}



albero creaAlbero1() {
    albero tmp = createVal(5);
    tmp->left = createVal(5);
    tmp->left->left = createVal(3);
    tmp->left->right = createVal(0);
    tmp->right = createVal(5);
    tmp->right->left = createVal(9);
    tmp->right->right = createVal(1);
    tmp->right->right->left = createVal(7);
    tmp->right->right->right = createVal(10);
    tmp->left->left->left = createVal(0);
    tmp->left->left->right = createVal(2);
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal(0);
    tmp->left = createVal(0);
    tmp->left->left = createVal(0);
    tmp->left->right = createVal(0);
    tmp->right = createVal(0);
    tmp->right->left = createVal(0);
    tmp->right->right = createVal(0);
    tmp->right->right->left = createVal(0);
    tmp->right->right->right = createVal(0);
    tmp->left->left->left = createVal(0);
    tmp->left->left->right = createVal(0);
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
