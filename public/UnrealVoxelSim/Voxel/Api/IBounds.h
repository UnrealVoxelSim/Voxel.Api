#pragma once

#include "UnrealVoxelSim/Voxel/Api/Region.h"

namespace UnrealVoxelSim::Voxel::Api
{
	// TODO The role of this interface is unclear. "IBounds" is too generic and does not express
	// what object's bounds are being queried or which cross-domain use case this abstraction serves.
	class IBounds
	{
	public:
		virtual ~IBounds() = default;

		// TODO Rename to GetBounds()
		[[nodiscard]] virtual Region Bounds() const noexcept = 0;
	};
} // namespace UnrealVoxelSim::Voxel::Api
