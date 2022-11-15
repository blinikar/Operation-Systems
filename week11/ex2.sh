echo Yegor >> file.txt
mkdir ../week01
link file.txt ../week01/_ex2.txt >> ex2.txt
kate ../week01/_ex2.txt # access
ls -i file.txt >> ex2.txt
find .. -inum 6175921 >> ex2.txt # inode number from prev command
find .. -inum 6175921 -exec rm {} \; >> ex2.txt
