#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x, int k){
  for(int i = 0;i < n;i++){
    k -= A[i] / x;
    if(A[i] % x)k--;
  }

  return k >= 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int m = (ub + lb) / 2;
    if(p(m, k)){
      ub = m;
    }else{
      lb = m;
    }
  }

  printf("%d\n", ub);

  return 0;
}
