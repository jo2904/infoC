#include <stdio.h>

int taille(int tableau[]){
  int i=0;
  while(tableau[i] != '\0'){
    i++;
  }
  return i;
}

void tri_bulle(int tableau[]){
  int n = taille(tableau);
  for(int i = 0; i<n-1; i++){
      for(int j =0; j<n-1; j++){
       if(tableau[j] > tableau[j+1]){
         int temp = tableau[j];
          tableau[j] = tableau[j+1];
          tableau[j+1] = temp;
        }
     }
   }
}

void triSelection (int tableau[]){
  int n = taille(tableau);
    for(int i = 0; i < n; i++){
        int tmp = i;
        for(int j = i; j < n; j++){
            if(tableau[tmp] > tableau[j]){
                tmp = j;
            }
        }
        if(tmp != i){
            int var = tableau[i];
            tableau[i] = tableau[tmp];
            tableau[tmp] = var;
        }
    }
}
int triInsertion(int tableau[]){
  int n = taille(tableau);
    int tmp;
    for(int i = 1; i <n; i++){
        int j = i;
        while((j > 0) && (tableau[j-1] > tableau[j])){
            tmp = tableau[j];
            tableau[j] = tableau[j-1];
            tableau[j-1] = tmp;
            j--;
        }
    }
}
