/**
* @file dosya.h
* @description Dosya üzerinden okuma ve kuyruğa aktarma işlemlerini barındırır.
* @course 2A
* @assignment 3
* @date 6.12.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/


#ifndef DOSYA_H
#define DOSYA_H


#include "hata.h"
#include "kuyruk.h"
#include "ikiliAramaAgaci.h"

class Dosya {
private:
    const char *_dosyaAdi;

    int _satirSayisi;

    std::string _dosyaIcerigi;

    bool rakamMi(char karakter);

    void kuyrugaAktar(Kuyruk &kuyruk, const std::string &katar);

public:
    Dosya(const char *dosyaAdi);

    int satirSayisi() const;

    void dosyayiOku() throw(DosyaAcmaHatasi);

    void agacaAktar(IkiliAramaAgaci &aramaAgaci, Kuyruk *kDizi) throw(DosyaUygunDegilHatasi);
};


#endif //DOSYA_H
