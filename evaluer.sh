#!/bin/bash
if [ -z $1 ]; then
correction=inf3135-h2019-tp2.correction
else
correction=$1
fi
if [ ! -f inf3135-h2019-tp2.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP2/master/inf3135-h2019-tp2.correction
fi
C=0 ; nbTotalNote=0 ;nbPoints=0;
utilisateur=$(cat cp.txt)
ln -sf tp3 tp2
while read line; do
espace=" "; resultat="echec"
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

fi
if [ ${tabP[$C]} -ne 0 ]; then
nbTotalNote=$[$nbTotalNote + ${tabP[$C]}]
fi
if [ "$C" -lt 10 ]; then
espace=" "
fi
echo -e " $C : $resultat${NC}";
C=$[$C+1];
done < inf3135-h2019-tp2.correction
echo "";

echo "Note (total) pour $utilisateur dans inf3135-h2019-tp2: $nbPoints/$C";
echo "FIN."
