#include "UnrealVoxelSim/Voxel/Api/FaceNeighborOffsets.h"

#include <gtest/gtest.h>

namespace UnrealVoxelSim::Voxel::Api
{
namespace
{

TEST(VoxelTopologyTest, DeclaresExactlyTheSixFaceNeighbors)
{
    EXPECT_EQ(FaceNeighborOffsets.size(), 6U);
    EXPECT_EQ(FaceNeighborOffsets[0], (Offset{-1, 0, 0}));
    EXPECT_EQ(FaceNeighborOffsets[5], (Offset{0, 0, 1}));
}

}
}
