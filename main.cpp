#include <iostream>
#include "DelimiterStack.h"
using namespace std;

void CheckDelim(string, DelimiterStack&, int);


int main() {
    char delimiter;
    int line =0;
    int counter;
    string input;
    DelimiterStack stack;
    do {
        cout << "" << endl;
        getline(cin, input);
        line++;
        CheckDelim(input, stack, line);
    } while (input != "DONE");



    return 0;
}
void CheckDelim(string input, DelimiterStack& stack, int line ){
    char c;
    int num;
    int count;
    for (int i = 0; i < input.length(); ++i) {
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

//
}