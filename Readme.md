## Implementação de Tabela Hash


####Objetivo
Nosso objetivo é implementar os métodos de uma hashtable com tentativa linear (*hashtable with linear probing and open addressing*).

####Considerações
Endereçamento aberto significa que resolvemos os problemas de colisão dentro da mesma tabela.

Tentativa linear implica que quando há colisão, busca-se sequencialmente até encontrar uma posição livre.

#### Algoritmo da remoção
Para remoção você deve usar a abordagem de realocação:

 1. Find and remove the desired element
 2. Go to the next bucket
 3. If the bucket is empty, quit
 4. If the bucket is full, delete the element in that bucket and re-add it to the hash table using the normal means. The item must be removed before re-adding, because it is likely that the item could be added back into its original spot.
5. Repeat step 2.




####Referências:

ref: https://pt.wikipedia.org/wiki/Tabela_de_dispers%C3%A3o

ref: https://programacaodescomplicada.wordpress.com/indice/estrutura-de-dados/