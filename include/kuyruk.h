#ifndef KUYRUK_H
#define KUYRUK_H

#include "hata.h"

class Kuyruk {
private:
    char *_kuyrukDizi;
    int _kapasite;
    int _uzunluk;
    int _bas;
    int _son;

    void genislet();

    bool bosMu() const;

public:
    Kuyruk();

    friend bool operator<(const Kuyruk &a, const Kuyruk &b);

    friend bool operator>(const Kuyruk &a, const Kuyruk &b);

    friend bool operator==(const Kuyruk &a, const Kuyruk &b);

    char operator[](int i) throw(IndeksAralikDisindaHatasi);

    int uzunluk() const;

    int rakamlarToplami() const throw(KuyrukBosHatasi);

    void kuyrugaEkle(char c);

    char kuyruktanCikar() throw(KuyrukBosHatasi);

    ~Kuyruk();
};


#endif //KUYRUK_H
