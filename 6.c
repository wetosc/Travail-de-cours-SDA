#ifndef F6_FILE
#define F6_FILE
#include "menu.h"
struct MobileApp app[30];
int nombre;
void writeFile(int offset);
void menu6()
{
    system("cls");
    printf("\n Donnez l'ID d'application a correcter:\n\n ");
    int temp,i,choice;
    scanf("%d",&temp);
    loadData();
    if (nombre==0) printf("Aucune application avec ce ID. Revenez au menu principal.");
    for (i=0; i<nombre; i++)
        if (app[i].ID==temp)
        {
            printf("\n Choisisez le parametre a correcter:\n");
            printf("\n 1. Nom de l'application\n");
            printf("\n 2. Nom de developpeur\n");
            printf("\n 3. Rating\n");
            printf("\n 4. Taille\n");
            printf("\n 5. Version\n");
            printf("\n\n ");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                printf("\n Donnez le nouveau nom:\n ");
                app[i].name=malloc(20);
                scanf("%s",app[i].name);
                writeFile(i);
                break;
            case 2:
                printf("\n Donnez le nouveau developeur:\n ");
                app[i].developer=malloc(20);
                scanf("%s",app[i].developer);
                writeFile(i);
                break;
            case 3:
                printf("\n Donnez le nouveau rating:\n ");
                scanf("%f",&app[i].rating);
                writeFile(i);
                break;
            case 4:
                printf("\n Donnez la nouvelle taile:\n ");
                scanf("%f",&app[i].size);
                writeFile(i);
                break;
            case 5:
                printf("\n Donnez le nouveau version:\n ");
                scanf("%d%d%d",&app[i].version.prim,&app[i].version.sec,&app[i].version.tert);
                writeFile(i);
                break;
            default:
                printf("Erreur. Revenez au menu principal.");
            }
        }
    getch();
    menu();
}

void writeFile(int i)
{
    if (strcmp(app[i].OS,"Android")==0)
    {
        FILE *f=fopen(FILE1,"rb+");
        fseek(f,sizeof(app[i])*i,SEEK_SET);
        fwrite(&app[i],sizeof(app[i]),1,f);
        fclose(f);
    }
    else if (strcmp(app[i].OS,"iOS")==0)
    {
        FILE *f=fopen(FILE2,"rb+");
        fseek(f,sizeof(app[i])*i,SEEK_SET);
        fwrite(&app[i],sizeof(app[i]),1,f);
        fclose(f);
    }
    else if (strcmp(app[i].OS,"WinPhone")==0)
    {
        FILE *f=fopen(FILE3,"rb+");
        fseek(f,sizeof(app[i])*i,SEEK_SET);
        fwrite(&app[i],sizeof(app[i]),1,f);
        fclose(f);
    }
}



#endif
