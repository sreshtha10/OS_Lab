#include <stdio.h>
#define MAX_FILE_NAME 100

int main()
{
    FILE* fp;

    int characters = 0,lines = 0,spaces =0 ;

    char filename[MAX_FILE_NAME];

    char c;

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");


    if (fp == NULL) {
        printf("Could not open file %s",
               filename);
        return 0;
    }

    for (c = getc(fp); c != EOF; c = getc(fp)){
        if(c == '\n'){
            lines += 1;
        }
        else if(c == ' '){
            spaces += 1;
        }
        else{
            characters += 1;
        }
    }

    fclose(fp);

    printf("The file %s has %d characters %d spaces and %d lines\n ",
           filename, characters,spaces,lines);

    return 0;
}
