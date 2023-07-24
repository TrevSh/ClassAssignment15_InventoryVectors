#include <string>
#include <vector>
#include <iostream>

int main()
{
    std::vector<std::string> inventory;                           //initialize a string vector. Vector is a container like array but can grow or shrink when needed.
    //std::vector<std::string> inventory(10, "nothing");         //<--With this, vector will start with a size of 10 and all values will be 'nothing'.
    inventory.push_back("sword");                               //Push_back() adds a value to be stored at the end of a vector.
    inventory.push_back("armor");
    inventory.push_back("shield");

    std::cout << "You have " << inventory.size() << " items.\n";                //size() simply returns the size of a vector.

    std::cout << "\nYour items: \n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        std::cout << inventory[i] << "\n";
    }

    std::cout << "\nYou trade you sword for a battle axe.\n";
    inventory[0] = "battle axe";
    std::cout << "\nYour item: \n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        std::cout << inventory[i] << "\n";
    }

    std::cout << "\nThe item name '" << inventory[0] << "' has ";
    std::cout << inventory[0].size() << " letters in it.\n";

    std::cout << "\nYour shield was destroyed in the attack!";
    inventory.pop_back();                                               //Pop_back() removes the last element in a vector and reduces vector by one. In this case, the shield.
    std::cout << "\nYour items: \n";
    for (unsigned int i = 0; i < inventory.size(); ++i) {
        std::cout << inventory[i] << "\n";
    }

    std::cout << "\nYou were robbed of all your possessions by a thief.";
    inventory.clear();                                                              //Clear() removes all items from a vector and sets its size to 0.
    if (inventory.empty()) {
        std::cout << "\nYou have nothing. \n";
    }
    else {
        std::cout << "\nYou have at least one item. \n";
    }
    system("pause");
    return 0;
}
