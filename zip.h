#include <iterator>

template<typename T, typename U>
class zip_iterator {
 public:
  using iterator_category = std::input_iterator_tag;
  using value_type = std::pair<typename T::value_type, typename U::value_type>;
  using difference_type = std::pair<typename T::value_type, typename U::value_type>;
  using pointer = std::pair<typename T::value_type, typename U::value_type>*;
  using reference = std::pair<typename T::value_type, typename U::value_type>&;

  zip_iterator(typename T::iterator first_iterator,
               typename U::iterator second_iterator)
      : first_iterator_(first_iterator), second_iterator_(second_iterator) {};

  zip_iterator& operator++() {
    first_iterator_++;
    second_iterator_++;

    return *this;
  }

  zip_iterator operator++(int) {
    zip_iterator copy(*this);
    ++(*this);

    return copy;
  }

  bool operator==(const zip_iterator& other) const {
    return (first_iterator_ == other.first_iterator_) or (second_iterator_ == other.second_iterator_);
  }

  bool operator!=(const zip_iterator& other) const {
    return !(*this == other);
  }

  value_type operator*() const {
    return std::make_pair(*first_iterator_, *second_iterator_);
  }

 private:
  typename T::iterator first_iterator_;
  typename U::iterator second_iterator_;
};

template<typename T, typename U>
class zip {
 public:
  using iterator = zip_iterator<T, U>;
  using const_iterator = const zip_iterator<T, U>;

  zip(T& first, U& second) : first_(first), second_(second) {}

  const_iterator cbegin() const {
    return const_iterator(first_.begin(), second_.begin());
  }

  const_iterator cend() const {
    return const_iterator(first_.end(), second_.end());
  }
  iterator begin() {
    return iterator(first_.begin(), second_.begin());
  }
  iterator end() {
    return iterator(first_.end(), second_.end());
  }

 private:
  T& first_;
  U& second_;
};

template<typename T, typename U>
zip(T, U) -> zip<T, U>;

template<typename T, typename U>
zip_iterator(T t, U u) -> zip_iterator<T, U>;