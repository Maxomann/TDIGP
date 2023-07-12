#pragma once

namespace tdm {
class ConnectableToDataSources {
 public:
  virtual ~ConnectableToDataSources() = default;

  virtual void connectToDataSources() = 0;
  virtual bool isRequiredDataAccessInformationAvailable() = 0;
  virtual bool isConnectedToDataSources() = 0;
};
}  // namespace tdm
