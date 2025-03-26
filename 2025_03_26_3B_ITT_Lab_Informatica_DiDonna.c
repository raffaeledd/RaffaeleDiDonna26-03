#include <stdio.h>

struct oggetto {
    int codice;
    int quantita;
    float prezzo;
};

int inserimento(struct oggetto *oggetto, int imput) {
    int ultimooggetto = imput;
    int x;

    do {
        printf("inserisci il numero di oggetti che si ha nel magazino (1-100):\n");

        scanf("%d", &x);
        imput += x;
        if (imput > 100) {
            printf("valore oltre il limite");
        }
    } while (imput > 100 || imput < 1);

    for (int i = ultimooggetto; i < imput; i++) {
        printf("inserisci il codice del prodotto:\n");
        scanf("%d", &oggetto[i].codice);
        printf("inserisci la quantita del prodotto:\n");
        scanf("%d", &oggetto[i].quantita);
        printf("inserisci il prezzo del prodotto:\n");
        scanf("%f", &oggetto[i].prezzo);
    }
    return imput;
}

void stampa(struct oggetto *oggetto, int numeroprodotti) {
    for (int i = 0; i < numeroprodotti; i++) {
        printf("codice prodotto:\t\t%d\n", oggetto[i].codice);
        printf("quantita' prodotto:\t\t%d\n", oggetto[i].quantita);
        printf("prezzo prodotto(singolo):\t%.2f$\n", oggetto[i].prezzo);
        printf("\n");
    }
}

int ricercapercodice(struct oggetto *oggetto, int numeroprodotti) {
    printf("inserisci il codice del prodotto da cercare:\n");
    int ricercacodice;
    scanf("%d", &ricercacodice);

    for (int i = 0; i < numeroprodotti; i++) {
        if (oggetto[i].codice == ricercacodice) {
            printf("codice prodotto cercato:\t\t%d\n", oggetto[i].codice);
            printf("quantita' prodotto cercacto:\t\t%d\n", oggetto[i].quantita);
            printf("prezzo prodotto cercato:\t%.2f$\n", oggetto[i].prezzo);
            return i;
        }
    }
    printf("prodotto non trovato\n");
    return 0;
}

void modificaquantita(struct oggetto *oggetto, int numeroprodotti) {
    int i = ricercapercodice(oggetto, numeroprodotti);
    printf("modifica la quantita del prodotto:");
    scanf("%d", &oggetto[i].quantita);
}

void calcolovalore(struct oggetto *oggetto, int numeroprodotti) {
    float prezzototale = 0;
    for (int i = 0; i < numeroprodotti; i++) {
        prezzototale += (oggetto[i].prezzo * oggetto[i].quantita);
    }
    printf("il magazzino vale in totale:\t%.2f$\n", prezzototale);
}

int main(void) {
    struct oggetto oggetto[100];
    int imput = 0;
    int x = 1;

    imput = inserimento(oggetto, imput);

    while (x != 0) {
        do {
            printf(
                "\n\tmenu\n\ninserimineto piu elementi nel magazzino: 1\nstampa prodotti nel magazzino: 2\nricerca singolo elemento per codice: 3\nmodifica quantita' di un elemento cercato per valore: 4\ncalcolo totale valore del magazzino: 5\nuscita: 0\n\n");
            scanf("%d", &x);
        } while (x < 0 || x > 5);
        switch (x) {
            case 0:
                printf("buona giornata");
                break;
            case 1:
                imput=inserimento(oggetto, imput);
                break;
            case 2:
                stampa(oggetto, imput);
                break;
            case 3:
                ricercapercodice(oggetto, imput);
                break;
            case 4:
                modificaquantita(oggetto, imput);
                break;
            case 5:
                calcolovalore(oggetto, imput);
                break;
            default:

        }
    }
}
