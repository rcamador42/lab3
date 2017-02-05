#if !defined PASSWORD_H
#define PASSWORD_H

//complete the includes

class Password
{
   private:
	      ListArray<String>* viable_words;  //the list of words that can still be the password
	      ListArray<String>* all_words;  //the original list of words
	      int len;  //the length of the first word entered is stored to check that all subsequent words have the same length

	      //a private helper method to report the number of character matches between two Strings
	      int getNumMatches(String* curr_word, String* word_guess);

   public:
   			Password();		// CONSTRUCTOR
	   		~Password();	// DESCTRUCTOR (THERE IS WORK TO DO HERE, DELETE THE INDIVIDUAL WORDS)
	   		void addword(String* word) // ADD A WORD TO THE LIST OF POSSIBLE VALUES
	   		void guess(int try_password, int num_matches); //INDEX OF GUESSED WORD IN THE LIST OF ALL 
	   													   //WORDS (1-BASED), NUMBER OF MATCHES REPORTED 
	   													   //BY FALLOUT 3, UPDATE VIABLE PASSWORDS LIST
	   		int getNumberOfPasswordsLeft(); // RETURNS THE NUMBER OF POSSIBLE PASSWORDS REMAINING
	   		void displayViableWords(); // DISPLAY THE CURRENT LIST OF POSSIBLE PASSWORDS
	   		int bestGuess(); //the best word in the original list to guess next (done for you)
	   		String* getOriginalWord(int index); //get a word from the original list of all passwords, 1-based

};

#endif
