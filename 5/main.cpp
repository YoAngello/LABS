#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v) {
    // —охран€ем количество элементов до дублировани€
    size_t n = v.size();

    // –езервируем пам€ть заранее, чтобы избежать многократных перевыделений
    v.reserve(n * 2);

    // ƒублируем элементы, использу€ индекс, а не итератор
    for (size_t i = 0; i < n; ++i) {
        v.push_back(v[i]);
    }
}