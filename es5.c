#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef char Tipo[N];

typedef struct ndP {
    float costo;
    int tavolo;
    Tipo nome;
    struct ndP *next;
} Piatto;

typedef Piatto *ListaP;

typedef struct ndT {
    int tavolo;
    Piatto *piatti;
    // ListaP piatti;
    struct ndT *next;
} Tavolo;

typedef Tavolo *ListaT;


ListaP InsInFondoPiatto(ListaP lista, float costo, int tavolo, Tipo nome);

void VisualizzaListaP(ListaP lista);

ListaP costruisci();

void organizzaPerTavoli();

int main() {
    ListaP ordini = costruisci();
    ListaP temp;
    ListaT tavoli = NULL;
    VisualizzaListaP(ordini);

    organizzaPerTavoli(ordini, &tavoli);

    return 0;
}


void organizzaPerTavoli(Piatto *ordini, Tavolo **tavoli) {
    for (Piatto *piatto_cur = ordini; piatto_cur != NULL; piatto_cur = piatto_cur->next) {
        // Cerco corrispondenza di identificativo piatto-tavolo.
        Tavolo *tavolo_cur;
        for (tavolo_cur = *tavoli; tavolo_cur != NULL; tavolo_cur = tavolo_cur->next) {
            if (tavolo_cur->tavolo == piatto_cur->tavolo) {
                break;
            }
        }

        if (tavolo_cur == NULL) {
            // Altrimenti creiamo nuovo elemento e aggiungiamo in fondo a 'tavoli'.
            tavolo_cur = malloc(sizeof(Tavolo));
            tavolo_cur->tavolo = piatto_cur->tavolo;
            if (*tavoli == NULL) {
                *tavoli = tavolo_cur;
            } else {
                Tavolo *cur;
                for (cur = *tavoli; cur->next != NULL; cur = cur->next) {
                }
                cur->next = tavolo_cur;
            }
        }

        tavolo_cur->piatti = InsInFondoPiatto(tavolo_cur->piatti,
                                              piatto_cur->costo,
                                              piatto_cur->tavolo,
                                              piatto_cur->nome);
    }
}


// Sviluppare qui le funzioni richieste
ListaP costruisci() {
    ListaP lista = NULL;
    lista = InsInFondoPiatto(lista, 10.5, 1, "Karelian Pie");
    lista = InsInFondoPiatto(lista, 8.0, 1, "Makkara");
    lista = InsInFondoPiatto(lista, 12.0, 1, "Musta Makkara");
    lista = InsInFondoPiatto(lista, 20, 2, "Baltic Herrings");
    lista = InsInFondoPiatto(lista, 20, 2, "Pasta all'Amatriciana");
    lista = InsInFondoPiatto(lista, 20, 1, "Herrings");
    lista = InsInFondoPiatto(lista, 20, 4, "Sgombro al Limone");
    lista = InsInFondoPiatto(lista, 20, 4, "Tiramisu'");
    return lista;
}

ListaP InsInFondoPiatto(ListaP lista, float costo, int tavolo, Tipo nome) {
    ListaP punt;
    if (lista == NULL) {
        punt = malloc(sizeof(Piatto));
        punt->next = NULL;
        punt->costo = costo;
        punt->tavolo = tavolo;
        strcpy(punt->nome, nome);
        return punt;
    } else {
        lista->next = InsInFondoPiatto(lista->next, costo, tavolo, nome);
        return lista;
    }
}

void VisualizzaListaP(ListaP lista) {
    if (lista == NULL) printf(" ---| \n");
    else {
        printf("\n nome:%s, tav:%d (%.2f) ---> ", lista->nome, lista->tavolo, lista->costo);
        VisualizzaListaP(lista->next);
    }
}
