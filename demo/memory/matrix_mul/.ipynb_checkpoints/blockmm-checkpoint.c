#include <stdio.h>
#include <stdlib.h>
#include "perfstats.h"

void blockmm(double **a, double **b, double **c);
int n=1;
  int ARRAY_SIZE=500;
int main(int argc, char **argv)
{
  double **a, **b, **c, *temp;
  int i, j, k;
  /* initialize a, b */
  if(argc == 2)
    n = atoi(argv[1]);
  if(argc >= 3)
  {
    ARRAY_SIZE = atoi(argv[1]);
    n = atoi(argv[2]);
  }
  temp = (double *)valloc(ARRAY_SIZE*ARRAY_SIZE*sizeof(double)*3);
  a = (double **)malloc(ARRAY_SIZE*sizeof(double *));
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    a[i] = temp;
    temp += ARRAY_SIZE;
    for(j = 0; j < ARRAY_SIZE; j++)
      a[i][j] = i+j;
  }
  b = (double **)malloc(ARRAY_SIZE*sizeof(double *));
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    b[i] = temp;
    temp += ARRAY_SIZE;
    for(j = 0; j < ARRAY_SIZE; j++)
      b[i][j] = i+j;
  }
  c = (double **)malloc(ARRAY_SIZE*sizeof(double *));
  for(i = 0; i < ARRAY_SIZE; i++)
  {
    c[i] = temp;
    temp += ARRAY_SIZE;
    for(j = 0; j < ARRAY_SIZE; j++)
      c[i][j] = 0;
  }
  perfstats_init();
  perfstats_enable();
  blockmm(a, b, c);
  perfstats_disable();
  perfstats_print();
  perfstats_deinit();
  
  return 0;
}

//START
void blockmm(double **a, double **b, double **c)
{
  int i,j,k, ii, jj, kk;
  for(i = 0; i < ARRAY_SIZE; i+=(ARRAY_SIZE/n))
  {
    for(j = 0; j < ARRAY_SIZE; j+=(ARRAY_SIZE/n))
    {
      for(k = 0; k < ARRAY_SIZE; k+=(ARRAY_SIZE/n))
      {        
          for(ii = i; ii < i+(ARRAY_SIZE/n); ii++)
            for(jj = j; jj < j+(ARRAY_SIZE/n); jj++)
              for(kk = k; kk < k+(ARRAY_SIZE/n); kk++)
                c[ii][jj] += a[ii][kk]*b[kk][jj];
      }
    }
  }  
}
//END