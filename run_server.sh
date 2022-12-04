rm -f ./recv/*
timeout 60s ./udpsrv ./recv 1000 10000
echo
echo Received file:
ls ./recv
