#ifndef KUYRUK_H
#define KUYRUK_H


class Kuyruk {
private:
    char *_kuyrukDizi;
    int _uzunluk;
    int _bas;
    int _son;

    void genislet();

public:
    Kuyruk();

    void kuyrugaEkle(char c);

    void kuyruktanCikar();
};


#endif //KUYRUK_H
