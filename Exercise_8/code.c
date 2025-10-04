#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int L[20],n;int chk(int k){for(int i=0;i<n;i++)if(k==L[i])return 1;return 0;}
void h(FILE*f1,FILE*f2,char o,char*A,char*B,char*R){
 fscanf(f1,"%s%s%s",A,B,R);
 fprintf(f2,"\n\tLOAD %s,R0\n\tLOAD %s,R1",A,B);
 fprintf(f2,"\n\t%s R1,R0",o=='+'?"ADD":o=='-'?"SUB":o=='*'?"MUL":"DIV");
 fprintf(f2,"\n\tSTORE R0,%s",R);
}
int main(){
 FILE*f1,*f2;char fn[20],op[10],A[8],B[8],R[8],c;int i=0;
 printf("File: ");scanf("%s",fn);
 if(!(f1=fopen(fn,"r"))||!(f2=fopen("target.txt","w")))return 0;
 while(fscanf(f1,"%s",op)!=EOF){
  if(chk(++i))fprintf(f2,"\nlabel#%d",i);
  if(!strcmp(op,"print")){fscanf(f1,"%s",R);fprintf(f2,"\n\tOUT %s",R);}
  else if(!strcmp(op,"goto")){fscanf(f1,"%s%s",A,B);fprintf(f2,"\n\tJMP %s,label#%s",A,B);L[n++]=atoi(B);}
  else if(!strcmp(op,"[]=")){fscanf(f1,"%s%s%s",A,B,R);fprintf(f2,"\n\tSTORE %s[%s],%s",A,B,R);}
  else if(!strcmp(op,"uminus")){fscanf(f1,"%s%s",A,R);fprintf(f2,"\n\tLOAD -%s,R1\n\tSTORE R1,%s",A,R);}
  else if(strchr("+-*/%",op[0]))h(f1,f2,op[0],A,B,R);
  else if(op[0]=='='){fscanf(f1,"%s%s",A,R);fprintf(f2,"\n\tSTORE %s %s",A,R);}
  else if(op[0]=='>'||op[0]=='<'){fscanf(f1,"%s%s%s",A,B,R);fprintf(f2,"\n\tLOAD %s,R0\n\tJ%cT %s,label#%s",A,op[0]=='>'?'G':'L',B,R);L[n++]=atoi(R);}
 }
 fclose(f1);fclose(f2);
 f2=fopen("target.txt","r");while((c=fgetc(f2))!=EOF)putchar(c);fclose(f2);
}
