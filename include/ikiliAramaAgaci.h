/**
* @file ikiliAramaAgaci.h
* @description Veriler üzerinde ortalama arama karmaşıklığının çok daha düşük olmasını sağlayan ikili arama ağacı veri
 * yapısı. Kuyruk nesnesi barındıran düğümler ile çalışacak şekilde özelleştirilmiştir.
* @course 2A
* @assignment 3
* @date 6.12.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/


#ifndef IKILIARAMAAGACI_H
#define IKILIARAMAAGACI_H


#include <sstream>
#include "dugum.h"
#include "hata.h"

// Sayıyı String değere dönüştürmek için kullanılan makro
#define SSTR(x) static_cast<std::ostringstream &>(std::ostringstream() << x).str()

class IkiliAramaAgaci {
private:
    Dugum *_kok;

    /**
     * Özyinelemeli olarak çalışır ve her seferinde başta gönderilen düğümün alt düğümlerini parametre olarak alır.
     * @param dugum Bu düğümden başlanarak boş bir düğüm bulunana kadar alt düğümlere bakılır.
     * @param kuyruk Düğüme eklenecek olan kuyruk, özyinelemede sabit olarak kalır.
     * @throws ElemanZatenVarHatasi Eklenecek olan eleman zaten var ise hata fırlatılır.
     */
    void elemanEkle(Dugum *&dugum, const Kuyruk &kuyruk) throw(ElemanZatenVarHatasi);

    /**
     * Düğüm için alt düğümlerin var olma durumlarına bakılır ve buna göre silme işlemi uygulanır.
     * @param dugum Silinecek olan düğüm.
     */
    void dugumuSil(Dugum *&dugum);

    void elemanSil(Dugum *&dugum, const Kuyruk &kuyruk) throw(ElemanBulunamadiHatasi);

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
