/**
 *
 * @author İbrahim Güldemir & ibrahim.guldemir@ogr.sakarya.edu.tr
 * @since 01.05.2024
 * <p>
 * Pire türündeki canlıların özelliklerini ve nasıl oluşacağını içeren sınıf
 * </p>
 */

#include "Pire.h"
//pire oluşturan ve bunu döndüren fonksiyon
Pire new_Pire(char *canliTuru, int canliDegeri)
{
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this->super = new_Bocek(canliTuru, canliDegeri);
    this->super->super->setCanliTuru = &setCanliTuruPire;
    this->delete_Pire = &delete_Pire;
    this->super->super->gorunum = &gorunumPire;
    this->super->super->ye = &yePire;
    setCanliTuruPire(this, canliTuru);
    return this;
}
//pire sınıfının silme fonksiyonu
void delete_Pire(Pire this)
{
    if (!this)
        return;
    this->super->delete_Bocek(this->super);
    free(this);
    
}
// pirenin canlı türünü set ettiğimiz fonksiyoon
void setCanliTuruPire(Pire this, char *canliTuru)
{
     this->super->super->canliTuru=canliTuru;
}
//pirenin görünümünü döndüren fonksiyon
char* gorunumPire(Canli this)
{
    return this->canliTuru;
}
//pirenin yeme durumlarını döndüren fonksiyon
bool yePire(Canli this,Canli canli)
{
    if(canli->canliMi==true)
    {
        char *canliTuru=canli->canliTuru;
        if (strcmp(canliTuru,"B")==0)
        {
            this->canliMi = false;
            return false;
            }
            else if (strcmp(canliTuru, "C") == 0)
            {
                this->canliMi = false;
                return false;
            }
            else if (strcmp(canliTuru, "S") == 0)
            {
                this->canliMi = false;  
                return false;
            }
            else if (strcmp(canliTuru, "P") == 0)
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
                return true;
        }

    }
    return false;
}

