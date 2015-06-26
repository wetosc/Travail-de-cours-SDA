#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE1 "android.db"
#define FILE2 "ios.db"
#define FILE3 "wp.db"
#define FILE_ "general.db"
struct Version
{
    int prim,sec,tert;
};

struct MobileApp
{
    int ID;
    char *name;
    char *developer;
    char *OS;
    float rating;
    float size;
    struct Version version;
};


#endif
