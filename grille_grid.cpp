
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

template <typename Map>
void
key_compare (Map const &lhs, Map const &rhs) 
{
    // cppreference.com/w/cpp/algorithm/equal
    std::equal( lhs.begin(), 
                lhs.end(), 
                rhs.begin(), 
                [] (auto ctext, auto hashes) 
                { 
                    auto dctext = ctext.second;
                    auto cnt = 0;
                    for (auto i : hashes.second) 
                    {
                        if (i == ' ')
                        {
                            std::cout << dctext[cnt];   
                        }
                        cnt++;
                    }
                    return ctext.first == hashes.first; 
                });
}


int main()
{
    std::vector<std::string>
    hashText
    {
        "##### ",   
        "#### #",   
        "# # # ",
        "## ###",   
        " ## ##",
        " #####"    
    };

    std::vector<std::string>
    cipherText
    {
        "ESVWGT",
        "HOWTHZ",
        "HIVSAI",
        "CASSAC",
        "FAAUCM",
        "NYMPCE"
    };

    std::map< int, std::string > textMap;
    std::map< int, std::string > hashMap;
    auto ccnt = 0;
    auto hcnt = 0;

    for (auto it = cipherText.begin(); it != cipherText.end(); it++) 
    {   
        textMap.insert({ccnt, *it});
        ccnt++;
    }
    for (auto it = hashText.begin(); it != hashText.end(); it++) 
    {   
        hashMap.insert({hcnt, *it});
        hcnt++;
    }

    key_compare(textMap, hashMap);
}
