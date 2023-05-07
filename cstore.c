#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nama;
    char harga, stock;
} Aksesoris;

typedef struct
{
    char nama;
    char harga, stock;
} Smartphone;

int main(void) {
    Aksesoris tipeak[] = {
        {"Charger 33W", 200, 159000},
        {"Redmi Buds Essential", 250, 199000},
        {"Powerbank Xiaomi 10.000mAh", 0, 249000},
        {"Redmi Smartband", 10, 399000},
        {"Redmi Buds 3", 10, 449000},
        {"Redmi Buds 3 Pro", 5, 699000}
    };
//memek
    Smartphone tipesm[] = {
        {"Redmi Note 12", 100, 2999000},
        {"Redmi Note 12 Pro", 80, 4599000},
        {"Poco M4 Pro", 200, 2799000},
        {"Poco X5 5G", 0, 3449000},
        {"iPhone 12", 0, 12499000},
        {"iPhone 12 Pro", 100, 15499000}
    };
    
    printf("Selamat datang di Store Kami");
    printf("Pilih 'A' untuk Aksesoris\n atau 'S' untuk Smartphone");

    while (A) {
        
    }
}