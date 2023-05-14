#include<stdio.h>
#include<stdlib.h>

int main(){

int x, y;

printf("Digite o valor de X: ");
 scanf("%d", &x);
printf("Digite o valor de Y: ");
 scanf("%d", &y); 

 if(x == 0 && y == 0){
   printf("Base");
 } else if(x > 0 && y > 0){
   printf("primeiro quadrante");
 } else if(x < 0 && y > 0){
   printf("segundo quadrante");
 } else if(x < 0 && y < 0){
   printf("terceiro quadrante");
 } else if(x > 0 && y < 0){
   printf("quarto quadrante");
 }

 return 0;

 }