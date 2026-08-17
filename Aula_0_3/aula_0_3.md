# Quick Sort

## 1. Visão Geral e Características Principais
* **Paradigma:** Utiliza a técnica de Divisão e Conquista.
* **In-place:** Diferente do Merge Sort, o Quicksort ordena os elementos "no próprio local" (no próprio vetor), necessitando apenas de uma quantidade de memória extra (ignorando a pilha de recursão).
* **Desempenho Prático e Notações:** O tempo de execução do pior caso é $\Theta(n^2)$. Apesar disso, o Quicksort frequentemente é a melhor opção prática para ordenação porque o seu tempo de execução esperado é $\Theta(n \log n)$, e os fatores constantes ocultos nessa notação são bastante pequenos.

## 2. O Paradigma de Divisão e Conquista no Quicksort
É dividido em três passos clássicos do paradigma:
* **Dividir:** O array é particionado (reorganizado) em dois subarrays (possivelmente vazios). A regra é: cada elemento do subarray esquerdo é menor ou igual ao pivô, e cada elemento do subarray direito é maior. O índice do pivô é calculado como parte deste processo.
* **Conquistar:** O algoritmo chama a si mesmo recursivamente (chamadas ao Quicksort) para ordenar os dois subarrays gerados.
* **Combinar:** Como a ordenação acontece *in-place* (localmente no próprio array) durante a fase de divisão, não é necessário nenhum trabalho extra para combinar os resultados. O array inteiro já estará ordenado.

## 3. O “Coração” do Algoritmo
A chave do Quicksort é o procedimento de partição (PARTITION).
* **Escolha do Pivô:** Na implementação padrão, o algoritmo sempre escolhe o último elemento do subarray como o pivô.
* **Funcionamento:** A rotina usa dois índices de controle ($i$ e $j$, por exemplo). O $j$ percorre o array explorando os elementos, enquanto o $i$ demarca o limite do "grupo dos menores que o pivô". Conforme encontra elementos menores que o pivô, ele os troca e avança o $i$. No final, o pivô é colocado na posição $i+1$, separando perfeitamente os maiores e os menores.

## 4. Análise de Complexidade (Tempo de Execução)
O tempo do Quicksort depende diretamente de quão "balanceada" é a partição gerada em cada passo:
* **Pior Caso:** Ocorre quando o algoritmo de partição produz uma divisão extremamente desbalanceada (um subarray com $n-1$ elementos e outro com $0$). Na implementação padrão (onde o último elemento é o pivô), o pior caso ocorre justamente quando o array já está ordenado ou na ordem inversa.
* **Melhor Caso e Caso Médio (A Intuição):** Ocorre quando o particionamento divide o problema em partes razoavelmente proporcionais. No caso médio (elementos em ordem aleatória), mesmo que a divisão pareça desequilibrada (como $9$ para $1$), qualquer divisão de proporcionalidade constante produz uma árvore de recursão de profundidade $\Theta(\log n)$. Isso significa que o custo em cada nível será $O(n)$ e o tempo de execução total será de $O(n \log n)$.

## 5. A Solução do Livro do Cormen: Quicksort Aleatorizado
Para evitar o problema catastrófico do pior caso em arrays já ordenados, introduz-se uma variação: o Quicksort Aleatorizado.
* **Como funciona:** Em vez de sempre pegar o último elemento como pivô, o algoritmo sorteia aleatoriamente um índice no intervalo do primeiro ao último elemento. Ele troca esse elemento aleatório com o último elemento e, em seguida, executa a partição normalmente.
* **Vantagem:** Isso garante que nenhuma entrada específica induza o comportamento do pior caso. O pior caso passa a depender apenas do "azar" do gerador de números aleatórios, garantindo um excelente tempo de execução no caso médio para qualquer tipo de entrada.
