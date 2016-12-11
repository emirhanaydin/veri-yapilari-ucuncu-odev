#include <fstream>
#include "dosya.h"

Dosya::Dosya(const char *dosyaAdi) {
    _dosyaAdi = dosyaAdi;
    dosyayiOku();
}

bool Dosya::rakamMi(char karakter) {
    return karakter >= '0' && karakter <= '9';
}

void Dosya::kuyrugaAktar(Kuyruk &kuyruk, const std::string &katar) {
    for (int i = 0, len = katar.length(); i < len; i++) {
        if (rakamMi(katar[i]))
            kuyruk.kuyrugaEkle(katar[i]);
    }
}

int Dosya::satirSayisi() const {
    return _satirSayisi;
}

void Dosya::dosyayiOku() throw(DosyaAcmaHatasi) {
    std::ifstream dosyaOku(_dosyaAdi);

    if (!dosyaOku.is_open()) throw DosyaAcmaHatasi();

    std::string satir;

    _dosyaIcerigi = std::string();
    _satirSayisi = 0;

    while (std::getline(dosyaOku, satir)) {
        _dosyaIcerigi += _satirSayisi > 0 ? "\n" + satir : satir;
        _satirSayisi++;
    }

    _dosyaIcerigi += "\n";

    dosyaOku.close();
}

void Dosya::agacaAktar(IkiliAramaAgaci &aramaAgaci, Kuyruk *kDizi) throw(DosyaUygunDegilHatasi) {
    if (_dosyaIcerigi == std::string()) throw DosyaUygunDegilHatasi();

    std::string satir = std::string();
    char simdikiKar;

    for (int i = 0, j = 0, len = _dosyaIcerigi.length(); i < len; ++i) {
        simdikiKar = _dosyaIcerigi[i];

        if (simdikiKar != '\n') {
            satir += simdikiKar;
        } else {
            kuyrugaAktar(kDizi[j], satir);
            satir = std::string();
            aramaAgaci.elemanEkle(kDizi[j]);
            ++j;
        }
    }
}
