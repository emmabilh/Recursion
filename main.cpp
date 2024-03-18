// Emma Bilhimer
// Lab Name: Recursion
// Busch SP24
// Due March 18, 2024
/*Description: Write a program that will reverse the order of a stack. For this lab,
 you will use your stack class and you’re not allowed to use any C++ loops. You must use
recursion.
*/

#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int x) { // insert an element at the bottom of a stack
    if (s.empty()) {                        // base case //copilot

        s.push(x);
        return;
    }
    
                                            // pop all elements and insert the element at the bottom
    int temp = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(temp);
}

// Function to reverse a stack
void reverseStack(stack<int> &s) {
    // Base case: if the stack is not empty, pop the top element and call reverseStack again
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        reverseStack(s);
        
                                        // insert the popped element at the bottom
        insertAtBottom(s, x);
    }
}

int main() {
    stack<int> s;                       // creates a stack and push some elements onto it

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "OG Stack: ";         //print original stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    reverseStack(s);                    //reverse the stack

                                        // print the reversed stack
    cout << "Reversed Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}



