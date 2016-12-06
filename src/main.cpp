#include <iostream>
#include <kuyruk.h>
#include <cstdlib>

using namespace std;

int main() {
    Kuyruk *kuyruk = new Kuyruk();

    kuyruk->kuyrugaEkle('a');
    kuyruk->kuyrugaEkle('b');
    kuyruk->kuyrugaEkle('c');
    kuyruk->kuyrugaEkle('d');
    kuyruk->kuyrugaEkle('e');

    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar() << endl;
    kuyruk->kuyrugaEkle('f');
    kuyruk->kuyrugaEkle('g');
    kuyruk->kuyrugaEkle('h');
    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar() << endl;
    kuyruk->kuyrugaEkle('i');
    kuyruk->kuyrugaEkle('j');
    kuyruk->kuyrugaEkle('k');
    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar() << endl;
    cout << kuyruk->kuyruktanCikar();

    delete kuyruk;

    system("PAUSE");
    return 0;
}