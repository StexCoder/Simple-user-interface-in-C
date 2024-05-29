#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

char user_name[MAX_USERNAME_LENGTH]; 
char password[MAX_PASSWORD_LENGTH]; 

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

struct User users[MAX_USERS];
int numUsers = 0;

void signUp() {
    printf("Please enter your username (you must use only letters):\n");
    scanf("%s", user_name); 
    
    printf("Please enter your password (you must use only letters):\n");
    scanf("%s", password);
    
    strcpy(users[numUsers].username, user_name);
    strcpy(users[numUsers].password, password);
    numUsers++;
    
    printf("You have created an account!\n");
}

int login() {
    printf("Please enter your username:\n");
    scanf("%s", user_name); 
    
    printf("Please enter your password:\n");
    scanf("%s", password);
    
    for (int i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, user_name) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1; 
        }
    }
    printf("Invalid username or password. Please try again.\n");
    return 0; 
}

void showMenu() {
    printf("Welcome! Press 1 to sign up and press 2 to log in: ");
}

int main() {
    int choice;
    int loggedIn = 0;
    
    do {
        showMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                signUp();
                loggedIn = login(); 
                break;
            case 2:
                loggedIn = login();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (!loggedIn); 
    
    return 0;
}
