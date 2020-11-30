#include <stdio.h>

int taille(int tableau[]){
  int i=0;
  while(tableau[i] != '\0'){
    i++;
  }
  return i;
}

void tri_bulle(int tableau[]){
  for(int i = 0; i<taille(tableau); i++){
      for(int j =0; j<taille(tableau); j++){
       if(tableau[j] > tableau[j+1]){
         int temp = tableau[j];
          tableau[j] = tableau[j+1];
          tableau[j+1] = temp;
        }
     }
   }
}

void tri_select(int tableau[]){
  for(int i = 0; i < taille(tableau); i++){
    int temp = tableau[i];
    int temp2 = i;
    for(int j = i+1; j < taille(tableau); j++){
      if(temp > tableau[j]){
        temp = tableau[j];
        temp2 = j;
      }
      tableau[j] = tableau[i];
      tableau[i] = temp;     
    }
  }
}

void tri_insertion(int taleau){
  

int main(){
  int tableau[9] = {4,2,5,3,1,9,8,6,7};
  tri_select(tableau);
  for(int i =0; i<taille(tableau); i++){
    printf("%d", tableau[i]);
  }
}
