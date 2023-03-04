#!/bin/bash

testfile=tests.txt
while mapfile -t -n 2 ary && ((${#ary[@]})); do
	iofiles=${ary[0]}
	cppfile=${ary[1]}
    
	#create executable to run tests
	g++ -I ../../library $cppfile
	
	#loop through all io file pairs
	for iofile in $(echo $iofiles | tr "," "\n")
	do	
		infile="inputs/$iofile.txt"
		outfile="outputs/$iofile.txt"
    	
		#run test
		timeusage=`\time -o timings.txt -f '%S %M' ./a.out < $infile > tmp.txt`
		
		elapsedtime=$(cat "timings.txt"  | awk '{ print $1 }')
		memoryusage=$(cat "timings.txt"  | awk '{ print $2 }')
		
		#check for success
		if cmp --silent -- "$outfile" "tmp.txt"; 
		then
			tput setaf 2
			printf "%-.20s PASSED \t %.3fs %dKB\n" "${iofile}                   " "$elapsedtime" "$memoryusage"
		else
			tput setaf 1
			printf "%-.20s FAILED \t %.3fs %dKB\n" "${iofile}                   " "$elapsedtime" "$memoryusage"
		fi
		tput sgr0

	done
done < $testfile

rm a.out
rm tmp.txt
rm timings.txt
