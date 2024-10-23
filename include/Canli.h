#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum Bool {false, true};
typedef enum Bool bool;

struct CANLI
{
    int canliID;
    int canliDegeri;
    char *canliTuru;
    bool canliMi;
    char* (*gorunum)();
    bool (*ye)();
    void (*delete_Canli)(struct CANLI *);
    void (*setCanliTuru)();
    };

typedef struct CANLI *Canli;

Canli new_Canli(char* canliTuru,int canliDegeri); // canli oluşturma fonksiyonu
void delete_Canli(Canli this); //canlinin silme fonksiyonu
#endif
