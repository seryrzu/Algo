#include "list.h"
#include <gtest/gtest.h>

TEST(ListTest, SampleTest) {
   Node * root;
   add_to_list_front(root, 100); 
   ASSERT_TRUE(root);
}
