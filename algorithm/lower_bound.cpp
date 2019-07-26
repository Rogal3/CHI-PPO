// ===================================================
//  
//  lower_bound.cpp
//  binary search
//  Rogal3
//  
// ===================================================

template<class It, class T, class Comp>
It lower_bound(It begin, It end, T data, Comp cmp) {
    It l = begin, r = end - 1;
    It p;
    while (l < r) {
        p = l + (r - l) / 2;
        if (cmp(*p, data)) {
            l = p + 1;
        } else if (cmp(data, *p)) {
            r = p - 1;
        } else {
            r = p;
        }
    }
    return l;
}
