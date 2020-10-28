#include <stdio.h>
#include <math.h>

int racine(int a, int b, int c){
  int discriminant;
 
  discriminant = (b*b)-(4*a*c);
  
  if (discriminant>0){
    printf("x1= %f\n", (-b-sqrt(discriminant))/2*a);
    printf("x1= (%d-rac(%d))/2\n", -b, discriminant);
    printf("x2= %f\n", (-b+sqrt(discriminant))/2*a);
    printf("x1= (%d-rac(%d))/2\n", -b, discriminant);
  }
  if (discriminant==0)
    printf("x= %d\nx= %d/2\n", (-b/2), -b);
  if (discriminant<0)
    printf("pas de solution\n");
  return 1;
 }
 
 int main(){
   int a, b, c;
  printf("Resolution de ax2+bx+c = 0\n");
  printf("a= ");
  scanf("%d", &a);
  printf("b= ");
  scanf("%d", &b);
  printf("c= ");
  scanf("%d", &c);
  racine(a, b, c);
}
