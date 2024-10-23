#ifndef HABITAT_H
#define HABITAT_H
#include <string.h>
#include "Bitki.h"
#include "Pire.h"
#include "Sinek.h"

// Habitat yapısı
struct HABITAT
{
    void (*dosyaOku)(struct HABITAT *, char *); // Dosyadan okuma işlemi yapan fonksiyon
    void (*yazdir)(struct HABITAT *, int);  // Habitat bilgilerini yazdıran fonksiyon
    int canliSayilari[4]; // Canlı sayılarını tutan dizi
    Canli (*canliTipiBulucu)(struct HABITAT *, int);  // Canlı tipini bulan fonksiyon
    Bocek *bocekler;   // Bocekler dizisi
    Bitki *bitkiler;  // Bitkiler dizisi
    Pire *pireler; // Pireler dizisi
    Sinek *sinekler;   // Sinekler dizisi
    Canli *canlilar;     // Canlilar dizisi
    void **Canlilar2;    // Canlilar2 dizisi
    void (*besinPiramidi)(struct HABITAT *, char *); // Bütün işlemlerin gerçekleştiği yeme fonksiyonlarıyla kazananın bulunduğu fonksiyon
    
    int satirdakiSayiSayisi;   // Satırdaki sayı sayısını tutan değişken
    void (*canlilarinDizisiOlusturucu)(struct HABITAT *, char *); // Canlıların dizisini oluşturan fonksiyon
    void (*canlilarinSayisi)(struct HABITAT *, char *); // Canlıların sayısını bulan fonksiyon
    void (*delete_Habitat)(struct HABITAT *);     // Habitat'ı silen fonksiyon
};

typedef struct HABITAT *Habitat; // Habitat tipi
Habitat new_Habitat();   // Yeni bir Habitat oluşturan fonksiyon
void dosyaOku(Habitat this, char *dosyaAdi);   // Dosyadan okuma işlemi yapan fonksiyon
void yazdir(Habitat this, int satirdakiSayiSayisi);  // Habitat bilgilerini yazdıran fonksiyon
Canli canliTipiBulucu(Habitat this, int canliDegeri);  // Canlı tipini bulan fonksiyon
void canlilarinDizisiOlusturucu(Habitat this, char *dosyaAdi); // Canlıların dizisini oluşturan fonksiyon
void besinPiramidi(Habitat this, char *);    // Bütün işlemlerin gerçekleştiği yeme fonksiyonlarıyla kazananın bulunduğu fonksiyon
void canlilarinSayisi(Habitat this, char *); // Canlıların sayısını bulan fonksiyon
void delete_Habitat(Habitat this);  // Habitat'ı silen fonksiyon
#endif