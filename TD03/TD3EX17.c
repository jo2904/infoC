#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
  int a = 10000, b = 450000, c, d, temps1;  
  time_t seconds;
  temps1 = time(NULL);

  do{
  c = (int)((float)b*rand()/RAND_MAX);
  }while(a>c);


  while(time(NULL)<temps1+45){
    printf("Donner un prix entre 10000€ et 45000€\n");
    scanf("%d", &d);
    if (c==d){
      printf("WIN!!\n");
      d = 0;
      break;
    }
    if(c<d){
      printf("plus petit\n");
    }
    if(c>d){
      printf("plus grand\n");
    }
  }
  if(d!=0)
    printf("trop tard\nle prix était %d\n", c);
  }
