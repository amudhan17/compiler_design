#include <stdio.h>
#include <string.h>
#define M 100
char s[M]; int p[M]; char o[M]; int n; char T='Z';

char get(int i,int d){
    while(i>=0 && s[i] && !strchr("+-*/=:",s[i])){
        if(s[i]!='$'){ char c=s[i]; s[i]='$'; return c; }
        i+=d;
    } return '?';
}

int main(){
    printf("Enter the Expression: ");
    scanf("%s",s);
    char prec[]=":/*+-";
    for(int k=0;k<5;k++) for(int i=0;s[i];i++) if(s[i]==prec[k]){p[n]=i;o[n++]=s[i];}
    for(int k=0;k<n;k++){
        char L=get(p[k]-1,-1),R=get(p[k]+1,1);
        printf("%c := %c %c %c\n",T,L,o[k],R);
        s[p[k]]=T--;
    }
    char r=get(0,1),l=get(strlen(s)-1,-1);
    printf("%c := %c\n",r,l);
}
