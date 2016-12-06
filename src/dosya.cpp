#include <fstream>
#include "dosya.h"

Dosya::Dosya(const char *dosyaAdi) : dosyaAdi(dosyaAdi) {}

void Dosya::kuyrugaAktar(Kuyruk &kuyruk) {
    std::ifstream dosyaOku(dosyaAdi);
    std::string satir;

//    TODO if (!dosyaOku.is_open()) throw dosyaOkumaHatasi

    while (std::getline(dosyaOku, satir)) {
        for (int i = 0, len = satir.length(); i < len; i++) {
            kuyruk.kuyrugaEkle(satir[i]);
        }
    };

    dosyaOku.close();
}
