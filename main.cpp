#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX 24

class KRS{
private:
    string NIM = "195150301111000";
    string password = "drowssap";

    float ip;
    int batasSKS[2];

    int countMatkul = 0;
    int countSKS = 0;
    string Matkul[MAX];
    int SKS[MAX];

public:
    void loginPage();
    bool isTrue(string nim , string pass);

    void inputIp();
    void setIp(float ip);

    void inputMatkul();
    void setMatkul(string matkul,int sks);
    void printMatkul();

    void main();
};

void KRS::loginPage() {
    string nim,pass;
    menu:
    cout<<"=========================== Login ==========================="<<endl<<endl;

    cout<<"Username\t: ";
    cin>>nim;
    cout<<"Password\t: ";
    cin>>pass;
    if(!isTrue(nim,pass)) {
        goto menu;
    }
}

bool KRS::isTrue(string nim, string pass) {
    if(nim==NIM && pass==password) {
        cout<<"\nLogin berhasil..."<<endl<<endl;
        system("pause");
        system("cls");
        return true;
    }
    else{
        cout<<"\nUsername atau password yang anda masukan salah..."<<endl
                <<"Silahkan masukan kembali..."<<endl<<endl;
        system("pause");
        system("cls");
        return false;
    }
}

//=================================================================================================

void KRS::inputIp() {
    float ip;

    menu:
    cout<<"=========================== Input IP ==========================="<<endl<<endl;

    cout<<"Masukan IP\t: ";
    cin>>ip;
    if(ip > 4) {
        cout<<"\nIP yang anda masukan melebihi batas..."<<endl
            <<"Silahkan masukan kembali..."<<endl<<endl;
        system("pause");
        system("cls");
        goto menu;
    }
    else {
        setIp(ip);
        cout<<"\nBerhasil memasukan ip..."<<endl<<endl;
        system("pause");
        system("cls");
    }
}

void KRS::setIp(float IP) {
    ip = IP;
    if(ip < 1.5) {
        batasSKS[0] = 0;
        batasSKS[1] = 12;
    }
    else if(ip>=1.5 && ip<2){
        batasSKS[0] = 12;
        batasSKS[1] = 15;
    }
    else if(ip>=2 && ip<2.5){
        batasSKS[0] = 16;
        batasSKS[1] = 18;
    }
    else if(ip>=2.5 && ip<3){
        batasSKS[0] = 19;
        batasSKS[1] = 21;
    }
    else {
        batasSKS[0] = 22;
        batasSKS[1] = 24;
    }
}

//=================================================================================================

void KRS::inputMatkul() {
    string matkul;
    int sks;
    int pilih;


    while (countSKS < batasSKS[1]){
        cout<<"====================== Input Matkul dan SKS ======================"<<endl<<endl;

        cout<<batasSKS[0]<<" - "<<batasSKS[1]<<" SKS yang dapat anda ambil..."<<endl
            <<"Silahkan masukan matkul dan SKS..."<<endl<<endl
            <<"\nSisa SKS yang dapat anda ambil : "<<batasSKS[1]-countSKS<<endl<<endl;

        if(countSKS >= batasSKS[0] && countSKS!=batasSKS[1]){
            cout<<"Apakah ingin menambahkan mata kuliah lagi?\n1. Ya\n2. Tidak\nPilih [1/2] : ";
            cin>>pilih;
            cout<<endl;
            if(pilih == 2) {
                cout<<"Berhasil memasukan matkul dan SKS..."<<endl<<endl;
                break;
            }
        }

        cin.get();
        cout<<"Matkul\t: ";
        getline(cin,matkul);
        cout<<"SKS\t: ";
        cin>>sks;
        setMatkul(matkul,sks);
    }
}

void KRS::setMatkul(string matkul, int sks) {
    if(countSKS+sks > batasSKS[1]){
        cout<<"\nERROR : SKS yang anda masukan melebihi peraturan IP..."<<endl
            <<"Silahkan masukan kembali..."<<endl<<endl;
        system("pause");
        system("cls");
    }
    else {
        transform(matkul.begin() , matkul.end() , matkul.begin() , ::toupper);
        Matkul[countMatkul] = matkul;
        SKS[countMatkul] = sks;
        countMatkul++;
        countSKS+=sks;
        if(countSKS==batasSKS[1]) {
            cout<<"\nBerhasil memasukan matkul dan SKS..."<<endl<<endl;
            system("pause");
            system("cls");
        }
        else{
            system("pause");
            system("cls");
        }
    }
}

//=================================================================================================

void KRS::printMatkul() {
    cout<<"fachry ananta";
    system("cls");
    cout<<"==================== Cetak Matkul dan SKS ===================="<<endl<<endl;
    cout<<"=========================================="<<endl;
    for(int i=0 ; i<countMatkul ; i++){
        cout<<"Matkul\t: "<<Matkul[i]<<endl
            <<"SKS\t: "<<SKS[i]<<endl
            <<"=========================================="<<endl;
    }
}

void KRS::main() {
    loginPage();
    inputIp();
    inputMatkul();
    printMatkul();
}

int main() {
    KRS krs;
    krs.main();
    return 0;
}