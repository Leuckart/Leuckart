##################################################
# File Name:  push.sh
# Author:  Leuckart
# Time:    2020-02-18   13:21
##################################################
#!/bin/bash

rm -rf .vscode

git add .

git commit -am "update_2021.03.04"

git push

