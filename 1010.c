#include <stdio.h>
float simpleCalculate(int units, float value){
  return (float)units * value;
}
int main(){
  int code,units,code2,units2;
  float value,value2;
  scanf("%d %d %f",&code,&units,&value);
  scanf("%d %d %f",&code2,&units2,&value2);
  printf("VALOR A PAGAR: R$ %.2f",
      (simpleCalculate(units,value)+simpleCalculate(units2,value2)));
  return 0;
}