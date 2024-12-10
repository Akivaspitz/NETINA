#include "Contacts.h"

int main() {
	Item item2("Bag", Clothing, 7, 2, "Blue"); //item check up
	Item item1;
	item1.print();
	cout << "************" << endl;

	item2.print();
	cout << "************" << endl;
	item2.setSize(3);
	item2.setAmount(4);
	item2.setType(Electronics);
	item2.setName("Ball");
	item2.print();
	cout << "************" << endl;
	item2.printName();
	item2.getSize();
	item2.getType();
	item2.getAmount();
	cout << "*****Items check finish*******" << endl;

	Proposal of1( Offer, item1, 1234, "Citypark");     //proposal check up
	Proposal re1;
	item2.printName();
	cout << "************" << endl;


	of1.getLocation();
	cout << "************ * ***********" << endl;

	re1.printProposal();
	cout << "************" << endl;

	of1.printProposal();
	cout << "************" << endl;

	Proposal of2(Offer, item2, 1122, "hello");
	of2.printProposal();
	cout << "************" << endl;
	of1.getNumber();
	of1.getProposalType();
	of1.setLocation("Hometown");
	of1.getLocation();
	of1.setNumber(55555);
	of1.getNumber();
	of1.setType(Offer);
	of1.getProposalType();
	of1.getAmount();
	cout << "******Proposal check finish******" << endl;

	User user1;
	User user2("Steve Roger", "SteveRoger@gmail.com");
	user2.addProposal(of1);
	user2.addProposal(of2);
	user2.printUser();
	user1.addProposal(of1);
	user1.getUserName();
	user1.getEmail();
	user1.setUserName("Frank Mosses");
	user1.setEmail("FrankMosses@gmail.com");
	user1.getUserName();
	user1.getEmail();
	item1.getName();
	std::cout << "User's name: " << item1.getName() << std::endl;
	cout << of1.getItem().getName() << endl; 
	if (user1.compareItemNames(of1, of1)) {
		cout << "works" << endl;
	}
	else(cout << "doesnt work" << endl);
	cout << "******User check finish******" << endl<<endl;

	user2.checkForMatches(user1, user2, "Ball");

	cout << "***************************All check finish*************************" << endl << endl;
   
	



	//Interactive code
	cout << "Welcome to ??? ???." << endl;

	// Variables to store user input
	string userName, userEmail, itemName, location, color; 
	int itemType, proposalType, size, amount, contactNumber; 

	// Get user information
	cout << "Enter user name: ";
	getline(cin, userName);  // Use getline for strings to handle spaces
	cout << "Enter user email: ";
	getline(cin, userEmail);

	// Create a user
	User user(userName, userEmail);
	user.getEmail();
	user.getUserName();
	// Get proposal information
	cout << "Enter item name: ";
	getline(cin, itemName);
	cout << "Enter item type (0 for Game, 1 for Clothing, 2 for Electronics, 3 for Other): ";
	cin >> itemType;
	if (itemType != 2) {
		cout << "Enter item color: ";
		cin >> color;
		if (itemType == 0) {
			cout << "Enter the age of use of the item: ";
		}
		else {
			cout << "Enter item size: ";
		}
		cin >> size;
	}
	else {
		color = "No color ";
		size = 1;
	}

	cout << "Enter item amount: ";
	cin >> amount;
	cout << "Enter proposal type (0 for Request, 1 for Offer): ";
	cin >> proposalType;
	cout << "Enter contact number for proposal: ";
	cin >> contactNumber;
	cout << "Enter proposal location: ";
	cin >> location;


	Item item5(itemName, static_cast<ItemType>(itemType), size, amount, color);
	Proposal proposal5(static_cast<ProposalType>(proposalType), item5, contactNumber, location);

	// Add the proposal to the user
	user.addProposal(proposal5);
	//user.addProposal(of1);
	//user.addProposal(of2);

	cout << "************" << endl;
	proposal5.printProposal();
	// Print user information
	//user.printUser();


	//user2.deleteItemNamesInProposals();
	return 0;
}