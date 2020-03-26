// 10
struct myhash {
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now()
            .time_since_epoch()
            .count();
    x ^= FIXED_RANDOM;
    return x ^ (x >> 16);
  }
};