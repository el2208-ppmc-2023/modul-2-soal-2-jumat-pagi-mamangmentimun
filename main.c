/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 255

int main()
{
    //silahkan tambah variabel lain yang dibutuhkan
    char namafile[MAX_LEN];
    char tempTanggal[9];

    printf("Masukkan nama file diary : ");
    scanf("%s", &namafile);
    printf("Masukkan tanggal hari ini (ex: 2 Februari 2023 -> 02022023) : ");
    scanf("%s", &tempTanggal);

    //................
    //jika file tidak ditemukan
    printf("Error : file invalid\n");
        

    printf("Hasil enkripsi diary Anda:\n");
    //................
    printf("\n");
    
    return 0;
}
