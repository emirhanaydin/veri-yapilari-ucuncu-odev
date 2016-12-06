#include "IkiliAramaAgaci.h"

IkiliAramaAgaci::IkiliAramaAgaci() {

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

void IkiliAramaAgaci::elemanEkle(const Kuyruk &kuyruk) {
    elemanEkle(_kok, kuyruk);
}
