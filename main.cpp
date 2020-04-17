#include <iostream>
using namespace std;
#define MAX 20

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
    cout<<"=========================== Login ==========================="<<endl<<endl;
    string nim,pass;

    menu:
    cout<<"Username\t: ";
    cin>>nim;
    cout<<"Password\t: ";
    cin>>pass;
    if(!isTrue(nim,pass)) goto menu;
}

bool KRS::isTrue(string nim, string pass) {
    if(nim==NIM && pass==password) {
        cout<<"\nLogin berhasil..."<<endl<<endl;
        return true;
    }
    else{
        cout<<"\nUsername atau password yang anda masukan salah..."<<endl
            <<"Silahkan masukan kembali..."<<endl<<endl;
        return false;
    }
}

//=================================================================================================

void KRS::inputIp() {
    cout<<"=========================== Input IP ==========================="<<endl<<endl;
    float ip;
    menu:
    cout<<"Masukan IP\t: ";
    cin>>ip;
    if(ip > 4) {
        cout<<"\nIP yang anda masukan melebihi batas..."<<endl
            <<"Silahkan masukan kembali..."<<endl<<endl;
        goto menu;
    }
    else {
        setIp(ip);
        cout<<"\nBerhasil memasukan ip..."<<endl<<endl;
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
    cout<<"====================== Input Matkul dan SKS ======================"<<endl<<endl;
    string matkul;
    int sks;
    bool done = true;
    int pilih;

    cout<<batasSKS[0]<<" - "<<batasSKS[1]<<" SKS yang dapat anda ambil..."<<endl
        <<"Silahkan masukan matkul dan SKS..."<<endl<<endl;

    while (countSKS < batasSKS[1] && done){
        cin.get();
        cout<<"Matkul\t: ";
        getline(cin,matkul);
        cout<<"SKS\t: ";
        cin>>sks;
        setMatkul(matkul,sks);
        if(countSKS >= batasSKS[0] && countSKS!=batasSKS[1]){
            cout<<"Apakah ingin menambahkan mata kuliah lagi?\n1. Ya\n2. Tidak\nPilih [1/2] : ";
            cin>>pilih;
            cout<<endl;
            if(pilih == 2) done = false;
        }
    }
    cout<<"Berhasil memasukan matkul dan SKS..."<<endl<<endl;
}

void KRS::setMatkul(string matkul, int sks) {
    if(countSKS+sks > batasSKS[1]){
        cout<<"\nERROR : SKS yang anda masukan melebihi peraturan IP..."<<endl
            <<"Silahkan masukan kembali..."<<endl<<endl;
    }
    else {
        Matkul[countMatkul] = matkul;
        SKS[countMatkul] = sks;
        countMatkul++;
        countSKS+=sks;
        if(countSKS != batasSKS[1])
            cout<<"\nSisa SKS yang dapat anda ambil : "<<batasSKS[1]-countSKS<<endl<<endl;
    }
}

//=================================================================================================

void KRS::printMatkul() {
    cout<<"==================== Cetak Matkul dan SKS ===================="<<endl<<endl;
    for(int i=0 ; i<countMatkul ; i++){
        cout<<Matkul[i]<<endl
            <<"SKS : "<<SKS[i]<<endl<<endl
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