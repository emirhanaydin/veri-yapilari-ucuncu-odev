/**
* @file dugum.cpp
* @description İkili ağaçta kullanılan ve veri olarak kuyruk nesnesi barındıran veri yapısı.
* @course 2A
* @assignment 3
* @date 6.12.2016
* @authors
 * Emirhan Aydın (g141210018@sakarya.edu.tr)
 * Oğuzhan Şahin (g141210066@sakarya.edu.tr)
*/


#ifndef DUGUM_H
#define DUGUM_H


#include "kuyruk.h"

class Dugum {
private:
    Dugum *_sol;
    Dugum *_sag;
    Kuyruk _kuyruk;
public:
    Dugum(const Kuyruk &kuyruk);

    Dugum *&sol();

    Dugum *&sag();

    const Kuyruk &kuyruk() const;

    void ayarlaKuyruk(const Kuyruk &kuyruk);
};


#endif //DUGUM_H
