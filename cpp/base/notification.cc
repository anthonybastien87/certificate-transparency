#include "base/notification.h"

#include <glog/logging.h>

using std::lock_guard;
using std::mutex;
using std::unique_lock;

namespace cert_trans {


void Notification::Notify() {
  lock_guard<mutex> lock(lock_);
  CHECK(!notified_);
  notified_ = true;
  cv_.notify_all();
}


bool Notification::HasBeenNotified() const {
  lock_guard<mutex> lock(lock_);
  return notified_;
}


void Notification::WaitForNotification() const {
  unique_lock<mutex> lock(lock_);
  cv_.wait(lock, [this]() { return notified_; });
}


}  // namespace cert_trans
