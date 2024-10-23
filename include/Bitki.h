#ifndef BITKI_H
#define BITKI_H
#include "Canli.h"
struct BITKI
{
    Canli super;
    void (*delete_Bitki)(struct BITKI *);
};
typedef struct BITKI *Bitki; //turu belirleme
Bitki new_Bitki(char *canliTuru, int canliDegeri); //bitki oluşturma fonksiyonu
void delete_Bitki(const Bitki this); // bitki türündeki nesneyi silme fonksiyonu
char *gorunumBitki(Canli this); // bitki tipindeki canlının görünümünü getiren fonksiyon
bool yeBitki(Canli this, Canli canli); //bitkinin yeme fonksiyonu
void setCanliTuruBitki(Bitki this, char* canliTuru);// oluşan bitki canlısının türünü canlı oluşurken setlemek için
#endif // !BITKI_H