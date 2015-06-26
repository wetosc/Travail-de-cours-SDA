#ifndef F7_FILE
#define F7_FILE
#include "menu.h"

struct MobileApp app[30];
void menu7()
{
    system("cls");
    printf("\n Choisisez le nombre de fichier a trier:\n");
    printf("\n  1. "FILE1);
    printf("\n  2. "FILE2);
    printf("\n  3. "FILE3);
    printf("\n  4. "FILE_);
    printf("\n\n ");
    int choice1,choice2;
    scanf("%d",&choice1);
    printf("\n");
    printf("\n Choisisez le parametre de tri:\n");
    printf("\n 1. ID\n");
    printf("\n 2. Rating\n");
    printf("\n 3. Taille\n\n ");
    scanf("%d",&choice2);
    if (choice2<4 && choice2>0)
        switch(choice1)
        {
        case 1:
            sortFile(FILE1,choice2);
            break;
        case 2:
            sortFile(FILE2,choice2);
            break;
        case 3:
            sortFile(FILE3,choice2);
            break;
        case 4:
            sortFile(FILE_,choice2);
            break;
        default:
            printf("Erreur. Revenez au menu principal.");
        }
    printf("\n\n");
    printf("\n  Tastez <Enter> pour revenir au menu principal.");
    getch();
    menu();
}

void sortFile(char fileName[20],int option)
{
    struct MobileApp a,min;

    FILE *f=fopen(fileName,"rb+");
    int i,j,n=0,pos;
    while (1)
    {
        fread(&a,sizeof(a),1,f);
        n++;
        if (feof(f)) break;
    }
    printf("\nN=%d\n",n);
    for (i=0; i<n-1; i++)
    {
        fseek(f,sizeof(a)*i,SEEK_SET);
        fread(&a,sizeof(a),1,f);
        min=a;
        pos=i;
        for (j=i+1; j<n; j++)
        {
            fseek(f,sizeof(a)*j,SEEK_SET);
            fread(&a,sizeof(a),1,f);

            switch (option)
            {
            case 1:

                if (a.ID<min.ID)
                {
                    min=a;
                    pos=j;
                }

                break;
            case 2:
                if (a.rating<min.rating)
                {
                    min=a;
                    pos=j;
                }
                break;
            case 3:
                if (a.size<min.size);
                {
                    min=a;
                    pos=j;
                }
                break;

            default:
                printf("Erreur. Revenez au menu principal.");
                break;
            }

        }
        fseek(f,sizeof(a)*i,SEEK_SET);
        fread(&a,sizeof(a),1,f);
        fseek(f,sizeof(a)*pos,SEEK_SET);
        fwrite(&a,sizeof(a),1,f);
        fseek(f,sizeof(a)*i,SEEK_SET);
        fwrite(&min,sizeof(min),1,f);
    }

}



#endif
