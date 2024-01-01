#ifndef MORRIS_BASE_COUNTDOWNLATCH_H
#define MORRIS_BASE_COUNTDOWNLATCH_H
#include <condition_variable>
#include <mutex>

namespace morris {

class CountDownLatch {
 public:
  explicit CountDownLatch(int cnt);
  void wait();
  void count_down();
  int get_count();

  CountDownLatch(const CountDownLatch&) = delete;
  CountDownLatch& operator=(const CountDownLatch&) = delete;

 private:
  std::mutex mtx;
  std::condition_variable cond;
  int count;
};

}  // namespace morris

#endif
