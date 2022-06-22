#pragma warning(disable : 4996)

#include <iostream>

#include <string>

#include "DateTime.h"

#include "Headers.h"

#include "Items.h"

#include <cstring>

#include "string.h"

#include "ICS0017DataSource.h"

#define SIZE 1

using namespace std;

void printStruct(HEADER_B *ps1);

HEADER_B *InsertItem(HEADER_B *p, char *pNewItemID = 0);

HEADER_B *RemoveItem(HEADER_B *p, char *pItemID);

int main()

{

    HEADER_B *ps1 = GetStruct1(4, 30);

    printStruct(ps1);

    const char *Cases[] = {"Z A", "Z Z", "Z K", "A Z", "A A", "A K", "G Z", "G A", "G K", "M A", "MBa", "M Bb", "M Z"};

    for (int i = 0; i < 13; i++)

    {

        char *lol = (char *)malloc(strlen(Cases[i]) * sizeof(char));

        strcpy(lol, Cases[i]);

        ps1 = InsertItem(ps1, lol);
    }

    printStruct(ps1);

    for (int i = 0; i < 13; i++)

    {

        char *lol = (char *)malloc(strlen(Cases[i]) * sizeof(char));

        strcpy(lol, Cases[i]);

        ps1 = RemoveItem(ps1, lol);
    }

    printStruct(ps1);

    return 0;
}

ITEM4 *GetMyItem(ITEM4 *pList, char *pChar)
{

    if (!pList || !pChar)
        return 0;

    ITEM4 *pItem;

    for (pItem = pList; pItem && strcmp(pChar, pItem->pID); pItem = pItem->pNext)
        ;

    return pItem;
}

HEADER_B *GetHeaderPositionB(HEADER_B *pList, char pChar)
{

    if (!pList || !pChar)
        return 0;

    HEADER_B *pB;

    for (pB = pList; pB; pB = pB->pNext)
    {

        if (pChar == pB->cBegin)
            break;
    }

    return pB;
}

HEADER_A *GetHeaderPositionA(HEADER_A *pList, char pKey)
{

    if (!pList || !pKey)
        return 0;

    HEADER_A *pA = pList;

    while (pA)
    {

        if (pKey == pA->cBegin)
            break;

        pA = pA->pNext;
    }

    return pA;
}

void printStruct(HEADER_B *p)
{

    int j = 0;

    HEADER_B *hB = p;

    while (hB)
    {

        HEADER_A *hA = hB->pHeaderA;

        while (hA)
        {

            ITEM4 *pI = (ITEM4 *)hA->pItems;

            while (pI)
            {

                printf("%d) %s %lu %s\n", ++j, pI->pID, pI->Code, pI->pDate);

                pI = pI->pNext;
            }

            hA = hA->pNext;
        }

        hB = hB->pNext;
    }
}

bool CheckForValidity(char *pChar)

{

    char *pSpace = strchr(pChar, ' ');

    if (pSpace != NULL)

    {

        if (*(pChar + 1) != ' ')

        {

            return false;
        }

        if (*(pSpace + 2) != NULL)

        {

            return false;
        }
    }

    else

    {

        return false;
    }

    return true;
}

