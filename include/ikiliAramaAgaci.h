#ifndef IKILIARAMAAGACI_H
#define IKILIARAMAAGACI_H


#include "dugum.h"

class IkiliAramaAgaci {
private:
    Dugum *_kok;

    void elemanEkle(Dugum *&yavru, const Kuyruk &kuyruk);

    void dugumuSil(Dugum *&dugum);

    void elemanSil(Dugum *&yavru, const Kuyruk &kuyruk);
public:
    IkiliAramaAgaci();

    void elemanEkle(const Kuyruk &kuyruk);

    void elemanSil(const Kuyruk &kuyruk);

    ~IkiliAramaAgaci();
};


#endif //IKILIARAMAAGACI_H
