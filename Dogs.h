#ifndef DOGS_H
#define DOGS_H

#include <string>
#include <unordered_map>
using namespace std;

class Dogs
{
    public:
        Dogs();
        int getDogPopulation();
        int getCountryPopulation();
        bool countryAvailable(string country);

    protected:
        void load_data(const string& dataFile);

    private:
        int m_dogpopulation = 0;
        unordered_map<string, int> m_dogs;
};

#endif // DOGS_H
