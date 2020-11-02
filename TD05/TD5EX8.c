#include <stdio.h>
#include <math.h>

int fonctionpuissancePointeur(int* pa, int n){
   *pa = pow(*pa, n);
   return 0;
}

int fonctionechange(char c1, char c2){
   char temp = c2;
   char * pc1= &c1, * pc2=&c2;
   *pc2 = *pc1;
   *pc1 = temp;
   return 0;
}

int main(){
  int a= 1849;
  float n=0.5;
  int * pa = &a;
  fonctionpuissancePointeur(pa, n);
  printf("%d", *pa);
  
  char c1='r', c2='k';
  fonctionechange(c1, c2);
}
