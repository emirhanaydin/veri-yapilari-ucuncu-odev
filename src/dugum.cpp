/**
* @file dugum.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 3
* @date 6.12.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/


#include "dugum.h"

Dugum::Dugum(const Kuyruk &kuyruk) {
    _sol = NULL;
    _sag = NULL;
    _kuyruk = kuyruk;
}

Dugum *&Dugum::sol() {
    return _sol;
}

Dugum *&Dugum::sag() {
    return _sag;
}

const Kuyruk &Dugum::kuyruk() const {
    return _kuyruk;
}

void Dugum::ayarlaKuyruk(const Kuyruk &kuyruk) {
    _kuyruk = kuyruk;
}
