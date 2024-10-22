//
//  structure.c
//  DebugTP3
//
//  Created by Ahmed Salia Toure on 14/04/2019.
//  Copyright © 2019 Ahmed Salia Toure. All rights reserved.
//

#include "structure.h"

Tableau_t Tableau_init(){
    Tableau_t T;
    T.Capacite = 2;
    T.Elements = malloc(sizeof(uint128_t)*(T.Capacite));
    T.nbElements = 0;
    return T;
    
}
void ajouter(Tableau_t* T, uint128_t element){
    int index = T->nbElements;
    if(T->Capacite == T->nbElements){
        T->Capacite *= 2;
        T->Elements = realloc(T->Elements, sizeof(uint128_t)*(T->Capacite));
    }
    if(T->nbElements == 0)
        T->Elements[0] = element;
    else{
        for(int i = T->nbElements-1; i>=0 ; i--){
            if(element < T->Elements[i]){
                T->Elements[i+1] = T->Elements[i];
                index--;
            }
            
        }
        T->Elements[index] = element;
    }
    ++T->nbElements;
}
bool contient(Tableau_t* T,uint128_t element){
   
    if(T->nbElements == 0)
        return false;
    for(int i = 0 ; i < T->nbElements ; i++)
        if(T->Elements[i] == element)
            return true;
    return false;
    
}

void vider(Tableau_t *T){
    free(T->Elements);
}

