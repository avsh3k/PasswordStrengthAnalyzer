//Password Strength Tester
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_password_strength(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    // Minimum length requirement
    if (length < 8) {
        return 0;
    }

    // Check for uppercase, lowercase, numbers, and special characters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else {
            has_special = 1;
        }
    }

    // Evaluate password strength based on criteria
    if (has_uppercase && has_lowercase && has_number && has_special) {
        return 1;  // Strong password
    } else {
        return 0;  // Weak password
    }
}

int main() {
    char password[100];

    // Prompt the user for a password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    int strength = check_password_strength(password);

    // Display the result
    if (strength) {
        printf("Strong: Password is secure.\n");
    } else {
        printf("Weak: Password is not secure.\n");
    }

    return 0;
}
