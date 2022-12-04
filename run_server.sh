rm -f ./recv/*
timeout 60s ./udpsrv ./recv 1000 10000
echo
echo Received file:
ls recv

i=0
for file in `ls -A recv`;
do
    if diff -Bq send/$file recv/$file
    then
        i=$(($i + 1))
    fi
done
printf "\*\* sucess rate = %.3f files = %d/1000\n" $(($i))e-3 $i
