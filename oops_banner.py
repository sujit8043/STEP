# oops_banner.py

class CharacterPattern:
    """Step 4: Defining a class to store the character pattern"""
    def __init__(self, character, pattern):
        self.character = character
        self.pattern = pattern

# Step 5: Using a map (dictionary in Python) to store the character pattern
def create_pattern_map():
    pattern_map = {}
    
    # Pattern for 'O'
    pattern_map['O'] = CharacterPattern('O', [
        " *** ",
        "*   *",
        "*   *",
        "*   *",
        " *** "
    ])
    
    # Pattern for 'P'
    pattern_map['P'] = CharacterPattern('P', [
        "**** ",
        "*   *",
        "**** ",
        "*    ",
        "*    "
    ])
    
    # Pattern for 'S'
    pattern_map['S'] = CharacterPattern('S', [
        " ****",
        "*    ",
        " *** ",
        "    *",
        "**** "
    ])
    
    return pattern_map

# Step 3 & 5: Function to display the OOPS in a Banner Format
def display_banner(word, pattern_map):
    """Refactored code to make it more modular using functions."""
    if not word:
        return
        
    word = word.upper()
    pattern_height = 5
    
    for row in range(pattern_height):
        row_str = ""
        for char in word:
            if char in pattern_map:
                row_str += pattern_map[char].pattern[row] + "   "
            else:
                row_str += "     " + "   " # 5 spaces for missing char
        print(row_str)

def step1_simple_print():
    """Step 1: Simple use case of displaying OOPS in the console"""
    print("Step 1: Simple use case of displaying OOPS in the console")
    print("-" * 60)
    print("OOPS\n")

def step2_hardcoded_banner():
    """Step 2: Extending the use case to display in a Banner Format using space and *"""
    print("Step 2: Display in a Banner Format using space and *")
    print("-" * 60)
    print(" ***    ***   ****    **** ")
    print("*   *  *   *  *   *  *    *")
    print("*   *  *   *  ****    ***  ")
    print("*   *  *   *  *          * ")
    print(" ***    ***   *      ****  \n")

def main():
    # Execute Step 1
    step1_simple_print()
    
    # Execute Step 2
    step2_hardcoded_banner()
    
    # Execute Steps 3, 4, 5
    print("Steps 3, 4 & 5: Modular using functions, class, and map")
    print("-" * 60)
    pattern_map = create_pattern_map()
    display_banner("OOPS", pattern_map)

if __name__ == "__main__":
    main()
