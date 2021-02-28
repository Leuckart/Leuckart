############################################################
# File Name:  Leet_195_TenthLine.sh
# Author:  Leuckart
# Time:    2020-04-11   01:07
############################################################
#!/bin/bash

awk 'FNR == 10 {print }'  file.txt

awk 'NR == 10' file.txt

sed -n 10p file.txt

tail -n+10 file.txt | head -1
