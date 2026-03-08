#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_SCORE 5
#define NO_STUDENT 10

typedef struct {
    char name[16];
    char surname[20];
    int score[NO_SCORE];
    float total;
} Student;

void writeData(Student stds[], int n);
void readDataAndProcess(int n);

int main() {
    Student stds[NO_STUDENT];
    int i, j;

   
    for(i = 0; i < NO_STUDENT; i++) {
        printf("Enter student %d data\n", i+1);
        printf("\tName : ");
        scanf("%s", stds[i].name);
        printf("\tSurname : ");
        scanf("%s", stds[i].surname);
        for(j = 0; j < NO_SCORE; j++) {
            printf("\tScore %d : ", j+1);
            scanf("%d", &stds[i].score[j]);
        }
    }

 
    writeData(stds, NO_STUDENT);

    
    readDataAndProcess(NO_STUDENT);

    return 0;
}

void writeData(Student stds[], int n) {
    FILE *fp = fopen(".\\lab11\\no2\\std10.dat", "wb");
    if(fp == NULL) {
        printf("Error opening file for writing!\n");
        exit(1);
    }
    fwrite(stds, sizeof(Student), n, fp);
    fclose(fp);
}

void readDataAndProcess(int n) {
    FILE *fp = fopen(".\\lab11\\no2\\std10.dat", "rb");
    if(fp == NULL) {
        printf("Error opening file for reading!\n");
        exit(1);
    }

    Student stds[NO_STUDENT];
    fread(stds, sizeof(Student), n, fp);
    fclose(fp);

 
    for(int i = 0; i < n; i++) {
        stds[i].total = 0.0;
        for(int j = 0; j < NO_SCORE; j++) {
            stds[i].total += stds[i].score[j];
        }

        printf("\nStudent %d: %s %s", i+1, stds[i].name, stds[i].surname);
        printf("\n\tScores: ");
        for(int j = 0; j < NO_SCORE; j++) {
            printf("%d ", stds[i].score[j]);
        }
        printf("\n\tTotal score = %.2f", stds[i].total);
        printf("\n\tAverage score = %.2f", stds[i].total / NO_SCORE);

 
        int count = 0;
        printf("\n\tScores less than 10: ");
        for(int j = 0; j < NO_SCORE; j++) {
            if(stds[i].score[j] < 10) {
                printf("[Test %d: %d] ", j+1, stds[i].score[j]);
                count++;
            }
        }
        if(count == 0) {
            printf("None");
        }
        printf("\n");
    }
}