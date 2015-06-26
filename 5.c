#ifndef F5_FILE
#define F5_FILE
#include "menu.h"

struct MobileApp app[30];
int nombre;
void menu5()
{
    system("cls");
    printf("\n Choisisez le parametre d'affichage selectif:\n");
    printf("\n 1. ID\n");
    printf("\n 2. Nom de l'application\n");
    printf("\n 3. Nom de developpeur\n");
    printf("\n 4. Rating\n");
    printf("\n 5. Taille\n");
    printf("\n\n ");
    loadData();
    int k,mini,maxi;
    float minf,maxf;
    char choice[20];
    scanf("%d",&k);
    printf("\n");
    switch (k)
    {
    case 1:
        printf("\n Donnez le minimum et le maximum de l'ID:\n");
        scanf("%d%d",&mini,&maxi);
        selectID(mini,maxi);
        break;
    case 2:
        printf("\n Donnez le nom de l'application:\n");
        scanf("%s",choice);
        selectNom(choice);
        break;
    case 3:
        printf("\n Donnez le nom de developeur:\n");
        scanf("%s",choice);
        selectDev(choice);
        break;
    case 4:
        printf("\n Donnez le minimum et le maximum de rating:\n");
        scanf("%f%f",&minf,&maxf);
        selectRat(minf,maxf);
        break;
    case 5:
        printf("\n Donnez le minimum et le maximum de taille:\n");
        scanf("%f%f",&minf,&maxf);
        selectSize(minf,maxf);
        break;
       default: printf("Erreur. Revenez au menu principal.");
    }
    getch();
    menu();
}

void selectID(int min,int max)
{
    int i;
    printf("| ID    |     Name   | Developer  |     OS     | Rat. | Size  | Version |\n");
    printf("+-------+------------+------------+------------+------+-------+---------+\n");
    for (i=0; i<nombre; i++)
        if (app[i].ID>=min && app[i].ID<=max)
        {
            printf("| %5d | %10s | %10s | %10s | %2.1f  | %3.2f | %2d.%2d.%2d |\n",
                   app[i].ID,app[i].name,app[i].developer,app[i].OS,app[i].rating,app[i].size,app[i].version.prim, app[i].version.sec, app[i].version.tert);
            printf("+-------+------------+------------+------------+------+-------+---------+\n");
        }
}

void selectNom(char s[20])
{
    int i;
    printf("| ID    |     Name   | Developer  |     OS     | Rat. | Size  | Version |\n");
    printf("+-------+------------+------------+------------+------+-------+---------+\n");
    for (i=0; i<nombre; i++)
        if (strstr(app[i].name,s) || strstr(s,app[i].name))
        {
            printf("| %5d | %10s | %10s | %10s | %2.1f  | %3.2f | %2d.%2d.%2d |\n",
                   app[i].ID,app[i].name,app[i].developer,app[i].OS,app[i].rating,app[i].size,app[i].version.prim, app[i].version.sec, app[i].version.tert);
            printf("+-------+------------+------------+------------+------+-------+---------+\n");
        }
}
void selectDev(char s[20])
{
    int i;
    printf("| ID    |     Name   | Developer  |     OS     | Rat. | Size  | Version |\n");
    printf("+-------+------------+------------+------------+------+-------+---------+\n");
    for (i=0; i<nombre; i++)
        if (strstr(app[i].developer,s) || strstr(s,app[i].developer))
        {
            printf("| %5d | %10s | %10s | %10s | %2.1f  | %3.2f | %2d.%2d.%2d |\n",
                   app[i].ID,app[i].name,app[i].developer,app[i].OS,app[i].rating,app[i].size,app[i].version.prim, app[i].version.sec, app[i].version.tert);
            printf("+-------+------------+------------+------------+------+-------+---------+\n");
        }
}

void selectRat(float min,float max)
{
    int i;
    printf("| ID    |     Name   | Developer  |     OS     | Rat. | Size  | Version |\n");
    printf("+-------+------------+------------+------------+------+-------+---------+\n");
    for (i=0; i<nombre; i++)
        if (app[i].rating>=min && app[i].rating<=max)
        {

            printf("| %5d | %10s | %10s | %10s | %2.1f  | %3.2f | %2d.%2d.%2d |\n",
                   app[i].ID,app[i].name,app[i].developer,app[i].OS,app[i].rating,app[i].size,app[i].version.prim, app[i].version.sec, app[i].version.tert);
            printf("+-------+------------+------------+------------+------+-------+---------+\n");
        }
}

void selectSize(float min,float max)
{
    int i;
    printf("| ID    |     Name   | Developer  |     OS     | Rat. | Size  | Version |\n");
    printf("+-------+------------+------------+------------+------+-------+---------+\n");
    for (i=0; i<nombre; i++)
        if (app[i].size>=min && app[i].size<=max)
        {
            printf("| %5d | %10s | %10s | %10s | %2.1f  | %3.2f | %2d.%2d.%2d |\n",
                   app[i].ID,app[i].name,app[i].developer,app[i].OS,app[i].rating,app[i].size,app[i].version.prim, app[i].version.sec, app[i].version.tert);
            printf("+-------+------------+------------+------------+------+-------+---------+\n");
        }
}


void loadData()
{
    FILE *f=fopen(FILE1,"rb");
    FILE *g=fopen(FILE2,"rb");
    FILE *h=fopen(FILE3,"rb");
    int k=0;
    while (1)
    {
        if (fread(&app[k],sizeof(app[k]),1,f))k++;
        if (feof(f)) break;
    }
    while (1)
    {
        if (fread(&app[k],sizeof(app[k]),1,g))k++;
        if (feof(g)) break;
    }
    while (1)
    {
        if (fread(&app[k],sizeof(app[k]),1,h))k++;
        if (feof(h)) break;
    }
    fclose(f);
    fclose(g);
    fclose(h);
    nombre=k;
}

#endif
