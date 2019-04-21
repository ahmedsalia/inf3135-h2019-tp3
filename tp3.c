
#include "outils.h"
#include "structure.h"


//main
int main(int argc, char *argv[]){
    Ordre ordre = DES;
    Tableau_t Tab = Tableau_init();
    
    String a = (char*)calloc(40, sizeof(char));
    String b = (char*)calloc(40, sizeof(char));
    bool nV = false;
    int verif = 0 ;
    bool io [] = {false,false};
    uint128_t bI = 0;
    uint128_t bS = 0;
    String c = NULL;
    FILE* fe = NULL ;
    FILE* fs = NULL ;
    FILE* code = NULL;
   	verif = verifEntree(argc,argv,&fe,&fs,io,&c, &ordre);
    
	if(verif != 10)
		return verif;
    code = fopen("code.txt" , "w+");
    if(codePermBon(c))
        fprintf(code,"%s \n" , c);
    else{
        return 2;
    }
	 if(!io[0])
         fe = stdin;
    while (!feof(fe)){
        nV = false;
        fscanf(fe, "%s %s", a , b) ;
        bI = toInt128(a, &nV);
        bS = toInt128(b, &nV);
        if( nV == true)
            continue;
    
        if(bI>bS)
        swap(&bI,&bS);
  
   
        // fprintf(stdout, "bI = %s \n bS = %s \n", toString(bI), toString(bS));
        int p1 = estPremier(&bI);
        int p2 = estPremier(&bS);
   
        // printf("p1 = %d \n p2 = %d \n", p1,p2);
        for(int z = p1; z<= p2; z++){
            uint128_t pP = 0;
            uint128_t pM = pow(2,z);
            pM -= 1;
            uint128_t pM2 = pow(2,z-1);
            if(Preums(z)&&Preums(pM)){
                pP = pM2 * pM;
            }
            else
                continue;
    
            if(estParfait(pP) && pP<=bS && pP >= bI){
                if(!contient(&Tab, pP))
                    ajouter(&Tab, pP);
            }
        }
    }
    fclose(fe);
    if(nV == true)
        return 4;
    
    if(ordre == ASC){
        for(int i = Tab.nbElements-1; i >= 0; i--)
            if(!io[1])
                fprintf(stdout, "%s \n", toString(Tab.Elements[i]));
            else
                if(fs == NULL)
                    return 6;
                else
                    fprintf(fs,"%s \n", toString(Tab.Elements[i]));
    }else{
        for(int i = 0; i<Tab.nbElements;i++)
            if(!io[1])
                fprintf(stdout, "%s \n", toString(Tab.Elements[i]));
            else
                if(fs == NULL)
                    return 6;
                else
                    fprintf(fs,"%s \n", toString(Tab.Elements[i]));
    }

    vider(&Tab);
    fclose(fs);
    
    
   
    return 0 ;
}
