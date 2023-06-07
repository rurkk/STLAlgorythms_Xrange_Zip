
template <typename T>
class xrange_iterator {
 public:
  using value_type = T;
  using difference_type = T;
  using pointer = const T*;
  using reference = const T&;
  using iterator_category = std::input_iterator_tag;

  xrange_iterator(value_type value, value_type step) : value_(value), step_(step) {}

  xrange_iterator& operator++() {
    value_ += step_;

    return *this;
  }

  xrange_iterator operator++(int) {
    xrange_iterator copy(*this);
    ++(*this);

    return copy;
  }

  bool operator==(const xrange_iterator& other) const {
    return value_ == other.value_;
  }

  bool operator!=(const xrange_iterator& other) const {
    return value_ < other.value_;
  }

  reference operator*() const {
    return value_;
  }

  pointer operator->() const {
    return &value_;
  }

 private:
  value_type value_;
  value_type step_;
};

template <typename T>
class xrange {
 public:
  using value_type = T;
  using iterator = xrange_iterator<T>;
  using const_iterator = const iterator;

  explicit xrange(value_type stop) : start_(0), stop_(stop), step_(1) {}
  xrange(value_type start, value_type stop, value_type step = 1) : start_(start), stop_(stop), step_(step) {}

  const_iterator cbegin() const {
    return const_iterator(start_, step_);
  }

  const_iterator cend() const {
    return const_iterator(stop_, step_);
  }
  iterator begin() {
    return iterator(start_, step_);
  }
  iterator end() {
    return iterator(stop_, step_);
  }

 private:
  value_type start_;
  value_type stop_;
  value_type step_;
};

template <typename T>
xrange(T) -> xrange<T>;

template <typename T>
xrange(T, T) -> xrange<T>;

template <typename T>
xrange(T, T, T) -> xrange<T>;