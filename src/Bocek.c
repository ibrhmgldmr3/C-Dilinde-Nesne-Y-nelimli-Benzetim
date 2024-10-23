/**
 *
 * @author İbrahim Güldemir & ibrahim.guldemir@ogr.sakarya.edu.tr
 * @since 01.05.2024
 * <p>
 * Bocek türündeki canlıların özelliklerini ve nasıl oluşacağını içeren sınıf
 * </p>
 */

#include "Bocek.h"
// Yeni bir Böcek oluşturan fonksiyon
Bocek new_Bocek(char* canliTuru, int canliDegeri)
{
    Bocek this;
    this = (Bocek)malloc(sizeof(struct BOCEK));      // Yeni bir Böcek oluşturuluyor
    this->super = new_Canli(canliTuru, canliDegeri); // Üst sınıfın (Canli) yapıcı fonksiyonu çağrılıyor
    this->super->setCanliTuru = &setCanliTuruBocek;  // Böcek'in canlı türünü ayarlayan fonksiyon atanıyor
    this->delete_Bocek = &delete_Bocek;              // Böcek'i silen fonksiyon atanıyor
    this->super->gorunum = &gorunumBocek;            // Böcek'in görünümünü döndüren fonksiyon atanıyor
    this->super->ye = &yeBocek;                      // Böcek'in bir canlıyı yiyip yiyemeyeceğini kontrol eden fonksiyon atanıyor
    setCanliTuruBocek(this, canliTuru);              // Böcek'in canlı türü ayarlanıyor
    return this;                                     // Oluşturulan Böcek döndürülüyor
}
// Böcek'in canlı türünü ayarlayan fonksiyon
void setCanliTuruBocek(Bocek this, char *canliTuru)
{
    this->super->canliTuru = canliTuru;
}
// Böcek'in görünümünü döndüren fonksiyon
char *gorunumBocek(Canli this)
{
    return this->canliTuru;
}
// Böcek'i silen fonksiyon
void delete_Bocek(Bocek this)
{
    if (!this)
        return;
    this->super->delete_Canli(this->super);
    free(this);
    
}
// boceğin yeme fonksiyonu
bool yeBocek(Canli this, Canli canli)
{
    if (canli != NULL && this != NULL && canli->canliMi == true)
    {
        char *canliTuru = canli->canliTuru;
        if (strcmp(canliTuru, "B") == 0)
        {
            canli->canliMi = false;
            return true;
        }
        if (strcmp(canliTuru, "P") == 0)
        {
            canli->canliMi = false;
            return true;
        }
        if (strcmp(canliTuru, "S") == 0)
        {            this->canliMi = false;
            return false;
        }
        if (strcmp(canliTuru, "C") == 0)
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
