#include <stdio.h>
#include <stdlib.h>

#include "dummyMath.h"
#include "squadra.h"

int main(int argc, char** argv) {
    float f;
    char scelta = 's';
    char nome[NOME_MAXLEN+1];
    int reti;
    int nSquadre = 0;
    int i;    
    struct squadra *lista;
    int dimensione;
    
    // SEZIONE 1 ------------------------------------------
    // ----------------------------------------------------
    printf("Inserisci un valore decimale da triplicare: ");
    scanf("%f", &f);
    // TODO Correggi l'implementazione della procedura raddoppia
    triplica(&f);
    printf("Il valore triplicato è: %f\n", f);
    
    // SEZIONE 2 ------------------------------------------
    // ----------------------------------------------------
    // Inserimento dei dati
    printf("\n==> Benvenuto nel più recente software di gestione fantacalcio.\n");
    while(scelta == 's') {
        printf("\nInserisci il nome della squadra (max %d caratteri): ", NOME_MAXLEN);
        scanf("%s", nome);
        printf("Inserisci il numero di reti: ");
        scanf("%d", &reti);
        
        // TODO Inserisci qui codice e chiamata alla funzione per l'aggiunta della squadra
        // nella memoria dinamica (vedi squadra.h)
        if(aggiungiSquadra(&lista, &nSquadre, &dimensione, nome, reti)) {
            fprintf(stderr, "Si è verificato un errore nell'allocazione di memoria.\n");
            exit(-1);
        }
        
        printf("Vuoi aggiungere un'altra squadra? (s/n) ");
        getchar();  // Non modificare (buffered read)
        scelta = getchar();
    }
    
    // Stampa delle informazioni, in ordine _INVERSO_ rispetto a quello di inserimento
    // TODO Modifica il codice seguente per eseguire quanto richiesto.
    // TODO Aggiungi eventuali funzioni a tuo piacimento
    printf("\nStampa degli elementi in ordine inverso rispetto all'inserimento\n");
    for(i=nSquadre-1; i>=0; i--) {
        printf("%s; %d\n", lista[i].nome, lista[i].reti);
    }
    
    return (EXIT_SUCCESS);
}
