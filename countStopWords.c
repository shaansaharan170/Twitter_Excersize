#include "headerA3.h"

void countStopWords(tweet * tweetList) {
    
    //declares all variables
    tweet *ptrTweet = tweetList;
    int stopWordsCount = 0;
    int tweetCount = 0;
    char * stopWordsFromFile[25] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its","of","on","that","the","to","was","were","will","with"}; //list of all the stop words
    char textSave[141]; //where the text will be saved to
    char *seperate; //use this to hold the seperated text

    while(ptrTweet != NULL)
    {
        strcpy(textSave, ptrTweet->text); //strcpy the text for the specific read tweet to textSave so avoid corrupting the original
        seperate = strtok(textSave, " ,.-:;"); //store the broken text into segments to be read through strtok

        while(seperate != NULL) //read until the end is reached
        {
            for(int counter = 0; counter < 25; counter++) //go through each stop word
            {
                if(strcmp(seperate, stopWordsFromFile[counter]) == 0) //if stop word is reached then...
                {
                    stopWordsCount++; //...add one to the total count
                    break;
                }
            }
            seperate = strtok(NULL, " ,.-:;"); //empty strtok to avoid error
        }

        ptrTweet = ptrTweet->next; //set the origninal text back to move to set set
        tweetCount++; //add one to the total tweet count

    }
    if(tweetCount == 1 && stopWordsCount == 1)
    {
        printf("Across %d tweet, %d stop word was found.\n", tweetCount, stopWordsCount); //output the given results
    }
    else if(tweetCount && stopWordsCount == 1)
    {
        printf("Across %d tweets, %d stop word was found.\n", tweetCount, stopWordsCount); //output the given results
    }
    else if(tweetCount == 1 && stopWordsCount)
    {
        printf("Across %d tweet, %d stop words were found.\n", tweetCount, stopWordsCount); //output the given results
    }
    else
    {
        printf("Across %d tweets, %d stop words were found.\n", tweetCount, stopWordsCount); //output the given results
    }
    return;
}
