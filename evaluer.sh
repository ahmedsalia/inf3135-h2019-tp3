#!/bin/bash
# evaluer.sh
if [ -z $1 ]
then
correction=inf3135-h2019-tp2.correction
else
correction=$1
fi
wget -q https://github.com/guyfrancoeur/INF3135_H2019_TP2/raw/master/${correction} -O ${correction}
if [ ! -f inf3135-h2019-tp2.correction ]
then
echo "erreur fatale, fichier correction inexistent."
exit 1
fi
C=0
nbPoints=0
NC='\033[0m'
utilisateur=$(cat cp.txt)
for line in `cat ${correction}`
do
espace=""
Color='\033[01;31m'
resultat="echec"
tabP[$C]=${line:0:2};
tabC[$C]=${line:4:2};
tabM[$C]=${line:29};
eval ${line:29} > /dev/null 2>&1;
tabR[$C]=$?;
if [ ${tabC[$C]} -eq ${tabR[$C]} ]; then
resultat="reussi ${tabP[$C]}pts";
nbPoints=$[$nbPoints+${tabP[$C]}];
Color='\033[1;32m'
fi
if [ "$C" -lt 10 ]; then
espace=" "
fi
echo -e "$espace$C ${tabC[$C]}: ${tabR[$C]} ${Color}$resultat${NC}: ${tabM[$C]}";
C=$[$C+1];
done
echo "";
echo "Note (total) pour $utilisateur dans inf3135-h2019-tp2: $nbPoints/$C";
echo "FIN."
