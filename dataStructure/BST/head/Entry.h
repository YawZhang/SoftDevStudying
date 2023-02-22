

template <typename K, typename V> struct Entry{//词条模板类
    K key; V value; // 关键码，数值
    Entry( K k = K(), V v = V() ): key(k), value(v) {};//默认构造
    Entry( Entry<K, V> const& e): key(e.key), value(e.value) {};//拷贝构造

    //比较器 大于 小于 等于 不等于
    bool operator> (Entry<K, V> const& e) { return key > e.key;}
    bool operator< (Entry<K, V> const& e) { return key < e.key;}
    bool operator= (Entry<K, V> const& e) { return key = e.key;}
    bool operator!= (Entry<K, V> const& e) { return key != e.key;}
}//得益于比较器和判别器，从此往后，不必严格区分词条和其对应的关键码