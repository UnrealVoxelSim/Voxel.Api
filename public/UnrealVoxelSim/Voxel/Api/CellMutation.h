#pragma once

#include "UnrealVoxelSim/Voxel/Api/CellValue.h"
#include "UnrealVoxelSim/Voxel/Api/Position.h"

namespace UnrealVoxelSim::Voxel::Api
{

struct CellMutation final
{
    Position Position{};
    CellValue Expected{};
    CellValue Desired{};
};

} // namespace UnrealVoxelSim::Voxel::Api
