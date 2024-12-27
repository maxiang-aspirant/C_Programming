#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
 
#define MAX_LINES 100
#define MAX_WORDS 10000  
#define MAX_WORD_LENGTH 50
 
typedef struct{  //define the struct
    char word[MAX_WORD_LENGTH];
    int totalCount;
    int lineCounts[MAX_LINES];
    bool isUsed;
} WordEntry;
 
WordEntry wordTable[MAX_WORDS];
int wordIndex = 0;
 
int findWordIndex(const char *word){  //to find the index of the word
    for(int i = 0;i < wordIndex;i++){
        if(wordTable[i].isUsed && strcmp(wordTable[i].word, word) == 0){
            return i;
        }
    }
    return -1;
}
 
void addWord(const char *word){  // to add a new word
    strcpy(wordTable[wordIndex].word, word);
    wordTable[wordIndex].totalCount = 0;
    for(int i = 0;i < MAX_LINES;i++){
        wordTable[wordIndex].lineCounts[i] = 0;
    }
    wordTable[wordIndex].isUsed = true;
    wordIndex++;
}
 
void split_and_count(char *str, int lineNum){  //to split the string and update numbers
    char *token = strtok(str, " ");
    while(token != NULL){
        int index = findWordIndex(token);
        if(index == -1){
            addWord(token);
            index = wordIndex - 1;
        }
        wordTable[index].totalCount++;
        wordTable[index].lineCounts[lineNum]++;
        token = strtok(NULL, " ");
    }
}
 
int main(){
    char *lines[MAX_LINES];
    char input[100];
    int lineCount = 0;
 
    while(1){ 
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = '\0';
        if(strcmp(input, "END") == 0){
		break;
	}
	if(lineCount <MAX_LINES){
            lines[lineCount] = strdup(input);
            split_and_count(lines[lineCount], lineCount);
            lineCount++;
	}
	else{
            fprintf(stderr,"Error: Exceeded maximum line count of %d.\n",MAX_LINES);
            break;
        }
    }
    for(int i = 0;i < wordIndex;i++){
        if(wordTable[i].isUsed){
            printf("Word: %s\n",wordTable[i].word);
            printf("Total count: %d\n",wordTable[i].totalCount);
            for(int j = 0;j < lineCount;j++){ 
                printf("Line %d count: %d\n",j + 1,wordTable[i].lineCounts[j]);
            }
            printf("\n");
        }
    }
 
    for(int i = 0;i < lineCount;i++){
        free(lines[i]);//free the memory
    }
 
    return 0;
}
