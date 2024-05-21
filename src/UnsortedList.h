#include <iostream>
#include <string>

template <class ItemType>
struct NodeType {
    ItemType data;
    NodeType* next;
};

template <class ItemType>
class UnsortedList {
    public:
    UnsortedList();
    ~UnsortedList();
    void InsertItem(ItemType item);
    std::string GetList();
    std::string GetSortedList();
    void ResetLoc();
    void Sort(NodeType<ItemType>* location);

    protected:
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr);

    private:
    NodeType<ItemType>* listData;
    NodeType<ItemType>* curPtr;
};