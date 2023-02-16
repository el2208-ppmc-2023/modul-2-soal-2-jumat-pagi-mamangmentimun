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
    char namafile[MAX_LEN];
    char line[MAX_LEN];
    char* token;
    char kata[MAX_LEN]; 
    char tempTanggal[9];
    char dummyTanggal;
    char dummy;
    int spaces = 0;
    FILE *diary; //pointer of type file

    printf("Masukkan nama file diary : ");
    scanf("%s", &namafile);
    printf("Masukkan tanggal hari ini (ex: 2 Februari 2023 -> 02022023) : ");
    scanf("%s", &tempTanggal);

    diary = fopen(namafile, "r"); //buka file mode read only

    if (diary == NULL){ //jika file tidak ditemukan
        printf("Error : file invalid\n");
        fclose(diary);
        return 0;
    }

    printf("Hasil enkripsi diary Anda:\n");
    while(fgets(line, MAX_LEN, diary)){
        spaces = 0;
        for (int i=0; i<strlen(line); i++){ //menghitung karakter spasi (parameter jumlah kata-1)
            if(line[i] == ' '){
                spaces++;
            }
        }

        //Handling kata pertama dalam satu baris
        if (spaces==0){
            token = strtok(line, "\n"); 
            strcpy(kata, token);
        }
        else{
            token = strtok(line, " "); 
            strcat(strcpy(kata, token), " ");
        }

        int n = 0;
        while(kata[n] != '\0'){ //operasi XOR per kata
            dummy =  kata[n] ^ tempTanggal[n%8];
            printf("%c", dummy);
            n++;
        }

        int x = strlen(kata)/2; //Pembulatan ke bawah
        for (int j=0; j<x && j<7; j++){ //rotate string to left sebanyak x
            dummyTanggal=tempTanggal[0];
            for(int i=0; i<7; i++){
                tempTanggal[i]=tempTanggal[i+1];
            }
            tempTanggal[7]=dummyTanggal;
        }

        //Handling kata selanjutnya dalam satu baris yang sama (jika ada)
        for (int k=0; k<spaces; k++){ 
            if(k==spaces-1){
                token = strtok(NULL, "\n");
                strcpy(kata, token);
            }
            else{
                token = strtok(NULL, " ");
                strcat(strcpy(kata, token), " ");
            }
            int n = 0;
            while(kata[n] != '\0'){ //operasi XOR per kata
                dummy =  kata[n] ^ tempTanggal[n%8];
                printf("%c", dummy);
                n++;
            }
            int x = strlen(kata)/2;
            for (int j=0; j<x && j<7; j++){ //rotate string to left sebanyak x
                dummyTanggal=tempTanggal[0];
                for(int i=0; i<7; i++){
                    tempTanggal[i]=tempTanggal[i+1];
                }
                tempTanggal[7]=dummyTanggal;
            }
        }
        printf("\n");
    }
    fclose(diary);
    return 0;
}
