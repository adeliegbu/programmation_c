
#include <stdio.h>

int main() {
    int num1;
    printf("Saisissez un entier : ");
    scanf("%d", &num1);  // On demande à l'utilisateur de saisir un entier
    int num2;
    printf("Saisissez un second entier : ");
    scanf("%d", &num2);  // On demande à l'utilisateur de saisir un second entier
    char op;
    printf("Saisissez un opérateur : ");
    scanf(" %c", &op);  // On demande à l'utilisateur de saisir un opérateur (+, -, *, /, %, &, |, ~)

    switch (op) {
        case '+' : 
            printf("%d %c %d = %d\n", num1, op, num2, (num1 + num2));  // On affiche le résultat de l'opération
            break;  // On sort du switch quand l'opérateur a été trouvé
        case '-' : 
            printf("%d %c %d = %d\n", num1, op, num2, (num1 - num2));
            break;
        case '*' :
            printf("%d %c %d = %d\n", num1, op, num2, (num1 * num2));
            break;
        case '/' :
            printf("%f %c %f = %f\n", (float)num1, op, (float) num2, (float)(num1 / num2));
            break;
        case '%' :
            printf("%d %c %d = %d\n", num1, op, num2, (num1 % num2));
            break;
        case '&' :
            printf("%d %c %d = %d\n", num1, op, num2, (num1 & num2));
            break;
        case '|' :
            printf("%d %c %d = %d\n", num1, op, num2, (num1 | num2));
            break;
        case '~' :
            printf("%c %d = %d\n", op, num1, ~num1);
            printf("%c %d = %d\n", op, num2, ~num2);	
            break;
    }
    return 0;
}