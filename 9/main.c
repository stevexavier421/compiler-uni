#include <stdio.h>
#include <string.h>

char inp[100];
int threecode_start_index = 0;
char threecode[100][100];

int evaluate(char expression[], int start_index, int three_code_start_index);

void printThreeCode(char expression[]) {
    strcpy(threecode[threecode_start_index], expression);
    printf("t%d := %s\n", threecode_start_index, expression);
    threecode_start_index++;
}

int main() {
    printf("Enter expression: ");
    scanf("%s", inp);
    evaluate(inp, 0, 0);
    return 0;
}

int evaluate(char expression[], int start_index, int three_code_start_index) {
    char parenthesis[100] = {0};
    char items[100] = "";
    char next_term[100] = "";
    char operation = '\0';
    char previous_operation = '\0';
    char previous_previous_term[100] = "";
    char previous_term[100] = "";
    char expr[100] = "";
    int i = start_index;

    while (i < strlen(expression)) {
        if (expression[i] == '(') {
            three_code_start_index = evaluate(expression, i + 1, three_code_start_index);
            strcat(expr, threecode[three_code_start_index]);
            strcat(previous_term, threecode[three_code_start_index]);
            i++;
        }
        else if (expression[i] == ')') {
            three_code_start_index++;
            strcpy(threecode[three_code_start_index], expr);
            printf("t%d := %s\n", three_code_start_index, expr);
            strcpy(expr, threecode[three_code_start_index]);
            return three_code_start_index;
        }
        else if (expression[i] == '*' || expression[i] == '+' || expression[i] == '/' || expression[i] == '-') {
            strncat(expr, &expression[i], 1);
            if (operation == '\0') {
                operation = expression[i];
            }
            else if (((operation == '+' || operation == '-') && (expression[i] == '+' || expression[i] == '-')) ||
                     ((operation == '*' || operation == '/') && (expression[i] == '*' || expression[i] == '/')) ||
                     ((operation == '*' || operation == '/') && (expression[i] == '+' || expression[i] == '-'))) {
                three_code_start_index++;
                sprintf(threecode[three_code_start_index], "%s%c%s", previous_term, operation, next_term);
                printf("t%d := %s%c%s\n", three_code_start_index, previous_term, operation, next_term);
                strcpy(next_term, "");
                operation = expression[i];
                sprintf(expr, "t%d%c", three_code_start_index, operation);
                strcpy(previous_term, threecode[three_code_start_index]);
            }
            else if ((operation == '+' || operation == '-') && (expression[i] == '*' || expression[i] == '/')) {
                if (previous_operation == '\0') {
                    strcpy(previous_previous_term, previous_term);
                    previous_operation = operation;
                    operation = expression[i];
                    strcpy(previous_term, next_term);
                    strcpy(next_term, "");
                }
                else {
                    // Handle case: previous_operation == '+' or '-' and operation == '*' or '/'
                    three_code_start_index++;
                    sprintf(threecode[three_code_start_index], "%s%c%s", previous_previous_term, previous_operation, previous_term);
                    printf("t%d := %s%c%s\n", three_code_start_index, previous_previous_term, previous_operation, previous_term);
                    strcpy(previous_previous_term, threecode[three_code_start_index]);
                    previous_operation = operation;
                    operation = expression[i];
                    strcpy(previous_term, next_term);
                    strcpy(next_term, "");
                }
            }
            else {
                // Handle case: previous_operation == '*' or '/' and operation == '+' or '-'
                three_code_start_index++;
                sprintf(threecode[three_code_start_index], "%s%c%s", previous_term, operation, next_term);
                printf("t%d := %s%c%s\n", three_code_start_index, previous_term, operation, next_term);
                strcpy(previous_term, threecode[three_code_start_index]);
                operation = expression[i];
                strcpy(next_term, "");
                strcat(expr, &operation);
            }
        }
        else {
            strncat(expr, &expression[i], 1);
            if (operation == '\0') {
                strcat(previous_term, &expression[i]);
            }
            else {
                strcat(next_term, &expression[i]);
            }
        }
        i++;
    }
    return three_code_start_index;
}
