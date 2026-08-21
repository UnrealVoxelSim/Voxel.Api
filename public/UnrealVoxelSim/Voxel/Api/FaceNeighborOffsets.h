#pragma once

#include "UnrealVoxelSim/Voxel/Api/Offset.h"

#include <array>

namespace UnrealVoxelSim::Voxel::Api
{

inline constexpr std::array FaceNeighborOffsets{
    Offset{-1, 0, 0}, Offset{1, 0, 0}, Offset{0, -1, 0}, Offset{0, 1, 0}, Offset{0, 0, -1}, Offset{0, 0, 1},
};

} // namespace UnrealVoxelSim::Voxel::Api
