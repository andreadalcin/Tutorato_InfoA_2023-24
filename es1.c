#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    char val;
    struct n *left;
    struct n *right;
} nodo;

typedef nodo *albero;

albero createVal(char val);

albero creaAlbero1();

albero creaAlbero2();

albero creaAlbero3();

void print(albero t);

void stampa(albero T);

int f(albero t, char str[]);

/* Funzioni da noi implementate */
int f_rec(albero t, int cnt, char str[]);

int indexOf(char c, const char *str);

int main() {
    int ris = 0;
    char str1[100] = "acacia", str2[100] = "sacca";
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
    printf("\n");

    //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI
    printf("%d\n", f(T1, str1));
    printf("%d\n", f(T1, str2));
    printf("%d\n", f(T2, str1));
    printf("%d\n", f(T2, str2));
    printf("%d\n", f(T3, str1));
    printf("%d\n", f(T3, str2));

    return 0;
}


//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
int f_rec(albero t, int cnt, char str[]) {
    if (indexOf(t->val, str) >= 0) {
        cnt++;
    }
    // cnt += indexOf(t->val, str) >= 0 ? 1 : 0;

    // Caso base
    if (t->left == NULL && t->right == NULL) {
        if (cnt == 2) {
            return 1;
        }

        return 0;
        // return cnt == 2 ? 1 : 0;
    }

    int sx = 1, dx = 1;
    if (t->left != NULL) {
        sx = f_rec(t->left, cnt, str);
    }
    if (t->right != NULL) {
        dx = f_rec(t->right, cnt, str);
    }

    if (sx == 1 && dx == 1) {
        return 1;
    }

    return 0;
    // return (sx == 1 && dx == 1) ? 1 : 0;
}

int indexOf(const char c, const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i]) {
            return i;
        }
    }
    return -1;
}

int f(albero t, char str[]) {
    if (t == NULL) {
        return 0;
    }

    return f_rec(t, 0, str);
}

albero creaAlbero1() {
    albero tmp = createVal('a');
    tmp->left = createVal('c');
    tmp->left->left = createVal('o');
    tmp->left->right = createVal('b');
    tmp->right = createVal('d');
    tmp->right->left = createVal('c');
    tmp->right->right = createVal('r');
    tmp->right->right->left = createVal('c');
    tmp->right->right->right = createVal('a');
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal('a');
    tmp->left = createVal('c');
    tmp->left->left = createVal('o');
    tmp->left->right = createVal('b');
    tmp->right = createVal('d');
    tmp->right->left = createVal('c');
    tmp->right->right = createVal('a');
    tmp->right->right->left = createVal('c');
    tmp->right->right->right = createVal('a');
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal('s');
    tmp->left = createVal('c');
    tmp->left->left = createVal('o');
    tmp->left->right = createVal('b');
    tmp->right = createVal('d');
    tmp->right->left = createVal('c');
    tmp->right->right = createVal('r');
    tmp->right->right->left = createVal('c');
    tmp->right->right->right = createVal('a');
    return tmp;
}

void print(albero t) {
    if (t == NULL)return;
    else {
        printf(" (");
        print(t->left);
        printf(" %c ", t->val);
        print(t->right);
        printf(") ");
    }
}

void stampa(albero T) {
    print(T);
    printf("\n");
}

albero createVal(char val) {
    albero tmp = malloc(sizeof(nodo));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}
