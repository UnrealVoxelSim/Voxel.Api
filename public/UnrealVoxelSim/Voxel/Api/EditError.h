#pragma once

namespace UnrealVoxelSim::Voxel::Api
{
	enum class EditError
	{
		OutOfBounds,
		DuplicatePosition,
		ValueConflict,
	};
}
