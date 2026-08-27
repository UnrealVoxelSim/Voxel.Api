#pragma once

#include <compare>
#include <cstdint>
#include <type_traits>

namespace UnrealVoxelSim::Voxel::Api
{
	class CellValue final
	{
	public:
		constexpr CellValue() noexcept = default;

		explicit constexpr CellValue(const std::uint32_t value) noexcept : m_Value(value)
		{
		}

		[[nodiscard]] constexpr bool IsEmpty() const noexcept
		{
			return m_Value == 0;
		}

		[[nodiscard]] constexpr std::uint32_t Value() const noexcept
		{
			return m_Value;
		}

		auto operator<=>(const CellValue&) const = default;

	private:
		std::uint32_t m_Value{};
	};

	static_assert(sizeof(CellValue) == sizeof(std::uint32_t));
	static_assert(std::is_trivially_copyable_v<CellValue>);
} // namespace UnrealVoxelSim::Voxel::Api
