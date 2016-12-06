#include <iostream>
#include <cstdlib>
#include <ikiliAramaAgaci.h>
#include <dosya.h>

using namespace std;

int main() {
    IkiliAramaAgaci aramaAgaci = IkiliAramaAgaci();

    const char *sayilar = "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-ucuncu-odev\\sayilar.txt";
    Dosya dosya = Dosya(sayilar);
    int satirSayisi = dosya.dosyaUzunlugu();

    Kuyruk *kDizi = new Kuyruk[satirSayisi];

    dosya.agacaAktar(aramaAgaci, kDizi, satirSayisi);

    cout << "inorder\n" << aramaAgaci.sirali() << endl;
    cout << "preorder\n" << aramaAgaci.onSirali() << endl;
    cout << "postorder\n" << aramaAgaci.sonSirali() << endl;

    delete[] kDizi;
    system("PAUSE");
    return 0;
}