// NOTE: this lab is currently broken.
// After migrating to a new compiler version the speedup is no longer measurable consistently.
// You can still try to solve it to learn the concept, but the result is not guaranteed.

#include <array>

// 假设这些常量永远不会改变
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME：此数据结构可以减小大小
struct S {
  float d;
  bool operator<(const S &s) const { return this->i < s.i; }
  long long l : 16;
  int       i : 8;
  short     s : 7;
  bool      b : 1;
};

// template <int N>
// class TD;

// TD<sizeof(S)> td;

void init(std::array<S, N> &arr);
S create_entry(int first_value, int second_value);
void solution(std::array<S, N> &arr);
