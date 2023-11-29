#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Calender{
    char *name, *des;
    int day;
};
typedef struct Calender cal;

cal* create(){
    return((cal* ) malloc(7*sizeof(cal)));
}
void read(cal *d){
    int i, flag;
    for(i=0;i<7;i++){
        d[i].name=NULL;
        d[i].day=-1;
        d[i].des=NULL;
    }
    do{
        printf("Enter the day Number: ");
        scanf("%d",&i);
        if(i<0 || i>6){
            printf("Invalid Input");
        }
        else{
            d[i].day=1;
            printf("Enter the day name and description: ");
            scanf("%s",d[i].name);
            scanf("%s",d[i].des);
        }
        printf("Enter 1 for more activities else 0: ");
        scanf("%d",&flag);
    }while(flag!=0);
}

void display(cal *d){
    printf("Day\t\tDay Number\t\tDescriptions\n");
    for (int i = 0; i <7; i++){
        printf("%s\t\t%d\t\t%s\n",d[i].name,d[i].day,d[i].des);
    }
    
}
int main(){
    cal *d=create();
    read(d);
    display(d);
    free(d);
}