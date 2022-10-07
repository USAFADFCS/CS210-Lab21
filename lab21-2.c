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

    char prevTime[50] = "";
    char prevTitle[100] = "";

    // Read File Contents
    char time[50]; 
    char title[100];
    char rating[50];

    int firstLine = 0;
    
    do {
        
        fscanf(file, "%[^,],%[^,],%[^\n]\n", time, title, rating);
        
        if (strlen(title) > 44) {
            title[44] = '\0';
        }

        if (strcmp(title, prevTitle) == 0) {
            printf(" %5s", time);
        }
        else {
            if (firstLine == 0) {
                firstLine++;
            }
            else {
                printf("\n");
            }
            
            printf("%-44s | %5s | %5s", title, rating, time);
        }

        strcpy(prevTitle, title);

    } while (!feof(file));
}