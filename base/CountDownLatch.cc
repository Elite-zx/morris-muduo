#include "CountDownLatch.h"

#include <condition_variable>
using namespace morris;

CountDownLatch::CountDownLatch(int cnt) : mtx(), cond(), count(cnt) {}

void CountDownLatch::wait() {
  std::unique_lock<std::mutex> lk(mtx);
  cond.wait(lk, [&] { return count > 0; });
}

void CountDownLatch::count_down() {
  std::lock_guard<std::mutex> lk(mtx);
  --count;
  if (count == 0) cond.notify_all();
}

int CountDownLatch::get_count() {
  std::lock_guard<std::mutex> lk(mtx);
  return count;
}
