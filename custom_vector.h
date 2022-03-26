#ifndef CUSTOM_VECTOR
#define CUSTOM_VECTOR

class custom_vector {
private:
    size_t n, allocated_n;
    int64_t *arr;
public:
    custom_vector(size_t n);
    ~custom_vector();
    custom_vector(const custom_vector &other);
    custom_vector& operator=(const custom_vector &other);

    int64_t& operator[](size_t i);

    void reserve(size_t new_size);
    void push_back(int64_t x);
};

void custom_vector::reserve(size_t new_size) {
    if (new_size <= allocated_n) {
        return;
    }
    allocated_n = new_size;
    int64_t *new_arr = new int64_t[allocated_n];
    for (size_t i = 0; i < n; i++) {
        new_arr[i] = arr[i];
    }
    delete[] arr;
    arr = new_arr;
}

void custom_vector::push_back(int64_t x) {
    if (!allocated_n) {
        reserve(1);
    }
    if (n == allocated_n) {
        reserve(allocated_n << 1);
    }
    arr[n++] = x;
}

custom_vector::custom_vector(size_t n = 0): n(n), allocated_n(n) {
    arr = new int64_t[allocated_n]{};
}

custom_vector::~custom_vector() {
    delete[] arr;
}

custom_vector::custom_vector(const custom_vector &other) {
    n = other.n;
    allocated_n = other.allocated_n;
    arr = new int64_t[allocated_n];
    for (size_t i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
}

custom_vector& custom_vector::operator=(const custom_vector &other) {
    n = other.n;
    allocated_n = other.allocated_n;
    delete[] arr;
    arr = new int64_t[allocated_n];
    for (size_t i = 0; i < n; ++i) {
        arr[i] = other.arr[i];
    }
    return *this;
}

int64_t& custom_vector::operator[](size_t i) {
    return arr[i];
}

#endif
