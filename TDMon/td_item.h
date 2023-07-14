#pragma once

#include <chrono>
#include <string>
#include <vector>

namespace tdmon {
class TdItem {
 public:
  using IssueId = std::string;
  using DeveloperId = std::string;
  using IssueLabel = std::string;

  using Id = unsigned int;

  /*
  ProjectId projectId_;
  IssueId issueId_;

  std::chrono::year_month_day dateCreated_;
  std::optional<std::chrono::year_month_day> dateResolved_;

  DeveloperId createdBy_;
  DeveloperId resolvedBy_;
  */
  // virtual const ProjectId& getProjectId() const = 0;

  virtual ~TdItem() = default;

  virtual const Id& getId() const = 0;
  virtual const std::vector<IssueLabel>& getLabels() const = 0;

  virtual bool isResolved() const = 0;

  virtual const std::chrono::year_month_day& getDateCreated() const = 0;
  virtual const std::chrono::year_month_day& getDateResolved() const = 0;

  virtual const DeveloperId& getReportedBy() const = 0;
  virtual const DeveloperId& getResolvedBy() const = 0;
};
}  // namespace tdmon
