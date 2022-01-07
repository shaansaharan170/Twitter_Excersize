#include "headerA3.h"

void addNodeToList(tweet**tweetList, tweet * node)
{
    //declare all variables
    tweet * tail;
    tweet * ptrTemp = malloc(sizeof(tweet)); //set the size for temp
    tail = *tweetList; //set tail to the pointer of tweetList
    strcpy(ptrTemp->user, node->user);
    strcpy(ptrTemp->text, node->text);
    ptrTemp->id = node->id;
    ptrTemp->next = NULL;

    if(*tweetList == NULL)
    {
        *tweetList = ptrTemp; //if the first item is null, then set the head
    }
    else
    {
        while(tail->next != NULL)
        {
            tail = tail->next; //read through the entire file
        }
    tail->next = ptrTemp; //move to next node
    }
}
