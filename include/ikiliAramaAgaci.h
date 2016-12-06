#ifndef IKİLİARAMAAGACİ_H
#define IKİLİARAMAAGACİ_H


#include "dugum.h"

class IkiliAramaAgaci {
private:
    Dugum *_kok;

    void elemanEkle(Dugum *&yavru, const Kuyruk &kuyruk);

public:
    IkiliAramaAgaci();

    void elemanEkle(const Kuyruk &kuyruk);
};


#endif //IKİLİARAMAAGACİ_H
