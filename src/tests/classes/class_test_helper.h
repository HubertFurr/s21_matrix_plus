
class S21TestHelper final {
 private:
 public:
  static constexpr double epsilon_ = 1e-7;
  static constexpr int random_test_num_ = 50;

  S21TestHelper() = delete;
  ~S21TestHelper() = delete;
  static int GetRandInt(const int min, const int max);
  static double GetRandDouble(const double min, const double max);
};
