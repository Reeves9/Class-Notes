//nfa for string starting with 01
#include <stdio.h>

enum states {q0,q1,qf,f};
int flag=0;

enum states delta(enum states s, char ch){
    enum states curr_state;
    switch(s){
        case q0:
            if(ch == '0'){
                curr_state = q1;
            }else{
                curr_state = f;
            }
        break;
        case q1:
            if(ch == '1'){
                curr_state = qf;
            }else{
                curr_state = f;
            }
        break;
        case qf:
            if(ch == '0'){
                curr_state = qf;
            }else{
                curr_state = qf;
            }
        break;
        
    }
    return curr_state;
}
int main(){
    char input[20];
    enum states curr_state = q0;
    int i=0;

    printf("Enter binary string:\t");
    scanf("%s",&input);
    char ch = input[i];
    while(ch != '\0'){
        curr_state = delta(curr_state,ch);
        ch = input[++i];
        if(curr_state == f)
            break;
    }

    if(curr_state == qf){
        printf("String is accepted!");
    }else{
        printf("String is not acceped");
    }
    return 0;
}