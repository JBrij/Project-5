#include "dogs.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

Dogs::Dogs() {
    load_data("dogs.txt");
}

int Dogs::getDogPopulation() {
    return m_dogpopulation;
}

int Dogs::getCountryPopulation() {
    string country;
    cout << "Enter the country name: ";
    cin >> country;

    auto it = m_dogs.find(country);
    if (it != m_dogs.end()) {
        return it->second;
    } else {
        cout << "Country not found in the data." << endl;
        return -1;
    }
}

bool Dogs::countryAvailable(string country) {
    return m_dogs.find(country) != m_dogs.end();
}

void Dogs::load_data(const string& dataFile) {
    try {
        ifstream file(dataFile);
        if (!file.is_open()) {
            throw runtime_error("Error: File '" + dataFile + "' not found.");
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string country;
            char comma = ',';
            int population;

            if (getline(iss, country, comma) && iss >> population) {
                m_dogs[country] = population;
                m_dogpopulation += population;
            } else {
                cerr << "Error parsing line: " << line << endl;
            }
        }
    } catch (const exception& e) {
        cerr << "An unexpected error occurred: " << e.what() << endl;
    }
}
