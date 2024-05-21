#include "gtest/gtest.h"
#include "UnsortedList.h"

TEST(UnsortedListTest, CompareUnsortedListTest) {
	UnsortedList list;

	list.InsertItem(1);
	list.InsertItem(3);
	list.InsertItem(2);
	list.InsertItem(5);

	EXPECT_EQ(list.GetList(), "5231");
}
