#include <stdio.h>
#include <math.h>
#include <stdlib.h>



int main()
{
  char fname[100] ;
  FILE *f ;
  int n ;
  double x[300],y[300] ;
  int i ;

  printf("Enter the name of the .xy file : ") ;
  scanf("%s", fname) ;
  
  f = fopen(fname,"r") ;
  if (f == NULL) {
    printf("can't read file, %s\n",fname)  ;
    exit(0) ;    
  }

  fscanf(f,"%d",&n) ;
  for (i = 0 ; i < n ; i++) {
    fscanf(f,"%lf %lf",&x[i],&y[i]) ;
  }

  /*printf("numpoints = %d\n",n) ;
  for (i = 0 ; i < n ; i++) {
    printf("%lf %lf\n",x[i],y[i]) ;
  }*/



  int convex = 1;
  for(int i = 0; i < n-1; ++i){
    int pos = 0, neg = 0;
    for(int a = 0; a < n; ++a){
      int result = ((y[i+1] - y[i])*(x[a] - x[i])) - ((x[i+1] - x[i])*(y[a] - y[i]));
      if(result > 0) ++pos;
      else if(result < 0) ++neg;
    }
    if(pos && neg) {
      convex = 0;
      break;
    }
  }
  if(convex != 0){
    int pos = 0, neg = 0;
    for(int a = 0; a < n; ++a){
      int result = ((y[0] - y[n-1])*(x[a] - x[n-1])) - ((x[0] - x[n-1])*(y[a] - y[n-1]));
      if(result > 0) ++pos;
      else if(result < 0) ++neg;
    }
    if(pos && neg) convex = 0;
  }

  if(convex == 0)
    printf("it's concave.\n");
  else printf("it's convex.\n");
  
}
