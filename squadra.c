#include "squadra.h"
#include <string.h>
#include <stdlib.h>

int aggiungiSquadra(struct squadra **lista, int *nElementi, int *dimensione, char nome[], int reti) {
    int r = 0;

    if (*nElementi == *dimensione) {
        r = ingrandisci(lista, dimensione);
    }
    if (r == 0) {
        strcpy((*lista)[*nElementi].nome, nome);
        (*lista)[*nElementi].reti = reti;
        (*nElementi)++;
    }

    return r;
}

int ingrandisci(struct squadra **lista, int *dimensione) {
    int r = -1;
    int nuovaDimensione = 2;
    int i;
    struct squadra *nuovaLista;
    if (*dimensione != 0)
        nuovaDimensione *= 2;
    nuovaLista = (struct squadra *) malloc(nuovaDimensione * sizeof (struct squadra));
    if (nuovaLista != NULL) {
        for (i = 0; i<*dimensione; i++)
            nuovaLista[i] = (*lista)[i];
        r = 0;
    }
    return r;
}
