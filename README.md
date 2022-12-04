# INP-Lab08
**Robust UDP challenge**

To compile and test the code, you can follow the steps below
### Download
```
git clone https://github.com/chung-en/INP-Lab08.git
```

## Compile
**You need to have `make` installed in your environment**
```
make
```
## Test

### Test - On challenge server
```
./submit.sh
```

### Test - local
**Server**
```
./run_server.sh
```
This will automatically show files that server received after the program terminates.

**Client**
```
./run_client.sh
```
This will automatically generate files if the target directory is empty before we run the client.
