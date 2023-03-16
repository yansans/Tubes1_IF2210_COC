#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <vector>
#include <functional>
#include <string>
#include <iostream>
#include "../Exception/Exception.h"


/**
 * @brief return max element in a vector. OPERATOR< MUST EXIST FOR T
 * 
 * @tparam T 
 * @param vec - minimum size of 1
 * @return T 
 */
template<class T>
T maxElement(const std::vector<T> &vec) {
    if (vec.size() == 0) throw EmptyContainerException();
    T maxEl = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (maxEl < vec[i]) {
            maxEl = vec[i];
        }
    }
    return maxEl;
}

/**
 * @brief return max element in an array. OPERATOR< MUST EXIST FOR T
 * 
 * @tparam T 
 * @param arr - minimum size of 1
 * @param n - size of array
 * @return T 
 */
template<class T>
T maxElement(const T arr[], int n) {
    if (n == 0) throw EmptyContainerException();
    T maxEl = arr[0];
    for (int i = 1; i < n; i++) {
        if (maxEl < arr[i]) {
            maxEl = arr[i];
        }
    }
    return maxEl;
}

/**
 * @brief return max element in an array. OPERATOR< MUST EXIST FOR T
 * @example @code 
 * Player p[n]; Player winner = maxElement(p, p+n);
 * @endcode
 * 
 * @tparam T 
 * @param itrBegin - pointer to first element
 * @param itrEnd - pointer to element after last element
 * @return T 
 */
template<class T>
T maxElement(const T *itrBegin, const T *itrEnd) {
    if (itrBegin == itrEnd) throw EmptyContainerException();
    T maxEl = *itrBegin;
    for (auto ptr = itrBegin; ptr != itrEnd; ptr++) {
        if (maxEl < *ptr) {
            maxEl = *ptr;
        }
    }
    return maxEl;
}

template<class P, class T>
T maxElement(const vector<T> &vec, std::function<P(T)> &lambda) {
    if (vec.size() == 0) throw EmptyContainerException();
    T maxEl = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (lambda(maxEl) < lambda(vec[i])) {
            maxEl = vec[i];
        }
    }
    return maxEl;
}

template<class T>
void sortPointer(vector<T*> &vec) {
    sort(vec.begin(), vec.end(), [](T *a, T *b) { return *a < *b; });
}

template<class T>
T* maxPointer(const vector<T*> &vec) {
    std::function<T(T*)> lambda = [](T *a) { return *a; };
    return maxElement(vec, lambda);
}

/**
 * @brief return sum of vector elements, described in lambda
 * 
 * @tparam Ret 
 * @tparam T 
 * @param vec 
 * @param lambda 
 * @return Ret 
 */
template<class Ret, class T>
Ret sumElement(const std::vector<T> &vec, std::function<Ret(T)> &lambda) {
    if (vec.size() == 0) throw EmptyContainerException();
    Ret sum = lambda(vec[0]);
    for (int i = 1; i < vec.size(); i++) {
        sum += lambda(vec[i]);
    }
    return sum;
}


#endif