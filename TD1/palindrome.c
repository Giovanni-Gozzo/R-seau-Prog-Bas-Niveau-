#include <stdio.h>
#include <string.h>
int palindrome(char *s){
    for(int i=0;i<strlen(s);i++){
        if(s[i]!=s[strlen(s)-(i+1)]){
            return 0;
        }
    }
    return 1;
}
int main(){
    printf("%i", palindrome("ma"));
}