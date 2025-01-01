#include <stdio.h>
#include "boolean.h"
#include "set.h"

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    S->Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFull(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (IsMember(*S, Elmt))
    {
        return;
    }
    S->Elements[S->Count] = Elmt;
    S->Count++;
}

void Delete(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    if (!IsMember(*S, Elmt))
    {
        return;
    }
    while (!found && idx < S->Count)
    {
        if (S->Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    for (iterator = idx + 1; iterator < S->Count; iterator++)
    {
        S->Elements[iterator - 1] = S->Elements[iterator];
    }
    S->Count--;
}

boolean IsMember(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah member dari S */
{
    boolean found = false;
    address idx = 0, iterator;
    while (!found && idx < S.Count)
    {
        if (S.Elements[idx] == Elmt)
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

Set SetUnion(Set s1, Set s2){
    for(int i = 0; i < s2.Count; i++){
        if(!IsMember(s1, s2.Elements[i])) Insert(&s1, s2.Elements[i]);
    }
    return s1;
}
// Mengembalikan set baru yang berisi elemen-elemen yang terdapat pada s1 atau s2
// Contoh: [1, 2] U [2, 3] = [1, 2, 3]

Set SetIntersection(Set s1, Set s2){
    Set result;
    CreateEmpty(&result);
    for(int i = 0; i < s2.Count; i++){
        if(IsMember(s1, s2.Elements[i])) Insert(&result, s2.Elements[i]);
    }
    return result;
}
// Mengembalikan set baru yang berisi elemen-elemen dari s1 dan s2 yang terdapat pada kedua set
// Contoh: [1, 2] ∩ [2, 3] = [2]

Set SetSymmetricDifference(Set s1, Set s2){
    for(int i = 0; i < s2.Count; i++){
        if(!IsMember(s1, s2.Elements[i])) Insert(&s1, s2.Elements[i]);
        else Delete(&s1, s2.Elements[i]);
    }
    return s1;
}
// Mengembalikan set baru yang berisi elemen yang ada di s1 atau s2, tapi tidak pada keduanya
// Contoh: [1, 2] ⊖ [2, 3] = [1, 3]

Set SetSubtract(Set s1, Set s2){
    for(int i = 0; i < s2.Count; i++){
        if(IsMember(s1, s2.Elements[i])) Delete(&s1, s2.Elements[i]);
    }
    return s1;
}
// Mengembalikan set baru yang berupa hasil pengurangan s1 dengan s2
// Contoh:
// s1 = [1, 2] s2 = [2, 3]
// s1 - s2 = [1]

