/**
 *
 * @author İbrahim Güldemir & ibrahim.guldemir@ogr.sakarya.edu.tr
 * @since 01.05.2024
 * <p>
 * Bütün işlemlerin gerçekleştiği main fonksiyonunu içeren 
 * </p>
 */

#include "Habitat.h"
#include <time.h>
#include <math.h>

int main()
{
    time_t start, end;
    double elapsed_time;
    start =time(NULL); 

    Habitat habitat = new_Habitat();
    habitat->dosyaOku(habitat, ".\\doc\\Veri.txt");
    habitat->canlilarinSayisi(habitat, ".\\doc\\Veri.txt");
    habitat->yazdir(habitat, habitat->satirdakiSayiSayisi);
    printf("\n");
    system("PAUSE");

    habitat->besinPiramidi(habitat, ".\\doc\\Veri.txt");
    delete_Habitat(habitat);
    
    end = time(NULL);
    elapsed_time = difftime(end, start);

    printf("\nPrograin Calisma suresi: %.0f dakika %.0f saniye\n", elapsed_time / 60, fmod(elapsed_time, 60));
    return 0;
}