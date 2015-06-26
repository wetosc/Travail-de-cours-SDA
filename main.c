#include "menu.h"

void menu()
{
    int option=9;
    rewriteDisplay();
    printf("\n  Votre option: ");
    scanf("%d",&option);
    callFunctions(option);
}

void callFunctions(int option)
{
    switch (option)
    {
    case 1:
        menu1(1);/*Crearea fisierelor initiale / Create initial files */
        break;
    case 2:
        menu2();/*Crearea unui alt fisier /  Create an auxiliary file*/
        break;
    case 3:
        menu3();/*Afisarea fisierelor / Display the files*/
        break;
    case 4:
        menu4();/*Adaugarea elementelor la fisiere / Add data to files*/
        break;
    case 5:
        menu5();/*Afisare selectiva / Selective display*/
        break;
    case 6:
        menu6();/*Modificare / corectarea fisierelor / Edit files */
        break;
    case 7:
        menu7(); /*Sortarea fisierelor metoda selectiei/ Selection in-file sort */
        break;
    case 0:
    case 8:
        exit(0);
        break;
    default:
        menu();
    }
}

int main()
{
    menu();
    return 0;
}
