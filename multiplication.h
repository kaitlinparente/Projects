#include <list>

using namespace std; 

#ifndef MULTIPLICATION
#define MULTIPLICATION

class Multiplication
{
	private:  // declare data members
		   
		int op1,
			op2,
			max_limit;  // maximum value for the operands; minimum value = 0
	
	public:   // declare function members

		Multiplication();  					// default constructor
		Multiplication(int new_max_limit); 	// specific constructor
		
		// accessor functions: access the data members, don't modify it 
		
		void display() const;    // displays the data of a Multiplication object
		int  get_result() const; // returns the result of the multiplication 
		void hint() const;       // display hint 
		bool check_result(int user_result) const;
					// if user_result == op1* op2 return true
		bool is_bigger(const Multiplication &other) const; // other's data members cannot be changed because of const
					
		// mutator functions: change data members 
		void set_max_limit(int new_max_limit);  // changes the value of max_limit
		int get_max_limit() const;
		void new_operands();  // assign new, random values to op1 and op2 between 0 and max_limit
};

// interacts with the user to get an answer to a multiplication sentence
// it makes sure that the answer is between 0 and max_answer limit (100)
class Answer
{
	private: 
		int answer;  // valid values: 0 to 100
	public:
		Answer(); // initialize answer to 0
		void enterValidAnswer(); // 1. ask user for a valid answer while the 
								 // entered input is not valid: less than -1 
								 //or greater than 100 
								 // (while (answer invalid) ask for a new answer
								 // valid answers: a number between 0 and 100 
		int getAnswer() const;    	 // return the value of answer
		void displayAnswer();    // cout the answer
};

// Problem class
// Ask the user for a correct answer to a multiplication sentence up to 
// max_tries
class Problem
{
	private:
			Multiplication sentence;
			Answer last_answer;       // last answer entered by the user
			int nr_incorrect_answers; // # incorrect answers user inputs for 
			int nr_correct_answers;  // this sentence: valid values: 
									  // 0 to max_tries
			int max_tries;			  // = 3

	public:
			Problem(int new_max_tries = 3, int new_op_max_limit = 10);
			/* Problem::Problem(int new_max_tries, int new_op_max_limit)
						: sentence(new_op_max_limit), max_tries(new_max_tries)
						{ 
						  nr_incorrect_answers = 0;
						}
			*/
			void setNewProblem(); // mutator function
			int  solveProblem();  // ask the user for a correct answer up to 
								 // max_tries times; then return the number of
								 // incorrect tries
								 // mutator function
								 							
			int getNrCorrect() const; 
			int  getNrIncorrect() const;				  // accessor function		
			void printHint() const;     // print hint // accessor function
			void display() const;     				  // accessor function   
			void setMaxLimit(int new_op_max_limit);   // mutator function
			void setMaxTries(int new_max_tries);						  // mutator function
													  // changes the data of 
													  // calling object
			int getMaxLimit() const;     // accessor function = does not change 
										 // the data members of a calling object 
			int getLastAnswer() const;   // accessor function
};

// Game class
// Purpose: implement the game: repeatedly generate multiplication problems, get 
// answers for them, keep statistics on the number of correct problems solved,
// change operand limits if 3 consecutive problems have at least one incorrect // answer, display a hint after 3 incorrect answers to the same problem

// Incorrect problem: a problem with at least one incorrect answer.
// Correct problem:   a problem with no incorrect answer = first valid answer was correct 

class Game
{
   private:
	 Problem current_pr;
	 // missing list_incorrect and list_correct
	 list<Problem> list_correct; 
	 list<Problem> list_incorrect; 
	 double prob_replay;  
	 // a # between 0 and 1 = probability of replying an incorrect problem
	 // I eliminated bool play because I find it to be unnecessary to the program
	 int  nr_incorrect_pr;       // total number of incorrect problems: 
	 int  nr_correct_pr; 	     // total # of correct problems: 
	 int  difficulty;          // optional  difficulty = 3  (max_limit = 10),
	 						  //                         2  (max_limit = 7)
	 						  //                         1  (max_limit = 5)
  public:
  	 Game(int new_difficulty);
  	 
  	 void playGame();  // ask user to solve problems repeatedly, until they don't want to play again. 
  	 bool playAgain() const; // ask user if they want to play again. This function will be called inside playGame().
  	 
  	 void printStats() const; 
  	 void updateStats();   // updates nr_incorrect_consec_pr or nr_correct_consec_prob, nr_incorrect_pr, nr_correct_pr
  	 
  	 int chooseDifficulty(); //explains difficulty and allows a choice
  	 void DiffOptions(); 
  	 void updateDifficulty(); 
  	 void setDifficulty(int difficulty);  // sets the difficulty to a new value; assert that new_difficulty is between 1 and 3. // Change the maxLimit for the operands of current_pr;
  	 
  	 int  getMaxLimit() const;  // returns the operands max_limit - actual value is 
	 
	 void generate_problem(); //with prob_random generate a new 
											//multiplication problem with 1 - prob_random
											//pick one of the problems in the list_incorrect 

};

#endif
