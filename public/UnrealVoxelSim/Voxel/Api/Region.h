#pragma once

#include "UnrealVoxelSim/Voxel/Api/Position.h"

#include <cstddef>
#include <cstdint>
#include <limits>
#include <optional>

namespace UnrealVoxelSim::Voxel::Api
{
	struct Region final
	{
		Position Min{};
		Position Max{};

		[[nodiscard]] constexpr bool IsValid() const noexcept
		{
			return Min.X <= Max.X && Min.Y <= Max.Y && Min.Z <= Max.Z;
		}

		[[nodiscard]] constexpr bool IsEmpty() const noexcept
		{
			return IsValid() && (Min.X == Max.X || Min.Y == Max.Y || Min.Z == Max.Z);
		}

		[[nodiscard]] constexpr bool Contains(const Position position) const noexcept
		{
			return IsValid() && position.X >= Min.X && position.X < Max.X && position.Y >= Min.Y && position.Y < Max.Y
				&&
				position.Z >= Min.Z && position.Z < Max.Z;
		}

		[[nodiscard]] constexpr bool Contains(const Region region) const noexcept
		{
			return IsValid() && region.IsValid() && region.Min.X >= Min.X && region.Max.X <= Max.X &&
				region.Min.Y >= Min.Y && region.Max.Y <= Max.Y && region.Min.Z >= Min.Z && region.Max.Z <= Max.Z;
		}

		[[nodiscard]] constexpr std::optional<std::size_t> CellCount() const noexcept
		{
			if (!IsValid())
			{
				return std::nullopt;
			}

			const auto x = static_cast<std::uint64_t>(static_cast<std::int64_t>(Max.X) - Min.X);
			const auto y = static_cast<std::uint64_t>(static_cast<std::int64_t>(Max.Y) - Min.Y);
			const auto z = static_cast<std::uint64_t>(static_cast<std::int64_t>(Max.Z) - Min.Z);
			constexpr auto Maximum = std::numeric_limits<std::size_t>::max();
			if (x != 0 && y > Maximum / x)
			{
				return std::nullopt;
			}
			const auto xy = x * y;
			if (xy != 0 && z > Maximum / xy)
			{
				return std::nullopt;
			}
			return static_cast<std::size_t>(xy * z);
		}

		auto operator<=>(const Region&) const = default;
	};
} // namespace UnrealVoxelSim::Voxel::Api
