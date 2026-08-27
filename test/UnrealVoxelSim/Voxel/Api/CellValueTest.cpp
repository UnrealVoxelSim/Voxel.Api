#include "UnrealVoxelSim/Voxel/Api/CellValue.h"

#include <gtest/gtest.h>

namespace UnrealVoxelSim::Voxel::Api
{
namespace
{

static_assert(CellValue{}.IsEmpty());
static_assert(!CellValue{42}.IsEmpty());
static_assert(CellValue{42}.Value() == 42);

TEST(CellValueTest, ZeroIsTheCanonicalEmptyValue)
{
    EXPECT_TRUE(CellValue{}.IsEmpty());
    EXPECT_EQ(CellValue{}.Value(), 0U);
}

}
}
