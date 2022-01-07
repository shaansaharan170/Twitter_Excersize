#include "headerA3.h"
#include <ctype.h>

int searchTweetsByKeyword(tweet * tweetList)
{
    //declare all variables
    tweet * ptrTweet;
    char word[141];
    char lowerWord[141];
    int similar = 0;
    int found = 1;

    printf("Enter a keyword to search: "); //prompt the user
    scanf(" %[^\n]", word); //gather input

    for(int counter = 0; word[counter]; counter++) //scan the keyword
    {
        lowerWord[counter] = tolower(word[counter]); //set all the input to lower
    }
    if (tweetList == NULL)
    {
        printf("No Tweets\n"); //if empty, let the user know
        return 0;
    }
    else
    {
        ptrTweet = tweetList; //set everything in list to ptr
        while(ptrTweet != NULL)
        {
            if(strstr(ptrTweet->text, lowerWord) != NULL)
            {
                printf("Match found for '%s': %s wrote: \"%s\"\n", lowerWord, ptrTweet->user, ptrTweet->text); //proivde the output
                similar = found; //set equal when the word is found
            }
        ptrTweet = ptrTweet->next; //read next set
        }
    }

    if(similar == found)
    {
        return 1; //true
    }
    else
    {
        printf("No match found\n"); //not found
    }
    return 0;
}
