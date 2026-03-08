#include <stdio.h>
#include <stdlib.h>

void addRecord(char *addName, int addAge);

int main() {
    char name[64]; 
    int age;

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%d", &age);

    addRecord(name, age);

    return 0;
}

void addRecord(char *addName, int addAge) {
    FILE *fp;

   
    fp = fopen(".\\lab11\\no1\\first.txt", "a");
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    
    fprintf(fp, "Name: %s, Age: %d\n", addName, addAge);

  
    fclose(fp);
}