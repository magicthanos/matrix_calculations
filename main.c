#include <stdio.h>
#include <stdlib.h>

int **create_2d(int m, int n){
  int **c = malloc(m * sizeof(int *));
  if(c == NULL) return NULL;
  for(int i = 0; i < m; i++){
    c[i] = calloc(n, sizeof(int));
    if(c[i] == NULL)
      return NULL;
  }

  return c;
}

int read_2d(int m, int n, int **a){
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++){
      printf("(%d, %d): ", i + 1, j + 1);
      if(scanf("%d", &a[i][j]) != 1)
        return -1;
    }
  return 0;
}

void print_2d(int m, int n, int **a){
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++)
      printf("%-3d ", a[i][j]);
    putchar('\n');
  }
  putchar('\n');
}

void free_2d(int m, int **a){
  for(int i = 0; i < m; i++)
    free(a[i]);
  free(a);
}

int main(int argc, char **argv){
  if(argc < 4)
    return 1;

  int m = atoi(argv[1]);
  int p = atoi(argv[2]);
  int n = atoi(argv[3]);

  if(m <= 0 || p <= 0 || n <= 0)
    return 2;

  int **a, **b, **axb;
  if((a   = create_2d(m, p)) == NULL) return 3;
  if((b   = create_2d(p, n)) == NULL) return 4;
  if((axb = create_2d(m, n)) == NULL) return 5;

  if(read_2d(m, p, a)) return 6;
  if(read_2d(p, n, b)) return 7;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < p; k++){
        axb[i][j] += a[i][k] * b[k][j];
      }
    }
  }

  printf("\na:\n"); 
  print_2d(m, p, a);

  printf("b:\n");   
  print_2d(p, n, b);

  printf("axb:\n"); 
  print_2d(m, n, axb);
  
  free_2d(m, a); free_2d(p, b); free_2d(m, axb);

  return 0;
}