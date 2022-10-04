# gcc channel.c -o ex1 -lm
# ./ex1

gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

gnome-terminal -- ./publisher

for ((i=0; i<$1;i++)) do
 gnome-terminal -- ./subscriber
done

