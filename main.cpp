#include "Bombs.cpp" 
#include "gtest/gtest.h"

TEST(MaxDetonatedBombsTest, ExampleOne) {
    Detonation detonation;
    std::vector<Bomb> bombs = { {2, 1, 3}, {6, 1, 4} };
    auto result = detonation.findMaxDetonatedBomb(bombs);

    ASSERT_EQ(result.first, 2);
    ASSERT_EQ(result.second[0], 6);
    ASSERT_EQ(result.second[1], 1);
    ASSERT_EQ(result.second[2], 4);
}

TEST(MaxDetonatedBombsTest, ExampleTwo) {
    Detonation detonation;
    std::vector<Bomb> bombs = { {1, 1, 5}, {10, 10, 5} };
    auto result = detonation.findMaxDetonatedBomb(bombs);

    ASSERT_EQ(result.first, 1);
}

TEST(MaxDetonatedBombsTest, ExampleThree) {
    Detonation detonation;
    std::vector<Bomb> bombs = { {1, 2, 3}, {2, 3, 1}, {3, 4, 2}, {4, 5, 3}, {5, 6, 4} };
    auto result = detonation.findMaxDetonatedBomb(bombs);

    ASSERT_EQ(result.first, 5);
    ASSERT_EQ(result.second[0], 1);
    ASSERT_EQ(result.second[1], 2);
    ASSERT_EQ(result.second[2], 3);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
