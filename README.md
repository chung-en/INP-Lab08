# INP-Lab08
**Robust UDP challenge**
To compile and test the code, you can follow the steps below
### Download
```
git clone https://github.com/chung-en/INP-Lab08.git
```

### Compile
**You need to have `make` installed in your environment**
```
make
```

### Test - On challenge server
```
chmod +x submit.sh # if it is first time to run submit.sh
./submit.sh
```

### Test - local
```
mkdir recv # if directory recv does not exsist
./udpsrv ./recv 3 10000
```
```
./udpcli ./send 3 10000 127.0.0.1
```
You can check the transmitted file in directory `recv` after the above run successfully.
Don't forget remove all files in recv before next test :)
