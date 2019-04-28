#!/bin/bash
if [ -z $1 ]; then
correction=inf3135-h2019-tp2.correction
else
correction=$1
fi
if [ ! -f inf3135-h2019-tp2.correction ]; then
wget -q https://raw.githubusercontent.com/guyfrancoeur/INF3135_H2019_TP2/master/inf3135-h2019-tp2.correction
fi
i=0 ; nbTotalNote=0 ;nbPoints=0; NC='\033[0m'
utilisateur=$(cat cp.txt)
while read line; do
C='\033[01;31m'; resultat="echec"
Points[$i]=${line:0:2}; Temps[$i]=${line:2:2};Sol[$i]=${line:4:2};
Eval[$i]=${line:29};
CMD="${Eval[$i]}"
if [ ${Temps[$i]} -ne "00" ]; then
CMD="timeout ${Temps[$i]}s ${Eval[$i]}";
fi
eval $CMD > /dev/null 2>&1;
Res[$i]=$?;
if [ ${Sol[$i]} -eq ${Res[$i]} ]; then
resultat="reussi ${Points[$i]}pts";
nbPoints=$[$nbPoints+${Points[$i]}];
C='\033[1;33m'
fi
if [ ${Points[$i]} -ne 0 ]; then
nbTotalNote=$[$nbTotalNote + ${Points[$i]}]
fi
echo -e "$i : ${C}$resultat${NC}";
i=$[$i+1];
done < inf3135-h2019-tp2.correction
echo "";
echo "Note (total) pour $utilisateur dans inf3135-h2019-tp2: $nbPoints/$nbTotalNote";
echo "FIN."
