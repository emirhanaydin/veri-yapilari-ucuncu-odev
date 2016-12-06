#include "IkiliAramaAgaci.h"

IkiliAramaAgaci::IkiliAramaAgaci() {
    _kok = nullptr;
}

void IkiliAramaAgaci::elemanEkle(Dugum *&yavru, const Kuyruk &kuyruk) {
    if (yavru == nullptr)
        yavru = new Dugum(kuyruk);
    else if (kuyruk < yavru->kuyruk()) {
        elemanEkle(yavru->sol(), kuyruk);
    } else if (kuyruk > yavru->kuyruk()) {
        elemanEkle(yavru->sag(), kuyruk);
    } else {
//        TODO throw elemanZatenVarHatasi

        return;
    }
}

void IkiliAramaAgaci::dugumuSil(Dugum *&dugum) {
    Dugum *sil = dugum;

    if (dugum->sol() == nullptr) {
        dugum = dugum->sag();
    } else if (dugum->sag() == nullptr) {
        dugum = dugum->sol();
    } else {
        sil = dugum->sag();
        Dugum *ebeveyn = dugum;

        while (sil->sol() != nullptr) {
            ebeveyn = sil;
            sil = sil->sol();
        }

        dugum->ataKuyruk(sil->kuyruk());

        if (ebeveyn == dugum) {
            dugum->sag() = sil->sag();
        } else {
            ebeveyn->sag() = sil->sol();
        }
    }

    delete sil;
}

void IkiliAramaAgaci::elemanSil(Dugum *&yavru, const Kuyruk &kuyruk) {
//    TODO if (yavru == nullptr) throw elemanBulunamadiHatasi

    if (kuyruk == yavru->kuyruk()) {
        dugumuSil(yavru);
        return;
    } else if (kuyruk < yavru->kuyruk()) {
        elemanSil(yavru->sol(), kuyruk);
    } else {
        elemanSil(yavru->sag(), kuyruk);
    }
}

void IkiliAramaAgaci::elemanEkle(const Kuyruk &kuyruk) {
    elemanEkle(_kok, kuyruk);
}

void IkiliAramaAgaci::elemanSil(const Kuyruk &kuyruk) {
    elemanSil(_kok, kuyruk);
}

IkiliAramaAgaci::~IkiliAramaAgaci() {
    while (_kok != nullptr) {
        dugumuSil(_kok);
    }
}
