/**
 *
 * @author İbrahim Güldemir & ibrahim.guldemir@ogr.sakarya.edu.tr
 * @since 01.05.2024
 * <p>
 * Canli soyut sınıfının özellikleri ve sahip olduğu fonksiyonları içeren sınıf
 * </p>
 */

#include "Canli.h"

// Canli'nin değerini ayarlayan fonksiyon
void setDeger(Canli this, int canliDegeri)
{
    this->canliDegeri = canliDegeri; // Canli'nin değeri ayarlanıyor
}

// Canli'nin türünü ayarlayan fonksiyon
void setCanliTuru(Canli this, char *canliTuru)
{
    this->canliTuru = canliTuru; // Canli'nin türü ayarlanıyor
}

// Yeni bir Canli oluşturan fonksiyon
Canli new_Canli(char *canliTuru, int canliDegeri)
{
    Canli this = (Canli)malloc(sizeof(struct CANLI)); // Yeni bir Canli oluşturuluyor
    this->canliDegeri = canliDegeri;// Canli'nin değeri atanıyor
    this->canliTuru = canliTuru;// Canli'nin türü atannıyor
    this->canliMi = true;   // Canli'nin durumu ayarlanıyor
    this->delete_Canli = &delete_Canli; // Canli'yi silen fonksiyon atanıyor
    setCanliTuru(this, canliTuru); // Canli'nin türü ayarlanıyor
    return this;  // Oluşturulan Canli döndürülüyor
}
//canlinin silme fonksiyonu
void delete_Canli(Canli this)
{
    if (!this)
        return;
    free(this);
}