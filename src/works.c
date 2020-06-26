#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int rest = x, hnum = k, pos = 0;
  while(pos < n && hnum > 0){
    if(rest < A[pos]){
      rest = x;
      hnum--;
    }else{
      rest -= A[pos];
      pos++;
    }
  }
  return pos == n;
}

int main(){
  int i, lb, ub, sum = 0;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    sum += A[i];
  }

  lb = 0;
  ub = sum;

  while(ub - lb > 1){
    int m = (ub + lb) / 2;
    if(p(m)){
      ub = m;
    }else{
      lb = m;
    }
  }

  printf("%d\n", ub);

  return 0;
}
