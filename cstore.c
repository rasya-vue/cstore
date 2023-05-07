#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char pilihan[1];
    char nama[10];
} Kategori;

typedef struct {
    char nama[50];
    int stock, harga;
} Aksesoris;

typedef struct {
    char nama[50];
    int stock, harga;
} Smartphone;

int main(void) {
    Kategori kate[] = {
        {"A", "Aksesoris"},
        {"S", "Smartphone"}
    };

    Aksesoris tipeak[] = {
        {"Charger 33W", 200, 159000},
        {"Redmi Buds Essential", 250, 199000},
        {"Powerbank Xiaomi 10.000mAh", 0, 249000},
        {"Redmi Smartband", 10, 399000},
        {"Redmi Buds 3", 10, 449000},
        {"Redmi Buds 3 Pro", 5, 699000}
    };

    Smartphone tipesm[] = {
        {"Redmi Note 12", 100, 2999000},
        {"Redmi Note 12 Pro", 80, 4599000},
        {"Poco M4 Pro", 200, 2799000},
        {"Poco X5 5G", 0, 3449000},
        {"iPhone 12", 0, 12499000},
        {"iPhone 12 Pro", 100, 15499000}
    };

    char katestore = sizeof(kate) / sizeof(kate[0]);
    int jmlaccak = sizeof(tipeak) / sizeof(tipeak[0]);
    int jmlaccsm = sizeof(tipesm) / sizeof(tipesm[0]);

    printf("Selamat datang di Store Kami\n");
    printf("Pilih 'A' untuk Aksesoris\natau 'S' untuk Smartphone\n");

    for (int i = 0; i < katestore; i++) {
        printf("%c.  %s. \n", i+1, kate[i].pilihan, kate[i].nama);
    }
}