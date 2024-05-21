#include "UnsortedList.h"

template <class ItemType>
UnsortedList<ItemType>::UnsortedList() {
    listData = NULL;
}

template <class ItemType>
UnsortedList<ItemType>::~UnsortedList() {
    NodeType<ItemType>* temp;

    while (listData != NULL) {
        temp = listData;
        listData = listData->next;
        delete temp;
    }
}

template <class ItemType>
void UnsortedList<ItemType>::InsertItem(ItemType item) {
    NodeType<ItemType>* node = new NodeType<ItemType>;
    node->data = item;

    node->next = listData;
    listData = node;
}

template <class ItemType>
void UnsortedList<ItemType>::ResetLoc() {
    curPtr = listData;
}

template <class ItemType>
NodeType<ItemType>* UnsortedList<ItemType>::MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr) {
    if (location != NULL) {
        if (location->data < minPtr->data)
            minPtr = location;

        return MinLoc(location->next, minPtr);
    } else {
        return minPtr;
    }
}

template <class ItemType>
void UnsortedList<ItemType>::Sort(NodeType<ItemType>* location) {
    NodeType<ItemType>* minPtr;
    ItemType temp;

    if (location != NULL && location->next != NULL) {
        minPtr = MinLoc(location);
        temp = minPtr->data;
        minPtr->data = location->data;
        location->data = temp;

        Sort(location->next);
    }
}

template <class ItemType>
std::string UnsortedList<ItemType>::GetList() {
    ResetLoc();

    std::string res = "";

    while (curPtr != NULL) {
        res += curPtr->data;
        curPtr = curPtr->next;
    }

    return res;
}

template <class ItemType>
std::string UnsortedList<ItemType>::GetSortedList() {
    Sort(listData);

    ResetLoc();

    std::string res = "";

    while (curPtr != NULL) {
        res += curPtr->data;
        curPtr = curPtr->next;
    }

    return res;
}