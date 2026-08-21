#pragma once

#include "UnrealVoxelSim/Voxel/Api/Region.h"

namespace UnrealVoxelSim::Voxel::Api
{

class IBounds
{
  public:
    virtual ~IBounds() = default;

    [[nodiscard]] virtual Region Bounds() const noexcept = 0;
};

} // namespace UnrealVoxelSim::Voxel::Api
