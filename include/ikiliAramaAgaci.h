#ifndef IKILIARAMAAGACI_H
#define IKILIARAMAAGACI_H


#include "dugum.h"
#include <sstream>

#define SSTR(x) static_cast<std::ostringstream &>(std::ostringstream() << x).str()

class IkiliAramaAgaci {
private:
    Dugum *_kok;

    void elemanEkle(Dugum *&dugum, const Kuyruk &kuyruk);

    void dugumuSil(Dugum *&dugum);

    void elemanSil(Dugum *&dugum, const Kuyruk &kuyruk);

    std::string sirali(Dugum *dugum, std::string &liste);

    std::string onSirali(Dugum *dugum, std::string &liste);

    std::string sonSirali(Dugum *dugum, std::string &liste);

public:
    IkiliAramaAgaci();

    void elemanEkle(const Kuyruk &kuyruk);

    void elemanSil(const Kuyruk &kuyruk);

    std::string sirali();

    std::string onSirali();

    std::string sonSirali();

    ~IkiliAramaAgaci();
};


#endif //IKILIARAMAAGACI_H
