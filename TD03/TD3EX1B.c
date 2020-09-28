#include <stdio.h>

int main(){
  int a=3, b=5, c=1;
  int M, m, n;

  if (a>b){
    M = a;
    m = b; 
  }
  else{
    M = b;
    m = a;
  }
  if (c>M){
    M = c;
  }
  if (c<m){
    m = c;
  }
n = a+b+c-M-m;
printf("m=%d, n=%d, M=%d\n",m,n,M);
}
