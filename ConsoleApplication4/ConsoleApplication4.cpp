// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "tictactoe.h"
#include "AI.h"
int main()
{
    tictactoe s;
    s.input(0, 0, 'p');
    s.input(1, 0, 'p');
    s.input(2, 0, 'c');
    AI ai;
    ai.initalise();
    std::vector<double> input1 = { 0.02,0.05,1 };
    std::vector<double>target1 = { 1,0 };
    std::vector<double> input2 = { 1,0.03,0.1 };
    std::vector<double>target2 = { 0,1 };
    
    int i = 0;
    while (i<9000) {
        ai.forwardPropagate(input1);
        ai.backPropagate(target1);

        //ai.forwardPropagate(input2);
       // ai.backPropagate(target2);
        i++;        
    }
    ai.forwardPropagate(input1);
    ai.printNetwork();
    ai.forwardPropagate(input2);
    ai.printNetwork();
    
   
    //s.print();
   // std::cout << "Hello World!\n";
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
