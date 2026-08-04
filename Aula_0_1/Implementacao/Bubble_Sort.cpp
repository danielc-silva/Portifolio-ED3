#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

// Procedimento BUBBLE-SORT
void bubbleSort(int A[], int n) {
    // O ciclo externo garante que faremos passagens suficientes.
    // Precisamos de n-1 passagens para ordenar n elementos.
    for (int i = 0; i < n - 1; i++) {

        // O ciclo interno faz as comparações adjacentes.
        // A cada passagem 'i', os últimos 'i' elementos já estão ordenados no fim,
        // logo, não precisamos de os comparar novamente (daí o n - 1 - i).
        for (int j = 0; j < n - 1 - i; j++) {

            // Se o elemento actual for maior que o próximo, faz a troca (swap)
            if (A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Exemplo de array A = (5, 2, 4, 6, 1, 3)
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    // Chama a função de ordenação
    bubbleSort(arr, n);

    cout << "Array ordenado: ";
    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;

    return 0;
}
