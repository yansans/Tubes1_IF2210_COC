#include "util.hpp"

template<class T>
T maxElement(const vector<T> &vec) {
    if (vec.size() == 0) throw EmptyContainerException();
    T maxEl = vec[0];
    for (int i = 1; i < vec.size(); i++) {
        if (maxEl < vec[i]) {
            maxEl = vec[i];
        }
    }
    return maxEl;
}

template<class T>
T maxElement(const T arr[], int n)
{
    if (n == 0) throw EmptyContainerException();
    T maxEl = arr[0];
    for (int i = 1; i < n; i++) {
        if (maxEl < arr[i]) {
            maxEl = arr[i];
        }
    }
    return maxEl;
}

template<class T>
T maxElement(const T *itrBegin, const T *itrEnd)
{
    if (itrBegin == itrEnd) throw EmptyContainerException();
    T maxEl = *itrBegin;
    for (auto ptr = itrBegin; ptr != itrEnd; ptr++) {
        if (maxEl < *ptr) {
            maxEl = *ptr;
        }
    }
    return maxEl;
}
