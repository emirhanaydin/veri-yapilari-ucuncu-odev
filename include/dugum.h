
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

    Dugum *&sol() const;

    Dugum *&sag() const;

    const Kuyruk &kuyruk() const;

    ~Dugum();
};


#endif //DUGUM_H
