# INP-Lab08
**Robust UDP challenge**
To compile and test the code, you can follow the steps below
### Download
```
git clone https://github.com/chung-en/INP-Lab08.git
```

### Compile
```
make
```

### Test - On challenge server
```
chmod +x submit.sh
./submit.sh
```

### Test - local
```
./udpsrv ./recv <total-number-of-files> <port>
```
```
./udpcli ./send <total-number-of-files> 127.0.0.1 <port>
```
You can check the transmitted file in directory `recv` after the above run successfully.
Don't forget remove all files in recv before next test :)
