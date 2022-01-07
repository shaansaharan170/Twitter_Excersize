#include "headerA3.h"

void saveTweetsToFile(tweet * tweetList)
{
    //declare all variables
    char saveFile[200];
    FILE * filePtr;
    tweet * ptrTweet;

    printf("Enter the filename where you would like to store your tweets: "); //print the prompt
    scanf("%s", saveFile); //user inputs the file name they wish to store to

    filePtr = fopen(saveFile, "w"); //writes to that file

    if(filePtr == NULL)
    {
        printf("Error has occured\n"); //if no file, then let the user know
        return;
    }
    else if(tweetList == NULL)
    {
        printf("Nothing has been entered\n"); //if empty, let the user know
        fclose(filePtr);
        return;
    }
    else
    {
        ptrTweet = tweetList; //set the pointer to all the collected data
        while(ptrTweet != NULL)
        {
            fprintf(filePtr, "%d,%s,%s\n", ptrTweet->id, ptrTweet->user, ptrTweet->text); //print all the inputted data into a file
            ptrTweet = ptrTweet->next; //move to the next set
        }
    }
    printf("Tweets Imported!\n"); //let the user know the tweets were imported
    fclose(filePtr); //close the file when done
    return;
}
