
//
// Created by io0om on 30/04/2022.
//

#define CATCH_CONFIG_MAIN

#include "../Items.h"
#include "catch.hpp"


// test case to retrieve items based on id.
TEST_CASE("retrieve items, [getItems()]"){
    Items* i;
    int id=1;
    vector<string> itemsVector = i->getItems(id);

    REQUIRE(itemsVector[2] == "Treats");

}


//  test case to restock item, the new qty should be the sum of the old qty and the additional qty.
TEST_CASE("increase qty of items, [restockItem(), increaseQTY()]"){
    Items* i;
    int id = 1;
    int newqty = 1;
    vector<string> oldItems = i->getItems(id);
    i->restockItem(id,newqty);
    vector<string> itemsVector = i->getItems(id);
    int oldqty = stoi(oldItems[6]);

    // new qty should be
    REQUIRE(stoi(itemsVector[6]) == (oldqty+newqty));

}


// test case to sell items.
// items must have 0.0 initial sales to pass this test
TEST_CASE("selling items, [itemSell()]"){
    Items* i;
    int id = 1;
    int sold = 1;
    vector<string> oldVector = i->getItems(id);
    Items::itemSell(id,sold);
    vector<string> itemsVector = i->getItems(id);

    REQUIRE(stof(itemsVector[7]) == (stof(oldVector[3])));

}

