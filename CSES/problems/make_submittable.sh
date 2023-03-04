#!/bin/bash

function recurse()
{   
    filename="$1"
    shift
    array=("$@")
    
    ./make_submittable.sh "../../library/$filename" "${array[@]}"
}

newfilename=submittable.cpp

# make sure that filename to submitify is given
if [[ $# -eq 0 ]] ; then
    echo 'need to supply a filename'
    exit 1
fi

currentfilename="$1"
shift

if [[ $# < 2 ]]
then
    rm $newfilename
    touch $newfilename
fi

arr=("$@")
# make sure we havent already outputted the current file
if [[ " ${arr[*]} " =~ " $currentfilename " ]]; then
    echo "already added $currentfilename, exiting..."
    exit 1
fi

echo "adding $currentfilename"
arr+=("$currentfilename")

cat $currentfilename | while read line
do
    if [[ $line = \#include* ]]
    then
        filename=`echo $line | cut -d'"' -f 2`
        echo $filename
        if [[ ($filename != *stdc\+\+* && ! $filename =~ "template.h")  || ($filename =~ "template.h" && $# = 1) ]]
        then
            recurse $filename "${arr[@]}"
        fi

        if [[ $filename = *stdc\+\+* && $currentfilename =~ "template.h" ]]
        then
            echo "$line" >> $newfilename
        fi
    else
        echo "$line" >> $newfilename
    fi
done

if [[ $# < 2 ]] 
then
    # make it readable
    sed 's/\r$//' $newfilename > tmp.txt
    mv tmp.txt $newfilename
    vim -e -s -n "+normal gg=GZZ" $newfilename
fi
