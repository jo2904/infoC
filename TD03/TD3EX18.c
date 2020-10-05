#include <stdio.h>
#include <string.h>

int main(){
  int min = 10000, max = 45000, c=0;
  char test;
  
  while(c==0){
  
  printf("%d ?", (min+max)/2);
  scanf(" %c", &test);

  if(test == '='){
    printf("J'ai trouvé !!\n");
    break;
  }
  if(test == '+')
    min = (min+max)/2;
  if(test == '-')
    max = (min+max)/2;
  }
}
