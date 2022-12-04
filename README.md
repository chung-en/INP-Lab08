# INP-Lab08
**Robust UDP challenge**

---

## Overview
- [Updates](#updates)
- [Results](#results)
- [Download](#download)
- [Compile](#compile)
- [Test](#test)
    - [Local](#local)
    - [Play with challenge server](#play-with-challenge-server)

---

## Updates 
- use `ualarm` to shrink the interval between each signal
- send same packet several times to increase the success rate

---

## Results
![result](https://github.com/chung-en/INP-Lab08/blob/v2/Result.png)

---

## Download
```
git clone https://github.com/chung-en/INP-Lab08.git
```

---

## Compile
**You need to have `make` installed in your environment**
```
make
```

---

## Test

### Local
- Server
```
./run_server.sh
```
This will automatically show files that server received after the program terminates and calculate success rate and the number of correct files.

- Client
```
./run_client.sh
```
This will automatically generate files if the target directory is empty before we run the client.

\# Note: You should run `./run_server.sh` and `./run_client.sh` on two windows simultaneously

### Play with challenge server
```
./submit.sh
```

