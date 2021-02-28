############################################################
# File Name:  Leet_192_WordFrequency.sh
# Author:  Leuckart
# Time:    2020-09-18   02:46
############################################################
#!/bin/bash

cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r |awk '{print $2,$1}'
