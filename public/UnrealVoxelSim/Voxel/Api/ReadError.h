#pragma once

namespace UnrealVoxelSim::Voxel::Api
{
	enum class ReadError
	{
		OutOfBounds,
		InvalidRegion,
		RegionVolumeOverflow,
		OutputSizeMismatch,
	};
} // namespace UnrealVoxelSim::Voxel::Api
