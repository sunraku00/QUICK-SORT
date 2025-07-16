#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class QuickSort {
private:
    vector<int> arr;
    int comparisons;
    int swaps;
    
    void printArray(const vector<int>& array, int low, int high, string message) {
        cout << message << " [" << low << ".." << high << "]: ";
        for (int i = low; i <= high; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    void printFullArray(const vector<int>& array, string message) {
        cout << message << ": ";
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    
    int partition(vector<int>& array, int low, int high) {
        int pivot = array[high]; 
        
        int i = low - 1; 
        
        for (int j = low; j < high; j++) {
            comparisons++;
            
            if (array[j] <= pivot) {
                i++;
                if (i != j) {
                    swap(array[i], array[j]);
                    swaps++;
                }
            } 
        }
        
        swap(array[i + 1], array[high]);
        swaps++;
        
        printArray(array, low, high, "Setelah partisi");
        return i + 1;
    }
    
    void quickSort(vector<int>& array, int low, int high, int depth) {
        if (low < high) {
            string indent(depth * 2, ' ');
            
            int pivotIndex = partition(array, low, high);
            
            if (low < pivotIndex - 1) {
                quickSort(array, low, pivotIndex - 1, depth + 1);
            } 
            
            if (pivotIndex + 1 < high) {
                quickSort(array, pivotIndex + 1, high, depth + 1);
            } 
        }
    }
    
public:
    QuickSort() : comparisons(0), swaps(0) {}
    
    void sort(vector<int> inputArray, string nim) {
        arr = inputArray;
        comparisons = 0;
        swaps = 0;
        
        cout << "=== QUICK SORT MENGGUNAKAN DIVIDE AND CONQUER ===" << endl;
        cout << "NIM: " << nim << " (angka 0 diganti dengan 11)" << endl;
        cout << "Data yang akan diurutkan berdasarkan digit NIM: 2, 3, 5, 3, 3, 7, 8, 11" << endl;
        
        printFullArray(arr, "\nArray awal");
        cout << "\n" << string(60, '=') << endl;
        cout << "MEMULAI QUICK SORT" << endl;
        cout << string(60, '=') << endl;
        
        quickSort(arr, 0, arr.size() - 1, 0);
        
        cout << "\n" << string(60, '=') << endl;
        cout << "HASIL AKHIR" << endl;
        cout << string(60, '=') << endl;
        printFullArray(arr, "Array setelah diurutkan");
        cout << "\nStatistik:" << endl;
        cout << "- Jumlah perbandingan: " << comparisons << endl;
        cout << "- Jumlah pertukaran: " << swaps << endl;
        
        cout << "\nPenjelasan Algoritma:" << endl;
        cout << "1. DIVIDE: Pilih pivot (elemen terakhir) dan partisi array" << endl;
        cout << "2. CONQUER: Rekursi pada sub-array kiri dan kanan dari pivot" << endl;
        cout << "3. COMBINE: Tidak diperlukan karena array sudah terurut in-place" << endl;
        
        cout << "\nKompleksitas:" << endl;
        cout << "- Best case: O(n log n)" << endl;
        cout << "- Average case: O(n log n)" << endl;
        cout << "- Worst case: O(n²)" << endl;
    }
};

int main() {
    string nim;
    cout << "Masukkan NIM Anda: ";
    cin >> nim;
    
    vector<int> data = {2, 3, 5, 3, 3, 7, 8, 11};
    
    QuickSort sorter;
    sorter.sort(data, nim);
    
    return 0;
}
