#include <stdio.h>
#include <stdlib.h>

#include "libbmp.h"

int comparaion(int a, int b){ //tri lexicometrique
  if(a > b){
    return 1;
  }
  else if(a == b){
    return 0;
  }
  else if(a < b){
    return -1;
  }
}
int lexica(Pixel i, Pixel j){//compare R puis G puis B
  if(comparaion(i.R, j.R) == 0){
    if(comparaion(i.G, j.G) == 0){
      return comparaion(i.B, j.B);
    }
    else{
      return comparaion(i.G, j.G);
    }
  }
  else{
    return comparaion(i.R, j.R);
  }
}


int Somme(Pixel i, Pixel j){ //compare somme R + G +B de tableau[i] et tableau[j]
  int a = i.R + i.G + i.B;
  int b = j.R + j.G +j.B;
  return comparaion(a, b);
}

int brillanceH(Pixel i, Pixel j){ //compare H la "brillance"
  return comparaion(i.H, j.H);
}

int brillanceY(Pixel i, Pixel j){ //compare la luminéscence Y
  return comparaion(i.Y, j.Y);
}

int partitionner(Pixel *tableau, int G, int D, int trie)
{
    int pivot, i, j;
    pivot = G;
    i = G;
    j = D;

    while(i<j){
      int compa;
      if(trie == 1){ //lexicometrie
        compa = lexica(tableau[i], tableau [j]);
      }
      if(trie == 2){ //somme R + G + B
        compa = Somme(tableau[i], tableau [j]);
      }
      if(trie == 3){ //brillance H
        compa = brillanceH(tableau[i], tableau [j]);
      }
      if(trie == 4){ //brillance Y
        compa = brillanceY(tableau[i], tableau [j]);
      }

        if(compa == 1){
            Pixel temp = tableau[i];
            tableau[i] = tableau[j];
            tableau[j] = temp;
            if(pivot == i){
                pivot = j;
            }
            else if(pivot == j){
                pivot = i;
            }
        }
        if(pivot == i){
            j--;
        }
        if(pivot == j){
            i++;
        }
    }
    return pivot;
}

int triRapide(Pixel *tableau, int deb, int fin, int trie){
    if(deb >= fin){
        return 0;
    }
    int pivot = partitionner(tableau, deb, fin, trie);
    triRapide(tableau, deb, pivot-1, trie);
    triRapide(tableau, pivot+1, fin, trie);

    return 0;
}

void tri_bulle(Pixel *tableau, int n, int trie){
  int compa;
  for(int i = 0; i<n-1; i++){
      for(int j =0; j<n-1; j++){
        if(trie == 1){ //lexicometrie
          compa = lexica(tableau[j], tableau [j+1]);
        }
        if(trie == 2){ //somme R + G + B
          compa = Somme(tableau[j], tableau [j+1]);
        }
        if(trie == 3){ //brillance H
          compa = brillanceH(tableau[j], tableau [j+1]);
        }
        if(trie == 4){ //brillance Y
          compa = brillanceY(tableau[j], tableau [j+1]);
        }
       if(compa == 1){
         Pixel temp = tableau[j];
          tableau[j] = tableau[j+1];
          tableau[j+1] = temp;
        }
     }
   }
}

void triSelection(Pixel *tableau, int n, int trie){
  int compa;
    for(int i = 0; i < n; i++){
        int tmp = i;
        for(int j = i; j < n; j++){
          if(trie == 1){ //lexicometrie
            compa = lexica(tableau[tmp], tableau [j]);
          }
          if(trie == 2){ //somme R + G + B
            compa = Somme(tableau[tmp], tableau [j]);
          }
          if(trie == 3){ //brillance H
            compa = brillanceH(tableau[tmp], tableau [j]);
          }
          if(trie == 4){ //brillance Y
            compa = brillanceY(tableau[tmp], tableau [j]);
          }
            if(compa == 1){
                tmp = j;
            }
        }
        if(tmp != i){
            Pixel var = tableau[i];
            tableau[i] = tableau[tmp];
            tableau[tmp] = var;
        }
    }
}

int compaInser(Pixel *tableau, int j, int trie){
  int compa;
  if(trie == 1){ //lexicometrie
    compa = lexica(tableau[j-1], tableau [j]);
    return compa;
  }
  if(trie == 2){ //somme R + G + B
    compa = Somme(tableau[j-1], tableau [j]);
    return compa;
  }
  if(trie == 3){ //brillance H
    compa = brillanceH(tableau[j-1], tableau [j]);
    return compa;
  }
  if(trie == 4){ //brillance Y
    compa = brillanceY(tableau[j-1], tableau [j]);
    return compa;
  }

}
int triInsertion(Pixel *tableau, int n, int trie){
  Pixel tmp;
  for(int i = 1; i <n; i++){
        int j = i;
        while((j > 0) && (compaInser(tableau, j, trie) == 1)){
            tmp = tableau[j];
            tableau[j] = tableau[j-1];
            tableau[j-1] = tmp;
            j--;
        }
    }
}
