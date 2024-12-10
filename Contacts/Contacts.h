#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;

enum  ItemType {  // the different types of items 
    Game,
    Clothing,
    Electronics,
    Other
};


class Item { //the product that can be requested or donated 
private:
	std::string* name1;
    ItemType type1;
    int size1;
    int amount1;
    std::string* color1;

    std::string typeToString(ItemType type) const { 
        switch (type) {
        case Game:
            return "Game";
        case Clothing:
            return "Clothing";
        case Electronics:
            return "Electronics";
        default:
            return "Other";
        }
    }
public:
    Item(const std::string& name, ItemType type, int size, int amount, const std::string& color);  //contruction
    Item(const std::string& name, int size);
    Item(const std::string& name, ItemType type);
    Item(const std::string& name);
    Item();

    ~Item();                                                            //decontracion
    void deleteName();

    void setName(const std::string& name);                              // setting information
    void setType(ItemType type);
    void setSize(int size);
    void setAmount(int amount);
    void setColor(const std::string& color);
    
    int getSize() const;                                               // getting information
    void getType();
    void printName();
    std::string getName() const;
    std::string getColor() const;
    int getAmount();
    
    void print() const;

    Item& operator=(const Item& other);


    ItemType getType() const{ return type1; }

    bool operator==(const Item& other) const;
    bool operator!=(const Item& other) const;
    bool chechName(const Item& otherItem);

};


//                ||
//                ||
//                ||
//                ||
//                ||
//             \  ||  /
//              \ || /
//               \||/
//                \/





enum  ProposalType {                                      // the different types of proposals
    Request,
    Offer,
    Undifined
};

class Proposal : public Item {                                 //making an offer or a request + contact
private:
    ProposalType type1;
    Item item1;
    int number1;
    std::string location1;

    std::string typeToString(ProposalType type) const {
        switch (type) {
        case Request:
            return "Request";
        case Offer:
            return "Offer";
        default:
            return "Undifined";
        }
    }

public:
    Proposal(ProposalType type, const Item& item, int number, const std::string& location);    //contruction
   // Proposal(ProposalType type, Item* item, std::string* location);
   // Proposal(ProposalType type, Item* item, int number);
   // Proposal(ProposalType type, Item* item);
    Proposal();

    ~Proposal();                                                       //decontracion
    void deleteItemName();

    void setLocation(const std::string& location);                              // setting information
    void setType(ProposalType type);
    void setNumber(int number);


    int getNumber();                                           // getting information
    void getLocation();
    void getProposalType();
    void printProposal() const;

    const Item& getItem() const;
    bool compareItemNames(const Proposal& proposal1, const Proposal& proposal2) const;
};



//                ||
//                ||
//                ||
//                ||
//                ||
//             \  ||  /
//              \ || /
//               \||/
//                \/


class User : public Proposal {                                                             //making a user                                  
private:
    std::string name2;
    std::string email;
    std::vector<Proposal> proposals;
    
public:
    User(const std::string& userName, const std::string& userEmail);                       //contruction
    User();

    ~User();                                                            //decontracion
    void deleteItemNamesInProposals();


    void setUserName(const std::string& name);                              // setting information
    void setEmail(const std::string& email);                           
    void addProposal(const Proposal& newProposal);


    void getUserName();                                                  // getting information
    void getEmail();
    void getProposalList();
    
    void printUser();

    const std::vector<Proposal>& getProposals() const;
    void checkForMatches(const Proposal& proposal1, const User& anotherUser, const std::string& itemName);
    
};
