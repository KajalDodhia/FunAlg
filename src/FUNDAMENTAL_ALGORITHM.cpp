#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <list>
#include "FUNDAMENTAL_ALGORITHM.h"
std::unordered_map<std::string, std::string> FUNDAMENTAL_ALGORITHM(std::unordered_map<std::string, std::vector<std::string>> p1, std::unordered_map<std::string, std::vector<std::string>> p2)
{
    // Set-up list of males and females
    std::vector<std::string> men = p2.begin()->second;
    std::vector<std::string> women = p1.begin()->second;

    // All men temporarily engaged to the undesirable woman
    // Hence initial matchings are:
    std::unordered_map<std::string, std::string> m;

    for (const auto& i : men)
    {
        m[i] = "omega";
    }

    int k = 0;
    int n = p1.size();

    // Add omega to end of list of preferences for each man
    for (auto& i : p1)
    {
        p1.at(i.first).push_back("omega");
    }

    // While not all women have matches
    while (k < n)
    {
        std::string X = women[k];
        while (X != "omega")
        {
            // X's list of preferences
            std::vector<std::string> preference_list = p2[X];

            // Get best choice
            std::string x = preference_list[0];

            // Current partner (fiance) of man x is:
            std::string h = m[x];

            // Find index of current partner
            auto i = std::find(p1[x].begin(), p1[x].end(), h);
            int current_index = std::distance(p1[x].begin(), i);

            // Find index of new potential partner
            i = std::find(p1[x].begin(), p1[x].end(), X);
            int potential_index = std::distance(p1[x].begin(), i);

            // If man prefers new woman then engage them
            if (potential_index < current_index)
            {
                m[x] = X;
                // X becomes preceding fiance of x
                X = h;
            }

            if (X != "omega")
            {
                // Withdraw x from X's list
                p2[X].erase(p2[X].begin());
            }
        }
        k = k + 1;
    }
    return m;
}
