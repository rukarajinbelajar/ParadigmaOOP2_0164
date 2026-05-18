#include <iostream>
using namespace std;

class RekeningBank {
public:
    virtual void potonganAdmin() = 0;
    virtual ~RekeningBank () {}
};

class RekeningSyariah : public RekeningBank {
private:
    string nama;
    double saldo;
public:
    void setRekening(string n, double s){
        nama = n;
        saldo = s;
    }

    void potonganAdmin() override {
        cout << "Nama   : " << nama << endl;
        cout << "Tipe   : Syariah" << endl;
        cout << "Admin  : Bebas Biaya Admin" << endl;
        cout << "Saldo  : " << saldo << endl;
        cout << "____________________" << endl;
    }
};