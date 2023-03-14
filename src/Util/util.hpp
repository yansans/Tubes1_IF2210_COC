#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <vector>
#include "../Exception/Exception.h"

/**
 * @brief return max element in a vector. OPERATOR< MUST EXIST FOR T
 * 
 * @tparam T 
 * @param vec - minimum size of 1
 * @return T 
 */
template<class T>
T maxElement(const std::vector<T> &vec);

/**
 * @brief return max element in an array. OPERATOR< MUST EXIST FOR T
 * 
 * @tparam T 
 * @param arr - minimum size of 1
 * @param n - size of array
 * @return T 
 */
template<class T>
T maxElement(const T arr[], int n);

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
T maxElement(const T *itrBegin, const T *itrEnd);

#endif