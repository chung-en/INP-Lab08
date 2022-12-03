if [ -z "$(ls -A /path/to/dir)" ];
then
   ./file_generator
fi

timeout 10s ./udpcli ./send 1000 10000 127.0.0.1
