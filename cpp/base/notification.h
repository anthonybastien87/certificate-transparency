#ifndef CERT_TRANS_BASE_NOTIFICATION_H_
#define CERT_TRANS_BASE_NOTIFICATION_H_

#include <condition_variable>
#include <mutex>

#include "base/macros.h"

namespace cert_trans {


class Notification {
 public:
  Notification() : notified_(false) {
  }

  void Notify();

  bool HasBeenNotified() const;

  void WaitForNotification() const;

 private:
  mutable std::mutex lock_;
  mutable std::condition_variable cv_;
  bool notified_;

  DISALLOW_COPY_AND_ASSIGN(Notification);
};


}  // namespace cert_trans

#endif  // CERT_TRANS_BASE_NOTIFICATION_H_
