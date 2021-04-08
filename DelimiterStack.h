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
        DelimiterNode* next;
    };
    DelimiterNode* top;
public:
    DelimiterStack()
    {top = nullptr; }

    ~DelimiterStack();

    void push(char, int, int);
    void pop(char &, int&, int&);
    bool isEmpty();
};


#endif //UNTITLED8_DELIMITERSTACK_H
