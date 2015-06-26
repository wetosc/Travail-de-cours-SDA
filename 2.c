#ifndef F2_FILE
#define F2_FILE
#include "menu.h"

void menu2()
{
    system("cls");
    FILE *f=fopen(FILE1,"rb");
    FILE *g=fopen(FILE2,"rb");
    FILE *h=fopen(FILE3,"rb");
    FILE *t=fopen(FILE_,"wb");
    copyFile(f,t);
    copyFile(g,t);
    copyFile(h,t);
    fclose(f);
    fclose(g);
    fclose(h);
    fclose(t);
    printf("\n  Le fichier a ete cree.\n");
    printf("\n  Tastez <Enter> pour revenir au menu principal.");
    getch();
    menu();
}

void copyFile(FILE *from, FILE *to)
{
    struct MobileApp temp;
    while (1)
    {
        if (fread(&temp,sizeof(temp),1,from))fwrite(&temp,sizeof(temp),1,to);
        if(feof(from)) break;
    }
}

#endif
