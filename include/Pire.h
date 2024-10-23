#ifndef PIRE_H
#define PIRE_H
#include "Bocek.h"

// Pire yapısı
struct PIRE
{
    Bocek super;  // Üst sınıftan kalıtım benzetimi
    void (*delete_Pire)(struct PIRE *); // Pire'yi silen fonksiyon
};

typedef struct PIRE *Pire; // Pire tipi

Pire new_Pire(char *canliTuru, int canliDegeri);  // Yeni bir Pire oluşturan fonksiyon
void setCanliTuruPire(Pire this, char *canliTuru); // Pire'nin canlı türünü ayarlayan fonksiyon
char *gorunumPire(Canli this);   // Pire'nin görünümünü döndüren fonksiyon
bool yePire(Canli this, Canli canli);    // Pire'nin bir canlıyı yiyip yiyemeyeceğini kontrol eden fonksiyon
void delete_Pire(Pire this); // Pire'yi silen fonksiyon

#endif // !PIRE_H