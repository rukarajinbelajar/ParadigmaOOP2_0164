#include <iostream>
using namespace std;

class RekeningBank {
public:
    virtual void potongAdmin() = 0;
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

    void potongAdmin() override {
        cout << "Nama   : " << nama << endl;
        cout << "Tipe   : Syariah" << endl;
        cout << "Admin  : Bebas Biaya Admin" << endl;
        cout << "Saldo  : " << saldo << endl;
        cout << "____________________" << endl;
    }
};

class rekeningKonvensial : public RekeningBank {
private:
    string nama;
    double saldo;
public:
    void setRekening(string n, double s){
        nama = n;
        saldo = s;
    }
    void potongAdmin() override {
        saldo -= 15000;
        cout << "Nama   : " << nama << endl;
        cout << "Tipe   : Konvensional " << endl;
        cout << "Admin  : Rp 15.000 dipotong " << endl;
        cout << "Saldo  : Rp " << saldo << endl;
    }
};

class RekeningPremium : public RekeningBank {
  private:
    string nama;
    double saldo;

  public:
    void setRekening(string n, double s){
      nama = n;
      saldo = s;
    }
    void potongAdmin() override {
      cout << "Nama     : " << nama << endl;
      cout << "Tipe     : Premium" << endl;
      if(saldo > 10000000){
        cout << "Admin    : Bebas biaya admin" << endl;
      } else {
        saldo -= 50000;
        cout << "Admin    : Rp 50.000 dipotong" << endl;
      }
      cout << "Saldo    : Rp " << saldo << endl;
      cout << "----------------------------" << endl;
    }
};