#include "IkiliAramaAgaci.h"

IkiliAramaAgaci::IkiliAramaAgaci() {
    _kok = nullptr;
}

void IkiliAramaAgaci::elemanEkle(Dugum *&dugum, const Kuyruk &kuyruk) {
    if (dugum == nullptr)
        dugum = new Dugum(kuyruk);
    else if (kuyruk < dugum->kuyruk()) {
        elemanEkle(dugum->sol(), kuyruk);
    } else if (kuyruk > dugum->kuyruk()) {
        elemanEkle(dugum->sag(), kuyruk);
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

void IkiliAramaAgaci::elemanSil(Dugum *&dugum, const Kuyruk &kuyruk) {
//    TODO if (dugum == nullptr) throw elemanBulunamadiHatasi

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
    if (dugum != nullptr) {
        sirali(dugum->sol(), liste);
        liste += SSTR(dugum->kuyruk().rakamlarToplami()) + " ";
        sirali(dugum->sag(), liste);
    }

    return liste;
}

std::string IkiliAramaAgaci::onSirali(Dugum *dugum, std::string &liste) {
    if (dugum != nullptr) {
        liste += SSTR(dugum->kuyruk().rakamlarToplami()) + " ";
        sirali(dugum->sol(), liste);
        sirali(dugum->sag(), liste);
    }

    return liste;
}

std::string IkiliAramaAgaci::sonSirali(Dugum *dugum, std::string &liste) {
    if (dugum != nullptr) {
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
    std::string liste = "";

    return sirali(_kok, liste);
}

std::string IkiliAramaAgaci::onSirali() {
    std::string liste = "";

    return onSirali(_kok, liste);
}

std::string IkiliAramaAgaci::sonSirali() {
    std::string liste = "";

    return sonSirali(_kok, liste);
}

IkiliAramaAgaci::~IkiliAramaAgaci() {
    while (_kok != nullptr) {
        dugumuSil(_kok);
    }
}
