#include <cstdint>

// standard types for consistency across archatectures.

// Scheduler layer identifiers.
enum class ConType : std::uint32_t {
  WorkerNode = 1,
  Client = 2,
  ResourceManager = 3
};

// job layer identifiers
enum class WorkerType : std::uint32_t {
  MapWorker = 4,
  ReduceWorker = 5,
  JobController = 6
};