HEADER_B *InsertItem(HEADER_B *p, char *pNewItemID)
{

    if (pNewItemID != 0)

    {

        if (CheckForValidity(pNewItemID) == false)

        {

            cout << "ERROR! Given index is wrong" << endl;

            return p;
        }
    }

    ITEM4 *pNewItem = (ITEM4*)GetItem(1, pNewItemID);

    if (!pNewItem)
        return p;

    char *pFirstWord = pNewItemID;

    char *pSecondWord = strchr(pNewItemID, ' ') + 1;

    HEADER_B *hB = p;

    HEADER_B *holdhB = p;

    bool Bexists = false;

    char holdW1 = pFirstWord[0];

    while (holdhB)
    {

        if (holdhB->cBegin == holdW1)
        {

            Bexists = true;

            break;
        }

        holdhB = holdhB->pNext;
    }

    if (!Bexists)
    {

        HEADER_B **tracer = &p;

        HEADER_B *newHB = new HEADER_B;

        newHB->cBegin = holdW1;

        while (*tracer && (*tracer)->cBegin < holdW1)
        {

            tracer = &(*tracer)->pNext;
        }

        newHB->pNext = *tracer;

        *tracer = newHB;

        HEADER_A *newHA = new HEADER_A;

        newHB->pHeaderA = newHA;

        newHA->cBegin = pSecondWord[0];

        newHA->pItems = pNewItem;

        pNewItem->pNext = NULL;

        newHA->pNext = NULL;

        return p;
    }

    HEADER_A *hA = holdhB->pHeaderA;

    HEADER_A *holdhA = holdhB->pHeaderA;

    bool Aexists = false;

    char tmpWA = pSecondWord[0];

    while (holdhA)
    {

        if (holdhA->cBegin == tmpWA)
        {

            Aexists = true;

            break;
        }

        holdhA = holdhA->pNext;
    }

    if (!Aexists)
    {

        HEADER_A **tracer = &holdhB->pHeaderA;

        HEADER_A *newHA = new HEADER_A;

        newHA->cBegin = tmpWA;

        while ((*tracer) && (*tracer)->cBegin < tmpWA)
        {

            tracer = &(*tracer)->pNext;
        }

        newHA->pNext = *tracer;

        *tracer = newHA;

        newHA->pItems = pNewItem;

        return p;
    }

    ITEM4 *holdItem = (ITEM4 *)holdhA->pItems;

    while (holdItem)
    {

        if (GetMyItem(holdItem, pNewItemID))
        {

            printf("item ID exists\n");

            return p;
        }

        holdItem = holdItem->pNext;
    }

    holdItem = (ITEM4 *)holdhA->pItems;

    pNewItem->pNext = holdItem;

    holdhA->pItems = pNewItem;

    return p;
}

HEADER_B *RemoveItem(HEADER_B *p, char *pItemID)
{

    if (pItemID != 0)

    {

        if (CheckForValidity(pItemID) == false)

        {

            cout << "ERROR! Given index is wrong" << endl;

            return p;
        }
    }

    char pFirstWord = *pItemID;

    char pSecondWord = *(strchr(pItemID, ' ') + 1);

    HEADER_B *holdhB = GetHeaderPositionB(p, pFirstWord);

    if (!holdhB)
    {

        printf("item does not exist\n");

        return p;
    }

    HEADER_A *holdhA = GetHeaderPositionA(holdhB->pHeaderA, pSecondWord);

    if (!holdhA)
    {

        printf("item does not exist\n");

        return p;
    }

    ITEM4 *tmpI = (ITEM4 *)holdhA->pItems;

    if (!tmpI)
    {

        printf("item does not exist\n");

        return p;
    }

    ITEM4 *prevI, *pI;

    prevI = NULL;

    for (pI = tmpI; pI; prevI = pI, pI = pI->pNext)
    {

        if (strcmp(pItemID, pI->pID) == 0)
        {

            if (prevI == NULL)
                holdhA->pItems = pI->pNext;

            else
                prevI->pNext = pI->pNext;

            delete pI;

            break;
        }
    }

    if (!tmpI)
    {

        HEADER_A *prevA, *pA;

        prevA = NULL;

        for (pA = holdhB->pHeaderA; pA; prevA = pA, pA = pA->pNext)
        {

            if (strcmp((char *)pA->cBegin, (char *)holdhA->cBegin) == 0)
            {

                if (prevA == NULL)
                    holdhB->pHeaderA = pA->pNext;

                else
                    prevA->pNext = pA->pNext;

                delete pA;

                break;
            }
        }
    }

    if (!holdhA)
    {

        HEADER_B *prevB, *pB;

        prevB = NULL;

        for (pB = p; pB; prevB = pB, pB = pB->pNext)
        {

            if (strcmp(&pB->cBegin, (char *)holdhB->cBegin) == 0)
            {

                if (prevB == NULL)
                    holdhB = pB->pNext;

                else
                    prevB->pNext = pB->pNext;

                delete pB;

                break;
            }
        }
    }

    return p;