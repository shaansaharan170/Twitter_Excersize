#include "headerA3.h"

void deleteTweet(tweet ** tweetList)
{
    //declare all variables
    int countTweets = 0;
    int counter = 0;
    int reTotalTweets = 0;
    int position = 0;
    tweet *ptrTweet;
    tweet *ptrTemp;

        if(*tweetList == NULL)
        {
            printf("No Tweets\n"); //if no tweets, let the user know
            return;
        }
        else
        {
            ptrTweet= *tweetList; //set the pointer to read all the stored tweets
            while(ptrTweet!=NULL) //until the end is reached
            {
                countTweets = countTweets + 1; //add one to the counter of how many tweets there are
                ptrTweet = ptrTweet->next; //move to next tweet/next set
            }
        }
        if(countTweets > 1)
        {
           printf("Currently there are %d tweets\n\n", countTweets); //displays tweets
        }
        else
        {
            printf("Currently there is %d tweet\n\n", countTweets); //displays tweets
        }
        printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", countTweets); //give the range of tweets
        scanf("%d", &position); //let the user enter the tweet they wish to delete

        ptrTweet = *tweetList;

        if(position == 1)
        {
                *tweetList = ptrTweet->next; //if the head is chosen, set to delete
        }
        else
        {
            for(counter = 0; counter < (position - 1); counter++) //read through until the position is reached
            {
                ptrTemp = ptrTweet;
                ptrTweet = ptrTweet->next; //read the next set
                if(ptrTweet == NULL)
                {
                    printf("\nError has occured\n"); //if no location, let the user know
                    return;
                }
            }
        }
        ptrTemp->next = ptrTweet->next; //store the pointer of tweets in temp
        reTotalTweets = countTweets - 1; //set the new total
        if(reTotalTweets > 1 || reTotalTweets == 0)
        {
            printf("\nTweet %d deleted. There are now %d tweets left.\n", ptrTweet->id, reTotalTweets); //output the results
        }
        else
        {
            printf("\nTweet %d deleted. There are now %d tweet left.\n", ptrTweet->id, reTotalTweets); //output the results
        }
        return;
} 
