rm -f ./recv/*
timeout 10s ./udpsrv ./recv 1000 10000
echo Received file:
ls ./recv
