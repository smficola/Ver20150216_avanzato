#define NOME_MAXLEN 30

struct squadra {
    char nome[NOME_MAXLEN+1];
    int reti;
};

int aggiungiSquadra(struct squadra **lista, int *nElementi, int *dimensione, char nome[], int reti);

int ingrandisci(struct squadra **lista, int *dimensione);