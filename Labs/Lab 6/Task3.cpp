#include <iostream>
#include <string>
using namespace std;

const int MAX_LENGTH = 20;

char items[MAX_LENGTH];
int top = -1;

void push(char ch)
{
    if (top == MAX_LENGTH - 1)
    {
        cout << "Stack Overflow: cannot push '" << ch << "'." << endl;
        return;
    }

    top++;
    items[top] = ch;
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }

    char ch = items[top];
    top--;
    return ch;
}

int main()
{
    cout << "===== Task 3: Reverse a Word Using a Stack =====" << endl << endl;

    string word;
    cout << "Enter a word (maximum " << MAX_LENGTH << " characters): ";
    cin >> word;

    if (word.length() > MAX_LENGTH)
    {
        cout << "Error: the word has " << word.length()
             << " characters, which exceeds the limit of " << MAX_LENGTH << "." << endl;
        return 0;
    }

    for (int i = 0; i < (int)word.length(); i++)
    {
        push(word[i]);
    }

    cout << "Reversed word: ";
    while (top != -1)
    {
        cout << pop();
    }
    cout << endl;

    return 0;
}
