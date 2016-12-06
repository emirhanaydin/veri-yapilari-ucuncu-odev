#ifndef KUYRUK_H
#define KUYRUK_H


class Kuyruk {
private:
    char *_kuyrukDizi;
    int _kapasite;
    int _uzunluk;
    int _bas;
    int _son;

    void genislet();

public:
    Kuyruk();

    void kuyrugaEkle(char c);

    char kuyruktanCikar();

    ~Kuyruk();
};


#endif //KUYRUK_H
