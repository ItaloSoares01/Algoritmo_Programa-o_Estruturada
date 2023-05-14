#include <stdio.h>

int main()
{
    int vetor[6], i, nBusca, contador = 0, posicao[6];

    for (i = 0; i < 6; i++)
    {
        printf("Digite o valor:\n");
        scanf("%d", &vetor[i]);

        //vetor[i] = i * 5;
    }
    printf("Digite o numero: ");
    scanf("%d", &nBusca);
    
    for (i = 0; i < 6; i++)
    {
        if (nBusca == vetor[i])
        {
            posicao[contador]=i;
            contador++;
        }
    }

    printf("Quantidade de vezes que o numero %d aparece: %d" , nBusca, contador);
    
    for (i=0;i<contador;i++)
    printf("%d", posicao[i]);

  return 0;  
    
}
