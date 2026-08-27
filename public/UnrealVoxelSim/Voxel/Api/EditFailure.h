#pragma once

#include "UnrealVoxelSim/Voxel/Api/CellValue.h"
#include "UnrealVoxelSim/Voxel/Api/EditError.h"

#include <cstddef>

namespace UnrealVoxelSim::Voxel::Api
{
	struct EditFailure final
	{
		EditError Error{};
		std::size_t MutationIndex{};
		CellValue Actual{};
	};
}
