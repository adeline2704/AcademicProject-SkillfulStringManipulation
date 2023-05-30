#include "../include/alaskarovAdelineA2.h"

char * readFile (char * filename){
    //vars
    char * rFile;
    char character;
    int i = 0;
    int len = 0;
    //opens file and checks to see that it has been done successfully
    FILE * fptr = fopen(filename,"r");
    if(fptr == NULL) {
      printf("Error! File could not be opened");
      exit(1);
    }
    while((character = fgetc(fptr)) != EOF){
      len ++;
    }
    rewind(fptr);

    //allocates enough memory for the length of the file and null character
    rFile = malloc(sizeof(char) * (len));
    if(rFile == NULL){
      printf("Memory could not be allocated.");
      exit(1);
    }

    for(i = 0; i<len-1; i++){//so I don't grab newline
      rFile[i]= fgetc(fptr);

    }

    rFile[i] = '\0';//indicates end of string
    fclose(fptr);
    return rFile;//returns the contents of the file
}

char * goBig (char * aString){
    //vars
    int length = strlen(aString);
    int * numList = (int *)calloc(length, sizeof(int));
    if(numList == NULL){
      printf("Memory could not be allocated.");
      exit(1);
    }
    int charCounter = 0;
    //user inputs
    for (int i = 0; i < length; i++){
      printf("Enter a positive number for %c: ", aString[i]);
      scanf("%d", &numList[i]);
      while (numList[i] <= 0) { // when invalid input
            printf("Must be a positive integer. Try again for %c: ", aString[i]);
            scanf("%d", &numList[i]);
      }
      charCounter = charCounter + numList[i];//to know how much to malloc
    }
    char * goBig = (char *)malloc(sizeof(char)*(charCounter+1));
    if(goBig == NULL){
      printf("Memory could not be allocated.");
      free(numList);
      exit(1);
    }
    //making string according to inputs
    int k = 0;//uses k var to make sure index does not reset with every inner loop
    for (int j = 0; j < length; j++) {
        for (int l = 0; l < numList[j]; l++) {
            goBig[k] = aString[j];
            k++;
        }
    }

    goBig[k] = '\0'; // ends string
    free(numList);
    return goBig;
}

void dejaVu (char * aString, int * numWords, int * numSentences){
    //vars
    *numWords = 0;
    *numSentences = 0;
    int length = strlen(aString);
    char * newStr = malloc(sizeof(char)*(length+1));
    if(newStr == NULL){
      printf("Memory could not be allocated.");
      exit(1);
    }
    strcpy(newStr, aString);
    int i = 0;
    char prevChar = '\0';//to keep track if previous characters were also punctuation
    char * strToken = strtok(newStr, " \n");
    //to count words
    while(strToken != NULL){
      *numWords = *numWords + 1;
      strToken = strtok(NULL, " \n");//continues scan from the end of the prev token
    }
    //counts a sentence at puntuation
    while(i < length){
      char c = newStr[i];
      if((c == '.' || c == ':' || c == ';' || c == '!' || c == '?') && (prevChar != '.' && prevChar != ':' && prevChar != ';' && prevChar != '!' && prevChar != '?')){
        *numSentences = *numSentences + 1;
      }
      prevChar = c;
      i++;

    }
    printf("Number of Words = %d\nNumber of Sentences = %d\n", *numWords, *numSentences);
    free(newStr);
}

char * breathless (char * aString){
    //vars
    int len = strlen(aString);
    int i = 0;
    int j = 0;
    char *breathless = (char *)malloc(sizeof(char)*(len+1));
    if(breathless == NULL){
      printf("Memory could not be allocated.");
      exit(1);
    }
    //does not include punctuation in the new string "breathless"
    for (i = 0; i< len; i++){
      if(aString[i] != '.' && aString[i] != '!' && aString[i] != '?' && aString[i] != ':' && aString[i] != ';'){
        breathless[j] = aString[i];//skips over punctiation
        j++;
      }
    }
    breathless[j] = '\0';
    breathless = realloc(breathless, (sizeof(char) * (j)));
    return breathless;
}

void tail (char * aString, int whichWord, char * desiredSuffix){
    //vars
    char * aaString = breathless(aString);//gets rid of punctuation
    int words = 0;
    char ** list = goAway(aaString, &words);//to make into a list of words
    if(list == NULL){
      printf("Memory could not be allocated.");
      exit(1);
    }
    //prints in the desired format
    for (int i = 0; i<strlen(list[whichWord-1]); i++){
      printf("%c%s\n", list[whichWord-1][i], desiredSuffix);
    }
    //have to free for each element in list
    for(int j = 0; j < words; j++){
      free(list[j]);
    }
    free(list);

}

char ** goAway (char * aString, int * numWordsReturned){
    //vars
    char * newStr = malloc(sizeof(char)*(strlen(aString)+1));
    if(newStr == NULL){
      printf("Memory could not be allocated.");
      exit(1);
    }
    char * newStr2 =malloc(sizeof(char)*(strlen(aString)+1));
    if(newStr2 == NULL){
      printf("Memory could not be allocated.");
      free(newStr);
      exit(1);
    }
    //make buffers so that strtok does not affect aString
    strcpy(newStr, aString);
    strcpy(newStr2, aString);
    //for counting words
    char * strToken2 = strtok(newStr2, " \n");//this is the delimiter so that newlines and spaces indicate a separation between words
    while(strToken2 != NULL){
      *numWordsReturned = *numWordsReturned + 1;
      strToken2 = strtok(NULL, " \n");//continues scan from the end of the prev token
    }
    printf("Number of words in given string: %d\n", *numWordsReturned);//outputs number of words

    int i = 0;
    char ** wordList = malloc(sizeof(char*)*(*numWordsReturned));//allocates enough space based on words counted
    if(wordList == NULL){
      printf("Memory could not be allocated.");
      free(newStr);
      free(newStr2);
      exit(1);
    }
    char * strToken = strtok(newStr, " \n");
    while(strToken != NULL){
      wordList[i] = malloc(sizeof(char)*(strlen(strToken)+1));//alocates space for each word
      if(wordList[i] == NULL){
        printf("Memory could not be allocated.");
        free(newStr);
        free(newStr2);
        exit(1);
      }
      strcpy(wordList[i], strToken);//saves word
      i++;
      strToken = strtok(NULL, " \n");//continues scan from the end of the prev token
    }
    free(newStr);
    free(newStr2);
    return wordList;
}
