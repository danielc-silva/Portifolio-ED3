#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

// Procedimento SELECTION-SORT
void selectionSort(int A[], int n) {
    // O laço vai de 0 até n-2 (ou seja, percorre n-1 elementos)
    // último elemento já estará na posição certa no final.
    for (int j = 0; j < n - 1; j++) {

        // Assume inicialmente que o menor elemento é o primeiro da parte não ordenada
        int menor = j;

        // Procura se existe algum elemento menor no resto do arranjo
        for (int i = j + 1; i < n; i++) {
            if (A[i] < A[menor]) {
                menor = i; // Atualiza o índice do menor elemento encontrado
            }
        }

        // Se o menor elemento não for o que já estava na posição j, faz a troca (swap)
        if (menor != j) {
            int temp = A[j];
            A[j] = A[menor];
            A[menor] = temp;
        }
    }
}

int main() {
    // Exemplo de arranjo A = (5, 2, 4, 6, 1, 3)
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Arranjo original: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    // Chama a função de ordenação
    selectionSort(arr, n);

    cout << "Arranjo ordenado: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
