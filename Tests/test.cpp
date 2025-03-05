#define CATCH_CONFIG_MAIN
#include "catch/catch_amalgamated.hpp"
#include "DoublyLinkedList.h"

TEST_CASE("DoublyLinkedList: Append and Length") {
    DoublyLinkedList list;
    REQUIRE(list.length() == 0);

    list.append('A');
    REQUIRE(list.length() == 1);
    REQUIRE(list.get(0) == 'A');

    list.append('B');
    list.append('C');
    REQUIRE(list.length() == 3);
    REQUIRE(list.get(1) == 'B');
    REQUIRE(list.get(2) == 'C');
}

TEST_CASE("DoublyLinkedList: Insert") {
    DoublyLinkedList list;
    list.append('A');
    list.append('C');
    
    list.insert('B', 1);
    REQUIRE(list.length() == 3);
    REQUIRE(list.get(1) == 'B');
    REQUIRE(list.get(2) == 'C');
}

TEST_CASE("DoublyLinkedList: DeleteAt") {
    DoublyLinkedList list;
    list.append('A');
    list.append('B');
    list.append('C');

    char deleted = list.deleteAt(1);
    REQUIRE(deleted == 'B');
    REQUIRE(list.length() == 2);
    REQUIRE(list.get(1) == 'C');
}

TEST_CASE("DoublyLinkedList: Reverse") {
    DoublyLinkedList list;
    list.append('A');
    list.append('B');
    list.append('C');

    list.reverse();
    REQUIRE(list.get(0) == 'C');
    REQUIRE(list.get(1) == 'B');
    REQUIRE(list.get(2) == 'A');
}

TEST_CASE("DoublyLinkedList: FindFirst and FindLast") {
    DoublyLinkedList list;
    list.append('A');
    list.append('B');
    list.append('C');
    list.append('B');

    REQUIRE(list.findFirst('B') == 1);  
    REQUIRE(list.findLast('B') == 3);   
}
