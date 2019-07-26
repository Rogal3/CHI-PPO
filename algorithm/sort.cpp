// ===================================================
//  
//  sort.cpp
//  quick sort
//  cws0188
//  
// ===================================================

template<class T>
inline void swap_(T &a, T &b) {
    T t(a); a = b; b = t;
}

// [begin, end)
template<class Iter, class Comp>
void sort_(Iter begin, Iter end, Comp comp) {
    if (begin + 1 >= end)  // if size <= 1
        return;
    swap_(*begin, *(begin + (end - begin) / 2));
    Iter pivot = begin;
    Iter left = begin + 1;
    Iter right = end - 1;
    while (left <= right) {
        while (left <= right && !comp(*pivot, *left))
            ++left;
        while (left <= right && !comp(*right, *pivot))
            --right;
        if (left < right) 
            swap_(*left++, *right--);
    }
    swap_(*pivot, *right);
    sort_(begin, right, comp);  // [begin, pivot)
    sort_(right + 1, end, comp);  // (pivot, end)
}

/*
bool compare(int a, int b) {
    return a < b;
}
*/
