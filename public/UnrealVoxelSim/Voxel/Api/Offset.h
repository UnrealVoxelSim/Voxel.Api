#pragma once

#include <compare>
#include <cstdint>
#include <type_traits>

namespace UnrealVoxelSim::Voxel::Api
{
	struct Offset final
	{
		std::int32_t X{};
		std::int32_t Y{};
		std::int32_t Z{};

		auto operator<=>(const Offset&) const = default;
	};

	static_assert(std::is_trivially_copyable_v<Offset>);
}
