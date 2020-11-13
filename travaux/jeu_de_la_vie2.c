#include <stdio.h>

int WIDTH =20, HEIGHT=20;
int grid[100][100];


int initGame(void){
  int motif;
  printf("Quel motif de départ ?\n");
  printf("1) ###\n\n2) # #\n   # #\n   ###\n\n3) ###\n    #\n   #\n\n quel motif ?  ");
  scanf("%d", &motif);
  return motif;
}

int loadGame(int motif){
  if(motif == 1){
    printf("%d %d", HEIGHT, WIDTH );
    grid[HEIGHT/2][WIDTH/2] = 1;
    grid[HEIGHT/2][(WIDTH/2)+1] = 1;
    grid[HEIGHT/2][(WIDTH/2)+2] = 1;
    return 1;
  }
  else
    return 0;
}

void drawGame(void){
    for(int i=0; i<HEIGHT; i++){
      for(int j=0; j<WIDTH; j++){
        if(grid[i][j] == 1)
          printf("#");
        else
          printf(" ");
      }
      printf("\n");
    }
}

int IsInRange( int ligne, int colonne){
    if(ligne > 0 && ligne < HEIGHT && colonne > 0 && colonne < WIDTH)
      return 1;
    else
      return 0;
}

int NbCasseAdj(int ligne, int colonne){
  int voisin = 0;
  //calcul du nombre de voisin
  if(grid[ligne-1][colonne-1] == 1 && IsInRange(ligne-1, colonne-1) == 1){
    voisin += 1;
  }
  if(grid[ligne-1][colonne] == 1 && IsInRange(ligne-1, colonne) ==1){
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

void UpdateGame(void){
  char grid2[HEIGHT][WIDTH];
  for(int i=0; i<HEIGHT; i++){
    for(int j=0; j<WIDTH; j++){
      int voisin = NbCasseAdj(i, j);
      if(grid[i][j] == 1 && voisin > 1 && voisin <4)
        grid2[i][j] = 1;
      if(voisin == 3)
        grid2[i][j] = 1;
    }
  }
  grid[HEIGHT][WIDTH] = grid2[HEIGHT][WIDTH];
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
