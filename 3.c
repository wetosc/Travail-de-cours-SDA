#ifndef F3_FILE
#define F3_FILE
#include "menu.h"

struct MobileApp app[30];
void menu3()
{
    system("cls");
    printf("\n Choisisez le nombre de fichier a aficher:\n");
    printf("\n  1. "FILE1);
    printf("\n  2. "FILE2);
    printf("\n  3. "FILE3);
    printf("\n  4. "FILE_);
    printf("\n\n ");
    int choice;
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
    case 1:
        displayInfo(readInfo(FILE1));
        break;
    case 2:
        displayInfo(readInfo(FILE2));
        break;
    case 3:
        displayInfo(readInfo(FILE3));
        break;
    case 4:
        displayInfo(readInfo(FILE_));
        break;
    default:
        printf("Erreur. Revenez au menu principal.");
    }
    printf("\n\n");
    printf("\n  Tastez <Enter> pour revenir au menu principal.");
    getch();
    menu();
}




int readInfo(char fileName[20])
{
    int k=0;
    FILE *f=fopen(fileName,"rb");
    while (1)
    {
        app[k].name=malloc(20);
        app[k].developer=malloc(20);
        app[k].OS=malloc(10);
        fread(&app[k],sizeof(app[k]),1,f);
        k++;
        if (feof(f))break;
    }
    fclose(f);
    return k-1;
}

void displayInfo(int k)
{
    int i;
    printf("| ID    |     Name   | Developer  |     OS     | Rat. | Size  | Version |\n");
    printf("+-------+------------+------------+------------+------+-------+---------+\n");
    for (i=0; i<k; i++)
    {
        printf("| %5d | %10s | %10s | %10s | %2.1f  | %3.2f | %2d.%2d.%2d |\n",
               app[i].ID,
               app[i].name,
               app[i].developer,
               app[i].OS,
               app[i].rating,
               app[i].size,
               app[i].version.prim, app[i].version.sec, app[i].version.tert);
        printf("+-------+------------+------------+------------+------+-------+---------+\n");
    }

}

#endif
