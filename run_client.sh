if [ -z "$(ls -A /send)" ];
then
   ./file_generator
fi

timeout 60s ./udpcli ./send 1000 10000 127.0.0.1
