#include "map.h"

void CreateEmpty(Map *M)
{
    M->Count = Nil;
}

boolean IsEmpty(Map M)
{
    return M.Count == Nil;
}

boolean IsFull(Map M)
{
    return M.Count == MaxEl;
}

valuetype Value(Map M, keytype k)
{
    address i = 0;
    while (i < M.Count && M.Elements[i].Key != k)
    {
        i++;
    }
    if (i < M.Count)
    {
        return M.Elements[i].Value;
    }
    else
    {
        return Undefined;
    }
}

void Insert(Map *M, keytype k, valuetype v)
{
    if (Value(*M, k) == Undefined && !IsFull(*M))
    {
        M->Elements[M->Count].Key = k;
        M->Elements[M->Count].Value = v;
        M->Count++;
    }
}

void Delete(Map *M, keytype k)
{
    address i = 0;
    while (i < M->Count && M->Elements[i].Key != k)
    {
        i++;
    }
    if (i < M->Count)
    {
        M->Count--;
        while (i < M->Count)
        {
            M->Elements[i] = M->Elements[i + 1];
            i++;
        }
    }
}

boolean IsMember(Map M, keytype k)
{
    address i = 0;
    while (i < M.Count && M.Elements[i].Key != k)
    {
        i++;
    }
    return i < M.Count;
}

