//
// Created by Abdul Aziz Ibrahim on 4/8/21.
//

#ifndef DELIMITERSTACK_H
#define DELIMITERSTACK_H


class DelimiterStack {
private:
    struct DelimiterNode {
        char character;
        int lineNumber;
        int charCount;
        DelimiterNode* next;    // points to the next node
    };
    DelimiterNode* top; // This is the top of the stack
public:
    DelimiterStack()   //Default constructor
    {top = nullptr; }

    ~DelimiterStack();

    void push(char, int, int);  // This function adds to the stack
    void pop(char &, int&, int&);   // This function removes from the stack
    bool isEmpty();     // This function checks if the stack is empty
};


#endif //UNTITLED8_DELIMITERSTACK_H
