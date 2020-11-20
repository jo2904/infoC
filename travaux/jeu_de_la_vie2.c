#include <stdio.h>
#include <stdlib.h>

int WIDTH =30, HEIGHT=30;
int grid[30][30];

//MENU UTILISATEUR return numéro du motif
int initGame(void){
  int motif;
  printf("Quel motif de départ ?\n");
  printf("1) ###\n\n2) # #\n   # #\n   ###\n\n3) ###\n    #\n   #\n\n quel motif ?  ");
  scanf("%d", &motif);
  return motif;
}

//place les cellules initiales en fonction du motif 
int loadGame(int motif){
  if(motif == 1){
    grid[HEIGHT/2][WIDTH/2] = 1;
    grid[HEIGHT/2][(WIDTH/2)+1] = 1;
    grid[HEIGHT/2][(WIDTH/2)+2] = 1;
    return 1;
  }
  if(motif == 2){
    grid[HEIGHT/2][WIDTH/2] = 1;
    grid[HEIGHT/2][(WIDTH/2)+1] = 1;
    grid[HEIGHT/2][(WIDTH/2)+2] = 1;
    grid[(HEIGHT/2)-1][WIDTH/2] = 1;
    grid[(HEIGHT/2)-2][WIDTH/2] = 1;
    grid[(HEIGHT/2)-1][WIDTH/2+2] = 1;
    grid[(HEIGHT/2)-2][WIDTH/2+2] = 1;
    return 1;
  }
  if(motif == 3){
    grid[HEIGHT/2][WIDTH/2] = 1;
    grid[HEIGHT/2][(WIDTH/2)+1] = 1;
    grid[HEIGHT/2][(WIDTH/2)+2] = 1;
    grid[(HEIGHT/2)+1][(WIDTH/2)+1] = 1;
    grid[(HEIGHT/2)+2][WIDTH/2] = 1;
    return 1;
  }
  else
    return 0;
}

//dessine la grille 
void drawGame(void){
    //system("clear");
    printf("\n");
    for(int i=0; i<HEIGHT+2; i++){
      printf("-");
    }
    printf("\n");
    for(int i=0; i<HEIGHT; i++){
      printf("|");
      for(int j=0; j<WIDTH; j++){
        if(grid[i][j] == 1)
          printf("#");
        else
          printf(" ");
      }
    printf("|\n");
    }
    for(int i=0; i<HEIGHT+2; i++){
      printf("-");
    }
}

//Confirme l'existance de la case
int IsInRange( int ligne, int colonne){
    if(ligne > 0 && ligne < HEIGHT && colonne > 0 && colonne < WIDTH)
      return 1;
    else
      return 0;
}

//compte le nombre de voisin
int NbCasseAdj(int ligne, int colonne){
  int voisin = 0;
  //calcul du nombre de voisin
  if(grid[ligne-1][colonne-1] == 1 && IsInRange(ligne-1, colonne-1) == 1){
    voisin += 1;
  }
  if(grid[ligne-1][colonne] == 1 && IsInRange(ligne-1, colonne) == 1){
    voisin += 1;
  }
  if(grid[ligne-1][colonne+1] == 1 && IsInRange(ligne-1, colonne+1) == 1){
    voisin += 1;
  }
  if(grid[ligne][colonne-1] == 1 && IsInRange(ligne, colonne-1) == 1){
    voisin += 1;
  }
  if(grid[ligne][colonne+1] == 1 && IsInRange(ligne, colonne+1) == 1){
    voisin += 1;
  }
  if(grid[ligne+1][colonne-1] == 1 && IsInRange(ligne+1, colonne-1) == 1){
    voisin += 1;
  }
  if(grid[ligne+1][colonne] == 1 && IsInRange(ligne+1, colonne) == 1){
    voisin += 1;
  }
  if(grid[ligne+1][colonne+1] == 1 && IsInRange(ligne+1, colonne+1) == 1){
    voisin += 1;
  }
  return voisin;
}

//récupere nombre de voisin et transforme la grille
void UpdateGame(void){
  char grid2[HEIGHT][WIDTH];
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      int voisin = NbCasseAdj(i, j);
      if(grid[i][j] == 1 && voisin > 1 && voisin <4){
        grid2[i][j] = 1;
        break;}
      if(grid[i][j] == 0 && voisin == 3){
        grid2[i][j] = 1;
        break;}
      else {
      grid2[i][j] = 0;}
    }
  }
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++)
      grid[i][j] = grid2[i][j];
  }

  }

void PlayGame(void){
     loadGame(initGame());
     drawGame();
     char suite;
     do {
       UpdateGame();
       drawGame();
       scanf("%c", &suite);
     } while(suite != 's');

}

int main(){
  PlayGame();
}
