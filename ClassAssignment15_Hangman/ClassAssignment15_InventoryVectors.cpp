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

    std::vector<std::string>::iterator myIterator;                              //Declaring a string iterator. Iterators are values that identify an element in a vector. Can be used to access or change the value.
    std::vector<std::string>::const_iterator iter;                              //A contst_iterator is like a normal one but you CANNOT change the value of the element its attached to. 

    std::cout << "You have " << inventory.size() << " items.\n";                //size() simply returns the size of a vector.

    std::cout << "\nYour items: \n";
    for (iter = inventory.begin(); iter != inventory.end();++iter) {
        std::cout << *iter << "\n";                                             //The dereference operator(*) infront of a iterator allows the iterator to reference the value in the vector and not the iterator itself, just as shown.
    }

    std::cout << "\nYou trade you sword for a battle axe.\n";
    myIterator = inventory.begin();
    *myIterator = "battle axe";                                                 //As explained above, the (*) allows the iterator to change the value in the vector without changing the iterator itself.
    std::cout << "\nYour item: \n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
        std::cout << *iter << "\n";
    }

    std::cout << "\nThe item name '" << *myIterator << "' has ";                //Using the (*) will output the value of the referenced value in the vector, being the 'battle axe'.
    std::cout << (*myIterator).size() << " letters in it.\n";                   //Using size on a dereferenced iterator will display the save of the referenced vector value. The parentheses ensure the dot operator (.) will be applied to the object referenced.

    std::cout << "\nThe item name '" << *myIterator << "' has ";
    std::cout << myIterator->size() << " letters in it.\n";                     //This version of the above size() operator is exactly the same but more readable. Notice there is no dereference operator(*), as it is not needed in this syntax. the arrow operator (->) can also be used to access member functions of a referenced object.

    std::cout << "\nYou recover a crossbow from a slain foe!";
    inventory.insert(inventory.begin(), "crossbow");                            //insert() is used to insert an element into the vector just before a given iterator (here being inventory.begin()). The second argument is whats being inserted.               
    std::cout << "\nYour items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter) {               //Moves const_iterator through all the elements in a vector like a normal for loop. It will start at the beginning of the vector and access every element until the last element plus one (Not the last element, but after it).
        std::cout << *iter << "\n";
    }

    std::cout << "\nYour armor was destroyed in the attack!";
    inventory.erase((inventory.begin() + 2));                                       //erase() is used to remove an element from chosen location in a vector. Will move the following elements up in position by one. Invalidates ALL iterators AFTER the removed element due to change in position.      
    std::cout << "\nYour items: \n";
    for (iter = inventory.begin(); iter != inventory.end(); ++iter) {
        std::cout << *iter << "\n";
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
