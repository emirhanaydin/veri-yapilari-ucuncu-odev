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

    friend bool operator<(const Kuyruk &a, const Kuyruk &b);

    friend bool operator>(const Kuyruk &a, const Kuyruk &b);

    int uzunluk() const;

    int rakamlarToplami() const;

    void kuyrugaEkle(char c);

    char kuyruktanCikar();

    ~Kuyruk();
};


#endif //KUYRUK_H
