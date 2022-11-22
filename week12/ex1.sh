# You should unmound your devices using losetup -D before using this script

fallocate -l 50M lofs.img
sudo losetup -f lofs.img
LONAME=$(losetup -a | grep 'lofs.img' | grep -o "/dev/loop[0-9]*")
sudo mkfs.ext4 $LONAME
mkdir lofsdisk
echo $LONAME
sudo mount $LONAME ./lofsdisk

