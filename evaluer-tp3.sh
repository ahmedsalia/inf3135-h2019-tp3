#!/bin/bash
# evaluer.sh
if [ -z $1 ]; then
correction=inf3135-h2019-tp3.correction
else
correction=$1
fi
if [ ! -f inf3135-h2019-tp3.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP3/master/inf3135-h2019-tp3.correction
fi
C=0 ; nbTotalNote=0 ;nbPoints=0; NC='\033[0m'
utilisateur=$(cat cp.txt)
while read line; do
espace=""; Color='\033[01;31m'; resultat="echec"
tabP[$C]=${line:0:2}; tabT[$C]=${line:2:2};tabC[$C]=${line:4:2};
tabM[$C]=${line:29};
CMD="${tabM[$C]}"
if [ ${tabT[$C]} -ne "00" ]; then
CMD="timeout ${tabT[$C]}s ${tabM[$C]}";
fi
eval $CMD > /dev/null 2>&1;
tabR[$C]=$?;
if [ ${tabC[$C]} -eq ${tabR[$C]} ]; then
resultat="reussi ${tabP[$C]}pts";
nbPoints=$[$nbPoints+${tabP[$C]}];
Color='\033[1;32m'
fi
if [ ${tabP[$C]} -ne 0 ]; then
nbTotalNote=$[$nbTotalNote + ${tabP[$C]}]
fi
if [ "$C" -lt 10 ]; then
espace=" "
fi
echo -e "$espace$C ${tabC[$C]}: ${tabR[$C]} ${Color}$resultat${NC}: ${tabM[$C]}";
C=$[$C+1];
done < inf3135-h2019-tp3.correction
echo "";
echo "Note (total) pour $utilisateur dans inf3135-h2019-tp3: $nbPoints/$nbTotalNote";
echo "FIN."
