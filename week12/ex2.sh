sudo chmod 777 lofsdisk
cd lofsdisk

echo 'Yegor' >> file1
echo 'Blinov' >> file2

mkdir bin && cp /bin/bash bin/bash && cp /bin/ls bin/ls 
cp /bin/cat bin/cat && cp /bin/echo bin/echo

mkdir lib 
mkdir lib64 
mkdir usr
mkdir usr/lib
mkdir usr/lib64

directories=("bash" "ls" "cat" "echo")
for i in $directories
do
   files="$(ldd /bin/$i | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib)"
   for j in $files
   do
      cp -v "$j" ".$j"
   done
done

gcc ../ex2.c -static -o ex2.out
sudo chroot . ./ex2.out >> ../ex2.txt

