#include <stdio.h>
#include <stdlib.h>

int main(){
  int array_size,marked=0;
  scanf("%d",&array_size);getchar();
  int array[array_size];
  for(int i = 0; i<array_size;i++){
    scanf("%d",&array[i]);getchar();
    if(i>0 && array[i-1]!=array[i])
      marked++;
  }//  1 2 3     4   5   6
  //[1,2,1,2,2,2,1,1,2,2,1,1]
  printf("%d\n",++marked);

  return EXIT_SUCCESS;
}
