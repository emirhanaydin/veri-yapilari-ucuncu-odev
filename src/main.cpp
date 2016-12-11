/**
* @file main.cpp
* @description Ağaç yapısının ve ağaçta yer alan kuyrukların ekrana yazdırıldığı ana program.
* @course 2A
* @assignment 3
* @date 6.12.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/


#include <iostream>
#include <ikiliAramaAgaci.h>
#include <dosya.h>
#include <cstdlib>

using namespace std;

int main() {
    IkiliAramaAgaci *aramaAgaci = new IkiliAramaAgaci();

    const char *dosyaAdi = "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-ucuncu-odev\\sayilar.txt";
    Dosya *dosya = new Dosya(dosyaAdi);
    int satirSayisi = dosya->satirSayisi();

    Kuyruk *kDizi = new Kuyruk[satirSayisi];

    dosya->agacaAktar(*aramaAgaci, kDizi);

    delete dosya;

    system("CLS");

    cout << "Okunan dosya: " << dosyaAdi << endl << endl;

    {
        Kuyruk *kuyruk;
        for (int i = 0; i < satirSayisi; i++) {
            kuyruk = &kDizi[i];

            cout << i + 1 << ". Kuyruk: ";
            for (int j = 0, len = kuyruk->uzunluk(); j < len; j++) {
                cout << (*kuyruk)[j];
                if (j < len - 1) cout << " - ";
            }
            cout << "   (Toplam: " << kuyruk->rakamlarToplami() << ')' << endl;
        }
    }

    cout << endl << endl;

    cout << "Ikili arama agacindan okuma metotlari:" << endl << endl;

    cout << "Sirali okuma (inorder)\n" << aramaAgaci->sirali() << endl << endl;
    cout << "Onden sirali okuma (preorder)\n" << aramaAgaci->onSirali() << endl << endl;
    cout << "Sondan sirali okuma (postorder)\n" << aramaAgaci->sonSirali() << endl << endl;

    delete aramaAgaci;
    delete[] kDizi;

    system("PAUSE");
    return 0;
}