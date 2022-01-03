#include <iostream>
#include <fstream>

using namespace std;

string bilangan[]= {" ", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tuju", "Delapan", "Sembilan", "Sepuluh", "Sebelas"};
string eja(int angka){
    if(angka < 0){
        return "Negatif " + eja(-angka);
    }else if(angka < 12){
        return bilangan[angka];
    }else if(angka < 20){
        return eja(angka%10)+ " Belas";
    }else if(angka < 100){
        return eja(angka/10) + " Puluh " +eja(angka%10);
    }else if(angka < 200){
        return "Seratus "+eja(angka%100);
    }else if(angka < 1000){
        return eja(angka/100) + " Ratus " +eja(angka%100);
    }else if(angka < 2000){
        return "Seribu " +eja(angka%1000);
    }else if(angka < 10000){
        return eja(angka/1000)+ " Ribu " + eja(angka%1000);
    }
}


void simpan(string file, int angka){
    ofstream simpan;
    simpan.open(file + ".txt", ios::out);
    (angka == 0)? simpan << "Nol" : simpan << angka << " = " << eja(angka);
//    simpan << eja(angka);
    simpan.close();
}


int main(){
    string sparator = "==========================\n";
    int angka;
    string kembali, file;

ulang:
    cout << sparator << "Program Pengeja Bilangan 4 Digit \n";
    cout << "Masukkan nama file: "; cin >> file;
    cout << "Masukkan harus berupa angka \n";
    cout << "Masukkan angka (1-4): ";cin >> angka;

    if(cin.good()){
        (angka == 0)? cout << "Nol" : cout << "Angka Tersebut adalah:\n"<< eja(angka) <<endl;
        simpan(file, angka);
    }else{
        cout << "maaf angka yang anda masukkan salah \n";
        cin.clear();cin.ignore();
    }

    cout<< "Lagi? (Y/N)";cin >>kembali;
    if(kembali== "Y" || kembali=="y"){
        goto ulang;
    }else if(kembali == "N" || kembali=="n"){
        cout<< "Terimakasi";
    }
}
