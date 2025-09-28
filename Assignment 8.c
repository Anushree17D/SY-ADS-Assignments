#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100
char infix[MAX], postfix[MAX], prefix[MAX];

char stack[MAX];
int top = -1;

void push(char c){
    stack[++top] = c;
}

int pop(){
    return stack[top--];
}

int isEmpty(){
    if(top==-1) return 1;
    else return 0;
}

int peek(){
    return stack[top];  
}

int precedence (char c){
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

void InfixToPostfix (char infix[], char postfix[]){
    int j = 0;
    for (int i = 0; i < strlen(infix); i++){
        char c = infix[i];
        if(isalnum(c)){
            postfix[j++] = c;
        }

        else if(c == '('){
            push(c);
        }

        else if (c == ')'){
            while (!isEmpty() && peek()!= '('){
                postfix[j++] = pop();
            }
            pop();
        }

        else{
            while(!isEmpty() && precedence(peek()) > precedence(c)){
                postfix[j++] = pop();
            }
            push(c);
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

void reverse(char str[]){
    int n = strlen(str);
    for (int i = 0; i < n/2; i++){
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }

    for (int i = 0; i < n; i++){
        if (str[i] == '(') str[i] = ')';
        else if (str[i] == ')') str[i] = '(';
    }
}

void InfixToPrefix(char infix[], char prefix[]){
    char revInfix[MAX], revPostfix[MAX];
    strcpy(revInfix, infix);

    reverse(revInfix);
    InfixToPostfix(revInfix,revPostfix);
    reverse(revPostfix);

    strcpy(prefix, revPostfix);
}

int postfixEval(char postfix[]){
    for (int i = 0; i < strlen(postfix); i++){
        char c = postfix[i];

        if(isdigit(c)){
            push(c -'0');
        }else{
            int val2 = pop();
            int val1 = pop();

            switch (c){
                case '+':
                push(val1 + val2);
                break;
                case '-':
                push(val1 - val2);
                break;
                case '*':
                push(val1 * val2);
                break;
                case '/':
                push(val1 / val2);
                break;
                case '^':
                push(pow(val1, val2));
                break;
            }
        }
    }
    return pop();
}

int prefixEval(char prefix[]){
    for (int i = strlen(prefix); i <= 0; i++){
        char c = prefix[i];

        if(isdigit(c)){
            push(c -'0');
        }else{
            int val1 = pop();
            int val2 = pop();

            switch (c){
                case '+':
                push(val1 + val2);
                break;
                case '-':
                push(val1 - val2);
                break;
                case '*':
                push(val1 * val2);
                break;
                case '/':
                push(val1 / val2);
                break;
                case '^':
                push(pow(val1, val2));
                break;
            }
        }
    }
    return pop();
}
 
int main() {
    int choice;
    printf ("---Expression Arithmetics---\n");
    printf ("1. Infix -> Postfix\n");
    printf ("2. Infix -> Prefix\n");
    printf ("3. Postfix Evaluation\n");
    printf ("4. Prefix Evaluation\n");
    printf ("Enter your choice: \n");
    scanf ("%d", &choice);

    switch(choice){
        case 1:
        printf ("Enter the Infix Expression: \n");
        scanf ("%s", infix);
        InfixToPostfix(infix,postfix);
        printf ("Equivalent Postfix Expression is: \n%s",postfix);
        break;

        case 2:
        printf ("Enter the Infix Expression: \n");
        scanf ("%s", infix);
        InfixToPrefix(infix,prefix);
        printf ("Equivalent Prefix Expression is: \n%s",prefix);
        break;

        case 3:
        printf ("Enter postfix expression: ");
        scanf ("%s", postfix);
        int posResult = postfixEval(postfix);
        printf ("Evaluated Result:\n%d",posResult);

        case 4:
        printf ("Enter prefix expression: ");
        scanf ("%s", prefix);
        int preResult = prefixEval(prefix);
        printf ("Evaluated Result:\n%d",preResult);
    }

    return 0;
}
