#include "solution.hpp"

uint16_t checksum(const Blob& blob) {
  uint32_t acc = 0;
  for (const auto value : blob) {
    acc += value;
  }

  auto high = acc >> 16;
  auto low = acc & 0xFFFFu;
  // 包装加法以确保结果适合 16 位，用于校验和计算。
  acc = low + high;

  high = acc >> 16;
  low = acc & 0xFFFFu;
  acc = low + high;
  // 校验和算法通过迭代对 16 位高电平和低电平部分求和，将 32 位累加器减少到 16 位，直到没有溢出。
  return static_cast<uint16_t>(acc);
}
