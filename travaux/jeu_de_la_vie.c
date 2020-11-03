#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void remplir(int tab, int taille){
  srand(time(NULL));
  for(int i=1; i<taille-1; i++){
    for(int j=1; j<taille-1; j++){
      tab[i][j] = rand()%2;
      if(tab[i][j] == 1){
        printf("#");
      }
      else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(){
  int taille = 100;
  int tab[100][100], voisin;
  int nbJour =50;

  remplir(tab[100][100], taille);

  for(int h; h < nbJour; h++){
    //attente et netoyage
    sleep(1);
    system("clear");

    for(int i=1; i<taille-1; i++){
      for(int j=1; j<taille-1; j++){
        voisin = 0;
        //calcul du nombre de voisin
        if(tab[i-1][j-1] == 1){
          voisin += 1;
        }
        if(tab[i-1][j] == 1){
          voisin += 1;
        }
        if(tab[i-1][j+1] == 1){
          voisin += 1;
        }
        if(tab[i][j-1] == 1){
          voisin += 1;
        }
        if(tab[i][j+1] == 1){
          voisin += 1;
        }
        if(tab[i+1][j-1] == 1){
          voisin += 1;
        }
        if(tab[i+1][j] == 1){
          voisin += 1;
        }
        if(tab[i+1][j+1] == 1){
          voisin += 1;
        }
        //si la cellule est vivante et nb de vosin != 2 ou 3 => MORT
        if(tab[i][j] == 1){
          if(voisin != 2 || voisin != 3){
            tab[i][j] = 0;
          }
        }
        //si la cellule est morte et nb de voisin == 3 => VIE
        if(tab[i][j] == 0){
          if(voisin == 3){
            tab[i][j] = 1;
          }
        }
        //affichage de # si 1 et vide sinon
        if(tab[i][j] == 1){
          printf("#");
        }
        else{
          printf(" ");
        }
      }
      printf("\n");
    }
  }
}
