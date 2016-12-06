
#ifndef DOSYA_H
#define DOSYA_H


#include "kuyruk.h"

class Dosya {
private:
    const char *dosyaAdi;
public:
    Dosya(const char *dosyaAdi);

    void kuyrugaAktar(Kuyruk &kuyruk);
};


#endif //DOSYA_H
