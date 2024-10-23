/**
 *
 * @author İbrahim Güldemir & ibrahim.guldemir@ogr.sakarya.edu.tr
 * @since 01.05.2024
 * <p>
 * Canlıların tutulduğu ve üzerlerinde işlemlerin yapıldığı sınıf
 * </p>
 */

#include "Habitat.h"

//yeni bir habitat oluşturan fonksiyon
Habitat new_Habitat()
{
    Habitat this;
    this= (Habitat)malloc(sizeof(struct HABITAT));
    printf("\nHabitat olusturuldu\n");
    this->dosyaOku = &dosyaOku;
    this->yazdir = &yazdir;
    this->canliTipiBulucu=&canliTipiBulucu;
    this->besinPiramidi=&besinPiramidi;
    this->canlilarinSayisi = &canlilarinSayisi;
    this->canlilarinDizisiOlusturucu = &canlilarinDizisiOlusturucu;
    this->delete_Habitat = &delete_Habitat;
    this->satirdakiSayiSayisi = 0;

    return this;
}

//canliların  türlerini ekrana sırayla matrissel formda yazdıran fonksiyon
void yazdir(Habitat this, int satirdakiSayiSayisi)
{
    if (this == 0)
    {
        printf("HATA!!! Habitat yanlis!\n");
        return;
    }
    system("cls");
    printf("\n\n");
    int toplamCanliSayisi = this->canliSayilari[0] + this->canliSayilari[1] + this->canliSayilari[2] + this->canliSayilari[3];
    int index = 0;
    for (int i = 0; i < toplamCanliSayisi; i++)
    {
        if (i % satirdakiSayiSayisi == 0)
        {
            printf("\n");
        }
        if (this->canlilar[i]!=NULL)
        {
            printf(" %s ", this->canlilar[i]->gorunum(this->canlilar[i]));
        }
        if (this->canlilar[i] == NULL)
        {
            printf(" X "); 
        }

    }
}
//canlı tipini bulup onu uygun dizisine atayan ve canlı superini döndüren fonksiyon
Canli canliTipiBulucu(Habitat this, int canliDegeri)
{
    Canli canli=0;
    if (canliDegeri >= 1 && canliDegeri <= 9)
    {
        this->bitkiler[--this->canliSayilari[0]] = new_Bitki("B", canliDegeri);
        canli = this->bitkiler[this->canliSayilari[0]]->super;
        return canli;
    }
    else if (canliDegeri >= 10 && canliDegeri <= 20)
    {
        this->bocekler[--this->canliSayilari[1]] = new_Bocek("C", canliDegeri);
        canli = this->bocekler[this->canliSayilari[1]]->super;
        return canli;
    }
    else if (canliDegeri >= 21 && canliDegeri <= 50)
    {
        this->sinekler[--this->canliSayilari[2]] = new_Sinek("S", canliDegeri);
        canli = this->sinekler[this->canliSayilari[2]]->super->super;

        return canli;
    }
    else if (canliDegeri >= 51 && canliDegeri <=99)
    {
        this->pireler[--this->canliSayilari[3]] = new_Pire("P", canliDegeri);
        canli = this->pireler[this->canliSayilari[3]]->super->super;

        return canli;
    }
    else
    {
        printf("Hata\n");
        system("PAUSE");
        return canli;   
    }
}
//canlıların türlerine göre sayılarını bulan fonksiyon
void canlilarinSayisi(Habitat this ,char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "r");
    this->canliSayilari[0] = 0;
    this->canliSayilari[1] = 0;
    this->canliSayilari[2] = 0;
    this->canliSayilari[3] = 0;
    char *satir = (char *)malloc(2048* sizeof(char));
    while (fgets(satir, 2048, dosya) != 0)
    {
        int sayi = 0;
        for (int i = 0; i < strlen(satir); i++)
        {
            if (satir[i] >= '0' && satir[i] <= '9')
            {
                sayi = sayi * 10 + (satir[i] - '0');
            }
            else if (sayi != 0)
            {

                if (sayi >= 1 && sayi <= 9)
                {
                    this->canliSayilari[0] += 1;
                }
                else if (sayi >= 10 && sayi <= 20)
                {
                    this->canliSayilari[1] += 1;
                }
                else if (sayi >= 21 && sayi <= 50)
                {
                    this->canliSayilari[2] += 1;
                }
                else if (sayi >= 51 && sayi < 100)
                {
                    this->canliSayilari[3] += 1;
                }
                sayi = 0;
            }
        }
        if (sayi != 0)
        {

            if (sayi >= 1 && sayi <= 9)
            {
                this->canliSayilari[0] += 1;
            }
            else if (sayi >= 10 && sayi <= 20)
            {
                this->canliSayilari[1] += 1;
            }
            else if (sayi >= 21 && sayi <= 50)
            {
                this->canliSayilari[2] += 1;
            }
            else if (sayi >= 51 && sayi < 100)
            {
                this->canliSayilari[3] += 1;
            }
            sayi = 0;
        }
    }
    
    free(satir);
    fclose(dosya);
}
//bulunan sayılara göre bellekten hepsine uygun sayıda yer ayıran fonksiyon
void canlilarinDizisiOlusturucu(Habitat this, char *dosyaAdi)
{
    canlilarinSayisi(this,dosyaAdi);
    
    Bitki* bitkiler = (Bitki*)malloc(sizeof(struct BITKI*) * this->canliSayilari[0]);
    this->bitkiler = bitkiler;

    Bocek* bocekler = (Bocek*)malloc(sizeof(struct BOCEK*) * this->canliSayilari[1]);
    this->bocekler = bocekler;

    Sinek *sinekler = (Sinek*)malloc(sizeof(struct SINEK*) * this->canliSayilari[2]);
    this->sinekler = sinekler;

    Pire *pireler = (Pire*)malloc(sizeof(struct PIRE*) * this->canliSayilari[3]);
    this->pireler = pireler;

    int toplamSayi=this->canliSayilari[0]+this->canliSayilari[1]+this->canliSayilari[2]+this->canliSayilari[3];
    Canli* canlilar = (Canli*)malloc(sizeof(struct CANLI*) * toplamSayi);
    this->canlilar = canlilar;

}
//dosyadan okuyup dizilere atama işleminin gerçekleştiği fonksiyon
void dosyaOku(Habitat this, char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "r");
    if (dosya == 0)
    {
        printf("Dosya acilamadi\n");
        return;
    }
    canlilarinDizisiOlusturucu(this, dosyaAdi);
    char *satir = (char *)malloc(2048 * sizeof(char));
    int sayi = 0;
    int index = 0;
    this->satirdakiSayiSayisi = 0;
    dosya = fopen(dosyaAdi, "r");
    while (fgets(satir, 2048, dosya) != 0)
    {
        if(satir[0]==' ')
            continue;
        this->satirdakiSayiSayisi = 0;
        for (int i = 0; i < strlen(satir); i++)
        {
            if (satir[i] >= '0' && satir[i] <= '9')
            {
                sayi = sayi * 10 + (satir[i] - '0');
            }
            else if (sayi != 0)
            {
                this->canlilar[index] = canliTipiBulucu(this, sayi);
                this->canlilar[index]->canliID=index;
                index++;
                sayi = 0;
                this->satirdakiSayiSayisi++;
            }
            }
            if (sayi > 0)
            {

                this->canlilar[index] = canliTipiBulucu(this, sayi);
                this->canlilar[index]->canliID = index;
                index++;
                this->satirdakiSayiSayisi++;
            }
        
    }

    free(satir);
    fclose(dosya);
}
//verilen canlının canliID sine ve türüne göre canlının türünü bulup uygun id'yi bulduktan sonra o diziden silen fonksiyon
void bulVeSil(Habitat this, char *canliTuru, int canliID)
{
    if (strcmp(canliTuru, "B") == 0)
    {
        for (int i = 0; i < this->canliSayilari[0]; i++)
        {
            if (this->bitkiler[i] != 0)
            {
                if (this->bitkiler[i]->super->canliID == canliID)
                {
                    this->bitkiler[i]->delete_Bitki(this->bitkiler[i]);
                    this->bitkiler[i] = 0;
                }
            }
        }
    }
    else if (strcmp(canliTuru, "C") == 0)
    {
        for (int i = 0; i < this->canliSayilari[1]; i++)
        {
            if (this->bocekler[i] != 0)
            {
                if (this->bocekler[i]->super->canliID == canliID)
                {
                    this->bocekler[i]->delete_Bocek(this->bocekler[i]);
                    this->bocekler[i] = 0;
                }
            }
        }
    }
    else if (strcmp(canliTuru, "S") == 0)
    {
        for (int i = 0; i < this->canliSayilari[2]; i++)
        {
            if (this->sinekler[i] != 0)
            {
                if (this->sinekler[i]->super->super->canliID == canliID)
                {
                    this->sinekler[i]->delete_Sinek(this->sinekler[i]);
                    this->sinekler[i] = 0;
                }
            }
        }
    }
    else if (strcmp(canliTuru, "P") == 0)
    {
        for (int i = 0; i < this->canliSayilari[3]; i++)
        {
            if (this->pireler[i] != 0)
            {
                if (this->pireler[i]->super->super->canliID == canliID)
                {
                    this->pireler[i]->delete_Pire(this->pireler[i]);
                    this->pireler[i] = 0;
                }
            }
        }
    }
}
//oluşturulan canlı dizisinin sırayla gezilip yiyip yiyeme durumlarını kontrol ederek bunu tekrarlayıp kazananı bulan fonksiyon
void besinPiramidi(Habitat this, char *dosyaAdi)
{
    int toplamCanliSayisi = this->canliSayilari[0] + this->canliSayilari[1] + this->canliSayilari[2] + this->canliSayilari[3];
    int index = 0;
    int satir=0, sutun=0;
    
    Canli canliKontrol = this->canlilar[index];
    for (int i = 1; i < toplamCanliSayisi; i++)
    {
        if (!canliKontrol->ye(canliKontrol, this->canlilar[i]))
        {
            
            bulVeSil(this, canliKontrol->canliTuru, canliKontrol->canliID);
            this->canlilar[index]=NULL;
            canliKontrol = this->canlilar[i];
            index = i;
            satir = (1 + i) / this->satirdakiSayiSayisi;
            sutun = i % this->satirdakiSayiSayisi;
        }
        else
        {
            bulVeSil(this, this->canlilar[i]->canliTuru, this->canlilar[i]->canliID);
            this->canlilar[i]=NULL;
        }
        yazdir(this, this->satirdakiSayiSayisi);
    }
    printf("\n\n");
    printf("\n\n\tKazanan: %s : (%d,%d)\n", this->canlilar[index]->gorunum(this->canlilar[index]), satir, sutun);

    


}
//en sonda alınan bellekleri iade eden ve sona kalan canlıyı silip dizilerin alanlarını iade eden alan
void delete_Habitat(Habitat this)
{
    if (!this)
        return;
    for (int i = 0; i < this->canliSayilari[0]; i++)
    {
        if (this->bitkiler[i] != 0)
        {
            this->bitkiler[i]->delete_Bitki(this->bitkiler[i]);
            this->bitkiler[i]=0;    
        }
    }
    for (int i = 0; i < this->canliSayilari[1]; i++)
    {
        if (this->bocekler[i] != 0)
        {
            this->bocekler[i]->delete_Bocek(this->bocekler[i]);
            this->bocekler[i] = 0;
        }
    }
    for (int i = 0; i < this->canliSayilari[2]; i++)
    {
        if (this->sinekler[i] != 0)
        {
            this->sinekler[i]->delete_Sinek(this->sinekler[i]);
            this->sinekler[i] = 0;
        }
    }
    for (int i = 0; i < this->canliSayilari[3]; i++)
    {
        if (this->pireler[i] != 0)
        {
            this->pireler[i]->delete_Pire(this->pireler[i]);
            this->pireler[i] = 0;
        }
    }
    free(this->bitkiler);
    free(this->bocekler);
    free(this->sinekler);
    free(this->pireler);
    free(this->canlilar);
    free(this);
}
