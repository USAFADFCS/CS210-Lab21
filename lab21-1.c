#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* file = NULL;
    char inputFileName[100] = "";

    scanf("%s", inputFileName);

    file = fopen(inputFileName, "r");

    if (file == NULL) {
        // Do Something.
    }

    char line[100] = "";
    
    do {
        
        fgets(line, 100, file);

        int numCommas = 0;

        for (int i=0; i<strlen(line); i++) {
            if (line[i] == ',') {
                numCommas++;
            }

            if (numCommas == 1 && line[i] != ',') {
                printf("%c", line[i]);
            }
        }
        
        printf("\n");

    } while (!feof(file));
}