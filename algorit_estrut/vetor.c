#include<stdio.h>

int main(){

float n1[4], n2[4], media[4];
int i;

for(i = 0; i < 4; i++){
  printf("Digite o valor do vetor na posicao ", i);
  scanf("%f%f", &n1[i], &n2[i]);

  media[i] = (n1[0] + n2[0]) / 2;

  printf("%f", media[i]);


}

for(i = 0; i < 4; i++){
  printf("%2f", n2[i]);

}


}