//
// Created by Abdul Aziz Ibrahim on 4/8/21.
//

#include "DelimiterStack.h"
#include <iostream>
using namespace std;

DelimiterStack::~DelimiterStack() {
    DelimiterNode* nodePtr = nullptr, *nextNode = nullptr;
    nodePtr = top;
    while (nodePtr != nullptr){
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

void DelimiterStack::push(char c, int linenumber, int charcount) {
    DelimiterNode* newNode = nullptr;
    newNode = new DelimiterNode;
    newNode->character = c;
    newNode->lineNumber = linenumber;
    newNode->charCount = charcount;
    if (isEmpty()){
        top = newNode;
        newNode->next = nullptr;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
}

void DelimiterStack::pop(char &c, int &linenumber, int &charcount) {
    DelimiterNode* temp = nullptr;
    if (isEmpty()){
        cout << "The stack is empty. \n";
    }
    else{
        c = top->character;
        linenumber = top->lineNumber;
        charcount = top->charCount;
        temp = top->next;
        delete top;
        top = temp;
    }
}

bool DelimiterStack::isEmpty() {
    bool status;
    if (!top){
        status = true;
    }
    else{
        status = false;
    }
    return status;
}
