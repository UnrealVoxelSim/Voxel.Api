#pragma once

#include "UnrealVoxelSim/Voxel/Api/CellMutation.h"
#include "UnrealVoxelSim/Voxel/Api/EditFailure.h"
#include "UnrealVoxelSim/Voxel/Api/EditResult.h"

#include <expected>
#include <span>

namespace UnrealVoxelSim::Voxel::Api
{
	class IEditor
	{
	public:
		virtual ~IEditor() = default;

		[[nodiscard]] virtual std::expected<EditResult, EditFailure> Apply(std::span<const CellMutation> mutations) = 0;
	};
} // namespace UnrealVoxelSim::Voxel::Api
