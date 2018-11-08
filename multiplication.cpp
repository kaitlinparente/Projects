#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "multiplication.h"

using namespace std;

// default constructor
// Purpose: initialize data members to default values
// Precondition: random generator seed is initialized 
// Postcondition: new multiplication object with random operators between 0 
// and 10
Multiplication::Multiplication()  	
{
	max_limit = 10;
	new_operands();
	// op1 = rand() % (max_limit+1) 
	// op2 = the same

}
// specific constructor
// Purpose: initialize a new multiplication object with a set max_limit
// Precondition: 1) random generator seed is initialized 
//               2) new_max_limit > 0 
// Postcondition: data in the new object: op1 and op2 are random values between 
// 0 and new_max_limit

Multiplication::Multiplication(int new_max_limit) 	
{
   assert(new_max_limit > 0);
   max_limit = new_max_limit;
   new_operands(); // set op1 and op2 randomly
}

// displays the data of a Multiplication object
// Preconditions: none
// Postconditions: none
void Multiplication::display() const   
{
	cout << op1 << " X " << op2 << endl;
	cout << "Max operand value is " << max_limit << endl;
}

// returns the result of the multiplication 
// Preconditions: none
// Postconditions: none
int Multiplication::get_result() const
{
   return op1*op2;
}

// is_bigger = compare the calling object with the passed object (other)
// result is true if the result of the multiplication for the calling object 
// is larger than the result of the multiplication for the other object

bool Multiplication::is_bigger(const Multiplication &other) const
{
   return (get_result() > other.get_result());
   // "this" is a pointer to the calling object use -> instead of . 
   // the expressions below are all equivalent
   // 1. get_result()
   // 2. (*this).get_result()
   // 3. this -> get_result();
}


// display hint 
// op1 = 2, op2 = 3: 
//        2 * 1 = 2 
//        2 * 2 = 4
//        2 * 3 = ?
// Preconditions: max_limit <= 10
 
void Multiplication::hint() const       
{
   if (op1 == 0 || op2 == 0 )
     cout << "Any number multiplied by 0 is 0" << endl;
   else if(op1==1 || op2 ==1)
	 cout << "Any number multiplied by 1 is that number itself." << endl; 
   else
   {
   	for (int i = 0; i < op2; i++)
   		cout << op1 << " * " << i << " = " << op1 * i << endl;
   	cout << op1 << " * " << op2 << " = ? " << endl;
   	}
}
	
// accessor functions: access the data members, don't modify it 
		
// if user_result == op1* op2 return true
// Preconditions: none;
// Postconditions: none
bool Multiplication::check_result(int user_result) const
{ 
	return (op1*op2 == user_result); 
}
					
// mutator functions: change data members 

// set_max_limit = changes the value of max_limit
// Precondition: new_max_limit > 0
// Postcondition: max_limit value is changed to new_max_limit and 
// new values are being assigned randomly to the two operands 
void  Multiplication::set_max_limit(int new_max_limit)
{
	assert(new_max_limit > 0);
	max_limit = new_max_limit;
	new_operands();
}

int Multiplication::get_max_limit() const
{
	return max_limit; 
}

// new_operands() = assign new, random values to op1 and op2 between 0 and
//  max_limit			
//	Preconditions: none
//  Postconditions:  operand values changed
void Multiplication::new_operands()
{
	op1 = rand() % (max_limit + 1);  // possible values are 0, 1,... max_limit
	op2 = rand() % (max_limit + 1);
}

//initialize user_answer to 0 
//Preconditions: the user gives and input
Answer::Answer()
{
	answer = 0; 
}

//makes sure the answer is between 0 and 100
//Preconditions: there is an answer
void Answer::enterValidAnswer()
{
	cout << "Enter a number between 0 and 100. " << endl; 
	cin >> answer;
	
	while(answer < 0 || answer > 100) 
	{	
		cout << "That is not a valid number. Please enter a valid number. " << endl; 
		cin >> answer;
	}

}

//returns what the user inputted
//Preconditions: none
int Answer::getAnswer() const
{
	return answer;
}

//displays what hte user inputted 
//preconditions: none 
void Answer::displayAnswer()
{
	cout << "Your answer is " << answer << endl; 
}
	/* Problem::Problem(int new_max_tries, int new_op_max_limit)
						: sentence(new_op_max_limit), max_tries(new_max_tries)
						{ 
						  nr_incorrect_answers = 0;
						}
			*/
Problem::Problem(int new_max_tries, int new_op_max_limit)
: sentence(new_op_max_limit), max_tries(new_max_tries)
{
	max_tries = new_max_tries;
	setMaxLimit(new_op_max_limit);
	nr_incorrect_answers = 0;
	nr_correct_answers = 0;
	 
}

