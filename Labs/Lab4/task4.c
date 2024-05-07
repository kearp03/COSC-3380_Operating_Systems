/*
Task-04
C program to read 50 bytes from one file and then write them into a second file using the
POSIX interface. The program copies the content of the file named file1.txt,
character-by-character, to another file named out_test.txt.
Note: out_test.txt should not be overwritten.
*/
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
    int fdin = open("file1.txt", O_RDONLY); // if the file already exists
    int fdout = open("out_test.txt", O_CREAT|O_WRONLY|O_APPEND); // if the file does not exists
    char buffer[60];
    int bytesRead = read(fdin, buffer, 50);
    write(fdout, buffer, bytesRead);
    close(fdin);
    close(fdout);
    return 0;
}