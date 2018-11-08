#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "multiplication.h"

using namespace std;

int main()
{
	srand(time(NULL));

   /*cout << "test default constructor \n";  // no input parameters to the new new object
   Multiplication m_default;
   m_default.display();
   cout << "--------------------" << endl;
   
   cout << "test get_result \n";
   cout << "The result of the multiplication of m_default is " 
   		<< m_default.get_result() << endl;
   cout << "--------------------" << endl;
   
   cout << "test specific constructor \n";
   Multiplication m_specific(7); 
   m_specific.display();
   cout << "--------------------" << endl;

   cout << "test get_result \n";
   cout << "The result of the multiplication of m_specific is " 
   		<< m_specific.get_result() << endl;
   cout << "--------------------" << endl;
   
      
   cout << "test check_result \n";
   int user_input;
   cout << "Enter the result of: "; 
   m_default.display();
   cin >> user_input;
   if (m_default.check_result(user_input))
   		cout << "Correct answer \n";
   else
   		cout << "Incorrect answer \n";
   cout << "--------------------" << endl;
   
   cout << "test hint\n";
   m_default.hint();
   cout << "--------------------" << endl;
   
   cout << "test set_max_limit\n";
   m_default.set_max_limit(5);
   m_default.display();
   cout << "--------------------" << endl;
   
   cout <<  "test new_operands \n";
   cout << "Old operands \n";
   m_specific.display();
   cout << endl;
   
   m_specific.new_operands();
   cout << "New operands  \n";
   m_specific.display();
   cout << "--------------------" << endl;
   
   cout <<  "test is_bigger() \n";
   cout << "m_default\n";
   m_default.display();
   cout << "m_specific\n";
   m_specific.display();
   
   cout << "Is m_default bigger than m_specific " <<  
         m_default.is_bigger(m_specific) << endl; 
   cout << "--------------------" << endl;
	
	Answer answers; 
	
	cout << "is the answer valid? " << endl;
	answers.enterValidAnswer(); 
	cout << "--------------------" << endl;
	
	cout << "return the answer " << endl; 
	answers.getAnswer(); 
	cout << "-------------------" << endl; 
	
	cout << " display the answer " << endl; 
	answers.displayAnswer(); 
	cout << "-------------------" << endl; 
	
	
	Problem problem1(3, 10); 
	
	cout << "get a new problem " << endl; 
	problem1.setNewProblem(); 
	cout << "-------------------" << endl; 
	
	cout << "solve the problem " << endl; 
	problem1.solveProblem(); 
	cout << "-------------------" << endl; 
	
	cout << "how many incorrect problems " << endl; 
	cout << problem1.getNrIncorrect() << endl;
	cout << "--------------------" << endl; 
	
	cout << "print hint" << endl; 
	problem1.printHint(); 
	cout << "---------------------" << endl; 
	
	cout << " display " << endl; 
	problem1.display(); 
	cout << "--------------------" << endl; 
	
	cout << " set max limit " << endl; 
	problem1.setMaxLimit(10); 
	cout << "--------------------" << endl; 
	
	cout << " set max tries" << endl; 
	problem1.setMaxTries(4); 
	cout << " -------------------" << endl; 
	
	cout << "get max limit " << endl; 
	cout << problem1.getMaxLimit() << endl; 
	cout << "-------------------" << endl; 
	
	cout << "get the previous answer " << endl; 
	cout << problem1.getLastAnswer() << endl; 
	cout << "-------------------" << endl; 
 
	Game game1(3); 
	
	cout<< "Play again "<< endl; 
	game1.playAgain(); 
	cout << "------------------" << endl;
	
	cout << "play game" << endl; 
	game1.playGame(); 
	cout << "------------------" << endl; 
	
	cout << "print stats " << endl; 
	game1.printStats(); 
	cout << "------------------" << endl; 
	
	cout <<"choose difficulty" << endl; 
	game1.chooseDifficulty(); 
	cout << "------------------" << endl;
	
	cout << " set difficulty " << endl; 
	game1.setDifficulty(2); 
	cout << "------------------" << endl;
	
	cout << " update difficulty " << endl; 
	game1.updateDifficulty(); 
	cout << "------------------" << endl;
	
	cout << "get max limit " << endl; 
	cout << game1.getMaxLimit() << endl; 
	cout << "------------------" << endl;
	*/
	
	Game m(1);
	
	m.playGame(); 
	
}
