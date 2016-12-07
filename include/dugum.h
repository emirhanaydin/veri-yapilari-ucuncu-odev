
#ifndef DUGUM_H
#define DUGUM_H


#include "kuyruk.h"

class Dugum {
private:
    Dugum *_sol;
    Dugum *_sag;
    Kuyruk _kuyruk;
public:
    Dugum(const Kuyruk &kuyruk);

    Dugum *&sol();

    Dugum *&sag();

    const Kuyruk &kuyruk() const;

    void ayarlaKuyruk(const Kuyruk &kuyruk);
};


#endif //DUGUM_H
