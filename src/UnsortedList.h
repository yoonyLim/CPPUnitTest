#include <iostream>
#include <string>

struct NodeType {
    int data;
    NodeType* next;
};

class UnsortedList {
public:
    UnsortedList();
    ~UnsortedList();
    void InsertItem(int item);
    std::string GetList();
    std::string GetSortedList();
    void ResetLoc();
    void Sort(NodeType* location);

protected:
    NodeType* MinLoc(NodeType* location, NodeType* minPtr);

private:
    NodeType* listData;
    NodeType* curPtr;
};
