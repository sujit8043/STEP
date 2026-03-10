// OopsBanner.java
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.Arrays;

// Step 4: Defining a class to store the character pattern
class CharacterPattern {
    private char character;
    private List<String> pattern;

    public CharacterPattern(char character, List<String> pattern) {
        this.character = character;
        this.pattern = pattern;
    }

    public List<String> getPattern() {
        return pattern;
    }
}

public class OopsBanner {

    // Step 5: Using a map to store the character pattern
    public static Map<Character, CharacterPattern> createPatternMap() {
        Map<Character, CharacterPattern> map = new HashMap<>();

        // Pattern for 'O'
        map.put('O', new CharacterPattern('O', Arrays.asList(
            " *** ",
            "*   *",
            "*   *",
            "*   *",
            " *** "
        )));

        // Pattern for 'P'
        map.put('P', new CharacterPattern('P', Arrays.asList(
            "**** ",
            "*   *",
            "**** ",
            "*    ",
            "*    "
        )));

        // Pattern for 'S'
        map.put('S', new CharacterPattern('S', Arrays.asList(
            " ****",
            "*    ",
            " *** ",
            "    *",
            "**** "
        )));

        return map;
    }

    // Step 3 & 5: Use function to display the word in a Banner Format
    public static void displayBanner(String word, Map<Character, CharacterPattern> map) {
        if (word == null || word.isEmpty()) return;
        
        word = word.toUpperCase();
        int patternHeight = 5;

        for (int row = 0; row < patternHeight; row++) {
            StringBuilder rowStr = new StringBuilder();
            for (char c : word.toCharArray()) {
                if (map.containsKey(c)) {
                    rowStr.append(map.get(c).getPattern().get(row)).append("   ");
                } else {
                    rowStr.append("        "); // Spaces for unknown characters
                }
            }
            System.out.println(rowStr.toString());
        }
        System.out.println();
    }

    public static void main(String[] args) {
        // Step 1: Simple use case of displaying OOPS in the console
        System.out.println("Step 1: Simple use case of displaying OOPS in the console");
        System.out.println("---------------------------------------------------------");
        System.out.println("OOPS\n");

        // Step 2: Display in a Banner Format using space and *
        System.out.println("Step 2: Display in a Banner Format using space and *");
        System.out.println("----------------------------------------------------");
        System.out.println(" ***    ***   ****    **** ");
        System.out.println("*   *  *   *  *   *  *    *");
        System.out.println("*   *  *   *  ****    ***  ");
        System.out.println("*   *  *   *  *          * ");
        System.out.println(" ***    ***   *      ****  \n");

        // Steps 3, 4, 5
        System.out.println("Steps 3, 4 & 5: Modular using functions, class, and map");
        System.out.println("-------------------------------------------------------");
        Map<Character, CharacterPattern> patternMap = createPatternMap();
        displayBanner("OOPS", patternMap);
    }
}
