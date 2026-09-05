#include "UnrealVoxelSim/Voxel/Api/Set.h"

#include <gtest/gtest.h>

#include <array>
#include <vector>

namespace UnrealVoxelSim::Voxel::Api
{
	TEST(SetTest, CanonicalizesAndQueriesPositions)
	{
		Set set{std::vector<Position>{{2, 0, 0}, {1, 0, 0}, {2, 0, 0}}};

		ASSERT_EQ(set.Size(), 2U);
		EXPECT_TRUE(set.Contains({1, 0, 0}));
		EXPECT_TRUE(set.Contains({2, 0, 0}));
		EXPECT_FALSE(set.Contains({3, 0, 0}));
		EXPECT_EQ(set.Positions()[0], (Position{1, 0, 0}));
	}

	TEST(SetTest, InsertsAndErasesWithoutDuplicates)
	{
		Set set;

		EXPECT_TRUE(set.Insert({1, 2, 3}));
		EXPECT_FALSE(set.Insert({1, 2, 3}));
		EXPECT_TRUE(set.Erase({1, 2, 3}));
		EXPECT_FALSE(set.Erase({1, 2, 3}));
		EXPECT_TRUE(set.IsEmpty());
	}
}
