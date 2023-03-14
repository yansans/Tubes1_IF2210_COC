#include "util.hpp"

// template<class T>
// T maxElement(const vector<T> &vec) {
//     if (vec.size() == 0) throw EmptyContainerException();
//     T maxEl = vec[0];
//     for (int i = 1; i < vec.size(); i++) {
//         if (maxEl < vec[i]) {
//             maxEl = vec[i];
//         }
//     }
//     return maxEl;
// }

// template<class T>
// T maxElement(const T arr[], int n)
// {
//     if (n == 0) throw EmptyContainerException();
//     T maxEl = arr[0];
//     for (int i = 1; i < n; i++) {
//         if (maxEl < arr[i]) {
//             maxEl = arr[i];
//         }
//     }
//     return maxEl;
// }

// template<class T>
// T maxElement(const T *itrBegin, const T *itrEnd)
// {
//     if (itrBegin == itrEnd) throw EmptyContainerException();
//     T maxEl = *itrBegin;
//     for (auto ptr = itrBegin; ptr != itrEnd; ptr++) {
//         if (maxEl < *ptr) {
//             maxEl = *ptr;
//         }
//     }
//     return maxEl;
// }

// template<class Ret, class T>
// Ret sumElement(const std::vector<T> &vec, const std::function<Ret(T)> &lambda)
// {
//     if (vec.size() == 0) throw EmptyContainerException();
//     Ret sum = lambda(vec[0]);
//     for (int i = 1; i < vec.size(); i++) {
//         sum += lambda(vec[i]);
//     }
//     return sum;
// }
