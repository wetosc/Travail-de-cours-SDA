#ifndef F1_FILE
#define F1_FILE
#include "menu.h"
struct MobileApp readFromDisplay(int i);

void menu1(int haha)
{
    char *parameter;
    if (haha==1)parameter="wb";
    else if (haha==4) parameter="ab";
    FILE *f=fopen(FILE1,parameter);
    FILE *g=fopen(FILE2,parameter);
    FILE *h=fopen(FILE3,parameter);
    int nombre=0,i;
    system("cls");
    printf("\n  Donnez le nombre des applications:\n  ");
    scanf("%d",&nombre);
    for (i=0; i<nombre; i++)
    {
        struct MobileApp ap= readFromDisplay(i+1);
        if (strcmp(ap.OS,"Android")==0) fwrite(&ap,sizeof(ap),1,f);
        if (strcmp(ap.OS,"iOS")==0) fwrite(&ap,sizeof(ap),1,g);
        if (strcmp(ap.OS,"WinPhone")==0) fwrite(&ap,sizeof(ap),1,h);
    }
    fclose(f);
    fclose(g);
    fclose(h);

    printf("\n\n  Les informations sont enregistrees.\n  Tastez <Enter> pour revenir au menu principal.");
    getch();
    menu();
}

struct MobileApp readFromDisplay(int i)
{
    struct MobileApp ap;
    ap.name=malloc(20);
    ap.developer=malloc(20);
    ap.OS=malloc(10);
    int k=0;
    printf("\nEnregistrez l'application nr. %d\n",i);
    printf("\nDonnez l' ID:\n");
    scanf("%d",&ap.ID);
    printf("\nDonnez le nom:\n");
    scanf("%s",ap.name);
    printf("\nDonnez le developeur:\n");
    scanf("%s",ap.developer);
    printf("\nChoisisez le nombre de systeme d'operation:\n");
    printf("\n     1. Android");
    printf("\n     2. iOS");
    printf("\n     3. Windows Phone\n");
    scanf("%d",&k);
    switch (k)
    {
    case 1:
        strcpy(ap.OS, "Android");
        break;
    case 2:
        strcpy(ap.OS, "iOS");
        break;
    case 3:
        strcpy(ap.OS, "WinPhone");
        break;
    default:
        strcpy(ap.OS, "Undefined");
    }
    printf("\nDonnez le rating:\n");
    scanf("%f",&ap.rating);
    printf("\nDonnez la taille:\n");
    scanf("%f",&ap.size);
    printf("\nDonnez la version, avec le format: prim sec tert:\n");
    scanf("%d%d%d",&ap.version.prim,&ap.version.sec,&ap.version.tert);
    return ap;
}


#endif
