//include header
#include "headerA3.h"

tweet *createTweet(tweet *tweetList)
{
    //declare all variables
    tweet * ptrTweet;
    tweet * ptrTemp = tweetList;
    ptrTweet = NULL;
    ptrTweet = malloc(sizeof(tweet)); //set size
    int counter = 0;

    if(ptrTweet == NULL)
    {
        printf("Error has occured\n"); //if ptr has nothing added to it then...
        return 0; //... return 0, ends the program
    }

    //ask the user for the user input
    printf("Enter a username: ");
    scanf(" %[^\n]", ptrTweet->user);

    if(strlen(ptrTweet->user) > 51) //error check for length
    {
        printf("Too long! Enter a username: ");
        scanf(" %[^\n]", ptrTweet->user);
    }
    else if(strlen(ptrTweet->user) == 0) //error check for length
    {
        printf("Too short! Enter a username: ");
        scanf(" %[^\n]", ptrTweet->user);
    }

    //ask the user for the tweet
    printf("Enter the user's tweet: ");
    scanf(" %[^\n]", ptrTweet->text);

    if(strlen(ptrTweet->text) > 141) //error check for length
    {
        printf("Too long! Enter the user's tweet: ");
        scanf(" %[^\n]", ptrTweet->text);
    }
    else if(strlen(ptrTweet->text) == 0) //error check for length
    {
        printf("Too short! Enter the user's tweet: ");
        scanf(" %[^\n]", ptrTweet->text);
    }

    //keep calculating the uderID total until null space is reached
    for(counter = 0; counter < strlen(ptrTweet->user); counter++)
    {
        ptrTweet->id += ptrTweet->user[counter]; //add userID ASCII
    }

    ptrTweet->id = ptrTweet->id + strlen(ptrTweet->text); //calculate the total final
    ptrTweet->next = NULL; //set the tail as null
    if(ptrTemp != NULL) //only enter if the temp has no end or NULL
    {
        do //continue the loop until the end of the file is reached
        {
            if(ptrTweet->id == ptrTemp->id) //checks if the id already exists
            {
                ptrTweet->id = (rand() & (1000)) + ptrTweet->id; //create a random number if the id already exists
            }
        ptrTemp = ptrTemp->next; //move to next linked list node to and continue until loop command is met
        } while (ptrTemp != NULL);
    }

    printf("\n\nYour computer-generated userid is %d\n", ptrTweet->id); //print the final output
    return ptrTweet; //returns to allow it to be stored
}
