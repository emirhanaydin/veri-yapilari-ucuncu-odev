#include "kuyruk.h"

Kuyruk::Kuyruk() {
    _kuyrukDizi = nullptr;
    _kapasite = 0;
    _uzunluk = 0;
    _bas = -1;
    _son = -1;
}

bool operator<(const Kuyruk &a, const Kuyruk &b) {
    return a.rakamlarToplami() < b.rakamlarToplami();
}

bool operator>(const Kuyruk &a, const Kuyruk &b) {
    return a.rakamlarToplami() > b.rakamlarToplami();
}

bool operator==(const Kuyruk &a, const Kuyruk &b) {
    return a.rakamlarToplami() == b.rakamlarToplami();
}

int Kuyruk::uzunluk() const {
    return _uzunluk;
}

int Kuyruk::rakamlarToplami() const {
//    TODO if (_uzunluk < 1) throw kuyrukBosHatasi

    int sayi = 0;

    for (int i = 0; i < _uzunluk; i++) {
        sayi += _kuyrukDizi[i] - '0';
    }

    return sayi;
}

void Kuyruk::genislet() {
//    TODO if (_uzunluk < 1) throw kuyrukBosHatasi;

    if (_kapasite < 1) {
        _kuyrukDizi = new char[1];
        _kapasite = 1;
        return;
    }

    int yeniKapasite = 2 * _kapasite;
    char *yeniDizi = new char[yeniKapasite];

    for (int i = 0, n = _bas + i; i < _uzunluk; ++i, ++n) {
        if (n >= _uzunluk)
            n = 0;

        yeniDizi[i] = _kuyrukDizi[n];
    }

    delete[] _kuyrukDizi;
    _kuyrukDizi = yeniDizi;

//    Genişletilmiş dizi sıralı olacağından baş ve son doğrudan belirlenir.
    _son = _uzunluk; // Eski dizinin son elemanının bir sonrası
    _bas = 0;

    _kapasite = yeniKapasite;
}

void Kuyruk::kuyrugaEkle(char k) {
    if (_uzunluk < 1) {
        _bas = 0;
        _son = -1; // İşlemin devamında son değeri 1 artırılacağı için -1'e eşitlenir.
    }

    _son++; // Eleman ekleneceğinden son değeri bir artırılır.

    if (_son >= _kapasite) // Her ekleme işleminde modüler bölme yapmak yerine kapasiteye ulaşıldığında sıfır yapılır.
        _son = 0;

    if (_uzunluk >= _kapasite) { // Kuyruk dolmuş demektir, genişletilir.
        genislet();
    }

    _uzunluk++;
    _kuyrukDizi[_son] = k;
}

char Kuyruk::kuyruktanCikar() {
//    TODO if (_uzunluk < 1) throw kuyrukBosHatasi;
//    TODO if (_bas < 0) throw kuyrukBosHatasi;

    char siradaki;

    siradaki = _kuyrukDizi[_bas];

    if (_bas == _son) {
        _bas = _son = -1;
    } else {
        _bas++;

        if (_bas >= _kapasite)
            _bas = 0;
    }

    _uzunluk--;
    return siradaki;
}

Kuyruk::~Kuyruk() {
    delete[] _kuyrukDizi;
}
