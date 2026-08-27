#pragma once

#include "UnrealVoxelSim/Voxel/Api/CellValue.h"
#include "UnrealVoxelSim/Voxel/Api/ReadError.h"
#include "UnrealVoxelSim/Voxel/Api/Region.h"

#include <expected>
#include <span>

namespace UnrealVoxelSim::Voxel::Api
{
	class IRegionReader
	{
	public:
		virtual ~IRegionReader() = default;

		// Output uses X-major, then Y, then Z logical order.
		[[nodiscard]] virtual std::expected<void, ReadError> ReadRegion(Region region,
		                                                                std::span<CellValue> output) const noexcept = 0;
	};
} // namespace UnrealVoxelSim::Voxel::Api
