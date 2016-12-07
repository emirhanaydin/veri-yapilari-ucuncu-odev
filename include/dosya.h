
#ifndef DOSYA_H
#define DOSYA_H


#include "kuyruk.h"
#include "ikiliAramaAgaci.h"

class Dosya {
private:
    const char *dosyaAdi;

    void kuyrugaAktar(Kuyruk &kuyruk, const std::string &katar);

public:
    Dosya(const char *dosyaAdi);

    int dosyaUzunlugu();

    void agacaAktar(IkiliAramaAgaci &aramaAgaci, Kuyruk *kDizi);
};


#endif //DOSYA_H
