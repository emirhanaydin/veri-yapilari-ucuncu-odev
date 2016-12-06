#include <iostream>
#include <kuyruk.h>
#include <cstdlib>
#include <ikiliAramaAgaci.h>

using namespace std;

int main() {
    IkiliAramaAgaci aramaAgaci = IkiliAramaAgaci();

    Kuyruk kuyruk1 = Kuyruk();
    Kuyruk kuyruk2 = Kuyruk();
    Kuyruk kuyruk3 = Kuyruk();
    Kuyruk kuyruk4 = Kuyruk();

    kuyruk1.kuyrugaEkle('5');
    kuyruk1.kuyrugaEkle('3');
    kuyruk1.kuyrugaEkle('6');
    kuyruk1.kuyrugaEkle('4');
    kuyruk1.kuyrugaEkle('8');
    kuyruk1.kuyrugaEkle('9');
    kuyruk1.kuyrugaEkle('5');

    kuyruk2.kuyrugaEkle('2');
    kuyruk2.kuyrugaEkle('9');
    kuyruk2.kuyrugaEkle('5');

    kuyruk3.kuyrugaEkle('4');
    kuyruk3.kuyrugaEkle('5');
    kuyruk3.kuyrugaEkle('6');
    kuyruk3.kuyrugaEkle('4');
    kuyruk3.kuyrugaEkle('8');
    kuyruk3.kuyrugaEkle('9');
    kuyruk3.kuyrugaEkle('5');
    kuyruk3.kuyrugaEkle('4');
    kuyruk3.kuyrugaEkle('4');
    kuyruk3.kuyrugaEkle('2');

    aramaAgaci.elemanEkle(kuyruk1);
    aramaAgaci.elemanEkle(kuyruk2);
    aramaAgaci.elemanEkle(kuyruk3);

    cout << "inorder\n" << aramaAgaci.sirali() << endl;
    cout << "preorder\n" << aramaAgaci.onSirali() << endl;
    cout << "postorder\n" << aramaAgaci.sonSirali() << endl;

    system("PAUSE");
    return 0;
}