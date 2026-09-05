#pragma once

#include "UnrealVoxelSim/Voxel/Api/Position.h"

#include <algorithm>
#include <cstddef>
#include <span>
#include <utility>
#include <vector>

namespace UnrealVoxelSim::Voxel::Api
{
	class Set final
	{
	public:
		Set() = default;

		explicit Set(std::vector<Position> positions) : m_Positions(std::move(positions))
		{
			std::ranges::sort(m_Positions);
			m_Positions.erase(std::ranges::unique(m_Positions).begin(), m_Positions.end());
		}

		[[nodiscard]] bool Contains(const Position position) const noexcept
		{
			return std::ranges::binary_search(m_Positions, position);
		}

		[[nodiscard]] bool Insert(const Position position)
		{
			const auto iterator = std::ranges::lower_bound(m_Positions, position);
			if (iterator != m_Positions.end() && *iterator == position)
			{
				return false;
			}
			m_Positions.insert(iterator, position);
			return true;
		}

		[[nodiscard]] bool Erase(const Position position) noexcept
		{
			const auto iterator = std::ranges::lower_bound(m_Positions, position);
			if (iterator == m_Positions.end() || *iterator != position)
			{
				return false;
			}
			m_Positions.erase(iterator);
			return true;
		}

		[[nodiscard]] std::size_t Size() const noexcept
		{
			return m_Positions.size();
		}

		[[nodiscard]] bool IsEmpty() const noexcept
		{
			return m_Positions.empty();
		}

		[[nodiscard]] std::span<const Position> Positions() const noexcept
		{
			return m_Positions;
		}

		auto operator<=>(const Set&) const = default;

	private:
		std::vector<Position> m_Positions;
	};
}
