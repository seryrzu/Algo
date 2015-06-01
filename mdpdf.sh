input=$1
output=$(echo $1 | sed 's/\..*$/.pdf/')

gpp -H $input | pandoc -f markdown -t latex -o $output -V geometry:margin=1in
