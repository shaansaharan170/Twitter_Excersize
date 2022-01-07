#include "headerA3.h"

void loadTweetsFromFile(tweet ** tweetList)
{
    //declare all variables
    tweet * ptrTweet;
    tweet * ptrTemp;
    ptrTweet = malloc(sizeof(tweet));
    ptrTemp = malloc(sizeof(tweet));
    FILE * filePtr;
    char fileName[50];
    char info[200];
    char infoSave[200];
    char *segment;

    printf("Enter a file name to load from: "); //prompt the user
    scanf("%s", fileName); //let the user fileName
 
    filePtr = fopen(fileName, "r"); //let the file be read
 
    if(filePtr == NULL)
    {
        printf("Error has occured, no file exists.\n"); //if no file exists, end
        return;
    }
 
    ptrTweet = *tweetList; //assign the value of the list

    if(ptrTweet != NULL)
    {
        while(ptrTweet->next != NULL)
        {
            ptrTweet = ptrTweet->next; //set the head
        } 
    }
 
    while(fgets(info, 200, filePtr) != NULL)
    {
        strcpy(infoSave, info); //save to avoid corrupting the original
        segment = strtok(info, ","); //break the token
        ptrTemp->id = atoi(segment); //set the id
        strcpy(ptrTemp->user, strtok(NULL, ",")); //check for the break comma
        strcpy(ptrTemp->text, strtok(NULL, ",")); //check for the break comma
        addNodeToList(tweetList, ptrTemp); //set to the node list
    }

    printf("\nTweets imported!\n"); //let the user know the tweets where importe!
    fclose(filePtr);
    return;
    free(ptrTweet); //free all variables
    free(ptrTemp);
}   
