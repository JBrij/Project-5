#include "dogs.h"
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
    Dogs dog;

    while (true) {
        cout << endl << "Dog Menu:" << endl;
        cout << "1. See the total number of dogs in the world" << endl;
        cout << "2. Input a country name to find out how many dogs are in that country" << endl;
        cout << "3. Check if a country is available in the data" << endl;
        cout << "4. Exit" << endl << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Total number of dogs in the world: " << dog.getDogPopulation() << endl;
                break;

            case 2: {
                int countryPopulation = dog.getCountryPopulation();
                if (countryPopulation != -1) {
                    cout << "Number of dogs in that country: " << countryPopulation << std::endl;
                }
                break;
            }

            case 3: {
                string country;
                cout << "Enter the country name: ";
                cin >> country;

                if (dog.countryAvailable(country)) {
                    cout << "Country is available in the data." << endl;
                } else {
                    cout << "Country is not available in the data." << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
