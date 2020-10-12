#include <stdio.h>

int main(){
  float a=13.37, v;
  printf("v= ");
  scanf("%f", &v);
  if(v<a){
    printf("erreure\n");
  }
  else{
    printf("%0.2f\n", v-a);
  }
}
