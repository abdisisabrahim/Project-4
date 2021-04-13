#include <iostream>
#include "DelimiterStack.h"
using namespace std;

void checkDelim(string, DelimiterStack&, int);
void isStackEmpty( DelimiterStack&);

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
        checkDelim(input, stack, line);
    } while (input != "DONE");

    isStackEmpty(stack);

    return 0;
}
void checkDelim(string input, DelimiterStack& stack, int line){
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

}

void isStackEmpty( DelimiterStack& stack){
    char c;
    int num;
    int count;
    while (!stack.isEmpty()){
        stack.pop(c, num, count);
        cout << "Left Delimiter " << c << " at line " << num << ", char " << count << " had no right delimiter" << endl;

    }
}