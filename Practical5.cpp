#include <iostream> 
#include <string>  
using namespace std; 
template <class T> 
void selection_sort(T a[], int n)  
{  
    cout << "Sorting " << n << " elements...\n"; 
    for (int i = 0; i < n; i++) 
     {  
        cout << "a[" << i << "]="; 
        cin >> a[i]; 
    }   
    for (int i = 0; i < n - 1; i++)  
    { 
        int tem = i; 
        for (int j = i + 1; j < n; j++) { 
            if (a[j] < a[tem]) { 
                tem = j; 
            } 
        } 
        swap(a[i], a[tem]); 
    }   
    cout << "Sorted elements:\n"; 
    for (int i = 0; i < n; i++) { 
        cout << a[i] << "\n"; 
    } 
} 
int main() { 
    int c; 
    cout << "Choice (1: int, 2: float, 3: string): "; 
    cin >> c; 
    switch (c) { 
        case 1: { 
            cout << "Integer sorting...\n"; 
            const int size = 10;  
            int a[size];  
            selection_sort(a, size);  
            break; 
        } 
        case 2: { 
            cout << "Floating sorting...\n"; 
            const int size = 10;  
            float a[size]; 
            selection_sort(a, size);  
            break; 
        } 
        case 3: { 
            cout << "String sorting...\n"; 
            const int size = 10; 
            string a[size]; 
            selection_sort(a, size);  
            break; 
        } 
        default: 
            cout << "Invalid choice.\n"; 
            break; 
    } 
    return 0; 
} 
