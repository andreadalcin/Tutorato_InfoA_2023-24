#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int giorno, mese, anno;
} Data;

typedef struct ELP {
    char nome[50];
    Data giorno_scadenza;
    struct ELP *next;
} NodoP;

typedef NodoP *ListaP;

typedef struct ELS {
    ListaP prodotti;
    struct ELS *next;
} NodoS;

typedef NodoS *ListaS;


ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno);

ListaS costruisci();

void stampaData(Data d);

void stampaProdotto(NodoP *prodotto);

void stampaProdotti(ListaP prodotti);

void stampaScaffale(NodoS *scaffale);

void stampaScaffali(ListaS scaffali);


int primaDi(Data d1, Data d2);

ListaS eliminaScaduti(ListaS scaffali, Data G);

ListaP Cancella(ListaP lista, char articolo[50], Data sca);

int main() {
    ListaS scaffali = costruisci();
    Data G = {5, 9, 2022};
    printf("Data di scadenza: ");
    stampaData(G);
    printf("\n\n");
    printf("Prima della rimozione dei prodotti scaduti:\n");
    stampaScaffali(scaffali);


    printf("Dopo la rimozione dei prodotti scaduti:\n");
    scaffali = eliminaScaduti(scaffali, G);

    stampaScaffali(scaffali);
    return 0;
}

ListaS eliminaScaduti(ListaS scaffali, Data G) {
    ListaS tmp;
    ListaP protmp;

    if (scaffali == NULL)
        return scaffali;

    for (tmp = scaffali; tmp != NULL; tmp = tmp->next) {
        for (protmp = tmp->prodotti; protmp != NULL; protmp = protmp->next) {
            if (primaDi(protmp->giorno_scadenza, G)) {
                tmp->prodotti = Cancella(tmp->prodotti, protmp->nome, protmp->giorno_scadenza);
            }
        }
    }

    return scaffali;
}


ListaP Cancella(ListaP lista, char articolo[], Data sca) {
    ListaP puntTemp;
    if (lista != NULL)
        if (strcmp(lista->nome, articolo) == 0 && lista->giorno_scadenza.anno == sca.anno && lista->giorno_scadenza.mese
            == sca.mese && lista->giorno_scadenza.giorno == sca.giorno) {
            puntTemp = lista->next;
            free(lista);
            return puntTemp;
        } else
            lista->next = Cancella(lista->next, articolo, sca);
    return lista;
}

int primaDi(Data d1, Data d2) {
    //che restituisce 1 se d1 è una data antecedente alla data d2, 0 altrimenti
    //anno prima di un altro
    if (d1.anno < d2.anno)
        return 1;
    // stesso anno e mese prima
    if (d1.anno == d2.anno && d1.mese < d2.mese)
        return 1;
    // stesso messe e anno e giorno prima
    if (d1.anno == d2.anno && d1.mese == d2.mese && d1.giorno < d2.giorno)
        return 1;
    else return 0;
}


ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno) {
    if (prodotti == NULL) {
        prodotti = (ListaP) malloc(sizeof(NodoP));
        Data scad = {giorno, mese, anno};
        strcpy(prodotti->nome, nome);
        prodotti->giorno_scadenza = scad;
        prodotti->next = NULL;
        return prodotti;
    } else {
        prodotti->next = aggiungiProdotto(prodotti->next, nome, giorno, mese, anno);
        return prodotti;
    }
}

ListaS costruisci() {
    ListaS scaffali = NULL;
    scaffali = (ListaS) malloc(sizeof(NodoS));
    scaffali->prodotti = NULL;
    scaffali->next = NULL;
    scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Pasta", 14, 7, 2027);
    scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Riso", 8, 11, 2020);
    scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Farro", 9, 3, 2029);
    scaffali->next = (ListaS) malloc(sizeof(NodoS));
    scaffali->next->prodotti = NULL;
    scaffali->next->next = NULL;
    scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Biscotti", 4, 6, 2020);
    scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Cereali", 2, 7, 2025);
    scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Toast", 1, 3, 2018);
    scaffali->next->next = (ListaS) malloc(sizeof(NodoS));
    scaffali->next->next->prodotti = NULL;
    scaffali->next->next->next = NULL;
    scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "More", 7, 9, 2016);
    scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Lamponi", 25, 12, 2017);
    scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Ribes", 18, 5, 2010);
    return scaffali;
}

void stampaData(Data d) { printf("%d/%d/%d", d.giorno, d.mese, d.anno); }

void stampaProdotto(NodoP *prodotto) {
    printf(" ~ %s in scadenza il ", prodotto->nome);
    stampaData(prodotto->giorno_scadenza);
}

void stampaProdotti(ListaP prodotti) {
    if (prodotti == NULL) {
        printf(" * \n");
        return;
    }
    stampaProdotto(prodotti);
    printf("\n");
    stampaProdotti(prodotti->next);
}

void stampaScaffale(NodoS *scaffale) {
    printf("+ - - -\n");
    stampaProdotti(scaffale->prodotti);
}

void stampaScaffali(ListaS scaffali) {
    if (scaffali == NULL) {
        printf("+ _ _ _\n\n");
        return;
    }
    stampaScaffale(scaffali);
    stampaScaffali(scaffali->next);
}
