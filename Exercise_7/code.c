#include <stdio.h>
#include <string.h>
#define MAX 20
struct Exp { char l; char r[20]; } code[MAX], opt[MAX];
int main() {
    int n,i,j,k=0;
    printf("Enter no. of expr: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("[%d] LHS: ",i+1);
        scanf(" %c",&code[i].l);
        printf("    RHS: ");
        scanf("%s",code[i].r);
    }
    printf("\n-- Original Code --\n");
    for(i=0;i<n;i++) printf("%c=%s\n",code[i].l,code[i].r);
    for(i=0;i<n;i++){
        int used=0;
        for(j=i+1;j<n;j++) if(strchr(code[j].r,code[i].l)){ used=1; break; }
        if(used||i==n-1) opt[k++]=code[i];
    }
    printf("\n After DCE \n");
    for(i=0;i<k;i++) printf("%c=%s\n",opt[i].l,opt[i].r);

    for(i=0;i<k;i++) for(j=i+1;j<k;j++)
        if(strcmp(opt[i].r,opt[j].r)==0){
            char x=opt[j].l; opt[j].l=0;
            for(int m=j+1;m<k;m++){ char*p=strchr(opt[m].r,x); if(p) *p=opt[i].l; }
        }
    printf("\n After CSE \n");
    for(i=0;i<k;i++) if(opt[i].l) printf("%c=%s\n",opt[i].l,opt[i].r);
    return 0;
}
