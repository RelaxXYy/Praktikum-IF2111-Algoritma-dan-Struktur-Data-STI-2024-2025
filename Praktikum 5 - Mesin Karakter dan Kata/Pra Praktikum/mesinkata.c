#include "mesinkata.h"
#include "boolean.h"
#include "mesinkarakter.h"

/* State Mesin Kata */
boolean EndWord;
Word CurrentWord;

void IgnoreBlanks(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
   while (currentChar == BLANK && !IsEOP()){
      ADV();
   }
}

void STARTWORD(){
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
   START();
   IgnoreBlanks();
   if (currentChar == MARK){
      EndWord = true;
   } else {
      EndWord = false;
      CopyWord();
   }
}

void ADVWORD(){
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
   if (currentChar == MARK){
      EndWord = true;
   } else {
      CopyWord();
   }
}

void CopyWord(){
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
   int i = 0;
   while ((currentChar != MARK) && (currentChar != BLANK) && (i<NMax)) {
       CurrentWord.TabWord[i] = currentChar;
       ADV();
       i++;
   }
   CurrentWord.Length = i;   
}
