#pragma once

#include "UnrealVoxelSim/Voxel/Api/Region.h"

namespace UnrealVoxelSim::Voxel::Api
{
	class IBounds
	{
	public:
		virtual ~IBounds() = default;

		// TODO Rename to GetBounds()
		[[nodiscard]] virtual Region Bounds() const noexcept = 0;
	};
}
