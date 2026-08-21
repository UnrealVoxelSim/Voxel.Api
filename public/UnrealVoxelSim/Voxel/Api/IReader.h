#pragma once

#include "UnrealVoxelSim/Voxel/Api/CellValue.h"
#include "UnrealVoxelSim/Voxel/Api/Position.h"
#include "UnrealVoxelSim/Voxel/Api/ReadError.h"

#include <expected>

namespace UnrealVoxelSim::Voxel::Api
{

class IReader
{
  public:
    virtual ~IReader() = default;

    [[nodiscard]] virtual std::expected<CellValue, ReadError> Read(Position position) const noexcept = 0;
};

} // namespace UnrealVoxelSim::Voxel::Api
