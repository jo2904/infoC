#include <stdio.h>

int main(){


  float x=0, y=0, z;
  int a=0;

  printf("code 1\n");
  if ((x!=0) && ((1/x)>2))
    printf ("C'est plus grand\n");
  if (((1/x)>2) && (x!=0))
    printf ("Vraiment plus grand\n");

  printf("code 2\n");
  if (!(x==y))
    z = 1/(x-y);
  else
    z = 0;

  printf("code 3\n");
  if (a!=0)
    printf ("a ne vaut pas 0\n");


  printf("code 4\n");
  if (a==0)
    printf ("a vaut 0\n");
}
