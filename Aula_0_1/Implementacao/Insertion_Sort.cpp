#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

// Recebe o array A e o tamanho n
void insertionSort(int A[], int n) {
    // Começamos em 1.
    for (int j = 1; j < n; j++) {
        int chave = A[j]; // Guarda o valor do elemento atual a ser inserido

        // i representa o último elemento da parte já ordenada do arranjo
        int i = j - 1;

        // Enquanto o elemento anterior for maior que a chave,
        // deslocamos esse elemento uma posição para a direita.
        while (i >= 0 && A[i] > chave) {
            A[i + 1] = A[i];
            i = i - 1;
        }

        // Insere a chave na sua posição correta na sequência ordenada
        A[i + 1] = chave;
    }
}

int main() {
    // Exemplo de arranjo A = (5, 2, 4, 6, 1, 3) utilizado no Capítulo 2 do livro
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]); // Calcula a quantidade de elementos

    cout << "Arranjo original: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    // Chama a função de ordenação
    insertionSort(arr, n);

    cout << "Arranjo ordenado: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
