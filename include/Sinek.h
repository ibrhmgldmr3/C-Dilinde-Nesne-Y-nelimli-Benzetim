#ifndef SINEK_H
#define SINEK_H
#include "Bocek.h"

// Sinek yapısı
struct SINEK
{
    Bocek super; // Üst sınıfı temsil eder
    void (*delete_Sinek)(struct SINEK *); // Sinek'i silen fonksiyon
};

typedef struct SINEK *Sinek; // Sinek tipi
Sinek new_Sinek(char *canliTuru, int canliDegeri); // Yeni bir Sinek oluşturan fonksiyon
void setCanliTuruSinek(Sinek this, char *canliTuru); // Sinek'in canlı türünü ayarlayan fonksiyon
char *gorunumSinek(Canli this);  // Sinek'in görünümünü döndüren fonksiyon
void delete_Sinek(Sinek); // Sinek'i silen fonksiyon
bool yeSinek(Canli this, Canli canli); // Sinek'in bir canlıyı yiyip yiyemeyeceğini kontrol eden fonksiyon
#endif // !SINEK_H