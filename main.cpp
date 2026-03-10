#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cctype>

using namespace std;

// ============================================================================
// Step 4: Defining a class to store the character pattern
// ============================================================================
class CharacterPattern {
private:
    char character;
    vector<string> pattern;

public:
    CharacterPattern() : character(' ') {}
    
    CharacterPattern(char c, vector<string> p) : character(c), pattern(p) {}

    const vector<string>& getPattern() const {
        return pattern;
    }
    
    char getCharacter() const {
        return character;
    }
};

// ============================================================================
// Step 5: Using a map to store the character pattern
// ============================================================================
map<char, CharacterPattern> createPatternMap() {
    map<char, CharacterPattern> patternMap;
    
    // Pattern for 'O'
    patternMap['O'] = CharacterPattern('O', {
        " *** ",
        "*   *",
        "*   *",
        "*   *",
        " *** "
    });

    // Pattern for 'P'
    patternMap['P'] = CharacterPattern('P', {
        "**** ",
        "*   *",
        "**** ",
        "*    ",
        "*    "
    });

    // Pattern for 'S'
    patternMap['S'] = CharacterPattern('S', {
        " ****",
        "*    ",
        " *** ",
        "    *",
        "**** "
    });

    return patternMap;
}

// ============================================================================
// Step 3 & 5: Function to display the OOPS in a Banner Format
// ============================================================================
void displayBanner(const string& word, const map<char, CharacterPattern>& patternMap) {
    if (word.empty()) return;

    // Assuming all patterns have a height of 5
    const int patternHeight = 5;

    for (int row = 0; row < patternHeight; ++row) {
        for (char c : word) {
            char upperC = toupper(c);
            auto it = patternMap.find(upperC);
            if (it != patternMap.end()) {
                cout << it->second.getPattern()[row] << "   ";
            } else {
                // If character not found, print spaces
                cout << "     " << "   ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Function to demonstrate Step 1
void displaySimpleConsole() {
    cout << "Step 1: Simple use case of displaying OOPS in the console" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "OOPS" << endl << endl;
}

// Function to demonstrate Step 2
void displayHardcodedBanner() {
    cout << "Step 2: Extending use case to display in a Banner Format using space and *" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
    cout << " ***    ***   ****    **** " << endl;
    cout << "*   *  *   *  *   *  *    *" << endl;
    cout << "*   *  *   *  ****    ***  " << endl;
    cout << "*   *  *   *  *          * " << endl;
    cout << " ***    ***   *      ****  " << endl << endl;
}

int main() {
    // 1. Simple use case
    displaySimpleConsole();

    // 2. Banner Format (Hardcoded)
    displayHardcodedBanner();

    // 3, 4, 5. Refactored modular code using functions, class, and map
    cout << "Step 3, 4 & 5: Modular using functions, class, and map" << endl;
    cout << "------------------------------------------------------" << endl;
    map<char, CharacterPattern> patternMap = createPatternMap();
    displayBanner("OOPS", patternMap);

    return 0;
}
