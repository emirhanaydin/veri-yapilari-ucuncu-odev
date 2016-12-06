#include <fstream>
#include "dosya.h"

Dosya::Dosya(const char *dosyaAdi) : dosyaAdi(dosyaAdi) {}

void Dosya::kuyrugaAktar(Kuyruk &kuyruk, const std::string &katar) {
    for (int i = 0, len = katar.length(); i < len; i++) {
        kuyruk.kuyrugaEkle(katar[i]);
    }
}

int Dosya::dosyaUzunlugu() {
    std::ifstream dosyaOku(dosyaAdi);
//    TODO if (!dosyaOku.is_open()) throw dosyaOkumaHatasi

    std::string satir;

    int uzunluk = 0;

    while (std::getline(dosyaOku, satir)) {
        uzunluk++;
    }

    return uzunluk;
}

void Dosya::agacaAktar(IkiliAramaAgaci &aramaAgaci, Kuyruk *kDizi, int kDiziUzunluk) {
    std::ifstream dosyaOku(dosyaAdi);
//    TODO if (!dosyaOku.is_open()) throw dosyaOkumaHatasi

    std::string satir;

    for (int i = 0; std::getline(dosyaOku, satir); ++i) {
        kuyrugaAktar(kDizi[i], satir);
        aramaAgaci.elemanEkle(kDizi[i]);
    }

    dosyaOku.close();
}
