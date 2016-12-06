#include "kuyruk.h"

Kuyruk::Kuyruk() {
    _kuyrukDizi = nullptr;
    _uzunluk = 0;
    _bas = -1;
    _son = -1;
}

void Kuyruk::genislet() {
//    TODO if (_uzunluk < 1) throw exception;

    int yeniUzunluk = 2 * _uzunluk;
    char *yeniDizi = new char[yeniUzunluk];

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

    _uzunluk = yeniUzunluk;
}

void Kuyruk::kuyrugaEkle(char k) {
//    Eğer dizi yoksa oluşturulur.
    if (_kuyrukDizi == nullptr) {
        _kuyrukDizi = new char[]{k};
        _bas = 0;
        _son = 0;
        _uzunluk++;
    }

    _son++; // Eleman ekleneceğinden son değeri bir artırılır.

    if (_son < _bas) { // Kuyrukta yer varsa eleman eklenir.
        if (_son >= _uzunluk) // Her ekleme işleminde modüler bölme yapmak yerine uzunluğa ulaşıldığında sıfır yapılır.
            _son = 0;

        _kuyrukDizi[_son] = k;
    } else { // Kuyruk dolmuş demektir.
        genislet();
    }


}

void Kuyruk::kuyruktanCikar() {
//    TODO if (_uzunluk < 1) throw exception;
}
