/*******************************
 * Lab 3: exercise 1            *
 * Frequency table of words     *
 *******************************/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   //std::pair
#include <fstream>
#include <cassert>
#include <algorithm>


// A function to test the output of the program
void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n);

/***************************
 * Main function           *
 **************************/

int main() {  
    std::cout << "Text file: ";
	std::string file_name;
	std::cin >> file_name;

	std::ifstream in_File{"/home/linn/Documents/Repositories/TNG033/lab3/exercise2/" + file_name};  // modify path, if needed

	if (!in_File) {
		std::cout << "Could not open input file!!\n";
		return 0;
	}

    std::map<std::string, int> table;
    int counter{0};  // to count total number of words read from the input file

    std::string ignore = ".,!?:\"();";
    
    std::string word;
    while (in_File >> word) 
    {
        //remove chars
        word.erase(
            std::remove_if(
                word.begin(), 
                word.end(),
                [ignore](auto c) {
                    return ignore.contains(c);
                }
            ),
            word.end()
        );

        //to lower
        std::transform(
            word.begin(), 
            word.end(), 
            word.begin(),
            [](auto c) { 
                return std::tolower(c);
            }
        );

        counter++;
        table[word]++;
    }

    std::vector<std::pair<std::string, int>> freq;
    
    std::transform(
        table.begin(), 
        table.end(), 
        std::back_inserter(freq), 
        [](const auto& entry) {
            return entry; 
        }
    );

    std::sort(
        freq.begin(), 
        freq.end(), 
        [](const auto& a, const auto& b) { 
            return a.second == b.second ? a.first < b.first : a.second > b.second; 
        }
    );

    /* ************** Testing **************** */

    test(table, freq, "out_" + file_name, counter);
}


/*******************************
 * Test implementation         *
 * Do not modify               *
 *******************************/

void test(const std::map<std::string, int>& t, const std::vector<std::pair<std::string, int>>& v,
          const std::string& file_name, int n) {

    std::ifstream file{"/home/linn/Documents/Repositories/TNG033/lab3/exercise2/" + file_name}; //modify path, if needed

    // Test if stream is in good state
    assert(bool(file) == true);

    std::map<std::string, int> result1;
    std::string word;
    int counter{0};
    int total{0};

    // load expected frequency table sorted alphabetically
    while (file >> word >> counter && counter > 0) {
        result1[word] = counter;
        total += counter;
    }

    /*
     * uppgift1_kort: 69 words
     * uppgift1.txt: 1063 words
     */

    assert(total == n);    // test if total number of words is correct
    assert(t == result1);  // test if map/table contents are correct

    std::vector<std::pair<std::string, int>> result2;

    // load expected frequency table sorted by frequence
    while (file >> word >> counter) {
        result2.push_back(std::pair{word, counter});
    }
    assert(v == result2);  // test if vector contents are correct

    std::cout << "\nPassed all tests successfully!!\n";
}
