namespace std
{
    template<class T>
    const T& max(const T&, const T&);

    template<class T>
    const T& min(const T&, const T&);
    
    template<class T>
    void swap(T&, T&);
    
    template<class I>
    void reverse(I, I);
    
    template<class I>
    I rotate(I, I, I);
    
    template<class I, class O>
    O copy(I, I, O);
    
    template<class I, class O>
    O copy_backward(I, I, O);
    
    template<class I, class O>
    O move(I, I, O);
    
    template<class I, class O>
    O move_backward(I, I, O);
    
    template<class I>
    long distance(I, I);
    
    template<class I, class T>
    I lower_bound(I, I, const T&);
    
    template<class I, class T, class R>
    I lower_bound(I, I, const T&, R);
    
    template<class I, class T>
    I upper_bound(I, I, const T&);
    
    template<class I, class T, class R>
    I upper_bound(I, I, const T&, R);
 
    template<class I, class T>
    pair<I, I> equal_range(I, I, const T&);
    
    template<class I, class T, class R>
    pair<I, I> equal_range(I, I, const T&, R);
    
    template<class I, class T>
    I find(I, I, const T&);

    template<class I, class T>
    long count(I, I, const T&);
    
    template<class I, class O, class P>
    O remove_copy(I, I, O, P);

    template<class I, class P>
    I remove(I, I, P);
    
    template<class I, class T>
    void fill(I, I, const T&);
    
    template<class I, class T, class Op>
    T accumulate(I, I, T, Op);
    
    template<class I, class F>
    F for_each(I, I, F);
    
    template<class I, class O, class F>
    O transform(I, I, O, F);
    
    template<class I, class R>
    void insertion_sort(I, I, R);
    
    template<class I>
    void insertion_sort(I, I);
    
    template<class I, class R>
    void sort(I, I, R);
    
    template<class I>
    void sort(I, I);
    
    template<class I1, class I2, class R>
    bool equal(I1, I1, I2, I2, R);

    template<class I1, class I2>
    bool equal(I1, I1, I2, I2);
    
    template<class I1, class I2, class R>
    bool lexicographical_compare(I1, I1, I2, I2, R);

    template<class I1, class I2>
    bool lexicographical_compare(I1, I1, I2, I2);
    
    template<class I>
    I min_element(I, I);
    
    template<class T, class R>
    I min_element(I, I, R);
    
    template<class I>
    I max_element(I, I);
    
    template<class T, class R>
    I max_element(I, I, R);
    
    template<class T>
    T abs(const T&);
    
    template<class T>
    T gcd(T, T);
    
    template<class I>
    bool next_permutation(I, I);
    
    template<class I>
    bool prev_permutation(I, I);
    
    template<class I>
    void random_shuffle(I, I);
}
