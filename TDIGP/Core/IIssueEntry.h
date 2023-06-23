#pragma once
#include <chrono>
#include <string>
#include <vector>

class IIssueEntry {
  using ProjectId = std::string;
  using IssueId = std::string;
  using DeveloperId = std::string;
  using IssueLabel = std::string;

  /*
  ProjectId projectId_;
  IssueId issueId_;

  std::chrono::year_month_day dateCreated_;
  std::optional<std::chrono::year_month_day> dateResolved_;

  DeveloperId createdBy_;
  DeveloperId resolvedBy_;
  */

  virtual const ProjectId& getProjectId() const = 0;
  virtual const IssueId& getIssueId() const = 0;

  virtual const std::vector<IssueLabel>& getLabels() const = 0;

  virtual const std::chrono::year_month_day& getDateCreated() const = 0;
  virtual bool isResolved() const = 0;
  virtual const std::chrono::year_month_day& getDateResolved() const = 0;
};
