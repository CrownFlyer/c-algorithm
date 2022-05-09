#!bin/bash

set -u
K=1
if [[ -n ${K-} && $K == 1 ]]; then
	echo $K
else
	echo "none"
fi
