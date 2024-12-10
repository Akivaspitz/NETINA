#pragma once
#include <iostream>
#include <string>	
#include "Contacts.h"

Item::Item(const std::string& name, ItemType type, int size, int amount, const std::string& color) {                                  // setting the item up
    this->name1 = new std::string(name);
    this->color1 = new std::string(color);

    type1 = type;
    if (size <= 0 || size >= 60)
        size1 = 1;
    else
        size1 = size;
    amount1 = amount;
}

Item::Item(const std::string& name, int size) {
    this->name1 = new std::string(name);
    this->color1 = nullptr;

    type1 = ItemType::Other;
    if (size <= 0 || size >= 60)
        size1 = 1;
    else
        size1 = size;
    amount1 = 1;
}

Item::Item(const std::string& name, ItemType type) { 
    this->name1 = new std::string(name);
    this->color1 = nullptr;

    type1 = type;
    size1 = 1;
    amount1 = 1;
}

Item::Item(const std::string& name) { 
    this->name1 = new std::string(name);
    this->color1 = nullptr;

    type1 = ItemType::Other;
    size1 = 1;
    amount1 = 1;
}

Item::Item() { 
    
    this->name1 = nullptr; //std::string("no, name");
    this->color1 = nullptr;
    type1 = ItemType::Other;
    size1 = 1;
    amount1 = 1;
}

Item::~Item() {                                                              //deleting
    delete name1;
    name1 = nullptr;
    delete color1;
    color1 = nullptr;

}
void Item::deleteName() {
    delete name1;
    name1 = nullptr;

}

void Item::setName(const std::string& name) {                               // setting information
    this->name1 = new std::string(name);
}

void Item::setColor(const std::string& color) {                               
    this->color1 = new std::string(color);
}

void Item::setType(ItemType type) {
    type1 = type;
}

void Item::setSize(int size) {
    size1 = size;
}

void Item::setAmount(int amount) {
    amount1 = amount;
}

int Item::getSize() const {                                              // getting information
    std::cout << "Item size: " << size1 << endl;
    return size1;
}

 void Item::getType()  {
     std::cout << "Item type: " << typeToString(type1) << endl;
   return;
}

 void Item::printName() {
     std::cout << "Item name: " << *name1 << endl;
 }

 std::string Item::getName() const {
     if (name1 != nullptr) {
         return *name1;
     }
     else {
         return "NoName";
     }
 }

 std::string Item::getColor() const {
     if (color1 != nullptr) {
         return *color1;
     }
     else {
         return "No Color";
     }
 }

 int Item::getAmount() {
     std::cout << "Item amount: " << amount1 << endl;
     return amount1;
 }

 void Item::print() const {
     if (name1 != nullptr) {
         std::cout << "Item name: " << *name1 << endl;
     }
     else {
         std::cout << "Item name: None" << endl;
     }
     std::cout << "Item type: " << typeToString(type1) << endl;
     std::cout << "Item size: " << size1 << endl;
     if (color1 != nullptr) {
         std::cout << "Item color: " << *color1 << endl;
     }
     else {
         std::cout << "Item color: No color" << endl;
     }
     std::cout << "Item amount: " << amount1 << endl;
 }

 Item& Item::operator=(const Item& other) {
     if (this != &other) {
         type1 = other.type1;
         size1 = other.size1;
         amount1 = other.amount1;
         
         delete name1;
         name1 = (other.name1 != nullptr) ? new std::string(*(other.name1)) : nullptr;
         delete color1;
         color1 = (other.color1 != nullptr) ? new std::string(*(other.color1)) : nullptr;
     }

     return *this;

 }
 
 bool Item::operator==(const Item& other) const {
     return *name1 == *(other.name1);
 }

 bool Item::operator!=(const Item& other) const {
     return !(*this == other);
 }

 