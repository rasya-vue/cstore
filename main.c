#include <stdio.h>
#include <stdlib.h>


// struct untuk menyimpan informasi barang
typedef struct {
    char nama[50];
    int stok;
    int harga;
} Barang;

// fungsi untuk menampilkan pesan error dan mengulang input
void input_error(void) {
    printf("Input tidak valid. Silakan coba lagi.\n");
}

// fungsi untuk menampilkan struk
void print_struk(char kategori[], Barang barang[], int pesanan[][2], int jml_pesanan, int total) {
    // menampilkan header
    printf("============================\n");
    printf("|     TOKO GADGET MURAH     |\n");
    printf("============================\n\n");
    printf("Kategori: %s\n\n", kategori);
    
    // menampilkan pesanan
    printf("Pesanan:\n");
    for (int i = 0; i < jml_pesanan; i++) {
        int index_barang = pesanan[i][0];
        int jumlah = pesanan[i][1];
        printf("%d x %s - Rp %d\n", jumlah, barang[index_barang].nama, barang[index_barang].harga * jumlah);
    }
    
    // menampilkan subtotal dan total
    printf("\nSubtotal: Rp %d\n", total);
    printf("Pajak (10%%): Rp %d\n", total / 10);
    printf("Total: Rp %d\n\n", total * 11 / 10);
    
    // menampilkan pilihan
    printf("=======================\n");
    printf("Pilihan:\n");
    printf("- Ketik 'Hapus' diikuti dengan nomor pesanan untuk menghapus salah satu pesanan\n");
    printf("- Ketik 'Reset' untuk membatalkan semua pesanan\n\n");
}

int main(void) {
    // inisialisasi barang
    Barang barang[] = {
        {"Redmi Note 12", 3, 2999000},
        {"Redmi Note 12 Pro", 2, 4599000},
        {"Poco M4 Pro", 1, 2799000},
        {"Poco X5 5G", 2, 3449000},
        {"Redmi 10C", 0, 1899000},
        {"Xiaomi 12", 0, 7999000},
        {"Xiaomi 12 Pro", 1, 12999000}
        
    };
    int jml_barang = sizeof(barang) / sizeof(barang[0]);
    
    // inisialisasi kategori dan pesanan
    char kategori[] = "Smartphone/Aksesoris";
    int pesanan[100][2]; // maksimal 100 jenis pesanan
    int jml_pesanan = 0;
    int total = 0;
    
    // loop untuk input pesanan
    while (1) {
        // menampilkan daftar barang yang tersedia
        printf("Barang yang tersedia:\n");
        for (int i = 0; i < jml_barang; i++) {
            printf("%d. %s (Stok: %d) - Rp %d\n", i+1, barang[i].nama, barang[i].stok, barang[i].harga);
        }
        
        // input nomor barang dan jumlah
        int nomor_barang, jumlah;
        printf("Masukkan nomor barang yang ingin dibeli (0 untuk selesai): ");
        if (scanf("%d", &nomor_barang) != 1) {
            input_error();
            continue;
        }
        if (nomor_barang == 0) {
            break; // keluar dari
        }
        
    
        
        printf("Masukkan jumlah barang yang ingin dibeli: ");
        
        if (scanf("%d", &jumlah) != 1) {
            input_error();
            continue;
        }
        
        // validasi input dan kurangi stok barang jika berhasil dibeli
        int index_barang = nomor_barang - 1;
        if (index_barang < 0 || index_barang >= jml_barang) {
            input_error();
            continue;
        }
        if (barang[index_barang].stok < jumlah) {
            printf("Stok tidak cukup.\n");
            continue;
        }
        barang[index_barang].stok -= jumlah;
        
        // tambahkan pesanan ke array
        pesanan[jml_pesanan][0] = index_barang;
        pesanan[jml_pesanan][1] = jumlah;
        jml_pesanan++;
        total += barang[index_barang].harga * jumlah;
        
        // menampilkan struk
        print_struk(kategori, barang, pesanan, jml_pesanan, total);
        
     
        // input untuk menghapus pesanan atau reset
        char pilihan[10];
        printf("Masukkan pilihan: ");
        scanf("%s", pilihan);
        if (scanf(pilihan, "Reset") == 0) {
            // reset pesanan dan stok barang
            for (int i = 0; i < jml_pesanan; i++) {
                int index_barang = pesanan[i][0];
                int jumlah = pesanan[i][1];
                barang[index_barang].stok += jumlah;
            }
            jml_pesanan = 0;
            total = 0;
            printf("Pesanan berhasil direset.\n");
            continue;
        }
        
        else if (scanf(pilihan, "Hapus") == 0) {
            // input nomor pesanan yang ingin dihapus
            int nomor_pesanan;
            printf("Masukkan nomor pesanan yang ingin dihapus: ");
            if (scanf("%d", &nomor_pesanan) != 1) {
                input_error();
                continue;
        }
            
            if (nomor_pesanan < 1 || nomor_pesanan > jml_pesanan) {
                input_error();
                continue;
            }
            
            // hapus pesanan dan tambahkan stok barang
            int index_hapus = nomor_pesanan - 1;
            int index_barang_hapus = pesanan[index_hapus][0];
            int jumlah_hapus = pesanan[index_hapus][1];
            barang[index_barang_hapus].stok += jumlah_hapus;
            for (int i = index_hapus; i < jml_pesanan-1; i++) {
                pesanan[i][0] = pesanan[i+1][0];
                pesanan[i][1] = pesanan[i+1][1];
            }
            jml_pesanan--;
            total -= barang[index_barang_hapus].harga * jumlah_hapus;
            
            printf("Pesanan berhasil dihapus.\n");
            continue;
        } else {
            input_error();
            continue;
        }
    }
    
    return 0;
    
}

