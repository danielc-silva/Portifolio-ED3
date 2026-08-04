# Resumo de Algoritmos de Ordenação

## Algoritmos Estáveis vs. Instáveis

### Algoritmo Estável
* Elementos com o mesmo valor de chave aparecem no resultado final **exatamente na mesma ordem relativa** em que se encontravam na entrada original.
* Tem uma regra para desempate onde, quando o algoritmo encontra dois números ou elementos iguais, ele rompe o empate pela **ordem de chegada**: o elemento que apareceu primeiro na lista original aparecerá primeiro na lista ordenada.

### Algoritmo Instável
* **Não garante** que a ordem original dos elementos repetidos (ou com valores iguais) seja mantida após a ordenação.
* Algoritmos clássicos e muito utilizados, como o **Quicksort** (Ordenação Rápida) e o **Heapsort** (Ordenação por Heap), são exemplos de algoritmos instáveis em suas implementações padrão.

---

## Algoritmos com Complexidade O(n²)

### Ordenação por Inserção (Insertion Sort)
*Como o Algoritmo Funciona (A Analogia do Jogo de Cartas):*
1. Imagine que você inicia com a mão esquerda vazia e as cartas viradas com a face para baixo na mesa.
2. Em seguida, você remove uma carta de cada vez da mesa e a insere na posição correta na sua mão esquerda.
3. Para encontrar a posição correta dessa nova carta, você a compara com cada uma das cartas que já estão na mão, da direita para a esquerda.
4. A qualquer momento, as cartas que estão na sua mão esquerda permanecem ordenadas.

> **Nota sobre o uso de memória:** Os números são ordenados no local (*in-place*), o que significa que eles são reorganizados dentro do próprio arranjo original, armazenando no máximo um elemento fora do arranjo (a "chave" atual) a cada instante.

### Ordenação por Seleção (Selection Sort)
Funciona dividindo virtualmente o arranjo em duas partes: uma parte à esquerda que já está ordenada e uma parte à direita que ainda não está ordenada. O processo segue três passos principais:
1. **Encontrar o menor:** Ele varre o arranjo inteiro (ou o que resta dele) para encontrar o menor elemento.
2. **Trocar (Swap):** Quando encontra esse menor elemento, ele troca-o de lugar com o primeiro elemento da parte não ordenada.
3. **Avançar:** A fronteira entre a parte ordenada e a não ordenada avança uma posição para a direita. O processo repete-se para o segundo menor elemento, o terceiro, e assim por diante.

> **Por que o laço vai até `n - 1`?** Os autores destacam que o laço principal só precisa de ser executado para os primeiros `n - 1` elementos porque, quando você coloca os primeiros `n - 1` menores elementos nas suas posições corretas, o elemento que sobrar na última posição será garantidamente o maior de todos, não sendo necessário testá-lo.

### Ordenação por Bolha (Bubble Sort)
Recebe o nome de "Bolha" devido à forma como os elementos maiores "borbulham" (sobem) gradualmente para o final do array a cada iteração. Ele funciona da seguinte maneira:
1. **Comparações Adjacentes:** O algoritmo percorre o array a partir do primeiro elemento. Ele compara o primeiro elemento com o segundo.
2. **Troca (Swap):** Se o primeiro elemento for maior que o segundo, eles trocam de posição. Se não for, continuam onde estão.
3. **Avanço:** O processo repete-se comparando o segundo com o terceiro, o terceiro com o quarto, até ao final do array.
4. **Borbulhar do Maior:** Quando termina a primeira passagem completa, o maior elemento de todos estará garantidamente na última posição.
5. **Repetição:** O algoritmo repete o ciclo inteiro, mas desta vez ignora a última posição (pois o maior já lá está). Este processo repete-se até que o array esteja totalmente ordenado.

> **Estabilidade:** Ao contrário do Selection Sort, o Bubble Sort é um algoritmo **estável**, pois os elementos com valores iguais nunca trocarão de posição entre si (a condição de troca é estritamente maior: `>`).

---

## Invariantes de Laço
São usados essencialmente para **ajudar a entender e provar por que um algoritmo é correto**. Para que um invariante de laço seja válido e útil na prova de correção de um algoritmo, devemos mostrar três propriedades fundamentais:

* **Inicialização:** O invariante deve ser verdadeiro antes da primeira iteração do laço.
* **Manutenção:** Se o invariante for verdadeiro antes de uma iteração do laço, ele deve permanecer verdadeiro antes da próxima iteração.
* **Término:** Quando o laço termina, o invariante deve fornecer uma propriedade útil que ajude a demonstrar que o algoritmo está correto.