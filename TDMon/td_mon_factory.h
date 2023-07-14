#pragma once

#include <TDMon/td_mon.h>

#include <memory>

namespace tdmon {
class TdMonFactory {
 public:
  virtual ~TdMonFactory() = default;

  virtual std::unique_ptr<TdMon> create() = 0;
};
}  // namespace tdmon
