#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char STACK[20];
int top=-1;
void push(char sign){
        STACK[++top]=sign;
}
char pop(){
        return (STACK[top--]);
}
int prec(char sym){
        switch(sym){
                case '^':
                case '$':return 4;
                case '%':
                case '/':
                case '*':return 3;
                case '+':
                case '-':return 2;
                case '(':
                case ')':
                case '#':return 1;
                default:return 0;
}
}
void convertin(char infix[],char postfix[]){
        char symbol;
        int i=0;
        int j=0;
        push('#');
        for(i=0;i<strlen(infix);i++){
                symbol=infix[i];
                switch(symbol){
                        case '(':push(symbol);
                                break;
                        case ')':while(STACK[top]!='c')
                                        postfix[j++]=pop();
					pop();
                                        break;
                        case '^':
                        case '$':
                        case '%':
                        case '/':
                        case '*':
                        case '+':
                        case '-':while(prec(symbol)<=prec(STACK[top])){
                                        postfix[j++]=pop();
                                        push(symbol);}
                                break;
                        default:postfix[j++]=symbol;
        while(STACK[top]!='#')
                postfix[j++]=pop();
                postfix[j++]='\0';
        }
    }
}
void  main(){
        char infix[30],postfix[30];
        printf("Enter INFIX: ");
        gets(infix);
        convertin(infix,postfix);
        printf("POSTFIX: %s\n",postfix);
}
