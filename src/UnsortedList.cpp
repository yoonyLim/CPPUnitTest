#include "UnsortedList.h"

UnsortedList::UnsortedList() {
    listData = NULL;
}

UnsortedList::~UnsortedList() {
    NodeType* temp;

    while (listData != NULL) {
        temp = listData;
        listData = listData->next;
        delete temp;
    }
}

void UnsortedList::InsertItem(int item) {
    NodeType* node = new NodeType;
    node->data = item;

    node->next = listData;
    listData = node;
}

void UnsortedList::ResetLoc() {
    curPtr = listData;
}

NodeType* UnsortedList::MinLoc(NodeType* location, NodeType* minPtr) {
    if (location != NULL) {
        if (location->data < minPtr->data)
            minPtr = location;

        return MinLoc(location->next, minPtr);
    } else {
        return minPtr;
    }
}

void UnsortedList::Sort(NodeType* location) {
    NodeType* minPtr;
    int temp;

    if (location != NULL && location->next != NULL) {
        minPtr = MinLoc(location, location);
        temp = minPtr->data;
        minPtr->data = location->data;
        location->data = temp;

        Sort(location->next);
    }
}

std::string UnsortedList::GetList() {
    ResetLoc();

    std::string res = "";

    while (curPtr != NULL) {
        res += std::to_string(curPtr->data);
        curPtr = curPtr->next;
    }

    return res;
}

std::string UnsortedList::GetSortedList() {
    Sort(listData);

    ResetLoc();

    std::string res = "";

    while (curPtr != NULL) {
        res += std::to_string(curPtr->data);
        curPtr = curPtr->next;
    }

    return res;
}
