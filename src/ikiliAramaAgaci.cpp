/**
* @file ikiliAramaAgaci.cpp
* @description Açıklama ilgili başlık dosyasında yapılmıştır.
* @course 2A
* @assignment 3
* @date 6.12.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/


#include <hata.h>
#include "IkiliAramaAgaci.h"

IkiliAramaAgaci::IkiliAramaAgaci() {
    _kok = NULL;
}

void IkiliAramaAgaci::elemanEkle(Dugum *&dugum, const Kuyruk &kuyruk) throw(ElemanZatenVarHatasi) {
    if (dugum == NULL)
        dugum = new Dugum(kuyruk);
    else if (kuyruk < dugum->kuyruk()) {
        elemanEkle(dugum->sol(), kuyruk);
    } else if (kuyruk > dugum->kuyruk()) {
        elemanEkle(dugum->sag(), kuyruk);
    } else {
        throw ElemanZatenVarHatasi();
    }
}

void IkiliAramaAgaci::dugumuSil(Dugum *&dugum) {
    Dugum *sil = dugum;

    if (dugum->sol() == NULL) {
        dugum = dugum->sag();
    } else if (dugum->sag() == NULL) {
        dugum = dugum->sol();
    } else {
        sil = dugum->sag();
        Dugum *ebeveyn = dugum;

        while (sil->sol() != NULL) {
            ebeveyn = sil;
            sil = sil->sol();
        }

        dugum->ayarlaKuyruk(sil->kuyruk());

        if (ebeveyn == dugum) {
            dugum->sag() = sil->sag();
        } else {
            ebeveyn->sag() = sil->sol();
        }
    }

    delete sil;
}

void IkiliAramaAgaci::elemanSil(Dugum *&dugum, const Kuyruk &kuyruk) throw(ElemanBulunamadiHatasi) {
    if (dugum == NULL) throw ElemanBulunamadiHatasi();

    if (kuyruk == dugum->kuyruk()) {
        dugumuSil(dugum);
        return;
    } else if (kuyruk < dugum->kuyruk()) {
        elemanSil(dugum->sol(), kuyruk);
    } else {
        elemanSil(dugum->sag(), kuyruk);
    }
}

std::string IkiliAramaAgaci::sirali(Dugum *dugum, std::string &liste) {
    if (dugum != NULL) {
        sirali(dugum->sol(), liste);
        liste += SSTR(dugum->kuyruk().rakamlarToplami()) + " ";
        sirali(dugum->sag(), liste);
    }

    return liste;
}

std::string IkiliAramaAgaci::onSirali(Dugum *dugum, std::string &liste) {
    if (dugum != NULL) {
        liste += SSTR(dugum->kuyruk().rakamlarToplami()) + " ";
        sirali(dugum->sol(), liste);
        sirali(dugum->sag(), liste);
    }

    return liste;
}

std::string IkiliAramaAgaci::sonSirali(Dugum *dugum, std::string &liste) {
    if (dugum != NULL) {
        sirali(dugum->sol(), liste);
        sirali(dugum->sag(), liste);
        liste += SSTR(dugum->kuyruk().rakamlarToplami()) + " ";
    }

    return liste;
}

void IkiliAramaAgaci::elemanEkle(const Kuyruk &kuyruk) {
    elemanEkle(_kok, kuyruk);
}

void IkiliAramaAgaci::elemanSil(const Kuyruk &kuyruk) {
    elemanSil(_kok, kuyruk);
}

std::string IkiliAramaAgaci::sirali() {
    std::string liste = std::string();

    return sirali(_kok, liste);
}

std::string IkiliAramaAgaci::onSirali() {
    std::string liste = std::string();

    return onSirali(_kok, liste);
}

std::string IkiliAramaAgaci::sonSirali() {
    std::string liste = std::string();

    return sonSirali(_kok, liste);
}

IkiliAramaAgaci::~IkiliAramaAgaci() {
    while (_kok != NULL) {
        dugumuSil(_kok);
    }
}
