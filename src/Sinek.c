/**
 *
 * @author İbrahim Güldemir & ibrahim.guldemir@ogr.sakarya.edu.tr
 * @since 01.05.2024
 * <p>
 * Sinek türündeki canlıların özelliklerini ve nasıl oluşacağını içeren sınıf
 * </p>
 */

#include "Sinek.h"
//sinek tipinde canlı oluşturan ve döndüren fonksiyon
Sinek new_Sinek(char *canliTuru, int canliDegeri)
{
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
    this->super = new_Bocek(canliTuru, canliDegeri);
    this->super->super->setCanliTuru = &setCanliTuruSinek;
    this->delete_Sinek = &delete_Sinek;
    this->super->super->gorunum = &gorunumSinek;
    this->super->super->ye = &yeSinek;
    setCanliTuruSinek(this, canliTuru);
    return this;
}
// sineğin canlı türünü set ettiğimiz fonksiyoon

void setCanliTuruSinek(Sinek this, char *canliTuru)
{
    this->super->super->canliTuru = canliTuru;
}
// sineğin görünümünü döndüren fonksiyon
char *gorunumSinek(Canli this)
{
    return this->canliTuru;
}
// sinek sınıfının silme fonksiyonu
void delete_Sinek(Sinek this)
{
    if (!this)
        return;
    this->super->delete_Bocek(this->super);

    free(this);
    
}
// sinek yeme durumlarını döndüren fonksiyon
bool yeSinek(Canli this, Canli canli)
{

    if (canli->canliMi == true)
    {
        char *canliTuru = canli->canliTuru;
        if (strcmp(canliTuru, "B") == 0)
        {
            this->canliMi = false;
            return false;
        }
        else if (strcmp(canliTuru, "C") == 0)
        {
            canli->canliMi = false;
            return true;
        }
        else if (strcmp(canliTuru, "P") == 0)
        {
            canli->canliMi = false;
            return true;
        }
        else if (strcmp(canliTuru, "S") == 0)
        {
            if (this->canliDegeri >=canli->canliDegeri)
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