#include "gmock/gmock.h"
#include "UnsortedList.h"

/*
 * @brief Mock class to be used for test
 * @pre Each function is a mock method that takes in zero argument
 */
class MockUnsortedList: public UnsortedList {
public:
	MOCK_METHOD0(GetList, std::string());
	MOCK_METHOD0(GetSortedList, std::string());
};

/*
 * @brief Test class to utiltize mock object
 * @pre Mock instance initializes UnsortedList member variable
 */
class TestUnsortedList {
private:
	UnsortedList& testList;
public:
	TestUnsortedList(UnsortedList& _testList) : testList(_testList) {}

	void InsertItem(int num) {
		testList.InsertItem(num);
	}

	std::string GetList() {
		return testList.GetList();
	}

	std::string GetSortedList() {
		return testList.GetSortedList();
	}
};

/*
 * @brief Google Test Case: compare unsorted list for given inputs / Test Suite: Unsorted List Test
 */
TEST(UnsortedListTest, CompareUnsortedListTest) {
	MockUnsortedList mockList;
	TestUnsortedList list(mockList);

	list.InsertItem(1);
	list.InsertItem(3);
	list.InsertItem(2);
	list.InsertItem(5);

	EXPECT_EQ(list.GetList(), "5231");
}

/*
 * @brief Google Test Case: compare sorted list for given inputs / Test Suite: Unsorted List Test
 */
TEST(UnsortedListTest, CompareSortedListTest) {
	MockUnsortedList mockList;
	TestUnsortedList list(mockList);

	list.InsertItem(1);
	list.InsertItem(3);
	list.InsertItem(2);
	list.InsertItem(5);

	EXPECT_EQ(list.GetSortedList(), "1235");
}
