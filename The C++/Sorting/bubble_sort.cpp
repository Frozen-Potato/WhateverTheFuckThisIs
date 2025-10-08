#include <vector>
#include <algorithm>  
#include <iostream>

void bubble_sort(std::vector<int>& a) {
    bool swapped = true;
    int n = (int)a.size();
    for (int i = 0; i < n - 1 && swapped; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (a[j] > a[j+1]) {
                std::swap(a[j], a[j+1]);
                swapped = true;
            }
        }
    }
}

int main() {
    std::vector<int> a = {5, 1, 4, 2, 8, 5};
    bubble_sort(a);
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";
    return 0;
}
