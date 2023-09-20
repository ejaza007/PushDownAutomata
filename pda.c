// For the implementation of three different PDA machines.
//
// Modified by <your-name-here>
//

#include "pda.h"
#include "list.h"
#include "stack.h"

struct list_node *list = NULL;

int PDA1 (char *str) {

    enum state state = S0; // set the starting state
    // enum state accepting_state = ???; // set the accepting state

    // initialize the stack to NULL
    struct stack_node *stack = NULL;

    int cnt = 0;

    while (str[cnt]) {
        if (state == S0) {
            if (str[cnt] == 'a') {
                stack = push(stack, 'a');
            } else if (str[cnt] == 'b') {
                state = S1;
            }
        }
       if (state == S1) {
            if (peek(stack) == 'a') {
                stack = pop(stack);
            } else {
                return 0;
            }
        }
        cnt++;
    }
    if(peek(stack) == 'a'){
        return 0;
    }
    return 1;
}

int PDA2 (char *str) {
    enum state state = S0; // set the starting state
    // enum state accepting_state = ???; // set the accepting state

    // initialize the stack to NULL
    struct stack_node *stack = NULL;

    int cnt = 0;

    while (str[cnt]) {

            if (str[cnt] == '(') {
                stack = push(stack, '(');
            } else if (str[cnt] == ')') {
                if(peek(stack) == '(')
                stack = pop(stack);
                else{
                    return 0;
                }
            }

        cnt++;
    }

    if(peek(stack) == '('){
        return 0;
    }

    return 1;
}



int PDA3(char *str) {
    int cnt = 0;
    int scopeCnt = -1;
    struct stack_node *popper = NULL;
    struct stack_node *stack = NULL;
    struct list_node *head = NULL;
    struct list_node *curr = NULL;
    //struct list_node *current = NULL;
    head = generate_list_node('x');
    insert(head, 'y');
    insert(head, 'z');


    while (str[cnt]) {
        switch (str[cnt]) {
            case '{':
                stack = push(stack, '{');
                scopeCnt++;
                break;

            case '}':

                if(peek(stack) == '{')
                    stack = pop(stack);
                else{
                    return 0;
                }

                curr = head;
                while(curr!=NULL){


                    if(peek(curr->stack) == scopeCnt + '0'){
                        curr->stack  = pop(curr->stack);
                    }
                    curr = curr->next;

                }

                scopeCnt--;
                break;



            case 'i':
                cnt++;

                if (str[cnt] == 'x') {
                    head->stack = push(head->stack, scopeCnt + '0');
                    printf("init x level %d\n", scopeCnt);
                } else if (str[cnt] == 'y') {
                    head->next->stack = push(head->next->stack,scopeCnt + '0');
                    printf("init y level %d\n", scopeCnt);
                } else if (str[cnt] == 'z') {
                    head->next->next->stack= push(head->next->next->stack, scopeCnt + '0');
                    printf("init z level %d\n", scopeCnt);
                }
                break;

            case 'x':
                if(peek(head->stack) != '\0') {
                    printf("read x  level %c\n", peek(head->stack));
                }
                else{
                    printf("String is invalid\n");
                    return 0;
                }
                break;

            case 'y':
                if (peek(head->next->stack) != '\0') {
                    printf("read y level %c\n", peek(head->next->stack));
                }
                else{
                    printf("String is Invalid\n");
                    return 0;
                }
                break;

            case 'z':
                if (peek(head->next->next->stack) != '\0') {
                    printf("read z  level %c\n", peek(head->next->next->stack));
                }
                else{
                    printf("String is invalid\n");
                    return 0;
                }
                break;
        }

        cnt++;
    }

if(peek(stack) =='{'){
    printf("String is invalid\n");
    return 0;

}


    printf("String is Valid\n");

    return 1; // Input is valid
}





