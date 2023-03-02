#!/bin/bash

function recurse()
{
    ./make_submittable.sh "../../library/$1" 0
}

if [[ $# -eq 0 ]] ; then
    echo 'need to supply a filename'
        exit 1
    fi

newfilename=submittable.cpp

if [[ $# != 2 ]]
then
    rm $newfilename
    touch $newfilename
fi

cat $1 | while read line
do
    if [[ $line = \#include* ]]
    then
        filename=`echo $line | cut -d'"' -f 2`
        if [[ $filename != *stdc\+\+* && $# != 2 ]]
        then
            recurse $filename
        fi

        if [[ $filename = *stdc\+\+* && $# = 2 ]]
        then
            echo $line >> $newfilename
        fi
    else
        echo $line >> $newfilename
    fi
done

# make it readable
vim -e -s -n "+normal gg=GZZ" $newfilename
