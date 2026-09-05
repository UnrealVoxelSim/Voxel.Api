find_package(GTest CONFIG REQUIRED)

add_executable(
    ${PROJECT_NAME}.Test
    UnrealVoxelSim/Voxel/Api/CellValueTest.cpp
    UnrealVoxelSim/Voxel/Api/RegionTest.cpp
    UnrealVoxelSim/Voxel/Api/SetTest.cpp
    UnrealVoxelSim/Voxel/Api/VoxelTopologyTest.cpp
)

target_link_libraries(
    ${PROJECT_NAME}.Test
    PRIVATE
        ${PROJECT_NAME}
        GTest::gtest_main
)

UnrealVoxelSimConfigureTarget(${PROJECT_NAME}.Test)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.Test)
