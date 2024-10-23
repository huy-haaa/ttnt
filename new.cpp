#include <iostream>
#include <omp.h>

int main() {
    const int size = 1000000;
    int array[size];
    long long sum = 0;

    // Khởi tạo mảng
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }

    // Thiết lập số lượng luồng
    omp_set_num_threads(4);

    // Tính tổng song song
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }

    std::cout << "Tổng của mảng là: " << sum << std::endl;

    return 0;
}
