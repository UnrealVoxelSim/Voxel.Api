#include "UnrealVoxelSim/Voxel/Api/Region.h"

#include <gtest/gtest.h>

namespace UnrealVoxelSim::Voxel::Api
{
namespace
{

TEST(RegionTest, UsesMinimumInclusiveMaximumExclusiveBounds)
{
    constexpr Region region{{-2, 3, 4}, {2, 5, 7}};

    EXPECT_TRUE(region.Contains(Position{-2, 3, 4}));
    EXPECT_TRUE(region.Contains(Position{1, 4, 6}));
    EXPECT_FALSE(region.Contains(Position{2, 4, 6}));
    EXPECT_FALSE(region.Contains(Position{1, 5, 6}));
}

TEST(RegionTest, CountsCellsWithoutSignedOverflow)
{
    constexpr Region region{{-2, 3, 4}, {2, 5, 7}};

    ASSERT_TRUE(region.CellCount().has_value());
    EXPECT_EQ(*region.CellCount(), 24U);
}

TEST(RegionTest, RejectsInvertedBounds)
{
    constexpr Region region{{1, 0, 0}, {0, 1, 1}};

    EXPECT_FALSE(region.IsValid());
    EXPECT_FALSE(region.CellCount().has_value());
}

} // namespace
} // namespace UnrealVoxelSim::Voxel::Api
