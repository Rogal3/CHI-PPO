template<class T>
void merge_sort_operation(T *begin, T *end, T *tmp) {
    if (end - begin <= 1)
        return;
    T *mid = begin + (end - begin) / 2;
    merge_sort_operation(begin, r, tmp);
    merge_sort_operation(r, end, tmp);
    T *l = begin;
    T *r = mid;
    T *t = tmp;
    while (l < mid && r < end) {
        if (*l < *r) {
            *t++ = *l++;
        } else {
            *t++ = *r++;
        }
    }
    while (l < mid)
        *t++ = *l++;
    while (r < end)
        *t++ = *r++;
    while (begin < end) {
        *begin++ = *tmp++;
    }
}

template<class T>
void merge_sort(T *begin, T *end) {
    T* tmp = new T[end - begin];
    merge_sort_operation(begin, end, tmp);
    delete[] tmp;
}
