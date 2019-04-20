#include "outils.h"



// Validation Code Permanent
bool codePermBon(String s) {
    if(strlen(s)!=12){
        return false ;
    } else
        return true;
    
}

bool  Preums ( uint128_t n){
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i=3; i <=sqrt(n) ; i+=2) {
        if (n % i == 0 )
            return false;
    }
    return true;
}

uint128_t estPremier(uint128_t* N){
   uint128_t  p = 0;
    p = log((1+sqrt(1+8*(*N)))/2)/log(2);
  
    return p;
}

// Recherche des nombres parfaits
bool estParfait(uint128_t n1){
    uint128_t i = (n1%100);
    uint128_t k = (n1%10);
    if(i == 28 || k == 6)
        return true;
    else
        return false;
//    uint128_t somme=1;
//    if(n1<=1)
//        return false;
//    for(uint128_t j = 2; j<= sqrt(n1); j++){
//        if(n1%j==0){
//            if(pow(j,2) != n1)
//            somme += j + n1/j;
//            else
//            somme += j;
//        }
//    }
//    if(somme == n1)
//        return true;
//    else
//        return false;
    
}
void swap(uint128_t* a ,uint128_t* b){
   uint128_t t1 = *a;
   uint128_t t2 = *b;
        *a = t2;
        *b = t1;
}

void Reverse(String str)
{
    String debut = str;
    String fin = debut + strlen(str) - 1;
    char temp;
    if (str == 0 || *str == 0)
        return;
    
    while (fin > debut)
    {
        temp = *debut;
        *debut = *fin;
        *fin = temp;
        ++debut;
        --fin;
    }
}

String toString( uint128_t n)
{
    String res = (char*)calloc(40, sizeof(char));
   
    int i = 0;
    if (n == 0)
        return "0";
    while(n != 0){
        int k = n % 10;
        res[i++] = k + '0' ;
        n = n/10;
        
    }
    res[i] = '\0';
    Reverse(res);
    return res;
}
uint128_t toInt128 (String str , bool *nV)
{
    uint128_t res = 0;
    int sign = 1;
    int i = 0;
    if (str[0] == '-'){
        sign = -1;
        i = 1;
        *nV = true;
    }
    for (; str[i] != '\0'; ++i){
        int j = (int)str[i];
        if(!isdigit(j))
            *nV = true;
        res = res*10 + str[i] - '0';
        
    }
    // Return result with sign
    
    return res*sign;
}


int verifEntree(int argc, String argv[], FILE** fe, FILE** fs, bool io[], String* c, Ordre* o ){
    int z = 0;
    for(z = 0; z<argc; z++){
        if((z==argc-1 && *c == NULL)|| argc<3){
            fprintf(stderr, "Usage: %s <-c CODEpermanent> [-i fichier.in] [-o fichier.out] \n", argv[0]);
            return 1;
        }
		 if(strcmp(argv[z], "-c") == 0){
             *c = argv[z+1] ;
            continue;
        }else if(strcmp(argv[z], "-i") == 0){
            *fe = fopen(argv[z+1] , "r+");
            if(*fe == NULL)
                return  5;
            io[0] = true;
            continue;
        }else if(strcmp(argv[z], "-o") == 0 ){
            *fs = fopen(argv[z+1] , "w+");
            io[1] = true;
            continue;
        }else if (strcmp(argv[z], "-d") == 0){
            if(strcmp(argv[z+1] , "ASC") != 0 && strcmp(argv[z+1] , "DES") != 0)
            return 7;
            else if(strcmp(argv[z+1] , "ASC") == 0)
                *o = ASC;
            else
                *o = DES;
        }else if(argv[z][0] == '-')
           return 3;
    }
    return 10;
}


