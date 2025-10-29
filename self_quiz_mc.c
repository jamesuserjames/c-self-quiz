#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void intro();
int ask_question(const char *question, const char options[4][100], char correct_option);
void explain_line(const char *line_explanation);

int main(void) {
    intro();

    int score = 0;

    // Question 1
    const char q1_opts[4][100] = {
        "A) To include math functions",
        "B) To include input/output functions like printf()",
        "C) To make the program faster",
        "D) To access memory directly"
    };
    score += ask_question("1) Why do we include <stdio.h> at the top of a C program?", q1_opts, 'B');
    explain_line("<stdio.h> lets us use printf() and scanf() for input and output.");

    // Question 2
    const char q2_opts[4][100] = {
        "A) It stores the player’s score",
        "B) It counts the number of lines",
        "C) It holds characters typed by the user",
        "D) It initializes the compiler"
    };
    score += ask_question("2) What is the purpose of 'int score = 0;' ?", q2_opts, 'A');
    explain_line("score keeps track of how many answers are correct.");

    // Question 3
    const char q3_opts[4][100] = {
        "A) It stores a string input from the user",
        "B) It points to an integer variable",
        "C) It defines a constant",
        "D) It counts loop iterations"
    };
    score += ask_question("3) Why do we declare 'char answer[100];' ?", q3_opts, 'A');
    explain_line("The array stores the text the user types in (a string).");

    // Question 4
    const char q4_opts[4][100] = {
        "A) To print a question and check the user's answer",
        "B) To allocate memory",
        "C) To run the whole program",
        "D) To repeat the main loop"
    };
    score += ask_question("4) What does the ask_question() function do?", q4_opts, 'A');
    explain_line("It prints a question, checks the input, and returns 1 if correct.");

    // Question 5
    const char q5_opts[4][100] = {
        "A) Prints 'Incorrect!'",
        "B) Ends the program",
        "C) Repeats the question automatically",
        "D) Adds 10 points to the score"
    };
    score += ask_question("5) What happens if the user's answer is wrong?", q5_opts, 'A');
    explain_line("The function compares answers using strcmp() and prints 'Incorrect!' if not equal.");

    // Question 6
    const char q6_opts[4][100] = {
        "A) It is a pointer to a string",
        "B) It’s a comment",
        "C) It means multiplication",
        "D) It declares a constant"
    };
    score += ask_question("6) In 'const char *question', what does the * mean?", q6_opts, 'A');
    explain_line("It means the variable is a pointer to the first character of a string.");

    // Question 7
    const char q7_opts[4][100] = {
        "A) for loop",
        "B) do-while loop",
        "C) while loop",
        "D) switch statement"
    };
    score += ask_question("7) Which loop could repeat the quiz until the user quits?", q7_opts, 'C');
    explain_line("A while loop is ideal for repeating until a condition is false.");

    // Question 8
    const char q8_opts[4][100] = {
        "A) It allocates memory during runtime",
        "B) It frees memory",
        "C) It counts elements in an array",
        "D) It reads from a file"
    };
    score += ask_question("8) What does malloc() do?", q8_opts, 'A');
    explain_line("malloc() requests a block of memory from the OS while the program runs.");

    // Question 9
    const char q9_opts[4][100] = {
        "A) It prevents modifying the string",
        "B) It optimizes speed",
        "C) It makes the string uppercase",
        "D) It allocates static memory"
    };
    score += ask_question("9) Why do we use 'const' in 'const char *question'?", q9_opts, 'A');
    explain_line("const promises that the string data will not be changed by the function.");

    // Final score
    printf("=========================================\n");
    printf("🏁 Quiz Complete! You scored %d out of 9.\n", score);
    if (score == 9)
        printf("Perfect score! 🧠🔥\n");
    else if (score >= 6)
        printf("Nice job! You know your C fundamentals well.\n");
    else
        printf("Keep practicing! Try running the program again.\n");
    printf("=========================================\n");

    return 0;
}

// ===================== FUNCTION DEFINITIONS =====================

void intro() {
    printf("=========================================\n");
    printf("       🧠 MULTIPLE CHOICE SELF-QUIZ 🧠\n");
    printf("=========================================\n");
    printf("Type the letter (A, B, C, or D) of your answer.\n");
    printf("Each correct answer gives +1 point.\n");
    printf("-----------------------------------------\n\n");
}

int ask_question(const char *question, const char options[4][100], char correct_option) {
    char user_input[10];
    printf("%s\n", question);
    for (int i = 0; i < 4; i++) {
        printf("%s\n", options[i]);
    }
    printf("> ");
    fgets(user_input, sizeof(user_input), stdin);
    char answer = toupper(user_input[0]);

    if (answer == correct_option) {
        printf("✅ Correct!\n\n");
        return 1;
    } else {
        printf("❌ Incorrect! Correct answer: %c\n\n", correct_option);
        return 0;
    }
}

void explain_line(const char *line_explanation) {
    printf("💡 Explanation: %s\n", line_explanation);
    printf("-----------------------------------------\n\n");
}