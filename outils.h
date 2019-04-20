#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

typedef enum ordre {DES , ASC} Ordre;
typedef char* String;
#ifndef UINT
__extension__ typedef unsigned __int128 uint128_t;
#define UINT
#endif


// Validation Code Permanent
bool codePermBon(String s);
	
// Recherche des nombres parfaits
bool estParfait(uint128_t n1);

int verifEntree(int argc, String argv[], FILE** fe, FILE** fs, bool io[], String* c, Ordre* o );

uint128_t estPremier(uint128_t* );

void swap(uint128_t* , uint128_t* );

void Reverse(String );

bool Preums ( uint128_t n);

uint128_t toInt128( String  , bool*);

String toString( uint128_t );
