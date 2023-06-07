//all_of - возвращает true, если все элементы диапазона удовлетворяют некоторому предикату. Иначе false
//any_of - возвращает true, если хотя бы один из элементов диапазона удовлетворяет некоторому предикату. Иначе false
//none_of - возвращает true, если все элементы диапазона не удовлетворяют некоторому предикату. Иначе false
//one_of - возвращает true, если ровно один элемент диапазона удовлетворяет некоторому предикату. Иначе false
//is_sorted - возвращает true, если все элементы диапазона находятся в отсортированном порядке относительно некоторого критерия
//is_partitioned - возвращает true, если в диапазоне есть элемент, делящий все элементы на удовлетворяющие и не удовлетворяющие - некоторому предикату. Иначе false.
//find_not - находит первый элемент, не равный заданному
//find_backward - находит первый элемент, равный заданному, с конца
//is_palindrome - возвращает true, если заданная последовательность является палиндромом относительно некоторого условия. Иначе false.
#include "stack"

namespace algorithms {

template<class Iterator, class Predicate>
bool all_of(Iterator begin, Iterator end, Predicate condition) {
  for (Iterator i = begin; i < end; ++i) {
    if (!condition(*i)) {
      return false;
    }
  }

  return true;
}

template<class Iterator, class Predicate>
bool any_of(Iterator begin, Iterator end, Predicate condition) {
  for (Iterator i = begin; i < end; ++i) {
    if (condition(*i)) {
      return true;
    }
  }

  return false;
}

template<class Iterator, class Predicate>
bool none_of(Iterator begin, Iterator end, Predicate condition) {
  for (Iterator i = begin; i < end; ++i) {
    if (condition(*i)) {
      return false;
    }
  }

  return true;
}

template<class Iterator, class Predicate>
bool one_of(Iterator begin, Iterator end, Predicate condition) {
  bool found = false;
  for (Iterator i = begin; i < end; ++i) {
    if (condition(*i) and !found) {
      found = true;
    } else if (condition(*i) and found) {
      return false;
    }
  }
  if (found) {
    return true;
  }

  return false;
}

template<class Iterator, class Predicate>
bool is_sorted(Iterator begin, Iterator end, Predicate condition) {
  Iterator prev;
  prev = begin;
  for (Iterator i = ++begin; i < end; ++i) {
    if (!condition(*prev, *i)) {
      return false;
    }
    prev = i;
  }

  return true;
}

template<class Iterator>
bool is_sorted(Iterator begin, Iterator end) {
  Iterator prev;
  prev = begin;
  for (Iterator i = ++begin; i < end; ++i) {
    if (*prev > *i) {
      return false;
    }
    prev = i;
  }

  return true;
}

template<class Iterator, class Predicate>
bool is_partitioned(Iterator begin, Iterator end, Predicate condition) {
  if (end - begin < 2) {
    return false;
  }
  Iterator tmp = begin;
  for (; tmp != end; ++tmp) {
    if (!condition(*tmp)) {
      break;
    }
  }
  for (; tmp != end; ++tmp) {
    if (condition(*tmp)) {
      return false;
    }
  }

  return true;
}

template<class Iterator, class T>
Iterator find_not(Iterator begin, Iterator end, const T& value) {
  for (Iterator i = begin; i != end; ++i) {
    if (*i != value) {
      return i;
    }
  }
  return end;
}

template<class Iterator, class T>
Iterator find_backward(Iterator begin, Iterator end, const T& value) {
  if (end - begin < 1) {
    return end;
  }
  Iterator backward;
  backward = begin;
  for (Iterator i = begin; i != end; i++) {
    if (*i == value) {
      backward = i;
    }
  }
  if (*begin != value and backward != begin or *begin == value and backward == begin) {
    return backward;
  }

  return end;
}

template<class Iterator, class Predicate>
bool is_palindrome(Iterator begin, Iterator end, Predicate condition = [](char x, char y){ return x == y; }) {
  int cnt = 0;
  for (Iterator i = begin; i != end; i++, cnt++) {}
  if (cnt == 0 or cnt == 1) {
    return true;
  }
  std::stack<Iterator> reversed;
  Iterator tmp = begin;
  for (int i = 0; i < cnt / 2; i++, tmp++) {
    reversed.push(tmp);
  }
  if (cnt % 2 == 1) {
    tmp++;
  }
  for (; tmp != end; tmp++) {
    if (!condition(*tmp, *reversed.top())) {
      return false;
    }
    reversed.pop();
  }

  return true;
}

template<class Iterator>
bool is_palindrome(Iterator begin, Iterator end) {
  if (begin == end) {
    return true;
  }
  int cnt = 0;
  for (Iterator i = begin; i != end; i++, cnt++) {}
  if (cnt == 0 or cnt == 1) {
    return true;
  }
  std::stack<Iterator> reversed;
  Iterator tmp = begin;
  for (int i = 0; i < cnt / 2; i++, tmp++) {
    reversed.push(tmp);
  }
  if (cnt % 2 == 1) {
    tmp++;
  }
  for (; tmp != end; tmp++) {
    if (*tmp != *reversed.top()) {
      return false;
    }
    reversed.pop();
  }

  return true;
}

template<class Iterator, class Predicate>
requires std::bidirectional_iterator<Iterator>
bool is_palindrome(Iterator begin, Iterator end, Predicate condition) {
  if (begin == end) {
    return true;
  }
  end--;
  for (; begin != end; begin++, end--) {
    if (!condition(*begin, *end)) {
      return false;
    }
  }

  return true;
}

template<class Iterator>
requires std::bidirectional_iterator<Iterator>
bool is_palindrome(Iterator begin, Iterator end) {
  if (begin == end) {
    return true;
  }
  end--;
  for (; begin != end; begin++, end--) {
    if (*begin != *end) {
      return false;
    }
  }

  return true;
}

}
