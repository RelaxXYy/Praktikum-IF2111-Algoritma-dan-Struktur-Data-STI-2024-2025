#include "set.h"

void CreateEmpty(Set *S)
{
    S->Count = Nil;
}

boolean IsEmpty(Set S)
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
{
    return S.Count == MaxEl;
}

void Insert(Set *S, infotype Elmt)
{
    if (!IsMember(*S, Elmt) && !IsFull(*S))
    {
        S->Elements[S->Count++] = Elmt;
    }
}

void Delete(Set *S, infotype Elmt)
{
    if (IsMember(*S, Elmt))
    {
        address i = 0;
        while (S->Elements[i] != Elmt)
        {
            i++;
        }
        S->Count--;
        for (i; i < S->Count; i++)
        {
            S->Elements[i] = S->Elements[i + 1];
        }
    }
}

boolean IsMember(Set S, infotype Elmt)
{
    address i = 0;
    while (i < S.Count && S.Elements[i] != Elmt)
    {
        i++;
    }
    return i < S.Count;
}



