#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Panjang maksimum entry
#define MAX_LEN 255

int main() {
    // Input nama file
    char filename[MAX_LEN];
    printf("Masukkan nama file: ");
    scanf("%s", &filename);
	
	FILE* stream;
	
	// Validasi nama file
	while(!(stream = fopen(filename, "r"))){
		printf("File tidak ditemukan!\n\n");
		printf("Masukkan nama file: ");
		scanf("%s", &filename);
	}
	
	// Variabel penyimpan data dalam bentuk array of string
	char hospital[MAX_LEN];
	char names[MAX_LEN][MAX_LEN];
	char age[MAX_LEN][MAX_LEN];
	char disease[MAX_LEN][MAX_LEN];
	
	// Variabel penyimpan baris dari file sementara    
    char line[MAX_LEN];

    // Token penyimpan string sementara untuk parsing
    char* token;
	
	int i = 0;
	
	// Baca nama rumah sakit
	fgets(hospital, MAX_LEN, stream);
	
	// Baca file baris demi baris hingga habis
    while(fgets(line, MAX_LEN, stream)) {
        // Parse baris
        // Ambil string pada baris hingga tanda koma (koma tidak ikut dibaca)
        token = strtok(line, ",");

        // Copy string dari token ke array nama 
        // String pada C tidak bisa di-assign dengan operator =, gunakan strcpy
        strcpy(names[i], token);

        // Ambil string pada baris hingga tanda koma (koma tidak ikut dibaca)
        token = strtok(NULL, ",");
        // Copy string dari token ke array nama 
        // String pada C tidak bisa di-assign dengan operator =, gunakan strcpy
        strcpy(age[i], token);

        // Ambil string pada baris hingga karakter newline (newline tidak ikut dibaca)
        token = strtok(NULL, "\n");

        // Copy string dari token ke array nama 
        // String pada C tidak bisa di-assign dengan operator =, gunakan strcpy
        strcpy(disease[i], token);
      
		++i;
    }
	
	
	printf("\nNama Rumah Sakit: %s", hospital);
    
	// Menu dan meminta pilihan pencarian
	printf("\nJenis pencarian pasien:\n1. Nama\n2. Umur\n3. Penyakit\nPilihan pencarian: ");
	
	int choice;
	
	scanf("%d",&choice);
	
	// Variabel untuk algoritma pencarian
	char tempStr[MAX_LEN];
	char *ptr;
	int found = 0;
	int foundTemp = 0;
	int j = 0;
	
	printf("Masukkan pencarian: ");
	scanf("%s",&tempStr);
	
	// Loop untuk pencarian
	while(j <= i){
		// Menggunakan fungsi strstr untuk mencari substring di dalam string, terpisah untuk pilihan karena variabel yang dibandingkan berbeda
		if(choice == 1){
			if(!(ptr = strstr(names[j], tempStr))){
				foundTemp = 0;
			}
			else{
				foundTemp = 1;
			}
		}
		else if(choice == 2){
			if(!(ptr = strstr(age[j], tempStr))){
				foundTemp = 0;
			}
			else{
				foundTemp = 1;
			}
		}
		else if(choice == 3){
			if(!(ptr = strstr(disease[j], tempStr))){
				foundTemp = 0;
			}
			else{
				foundTemp = 1;
			}
		}
		
		// Menampilkan jika salah satu ditemukan
		if(foundTemp == 1){
			found = 1;
			printf("\nData pasien ke-%d\n", j+1);        
			printf("Nama pasien \t: %s\n", names[j]);
			printf("Umur pasien \t: %s\n", age[j]);
			printf("Kondisi pasien \t: %s\n", disease[j]);
		}
		++j;
	}
	
	// Jika tidak ditemukan maka akan muncul tulisan ini
	if(found == 0)
		printf("\nData pasien tidak ditemukan!");
    return 0;
}
