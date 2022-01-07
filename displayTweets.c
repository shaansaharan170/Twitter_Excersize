#include "headerA3.h"

void displayTweets(tweet * tweetList)
{
    tweet *ptrTweet;
    if(tweetList == NULL)
    {
        printf("No Tweets\n"); //if empty then let the user know
        return;
    }
    else
    {
        ptrTweet = tweetList;
        while(ptrTweet != NULL) 
        {
            printf("%d: created by %s: %s\n", ptrTweet->id, ptrTweet->user, ptrTweet->text); //output the tweets that were given in createTweets and addNodeToList
            ptrTweet = ptrTweet->next; //move to next set
        }
    }
}
