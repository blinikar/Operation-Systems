mkdir home
date
sleep 3
touch ./home/home.txt
date
sleep 3
mkdir root
date
sleep 3
touch ./root/root.txt

ls -lt -r ~ > ./home/home.txt
ls -lt -r / > ./root/root.txt

cat ./home/home.txt ./root/root.txt
ls home root