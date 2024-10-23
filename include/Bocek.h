#ifndef BOCEK_H
#define BOCEK_H
#include "Canli.h"
struct BOCEK
{
    Canli super;
    void (*delete_Bocek)(struct BOCEK*);
    
};
typedef struct BOCEK *Bocek; // turu belirleme
Bocek new_Bocek(char *canliTuru, int canliDegeri); // bocek oluşturma fonksiyonu
void setCanliTuruBocek(Bocek this, char *canliTuru); // oluşan bocek canlısının türünü canlı oluşurken setlemek için
char *gorunumBocek(Canli this); // bocek tipindeki canlının görünümünü getiren fonksiyon
void delete_Bocek(Bocek this); // bocek türündeki nesneyi silme fonksiyonu
bool yeBocek(Canli this, Canli canli); // boceğin yeme fonksiyonu
#endif // !BOCEK_H

