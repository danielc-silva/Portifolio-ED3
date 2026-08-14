#include <iostream>
#include <climits> // Necessário para usar INT_MAX como sentinela

using namespace std;

// Procedimento COMBINAR (Merge) otimizado com Sentinelas
void merge(int arr[], int inicio, int meio, int fim) {
    // Calcula o tamanho dos dois subarranjos
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Cria arranjos temporários com espaço extra (+1) para a sentinela
    int metade_esquerda[n1 + 1];
    int metade_direita[n2 + 1];

    // Copia os dados para os arranjos temporários
    for (int i = 0; i < n1; i++) {
        metade_esquerda[i] = arr[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        metade_direita[j] = arr[meio + 1 + j];
    }

    // Coloca a sentinela (infinito) na última posição de cada metade
    metade_esquerda[n1] = INT_MAX;
    metade_direita[n2] = INT_MAX;

    int i = 0; // Índice da metade_esquerda
    int j = 0; // Índice da metade_direita

    // Intercala as duas metades de volta no arranjo original
    // Graças às sentinelas, não precisamos checar se um dos lados ficou vazio!
    for (int k = inicio; k <= fim; k++) {
        if (metade_esquerda[i] <= metade_direita[j]) {
            arr[k] = metade_esquerda[i];
            i++;
        } else {
            arr[k] = metade_direita[j];
            j++;
        }
    }
}

// Procedimento principal do Merge Sort
void mergeSort(int arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontra o ponto médio para dividir o arranjo
        int meio = inicio + (fim - inicio) / 2;

        // CONQUISTAR: Chamadas recursivas para ordenar as metades
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        // COMBINAR: Faz a intercalação
        merge(arr, inicio, meio, fim);
    }
}

// Função auxiliar para imprimir o vetor
void imprimirVetor(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Declaração de um array tradicional de C++
    int lista[] = {59, 26, 41, 58, 31, 41};

    // Calcula o número de elementos do array
    int tamanho = sizeof(lista) / sizeof(lista[0]);

    cout << "Lista original: ";
    imprimirVetor(lista, tamanho);

    // Chama o mergeSort passando o array, o primeiro índice e o último índice
    mergeSort(lista, 0, tamanho - 1);

    cout << "Lista ordenada: ";
    imprimirVetor(lista, tamanho);

    return 0;
}
