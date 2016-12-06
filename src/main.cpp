#include <iostream>
#include <kuyruk.h>
#include <cstdlib>
#include <ikiliAramaAgaci.h>

using namespace std;

int main() {
    IkiliAramaAgaci aramaAgaci = IkiliAramaAgaci();

    Kuyruk kuyruk1 = Kuyruk();
    Kuyruk kuyruk2 = Kuyruk();

    kuyruk1.kuyrugaEkle('1');
    kuyruk1.kuyrugaEkle('2');
    kuyruk1.kuyrugaEkle('3');
    kuyruk1.kuyrugaEkle('4');

    kuyruk2.kuyrugaEkle('5');
    kuyruk2.kuyrugaEkle('6');
    kuyruk2.kuyrugaEkle('7');
    kuyruk2.kuyrugaEkle('8');

    aramaAgaci.elemanEkle(kuyruk1);
    aramaAgaci.elemanEkle(kuyruk2);

    system("PAUSE");
    return 0;
}