#include <stdio.h>

int compare(char char1[], char char2[]){
    int i = 0;
    while (char1[i] != '\0' && char2[i] != '\0'){
        if(char1[i]!=char2[i]){
            return 0;
        }
        i ++;
    }

    if (char1[i] == '\0' && char2[i] == '\0') {
        return 1;
    }
    return 0;
}
    
int main () {
    char chaine1[100] = "abcdef";
    char chaine2[100] = "abcdef";
    printf("comparaison : %d \n", compare(chaine1, chaine2));
    return 0;
}