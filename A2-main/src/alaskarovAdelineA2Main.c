#include "../include/alaskarovAdelineA2.h"

int main(int argc, char * argv[]){
    //reads file
    char * strRead = readFile(argv[1]);
    if (strRead  != NULL){
      printf("readFile successful - string read is \n%s\n", strRead);
      printf("Length = %lu\n", strlen(strRead));
    }
    //streches string
    char * aString = "hello";
    char * big = goBig (aString);
    printf("%s\n", big);

    int numWords;
    int numSentences;
    dejaVu(strRead, &numWords, &numSentences);//prints number of words and sentences in a given string

    //removes punctuation from given string
    char * punString = "What was the colour of the dress? Oh, it was red!";//string used to test function
    char * noPun = breathless(punString);
    printf("%s\n", noPun);

    //uses a string, parses through string until the word that is given, then goes through the letters of the word with the desired suffix attached
    char * tailStr = "Now is the winter of our discontent Made glorious summer by this Sun of York.";
    int whichWord = 15;
    char * desiredSuffix = "otter";
    tail(tailStr,whichWord, desiredSuffix);

    //function creates a list of words from given string and also outputs the number of words
    char * goneStr = "Oh, it was red!";
    int numWordsReturned;
    char ** listOfWords = goAway(goneStr, &numWordsReturned);
    for(int i = 0; i < numWordsReturned; i++){
      printf("%s ", listOfWords[i]);
    }

    //freeing memory that was returned from functions
    free(strRead);
    free(big);
    free(noPun);
    for(int j = 0; j < numWordsReturned; j++){
      free(listOfWords[j]);
    }
    free(listOfWords);
    return 0;
}
