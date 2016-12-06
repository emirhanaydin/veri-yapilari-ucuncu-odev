#include "dugum.h"

Dugum::Dugum(const Kuyruk &kuyruk) {
    _sol = nullptr;
    _sag = nullptr;
    _kuyruk = kuyruk;
}

Dugum::~Dugum() {
    delete _kuyruk;
}

Dugum *&Dugum::sol() const {
    return _sol;
}

Dugum *&Dugum::sag() const {
    return _sag;
}

const Kuyruk &Dugum::kuyruk() const {
    return _kuyruk;
}
