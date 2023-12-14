// A palindrome is a string of character that‘s the same forward and backward.
// Typically, punctuation, capitalization, and spaces are ignored. For example, “Poor
// Dan is in a droop” is a palindrome, as can be seen by examining the characters
// “poor danisina droop” and observing that they are the same forward and
// backward. One way to check for a palindrome is to reverse the characters in the
// string and then compare with them the original-in a palindrome, the sequence will
// be identical. Write C++ program with functions- a) To print original string followed




// by reversed string using stack b) To check whether given string is palindrome or
// not

#include <iostream>
using namespace std;
class strng
{
public:
    char cInp[30], cWSpace[30], cStack[20], cReverse[30];
    int top;

public:
    strng()
    {
        top = -1;
    }
    void Palindrome1();
    void reverse1();
    void push(char);
    char pop();
};
void strng ::push(char element)
{
    if (top < 20)
        cStack[++top] = element;
    else
        cout << "Stack Full";
}
char strng ::pop()
{
    if (top != -1)
        return cStack[top--];
    else
        cout << "Stack Empty";
}
void strng ::Palindrome1()
{
    int i = 0, b = 1;
    cout << "\n\nEnter the String:";
    cin >> cWSpace;
    cout << "\n\nEntered the String is:" << cWSpace;
    while (cWSpace[i] != '\0')
    {
        push(cWSpace[i]);
        i++;
    }
    i = 0;
    while (cWSpace[i] != '\0')
    {
        char ch = pop();
        if (cWSpace[i] != ch)
            b = 0;
        i++;
    }
    if (b == 1)
        cout << "\n\nTHE STRING IS PALINDROME";
    else
        cout << "\n\nTHE STRING IS NOT PALINDROME";
}
void strng ::reverse1()
{
    int i = 0;
    cout << "\nEnter the String:";
    cin >> cWSpace;
    cout << "\nEntered the String is:" << cWSpace;
    while (cWSpace[i] != '\0')
    {
        push(cWSpace[i]);
        i++;
    }
    i = 0;
    while (cWSpace[i] != '\0')
    {
        char ch = pop();
        cReverse[i] = ch;
        i++;
    }
    cReverse[i] = '\0';
    cout << "\nReverse String is:" << cReverse;
    cout << "\n";
}
int main()
{
    strng a;
    a.Palindrome1();
    a.reverse1();
    return 0;
}
