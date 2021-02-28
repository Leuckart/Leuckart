############################################################
# File Name:  Leet_194_TransposeFile.sh
# Author:  Leuckart
# Time:    2020-09-18   02:52
############################################################
#!/bin/bash

line=`cat file.txt | awk '{print NF}' | head -n 1`
for n in $(seq 1 ${line});
do
    cat  file.txt | awk -v n=$n '{print $n}' | xargs echo 
done
