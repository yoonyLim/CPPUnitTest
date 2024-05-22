#include "gmock/gmock.h"
#include "UnsortedList.h"

// https://www.youtube.com/watch?v=dLB2aDasVTg&list=PL_dsdStdDXbo-zApdWB5XiF2aWpsqzV55
class MockUnsortedList: public UnsortedList {
public:
	MOCK_METHOD0(GetList, std::string());
};

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
};

TEST(UnsortedListTest, CompareUnsortedListTest) {
	MockUnsortedList mockList;
	TestUnsortedList list(mockList);

	list.InsertItem(1);
	list.InsertItem(3);
	list.InsertItem(2);
	list.InsertItem(5);

	EXPECT_EQ(list.GetList(), "5231");
}
