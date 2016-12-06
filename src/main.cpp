#include <iostream>
#include <kuyruk.h>
#include <cstdlib>
#include <dosya.h>

using namespace std;

int main() {
    Kuyruk *kuyruk = new Kuyruk();

    Dosya dosya(
            "C:\\Users\\Emirhan\\OneDrive\\Belgeler\\Projeler\\Repositories\\veri-yapilari-ucuncu-odev\\sayilar.txt");
    dosya.kuyrugaAktar(*kuyruk);

    for (int i = 0, len = kuyruk->uzunluk(); i < len; i++) {
        cout << kuyruk->kuyruktanCikar() << endl;
    }

    delete kuyruk;

    system("PAUSE");
    return 0;
}