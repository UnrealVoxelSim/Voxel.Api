#pragma once

#include <cstddef>

namespace UnrealVoxelSim::Voxel::Api
{

struct EditResult final
{
    std::size_t ChangedCellCount{};
};

} // namespace UnrealVoxelSim::Voxel::Api
