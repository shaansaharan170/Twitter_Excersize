#include "headerA3.h"

int main()
{
    //declare all the vairables that will be used in the main
    int input = 0;
    tweet * storeNode;
    tweet * tweetList = NULL;
    tweet * tweetHead = NULL;
    
    while (input != 8) //loop until the input of the user is 8
    {
        //print the menu of SHWITTER
        printf("**********WELCOME TO SHWITTER**********");
        printf("\n1. Create a new tweet\n");
        printf("2. Display tweets\n");
        printf("3. Search a tweet (by keyword)\n");
        printf("4. Find how many words are \"stop words\" (stop words are explained in a later section)\n");
        printf("5. Delete the nth tweet\n");
        printf("6. Save tweets to a file\n");
        printf("7. Load tweets from a file\n");
        printf("8. Exit\n");
        printf("****************************************\n");

        printf("Choose a menu option: "); //prompt the user for the input
        scanf("%d", &input); //scan the input

        if(input == 1)
        {
            storeNode = createTweet(tweetHead); //store createTweet in a node
            addNodeToList(&tweetList, storeNode); //tweetList will be added as a node from createTweet
        }
        else if(input == 2)
        {
            displayTweets(tweetList); //displays the tweets
        }
        else if(input == 3)
        {
            searchTweetsByKeyword(tweetList); //searches keywords
        }
        else if(input == 4)
        {
            countStopWords(tweetList); //counts the stop words
        }
        else if(input == 5)
        {
            deleteTweet(&tweetList); //deletes a certain tweet
        }
        else if(input == 6)
        {
            saveTweetsToFile(tweetList); //saves the tweet to a file of your choosing
        }
        else if(input == 7)
        {
            loadTweetsFromFile(&tweetList); //loads all the pointers from a file
        }
        else if(input == 8)
        {
            printf("\nThanks for coming to SHWITTER\n\n"); //leaves SHWITTER
            free(tweetList);
            return 0; 
        }
        else
        {
            printf("Invalid, try again\n"); //if no correct options, prompt again
        }
    }
}
