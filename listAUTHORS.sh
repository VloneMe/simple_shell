#!/bin/bash
echo "# This file lists all contributors to this repository \n
To generate or add new list of authors use listAUTHORS.sh file" > AUTHORS
echo >> AUTHORS


git log --format="%aN <%aE>" | sort -uf >> AUTHORS
