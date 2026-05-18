#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
public:
    // Pure Virtual Function
    virtual void potongAdmin() = 0;
};

// Class Rekening Syariah
class RekeningSyariah : public RekeningBank {
private:
    double saldo;

public:
    RekeningSyariah(double s) {
        saldo = s;
    }

    void potongAdmin() {
        cout << "Rekening Syariah bebas biaya admin" << endl;
        cout << "Saldo akhir : Rp " << saldo << endl;
    }
};

// Class Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
private:
    double saldo;

public:
    RekeningKonvensional(double s) {
        saldo = s;
    }

    void potongAdmin() {
        saldo -= 15000;

        cout << "Biaya admin Rp 15.000 dipotong" << endl;
        cout << "Saldo akhir : Rp " << saldo << endl;
    }
};

// Class Rekening Premium
class RekeningPremium : public RekeningBank {
private:
    double saldo;

public:
    RekeningPremium(double s) {
        saldo = s;
    }

    void potongAdmin() {

        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000" << endl;
            cout << "Bebas biaya admin" << endl;
        }
        else {
            saldo -= 50000;

            cout << "Biaya admin Rp 50.000 dipotong" << endl;
        }

        cout << "Saldo akhir : Rp " << saldo << endl;
    }
};

int main() {

    RekeningBank* rekening;

    RekeningSyariah syariah(5000000);
    RekeningKonvensional konvensional(3000000);
    RekeningPremium premium(8000000);

    cout << "=== Rekening Syariah ===" << endl;
    rekening = &syariah;
    rekening->potongAdmin();

    cout << endl;

    cout << "=== Rekening Konvensional ===" << endl;
    rekening = &konvensional;
    rekening->potongAdmin();

    cout << endl;

    cout << "=== Rekening Premium ===" << endl;
    rekening = &premium;
    rekening->potongAdmin();

    return 0;
}