#include <stdio.h>                                                  
#include <iostream>
#include <cstring>
using namespace std;

void createFile(){
    char nama[50], charNama[40], npm[50];
    int i, c;
    string namaF, namaFile;
    FILE *fp;

    printf("\nMasukkan Nama File : ");
    fflush(stdin);
    getline(cin, namaF);
    namaFile = namaF + ".txt";
    strcpy(charNama, namaFile.c_str());

    fp = fopen(charNama, "w");

    fprintf(fp, "| No |\tNama\t\t|\tNPM \t\t|\n");

    cout<<"-------------------------------"<<endl;
    cout<<"Masukkan Jumlah Mahasiswa : ";
    cin>>c;

    for(int i=0; i<c; i++){
        printf("\n------ Data Ke-%d ------", i+1);
        printf("\nMasukkan Nama : ");
        fflush(stdin);
        gets(nama);
        fprintf(fp, "| %d", i+1);
        fprintf(fp, "  |\t%s   \t|", nama);
        printf("Masukkan NPM : ");
        fflush(stdin);
        gets(npm);
        fprintf(fp, "\t%s\t|\n", npm);
    }
    fclose(fp);

    printf("\n\nData Berhasil Dimasukkan");
}

void readFile(){
    char nama[50], charNama[40], npm[50];
    int i=1;
    string namaF, namaFile;
    FILE *fp;

    printf("\nNama File Untuk Dibaca : ");
    fflush(stdin);
    getline(cin, namaF);
    namaFile = namaF +".txt";
    strcpy(charNama, namaFile.c_str());

    fp = fopen(charNama, "r");

    while((fgets(nama,50,fp)&&(fgets(npm,50,fp))!=NULL)){
        printf(nama);
        printf(npm);

        i++;
    }
}

void menuFile(){
    int pilihan;
    cout<<"---------------------------------------"<<endl;
    cout<<"                 Menu                "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"1. Membuat dan Input data ke File    "<<endl;
    cout<<"2. Membaca data File                 "<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"Masukkan Pilihan : ";
    cin>>pilihan;

    if(pilihan==1){
        createFile();
    }
    if(pilihan==2){
        readFile();
    }
}

int main(){
    int ulang;
    do{
        menuFile();
        cout<<"\nIngin Kembali Ke Menu? (Y=1/T=2)";
        cin>>ulang;
        cout<<endl;
    }while(ulang==1);
    cout<<"Terimakasih...";
    cout<<endl;
    return 0;
}
