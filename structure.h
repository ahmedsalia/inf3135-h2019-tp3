//
//  structure.h
//  DebugTP3
//
//  Created by Ahmed Salia Toure on 14/04/2019.
//  Copyright © 2019 Ahmed Salia Toure. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#ifndef UINT
__extension__ typedef unsigned __int128 uint128_t;
#define UINT
#endif

typedef struct Tableau_s {
    uint128_t* Elements;
    int nbElements;
    int Capacite;
} Tableau_t;

Tableau_t Tableau_init(void);

void ajouter(Tableau_t* , uint128_t);

bool contient(Tableau_t* ,uint128_t);

void vider(Tableau_t *T);



 /* structure_h */
