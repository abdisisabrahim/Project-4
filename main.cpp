/*
Name: CS_2250_Project4.cpp
Author: Abdisis Abrahim
Description: This program has a stack which takes in delimiters and push the left one and pops them whnever the right one appears and compare them.
It will then output whenever the delimiters don't match. Also, it checks if the stack is empty and outputs the delimiters that don't have anything
it.
 */

#include <iostream>
#include "DelimiterStack.h"
using namespace std;

void checkDelim(string, DelimiterStack&, int);  //This function checks for delimiters in the input.
void isStackEmpty( DelimiterStack&);  // This functions checks if the stack is empty

int main() {
    int line =0;
    string input;
    DelimiterStack stack;
    // This loop takes the input of the user and execute it in the functions and outputs.
    do {
        cout << "Enter your input below." << endl;
        getline(cin, input);
        line++;
        checkDelim(input, stack, line);
        cout << endl;
        cout << "Type DONE when your finished." << endl;
    } while (input != "DONE");

    isStackEmpty(stack);

    return 0;
}
//This function takes in the string input of the user and the class delimiter and the line
void checkDelim(string input, DelimiterStack& stack, int line){
    char c;
    int num;
    int count;

    for (int i = 0; i < input.length(); ++i) {
        // The switch statement takes in the left delimiters and push it in the stack and pops it when it encounters and right delimiter and compare it.
        switch (input[i]) {
            case '(':
            case '[':
            case '{':
                stack.push(input[i], line, i+1);

                break;
            case ')':
                if (stack.isEmpty()){
                    cout << "Right Delimiter ) had no left delimiter found at line " << line << ", char " << i +1 << endl;
                }
                else{

                    stack.pop(c, num, count);
                    if (c != '('){
                        cout << "Mismatched delimiter " << c << " found at line " << num <<  ", char " << count << " does not match ) found at line " << line << ", char " << i +1 << endl;
                    }
                }
                break;
            case ']':
                if (stack.isEmpty()){
                    cout << "Right Delimiter ] had no left delimiter found at line " << line << ", char " << i +1 << endl;
                }
                else{

                    stack.pop(c, num, count);
                    if (c != '['){
                        cout << "Mismatched delimiter " << c << " found at line " << num <<  ", char " << count << " does not match ] found at line " << line << ", char " << i +1 << endl;
                    }
                }
                break;
            case '}':
                if (stack.isEmpty()){
                    cout << "Right Delimiter } had no left delimiter found at line " << line << ", char " << i +1 << endl;
                }
                else{

                    stack.pop(c, num, count);
                    if (c != '{'){
                        cout << "Mismatched delimiter " << c << " found at line " << num <<  ", char " << count << " does not match } found at line " << line << ", char " << i +1 << endl;
                    }
                }
                break;

            default:
                break;
        }

    }

}
// This function checks if the stack is empty and outputs when there is a left delimiter but no right delimiter.
void isStackEmpty( DelimiterStack& stack){
    char c;
    int num;
    int count;
    while (!stack.isEmpty()){
        stack.pop(c, num, count);
        cout << "Left Delimiter " << c << " at line " << num << ", char " << count << " had no right delimiter" << endl;

    }
}