#pragma once
#include <iostream>
#include <string>	
#include "Contacts.h"

Proposal::Proposal(ProposalType type, const Item& item, int number, const std::string& location)     //contruction
	: type1(type1), item1(item), number1(number), location1(location) {

}



Proposal::Proposal()
	: type1(ProposalType::Offer), item1(), number1(9999), location1("Default Location") {

	
}

Proposal::~Proposal() {                                                              //deleting
	deleteItemName();
}

void Proposal::deleteItemName() {
	item1.deleteName();
}

void Proposal::setLocation(const std::string& location) {                              // setting information
	this->location1 = std::string(location);

}

void Proposal::setType(ProposalType type) {
	type1 = type;
}

void Proposal::setNumber(int number) {
	number1 = number;
}

int Proposal::getNumber() {                                           // getting information
	std::cout << "Contact number: " << number1 << endl;
	return number1;
}

void Proposal::getLocation() {
	std::cout << "Contact location: " << location1 << endl;
}

void Proposal::getProposalType() {
	std::cout << "Proposal type: " << typeToString(type1) << endl;
}

void Proposal::printProposal() const{
	std::cout << "Proposal type: " << typeToString(type1) << endl;
	item1.print();
	std::cout << "Contact number: " << number1 << endl;
	if (location1 != "None") {
		std::cout << "Proposal location: " << location1 << endl;
	}
	else {
		std::cout << "Proposal location: None" << endl;
	}
}

const Item& Proposal::getItem() const {
	return item1;
}






//                ||
//                ||
//                ||
//                ||  
//                ||
//             \  ||  /
//              \ || /
//               \||/
//                \/                                                         //making a user 

User::User(const std::string& userName, const std::string& userEmail)         //contruction
	: name2(userName), email(userEmail) { 
}


User::User() 
	:name2("Jhon Doe"), email("No Email") {

}

User::~User() {
	deleteItemNamesInProposals();
}

void User::deleteItemNamesInProposals() {                                            //deleting
	for (Proposal& proposal : proposals) {
		proposal.deleteItemName();
	}
}

void User::setUserName(const std::string& name) {                              // setting information
	name2 = name;
}

void User::setEmail(const std::string& email1) {                             
	email = email1;
}

void User::addProposal(const Proposal& newProposal) {
	proposals.push_back(newProposal);
}

void User::getUserName() {                                                  // getting information
	std::cout << "Contact Name: " << name2 << endl;
}

void User::getEmail() {
	std::cout << "Contact Email: " << email << endl;
}

void User::getProposalList() {
	for (Proposal& proposal : proposals) {
		proposal.printProposal();
		cout << "************" << endl;

	}
}

const std::vector<Proposal>& User::getProposals() const {
	return proposals;
}

void User::printUser() {
	std::cout << "Contact Name: " << name2 << endl;
	std::cout << "Contact Email: " << email << endl;
	std::cout << "Proposal list:" << endl<<endl;

	for (Proposal& proposal : proposals) { 
		proposal.printProposal(); 
		cout << "************" << endl; 

	}
}


void User::checkForMatches(const Proposal& proposal1, const User& anotherUser, const std::string& itemName) {
	int sum = 0;
	for (const Proposal& anotherProposal : anotherUser.getProposals()) {
		if (proposal1.compareItemNames(proposal1, anotherProposal)) {
			std::cout << "Matching Proposal:\n";
			anotherProposal.printProposal();
			sum=+1;
		}
	}
	if (sum == 0) {
		std::cout << "No Matching Proposals\n";
	}
}

bool Proposal::compareItemNames(const Proposal& proposal1, const Proposal& proposal2) const {
	return proposal1.getItem().getName() == proposal2.getItem().getName();
}