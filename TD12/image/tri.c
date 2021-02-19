#include <stdio.h>
#include <stdlib.h>

#include "libbmp.h"


int comparaison(Pixel i, Pixel j){ //compare somme R + G +B de tableau[i] et tableau[j]
  int a = i.R;// + rgb[i].G +rgb[i].B;
  int b = j.R;// + rgb[j].G +rgb[j].B;
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

int comparaison2(Pixel i, Pixel j){ //La valeur = "brillance"
  float a = i.V;
  float b = j.V;
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

/*   partitionner()
 [IN/OUT] int *t : pointeur sur le début du tableau
 [IN]     int G  : indice de début de tableau
 [IN]     int D  : indice de fin de tableau
 La fonction partitionne le tableau autour de la valeur t[G] entre les indices G et D
 La fonction retourne l'indice du pivot une fois le tableau partitionné.
 */
int partitionner(Pixel *tableau, int G, int D)
{
    int pivot, i, j;
    pivot = G;
    i = G;
    j = D;

    while(i<j){
        if(comparaison2(tableau[i], tableau [j]) == 1){
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

/*   triRapide()
 [IN/OUT] int *t : pointeur sur le début du tableau
 [IN]     int G  : indice de début de tableau
 [IN]     int D  : indice de fin de tableau
 La fonction trie le tableau entre les indices G et D
 La fonction retourne 0 si tout s'est bien passé, -1 en cas d'erreur.
 */
int triRapide(Pixel *tableau, int deb, int fin){
    if(deb >= fin){
        return 0;
    }
    int pivot = partitionner(tableau, deb, fin);
    triRapide(tableau, deb, pivot-1);
    triRapide(tableau, pivot+1, fin);

    return 0;
}
