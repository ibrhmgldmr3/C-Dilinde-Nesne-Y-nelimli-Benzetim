/**
 *
 * @author İbrahim Güldemir & ibrahim.guldemir@ogr.sakarya.edu.tr
 * @since 01.05.2024
 * <p>
 * Bitki türündeki canlıların özelliklerini ve nasıl oluşacağını içeren sınıf
 * </p>
 */
#include "Bitki.h"
// Yeni bir Bitki oluşturan fonksiyon
Bitki new_Bitki(char *canliTuru, int canliDegeri)
{
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));      // Yeni bir Bitki oluşturuluyor
    this->super = new_Canli(canliTuru, canliDegeri); // Üst sınıfın (Canli) yapıcı fonksiyonu çağrılıyor
    this->super->setCanliTuru = &setCanliTuruBitki;  // Bitki'nin canlı türünü ayarlayan fonksiyon atanıyor
    this->super->gorunum = &gorunumBitki;            // Bitki'nin görünümünü döndüren fonksiyon atanıyor
    this->delete_Bitki = &delete_Bitki;              // Bitki'yi silen fonksiyon atanıyor
    this->super->ye = &yeBitki;                      // Bitki'nin bir canlıyı yiyip yiyemeyeceğini kontrol eden fonksiyon atanıyor
    setCanliTuruBitki(this, canliTuru);              // Bitki'nin canlı türü ayarlanıyor
    return this;                                     // Oluşturulan Bitki döndürülüyor
}
// Bitki'yi silen fonksiyon
void delete_Bitki( Bitki this)
{
    if (!this)
        return;
    this->super->delete_Canli(this->super);
    free(this);

} 
// Bitki'nin görünümünü döndüren fonksiyon
char* gorunumBitki(Canli this)
{
    return this->canliTuru;
}
// Bitki'nin canlı türünü ayarlayan fonksiyon
void setCanliTuruBitki(Bitki this, char* canliTuru)
{
    this->super->canliTuru=canliTuru;
}
// Bitki'nin bir canlıyı yiyip yiyemeyeceğini kontrol eden fonksiyon
bool yeBitki(Canli this, Canli canli)
{
    if (canli->canliMi == true)
    {
        char *canliTuru = canli->canliTuru;

        if (strcmp(canliTuru, "P") == 0)
        {
            canli->canliMi = false;
            
            return true;
            }
            else if (strcmp(canliTuru, "S") == 0)
            {
                canli->canliMi = false;
                
                return true;
            }
            else if (strcmp(canliTuru, "C") == 0)
            {
                this->canliMi = false;
                return false;
            }
            else if (strcmp(canliTuru, "B") == 0)
            {
                if (this->canliDegeri >= canli->canliDegeri)
                {
                    canli->canliMi = false;
                    return true;
                }
                else
                {
                    this->canliMi = false;
                    return false;
                }
            }
    }
    return false;
}