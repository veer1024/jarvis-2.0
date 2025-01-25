#!/bin/bash
echo "Usage => urltest.sh -t target -f targetsubdomainsfile -o output"
while getopts t:f:g:o: flag
do
    case "${flag}" in
        t) target=${OPTARG};;
        f) targetfile=${OPTARG};;
        g) gauonly=${OPTARG};;
        o) output=${OPTARG};;
    esac
done
Var="$gauonly"
if [ -z "$gauonly" ];
then
Var="No"
else
echo "OK"
fi
if [ $Var  == "yes" ];
then
gau -subs $target | sort -u >> "waybackurls.txt"
echo "Gau URL exploration Completed"
else
if [ ${#targetfile} -gt 1 ];
then
gau --subs $target;cat $targetfile | waybackurls | sort -u >> "waybackurls.txt"
echo " ............ "
echo " URL exploration done ......"
else
gau --subs $target; subfinder -d $target -silent | waybackurls | sort -u >> "waybackurls.txt"
fi
fi
#echo "Creating directory"
#mkdir $output
#echo "Moving $waybackurls.txt to directory ${output} ..."
#mv "${output}urls.txt" ./"${output}"/
#echo "Going to Directory ${output}"
#cd "${output}"
cat "waybackurls.txt" | gf ssrf | sort -u >> "waybackssrfurls.txt"
cat "waybackurls.txt" | gf redirect | sort -u >> "waybackredirecturls.txt"
cat "waybackurls.txt" | gf sqli | sort -u >> "waybacksqliurls.txt"
cat "waybackurls.txt" | gf s3-buckets | sort -u >> "waybacks3urls.txt"
cat "waybackurls.txt" | gf idor | sort -u >> "waybackidorurls.txt"
cat "waybackurls.txt" | gf xss | sort -u >> "waybackxssurls.txt"
cat "waybackurls.txt" | gf rce | sort -u >> "waybackrceurls.txt"
cat "waybackurls.txt" | gf wp | sort -u >> "waybackwpurls.txt"
cat "waybackurls.txt" | gf auth | sort -u >> "waybackauthurls.txt"
