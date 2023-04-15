#include <stdio.h>

int estPalindrome(char *s){
    int i=-1, j=0;
    while(s[i+1] != '\n'){
        i++;
    }
    while(j<i){
        if(s[i] != s[j]){
            printf("s[j] = %c != %c = s[i]\n",s[j],s[i]);
            return 0;
        }
        j++;
        i--;
    }
    return 1;
}

int main(){
    char chaine[80];
    printf("Entrez une chaîne: ");
    fgets(chaine, 80, stdin);
    printf("%i\n",  estPalindrome(chaine));
}