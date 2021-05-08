#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#define MAX_FILE_NAME 100


int main(){

    char filename[MAX_FILE_NAME];


    printf("Enter file name: ");
    scanf("%s", filename);

    char buffer[16384];
    int bytes_read;
    int lines = 0,spaces = 0,characters = 0;

    int fd1 = open(filename, O_RDONLY);

    while (bytes_read = read(fd1, buffer, sizeof(buffer))) {
        for (int i=0; i<bytes_read; i++){
            if (buffer[i] == '\n'){
                 lines += 1;
            }
            else if(buffer[i] == ' '){
                spaces += 1;
            }
            else{
                characters += 1;
            }

        }
    }


    close(fd1);
    
    printf("The file %s has %d characters %d spaces and %d lines\n ",filename, characters,spaces,lines);

    return 0;
}
