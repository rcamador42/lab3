#include "Password.h"
using CSC2110::ListArrayIterator;

#include <iostream>
using namespace std;

// CONSTRUCTOR
Password::Password()
{
   //DEFINE all_words & viable_words
   //dynamicly defined ListArray variable 
   all_words = new ListArray<String>();
   viable_words = new ListArray<String>(); // ALL T's IN ListArray = String
}

// DESTRUCTOR
Password::~Password()
{
   delete all_words;
   delete viable_words;
}

//ADD A WORD TO THE LIST OF POSSIBLE PASSWORDS
void Password::addWord(String* word)
{
   all_words->add(word);
   viable_words->add(word);
}

// INDEX OF GUESSED WORD IN THE LIST
void Password::guess(int try_password, int num_matches)
{
   int matches = 0;
   String* password = all_words->get(try_password);
   String* temp;

   for(int i = 1; i <= all_words->size(); i++)
   {
      temp = viable_words->get(i);
      for(int j = 0l j < password->length(); j++)
      {
         if(password->chatAt(j) == temp->charAt(j))
          matches++; 
      }
      
      if(matches != num_matches)
      viable_words->remove(i);
   } 
}

// RETURNS THE NUMBER OF POSSIBLE PASSWORDS REMAINING
int getNumberOfPasswordsLeft()
{
   return viable_words->size(); //???????????????????????????
}

// DISPLAY THE CURRENT LIST OF POSSIBLE PASSWORDS
void displayViableWords()
{
   int i=0;
   int sz = viable_words->size();

   for(int x = 1; x <= sz; x++)
   {
       viable_word->get(x)->displayString(); // CHECK!!!!!!!!!!!!!!!!!!!
   }

}

// GET A WORD FROM THE ORIGINAL LIST OF ALL PASSWORDS, 1-BASED
String* getOriginalWord(int index)
{
   all_words->get(index);
}








int Password::bestGuess()
{
   int best_guess_index = -1;
   int best_num_eliminated = -1;
   int num_viable_passwords = getNumberOfPasswordsLeft();

   //loop over ALL words, even if they have been eliminated as the password
   int count = 1;
   ListArrayIterator<String>* all_iter = all_words->iterator();
   while(all_iter->hasNext())
   {
      String* original_word = all_iter->next();

      //loop over only those words that could still be the password
      //count up the number of matches between a possible password and a word in the original list
      int* count_num_matches = new int[len + 1];

      for (int i = 0; i < len; i++) 
      {
         count_num_matches[i] = 0;
      }

      ListArrayIterator<String>* viable_iter = viable_words->iterator();
      while(viable_iter->hasNext())
      {
         String* viable_word = viable_iter->next();
         int num_matches = getNumMatches(viable_word, original_word);
         count_num_matches[num_matches]++;
      }
      delete viable_iter;

      //find the largest number in the count_num_matches array
      //the largest number indicates the guess that will generate the most eliminations
      int most_num_matches = 0;
      for (int j = 0; j < len; j++) 
      {
         int curr_num_matches = count_num_matches[j];
         if (curr_num_matches > most_num_matches)
         {
            most_num_matches = curr_num_matches;
         }
      }

      //compute the fewest that can possibly be eliminated by guessing the current word (original list)
      int num_eliminated = num_viable_passwords - most_num_matches;

      //select the word to guess that maximizes the minimum number of eliminations (minimax)
      if (num_eliminated > best_num_eliminated)
      {
         best_num_eliminated = num_eliminated;
         best_guess_index = count;
      }
      
      count++;
      delete[] count_num_matches;
   }

   delete all_iter;
   return best_guess_index;  //return a 1-based index into the all_words list of words (careful)
}
