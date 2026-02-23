#include "student.h"
#include <stdbool.h>
#include <string.h>

bool isValid(const char *s) {
    char stack[1000];   // stack to store opening brackets
    int top = -1;       // stack pointer

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        // If opening bracket, push to stack
        if (ch == '(' || ch == '{' || ch == '[') {
            stack[++top] = ch;
        }
        // If closing bracket
        else {
            // Stack empty → invalid
            if (top == -1) {
                return false;
            }

            char last = stack[top--];  // pop

            // Check matching pair
            if ((ch == ')' && last != '(') ||
                (ch == '}' && last != '{') ||
                (ch == ']' && last != '[')) {
                return false;
            }
        }
    }

    // If stack empty → valid
    return top == -1;
}