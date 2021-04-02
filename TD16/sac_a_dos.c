#include <stdio.h>
#include <stdlib.h>



void tri_bulle(float ** tableau, int taille){
  int n = taille;
  for(int i = 0; i<n-1; i++){
      for(int j =0; j<n-1; j++){
       if(tableau[j][1] < tableau[j+1][1]){
         float temp = tableau[j][1];
         float temp2 = tableau[j][0];
          tableau[j][0] = tableau[j+1][0];
          tableau[j][1] = tableau[j+1][1];
          tableau[j+1][1] = temp;
          tableau[j+1][0] = temp2;
        }
     }
   }
}

void tri_bulle2(int tableau[], int taille){
  int n = taille;
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

int main(int argc, char const *argv[]){
  int taille;
  scanf("%d", &taille);

  int ** tableau = NULL;//init tableau
  tableau = (int**)calloc(taille, sizeof(int*));
  for(int i = 0; i < taille; i++){
    tableau[i] = (int*)calloc(2, sizeof(int));
  }
  float ** ratio = NULL;//init tableau
  ratio = (float**)calloc(taille , sizeof(float*));
  for(int i = 0; i < taille; i++){
    ratio[i] = (float*)calloc(2, sizeof(float));
  }


  for(int i = 0; i < taille; i++){
    scanf("%d", &tableau[i][0]);//on recupQI
    scanf("%d", &tableau[i][1]);// on recup le temps
    ratio[i][0] = (float) i;
    ratio[i][1] = (float)tableau[i][0]/(float)tableau[i][1];//on calcule le ration QI/temps
  }

  tri_bulle(ratio, taille);//on tri le ratio

  int temps = 30;
  int i = 0, j = 0;
  int * solution = NULL;
  int nb_solution = 0;
  solution = (int*) calloc(taille, sizeof(int));
  for(int i =0; i<taille; i++){
    solution[i] = -1;
  }
  while(temps > 0 && i < taille){//si il reste du temps et des alliments
    int indice = (int)ratio[i][0];//je recup le plus grand ingrédient nn consomé

    if(temps - tableau[indice][1] >= 0){//si j'ai le temps de manger l'ingrédient
      temps = temps - tableau[indice][1];//je perds du temps
      solution[i] = indice;//on stoque la solution
      nb_solution ++;//on ajoute un nb de solution
      j = 1;
    }
    i++;//je passe au suivant
  }

  if(j==0){//si pas de solution
    printf("-1");
  }
  else{

    tri_bulle2(solution, taille);//on trie nos solution

    for(int i = 0; i < taille; i++){
      if(solution[i] != -1){
        printf("%d ", solution[i] );
      }
    }
  }

  free(solution);
  for(int i = 0; i < taille; i++){
    free(tableau[i]);
    free(ratio[i]);
  }
  free(tableau);
  free(ratio);
  return 0;
}
