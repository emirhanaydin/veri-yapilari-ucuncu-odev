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
