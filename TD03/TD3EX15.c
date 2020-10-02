#include <stdio.h>

int main(){
  int i, c, n;
  
  printf("c=");
  scanf("%d", &c);
  
  printf("n=");
  scanf("%d", &n);
  
  for(i=1; i<=n; i++){
    if (c%2 != 0)
      c = 3*c+1;
  }
  printf("U%d= %d", n, c);
  }
