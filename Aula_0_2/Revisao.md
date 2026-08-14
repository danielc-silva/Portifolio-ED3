# Merge Sort

Aborda o problema da ordenação quebrando-o em partes menores e mais fáceis de resolver, operando em três passos principais em cada nível da recursão:

*   **Dividir:** Divide a sequência de $n$ elementos a serem ordenados em duas subsequências menores, cada uma contendo $n/2$ elementos.
*   **Conquistar:** Ordena as duas subsequências de forma recursiva, utilizando o próprio algoritmo de ordenação por intercalação. A recursão atinge o seu caso base (ou "não funciona" mais) quando a sequência a ser ordenada chega ao comprimento 1, pois uma sequência de apenas um elemento já é considerada ordenada por natureza.
*   **Combinar:** Faz a intercalação (ou mescla) das duas subsequências que já estão ordenadas, produzindo assim a resposta final ordenada.

---

## A Operação Chave: Intercalação (Merge)

O verdadeiro "motor" do algoritmo acontece no passo de "combinação", através de um procedimento auxiliar chamado MERGE. Esse procedimento pressupõe que os dois subarranjos que ele recebe já estão ordenados e os funde em um único arranjo ordenado.

*   Imagine que você tem duas pilhas de cartas viradas para cima sobre uma mesa.
*   Cada pilha já está ordenada, com as cartas de menor valor no topo.
*   Desejamos juntar essas duas pilhas em uma única pilha de saída ordenada, voltada para baixo.
*   O passo básico consiste em olhar para as duas cartas no topo das pilhas viradas para cima, escolher a menor entre elas, removê-la e colocá-la na pilha de saída.
*   Repetimos esse processo até que uma das pilhas originais fique vazia; quando isso acontecer, basta pegar as cartas restantes da outra pilha e colocá-las na pilha de saída.

Como em cada passo computacional estamos comparando apenas dois elementos superiores, a intercalação de $n$ elementos demora um tempo linear, representado matematicamente como $\Theta(n)$.

---

## Complexidade de Tempo

Como a árvore de recursão divide o problema pela metade a cada passo e a operação de combinar custa um tempo linear, o tempo de execução total do Merge Sort no pior caso é $\Theta(n \log n)$. Para entradas grandes, esse desempenho supera algoritmos $O(n^2)$, como a Ordenação por Inserção.

---

## Estabilidade no Merge Sort

O Merge Sort é classificado como um algoritmo estável.
*   Elementos que possuem o mesmo valor aparecerão no resultado final exatamente na mesma ordem relativa em que estavam na entrada original.
*   Para desempatar elementos iguais, o algoritmo respeita a ordem de chegada: o número que apareceu primeiro na lista original também ficará em primeiro lugar entre os repetidos na lista ordenada.

---

## Sentinela

A adição de uma sentinela (como o valor especial $\infty$ infinito) no final das pilhas auxiliares é um truque de implementação que simplifica as condições de contorno e o código do algoritmo, agilizando a intercalação ao eliminar a necessidade de verificar a todo momento se alguma das pilhas já ficou vazia.