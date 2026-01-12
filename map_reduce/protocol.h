#include <cstdint>

// standard types for consistency across archatectures.
enum class ConType : std::uint32_t { Worker = 1, Client = 2, Server = 3 };

enum class WorkerType : std::uint32_t { MapWorker = 1, ReduceWorker = 2 };
