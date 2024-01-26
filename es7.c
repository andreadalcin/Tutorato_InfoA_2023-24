#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct n {
    char codice[100];
    int punteggio;
    struct n *next;
} nodo;

typedef nodo *Lista;

Lista InsInFondo(Lista lista, char c[], int p);

void VisualizzaLista(Lista lista);

Lista costruisci();

Lista caux(Lista lista, int i);

//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
Lista aggrega(Lista);

int codiceIn(Lista, const char *);

int main() {
    Lista lis, risultato;
    lis = costruisci();
    VisualizzaLista(lis);
    printf("\n\n");

    //TODO: invocazione funzione e visualizzazione risultato
    Lista aggr = aggrega(lis);
    VisualizzaLista(aggr);

    return 0;
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//
Lista aggrega(Lista list) {
    Lista aggr = NULL;

    for (Lista cur = list; cur != NULL; cur = cur->next) {
        if (codiceIn(aggr, cur->codice) != 0) {
            // Il codice corrente è già presente nella lista aggregata, non serve aggiungerlo nuovamente.
            continue;
        }

        // Calcola la somma dei punteggi per lo stesso cliente (codice)
        int sommaPunteggi = cur->punteggio;
        for (Lista cur1 = cur->next; cur1 != NULL; cur1 = cur1->next) {
            if (strcmp(cur1->codice, cur->codice) == 0) {
                sommaPunteggi += cur1->punteggio;
            }
        }

        // Aggiungo in coda ad 'aggr' un nuovo nodo con il cliente.
        const Lista ptr = malloc(sizeof(nodo));
        strcpy(ptr->codice, cur->codice);
        ptr->punteggio = sommaPunteggi;
        ptr->next = NULL;

        if (aggr == NULL) {
            aggr = ptr;
        } else {
            Lista cur2;
            for (cur2 = aggr; cur2->next != NULL; cur2 = cur2->next) {
            }
            cur2->next = ptr;
        }
    }

    return aggr;
}

int codiceIn(Lista list, const char *codice) {
    for (; list != NULL; list = list->next) {
        if (strcmp(list->codice, codice) == 0) {
            return 1;
        }
    }
    return 0;
}

Lista costruisci() { return caux(NULL, 0); }

Lista caux(Lista lista, int i) {
    int p[50] = {
        57, 63, 70, 88, 91, 97, 57, 59, 66, 88, 94, 92, 77, 61, 68, 75, 85, 94, 68, 77, 63, 89, 85, 100, 57, 77, 59, 97,
        68, 60, 87, 92, 94, 66, 61, 68, 75, 63, 89, 68, 75, 94, 57, 63, 75, 66, 92, 61, 77, 70
    };
    char c[50][20] = {
        "c2", "c1", "c3", "c1", "c5", "c2", "c5", "c4", "c5", "c1", "c3", "c4", "c4", "c5", "c1", "c5", "c2", "c2",
        "c5", "c2", "c3", "c1", "c5", "c3", "c1", "c3", "c3", "c2", "c2", "c1", "c3", "c3", "c1", "c4", "c3", "c4",
        "c4", "c4", "c1", "c1", "c2", "c2", "c4", "c2", "c2", "c5", "c5", "c3", "c4", "c3"
    };
    if (i == 50) return NULL;
    lista = (Lista) malloc(sizeof(nodo));
    lista->codice[0] = c[i][0];
    lista->codice[1] = c[i][1];
    lista->codice[2] = c[i][2];
    lista->punteggio = p[i];
    lista->next = caux(lista->next, i + 1);
    return lista;
}

void VisualizzaLista(Lista lista) {
    if (lista == NULL) printf(" ---| \n");
    else {
        printf(" (%s,%i) ---> ", lista->codice, lista->punteggio);
        VisualizzaLista(lista->next);
    }
}
