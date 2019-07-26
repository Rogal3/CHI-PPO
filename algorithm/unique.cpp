// ===================================================
//  
//  unique.cpp
//  left only unique
//  Rogal3
//  
// ===================================================

template<class It>
It unique(It begin, It end) {
    It l = begin, r = begin + 1;
    while (r < end) {
        if (*l == *r) {
            ++r;
        } else {
            *l++ = *r++;
        }
    }
    return l + 1;
}
