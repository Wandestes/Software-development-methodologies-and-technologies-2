#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
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
    REQUIRE(list.get(1) == 'Z'); 
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

TEST_CASE("DoublyLinkedList: Edge Cases - Empty List") {
    DoublyLinkedList list;
    REQUIRE(list.length() == 0);
    

    REQUIRE_THROWS_AS(list.get(0), std::out_of_range);  
    REQUIRE_THROWS_AS(list.deleteAt(0), std::out_of_range);  
}

TEST_CASE("DoublyLinkedList: Edge Cases - Out of Bound") {
    DoublyLinkedList list;
    list.append('A');
    list.append('B');
    
    // Перевірка на вихід за межі списку
    REQUIRE_THROWS_AS(list.get(2), std::out_of_range); 
    REQUIRE_THROWS_AS(list.deleteAt(3), std::out_of_range);  

TEST_CASE("DoublyLinkedList: Clone") {
    DoublyLinkedList list;
    list.append('A');
    list.append('B');

    DoublyLinkedList clonedList = list.clone(); 

    REQUIRE(clonedList.length() == 2);
    REQUIRE(clonedList.get(0) == 'A');
    REQUIRE(clonedList.get(1) == 'B');
}

TEST_CASE("DoublyLinkedList: Extend") {
    DoublyLinkedList list;
    list.append('A');
    list.append('B');

    DoublyLinkedList listToExtend;
    listToExtend.append('C');
    listToExtend.append('D');

    list.extend(listToExtend);  

    REQUIRE(list.length() == 4);
    REQUIRE(list.get(2) == 'C');
    REQUIRE(list.get(3) == 'D');
}
