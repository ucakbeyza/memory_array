#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hataKontrol(int boyut) {
    if (boyut <= 0) {
        printf("HATALI İŞLEM: Dizi boyutu pozitif bir tam sayi olmalidir.\n");
        exit(EXIT_FAILURE);
    }
}

void tekCiftAyir(int dizi[], int boyut, int **tDizi, int **cDizi, int *tBoyut, int *cBoyut) {
    *tDizi = (int *) malloc(boyut * sizeof(int));
    *cDizi = (int *) malloc(boyut * sizeof(int));
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] % 2 == 0) {
            (*cDizi)[*cBoyut] = dizi[i];
            (*cBoyut)++;
        } else {
            (*tDizi)[*tBoyut] = dizi[i];
            (*tBoyut)++;
        }
    }
}

void diziYazdir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main() {
    int boyut;

    printf("Dizinin boyutunu girin: ");
    scanf("%d", &boyut);

    hataKontrol(boyut);

    int *dizi = (int *) malloc(boyut * sizeof(int));
    int *tekDizi = NULL;
    int *ciftDizi = NULL;
    int tekBoyut = 0, ciftBoyut = 0;

    srand(time(NULL));
    printf("Dizi elemanları:\n");
    for (int i = 0; i < boyut; i++) {
        dizi[i] = rand() % 100;
        printf("%d ", dizi[i]);
    }
    printf("\n");

    tekCiftAyir(dizi, boyut, &tekDizi, &ciftDizi, &tekBoyut, &ciftBoyut);

    printf("Tek sayılar:\n");
    diziYazdir(tekDizi, tekBoyut);

    printf("Çift sayılar:\n");
    diziYazdir(ciftDizi, ciftBoyut);

    free(dizi);
    free(tekDizi);
    free(ciftDizi);

    return 0;
}
