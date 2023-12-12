#include <gtest/gtest.h>
#include "factory_npc.h"
#include "editor.h"
#include <cstdio>

using namespace lab06;

/*----------------FACTORY--------------------------------*/

TEST(factory, init) {
    FactoryNPC f;
    NPC* orc = f.create(ORC, "orc_name");
    ASSERT_FALSE(orc == nullptr);
    NPC* knight = f.create(KNIGHT_ERRANT, "knight_name");
    ASSERT_FALSE(knight == nullptr);
    NPC* bear = f.create(BEAR, "bear_name");
    ASSERT_FALSE(bear == nullptr);
}

TEST(factory, exception) {
    FactoryNPC f;
    ASSERT_ANY_THROW(f.create((TypeNPC) 123, "name"));
}

/*-----------------EDITOR------------------------------*/

TEST(editor, init) {
    Editor e;
    e.create_NPC(ORC, "orc_name", std::make_pair(0, 0));
    e.create_NPC(BEAR, "bear_name", std::make_pair(5, 50));
    e.create_NPC(KNIGHT_ERRANT, "knight_name", std::make_pair(50, 5));
    ASSERT_EQ(3, e.count_npc());
}

TEST(editor, delete_npc) {
    Editor e;
    for (int i = 0; i < 100; ++i) {
        e.create_NPC(BEAR, std::to_string(i), std::make_pair(i, i));
    }
    ASSERT_EQ(100, e.count_npc());
    for (int i = 0; i < 100; ++i) {
        e.delete_NPC(std::make_pair(i, i));
    }
    ASSERT_EQ(0, e.count_npc());
}

TEST(editor, move_npc) {
    Editor e;
    e.create_NPC(BEAR, "bear_name", std::make_pair(0, 0));
    e.move_NPC(std::make_pair(0, 0), std::make_pair(50, 50));
    ASSERT_EQ(e.count_npc(), 1);
    e.delete_NPC(std::make_pair(50, 50));
    ASSERT_EQ(e.count_npc(), 0);
}

TEST(editor, file) {
    Editor e;
    for (int i = 0; i < 100; ++i) {
        e.create_NPC(BEAR, std::to_string(i), std::make_pair(i, i));
    }
    char filename[L_tmpnam];
    std::tmpnam(filename);
    e.save_to_file(filename);
    Editor other;
    other.load_from_file(filename);
    ASSERT_EQ(other.count_npc(), 100);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