void Problem::setNewProblem() // mutator function
{
	sentence.new_operands();
	sentence.display();
}
// ask the user for a correct answer up to 
// max_tries times; then return the number of
// incorrect tries
// mutator function
int Problem::solveProblem()  
{
	int tries = 0; 
	nr_incorrect_answers = 0;
	nr_correct_answers  = 0;
	
	while(tries< max_tries)
	{
		last_answer.enterValidAnswer(); 
		if(sentence.check_result(last_answer.getAnswer()))
		{
			nr_correct_answers=1; 
			return tries; 
		}
		else
		{
			tries++;
			nr_incorrect_answers++;
			if(tries == max_tries -1) 
				sentence.hint(); 
		}
	}
	if(tries==max_tries) 
		cout << "The correct answer is " << sentence.get_result() << endl; 
	return tries; 
}

int Problem::getNrCorrect() const
{
	return nr_correct_answers; 
}

// accessor function						 							
int Problem::getNrIncorrect() const
{
	return nr_incorrect_answers;
}	
// print hint // accessor function	
void Problem::printHint() const
{
	sentence.hint(); 
}
// accessor function		
void Problem::display() const
{
	sentence.display(); 
}
			
void Problem::setMaxLimit(int new_op_max_limit)   // mutator function
{
	sentence.set_max_limit(new_op_max_limit); 
}
//mutator function
//changes the data of calling object
void Problem::setMaxTries(int new_max_tries)
{
	new_max_tries = max_tries;
}
//accessor function = does not change
//the data members of a calling object
int Problem::getMaxLimit() const     
{
	return sentence.get_max_limit();
} 
int Problem::getLastAnswer() const   // accessor function
{
	return last_answer.getAnswer();
}

Game::Game(int new_difficulty)
{
	difficulty = new_difficulty ; 
    // initialize the rest	
    prob_replay = 0.8;
    nr_incorrect_pr = 0;
    nr_correct_pr = 0;
} 

// ask user to solve problems repeatedly, until they don't want to play again. 
void Game::playGame()
{
	DiffOptions(); 
	updateDifficulty(); 
	
	while(playAgain())
	{
		updateStats(); 
		//current_pr.setNewProblem(); 
		generate_problem();
		
		current_pr.solveProblem(); 
		
		if (current_pr.getNrIncorrect() > 0)
		   list_incorrect.push_front(current_pr);
		else
			list_correct.push_front(current_pr);
		
	}
	
	printStats(); 
	
}
// ask user if they want to play again. This function will be called inside playGame().
bool Game::playAgain() const 
{
	char choice = 0; 
	cout << "Would you like to play again? Enter Y for yes or N for no" << endl;
	cin >> choice; 
	if (choice == 'Y' || choice == 'y') 
		return true; 
	else 
		return false; 
}

// updates nr_incorrect_consec_pr or nr_correct_consec_prob, nr_incorrect_pr, nr_correct_pr
void Game::updateStats()
{
	nr_incorrect_pr += (current_pr.getNrIncorrect() > 0);
	nr_correct_pr += current_pr.getNrCorrect(); 
}

void Game::printStats() const
{
	cout << "You have " << nr_incorrect_pr << " incorrect problems." << endl; 
	 
	cout << "You have " << nr_correct_pr << " correct problems. " << endl; 
	
	//cout << "Nr incorrect="  << list_incorrect.size() << endl; // ok
	
}

void Game::DiffOptions() 
{
	cout << "Difficulty 1 will go over all times tables from 0-3. " << endl; 
	cout << "Difficulty 2 will go over all times tables from 0-7. " << endl; 
	cout << "Difficulty 3 will go over all times tables from 0-10. " <<endl; 
	cout << "Which difficulty would you like?" << endl; 
}
	 
int Game::chooseDifficulty()
{
	assert(difficulty > 0 && difficulty < 4);
	cin >> difficulty;
	return difficulty; 
}

void Game::updateDifficulty()
{
	int difficulty = chooseDifficulty(); 
	setDifficulty(difficulty);
}
  	 
void Game::setDifficulty(int difficulty)  // sets the difficulty to a new value; assert that new_difficulty is between 1 and 3. // Change the maxLimit for the operands of current_pr;
{
	if(difficulty == 1)
		current_pr.setMaxLimit(3); 
	else if(difficulty == 2) 
		current_pr.setMaxLimit(7); 
	else
		current_pr.setMaxLimit(10); 
}
	 
int Game::getMaxLimit() const  // returns the operands max_limit - actual value is 
{
	return current_pr.getMaxLimit(); 
}

// with prob_random generate a new problem 
//precondition: srand was called and the random seed generator is initiated 
//post condition: this fucntion is called in post game
void Game::generate_problem() 
{
	prob_replay = .3;
	if ((double)rand()/RAND_MAX < 1-prob_replay || list_incorrect.empty())
	{ 
		cout << "NEW PROBLEM" << endl;
		current_pr.setNewProblem();  
	}
	else // pick an incorrect problem to 
	{
		cout << "REPLAY PROBLEM" << endl;
		//find the size of the list_incorrect 
		int size_incorrect = list_incorrect.size(); 
		//pick a random index between 0 and size -1 
		prob_replay = rand() % size_incorrect; 
		
		list<Problem>::iterator it = list_incorrect.begin(); 
		for(int i = 0; i < prob_replay; i++)
			it++; //point to the next node in the list 
		current_pr = *it; //*it access the item stored in the node
		current_pr.display(); 
	}
	
}
			
		
		
		
		
		
