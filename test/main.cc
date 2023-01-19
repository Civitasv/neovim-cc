#define APPROVALS_GOOGLETEST  // This tells Approval Tests to provide a main() -
                              // only do this in one cpp file
#include "approval/ApprovalTests.hpp"
// end-snippet

auto directoryDisposer =
    ApprovalTests::Approvals::useApprovalsSubdirectory("approval_tests");

auto path = "nvim";
auto arguments = "-d -O {Approved} {Received}";
auto reporter =
    ApprovalTests::CustomReporter::createForegroundReporter(path, arguments);
auto defaultReporterDisposer =
    ApprovalTests::Approvals::useAsDefaultReporter(reporter);
