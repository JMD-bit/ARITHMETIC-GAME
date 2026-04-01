#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX 10

void login();
void reg();
void leaderboard(char user[]);
void menu2(char user[]);
int add(char user[]);
int minus(char user[]);
int times(char user[]);
int divide(char user[]);
void saveScore(char user[], int score, char mode[]);
void sortScores(char filename[], char name[], int score);
void overallLeaderboard();



int menu(){
    system("cls");

    int choice;

    printf("\tARITHMETIC GAME\n");
    printf("\t\tMENU\n");
    printf("\t\t1.) LOG IN\n");
    printf("\t\t2.) REGISTER\n");
    printf("\t\t3.) EXIT\n");
    printf("\n\t\tChoice: ");
    
    scanf("%d", &choice);

    switch(choice){
        case 1: login(); 
                break;
        case 2: reg(); 
                break;
        case 3:
                printf("\nThank you for playing!\n");
                system("pause");
                exit(0);
        default:
                printf("Invalid input.\n");
                system("pause");
    }
    return 0;
}

int main(){

    srand(time(NULL));

    while(1){
        menu();
    }
}

void reg(){
    system("cls");

    char username[100];
    char password[100];
    char file_user[100], file_pass[100];
    int duplicate = 0;

    FILE *fp_check = fopen("login.txt", "r");
    
    if(fp_check != NULL){
        while(fscanf(fp_check, "%s %s", file_user, file_pass) != EOF){
   
        }
        fclose(fp_check);
    }

    getchar();

    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    fp_check = fopen("login.txt", "r");
    if(fp_check != NULL){
        while(fscanf(fp_check, "%s %s", file_user, file_pass) != EOF){
            if(strcmp(username, file_user) == 0){
                duplicate = 1;
                break;
            }
        }
        fclose(fp_check);
    }

    if(duplicate){
        printf("\nUsername already exists! Try another.\n");
        system("pause");
        return;
    }

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    FILE *fp = fopen("login.txt", "a");
    if(fp == NULL){
        printf("File error.\n");
        return;
    }

    fprintf(fp, "%s %s\n", username, password);

    printf("\nRegistration successful!\n");

    fclose(fp);
    system("pause");
}

void login(){
    char username[100];
    char password[100];
    char file_user[100], file_pass[100];
    int found = 0;

    FILE *fp = fopen("login.txt", "r");

    if(fp == NULL){
        printf("File error.\n");
        return;
    }

    getchar();

    printf("\tLOGIN\n\n");
    printf("Username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';

    while(fscanf(fp, "%s %s", file_user, file_pass) != EOF){
        if(strcmp(username, file_user) == 0){
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Username not found.\n");
        fclose(fp);
        system("pause");
        return;
    }

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    if(strcmp(password, file_pass) == 0){
        printf("    essful!\n");
        fclose(fp);
        system("pause");
        menu2(username);
    } else {
        printf("Incorrect password.\n");
        fclose(fp);
        system("pause");
    }
}

void menu2(char user[]){
    int choice;

    system("cls");
    printf("\tARITHMETIC GAME\n");
    printf("\tWelcome, %s!\n", user);
    printf("\n\t1. Addition\n\t2. Subtraction\n\t3. Multiplication\n\t4. Division\n\t5. Leaderboard\n\t6. Logout\n");
    printf("\nChoice: ");

    scanf("%d", &choice);

    switch(choice){
        case 1: add(user); 
                break;
        case 2: minus(user); 
                break;
        case 3: times(user);        
                break;
        case 4: divide(user); 
                break;
        case 5: leaderboard(user); 
                break;
        case 6: return;
        default:
            printf("Invalid input.\n");
            system("pause");
    }
}

int add(char user[]){
    int a, b, ans, cor = 0;

    system("cls");

    while(1){
        a = rand() % 20 + 1;
        b = rand() % 20 + 1;

        printf("\n%d + %d = ", a, b);
        scanf("%d", &ans);

        if(ans == a + b){
            printf("Correct!\n");
            cor++;
        } else {
            printf("Wrong! Answer: %d\n", a + b);
            break;
        }
    }

    printf("\nScore: %d\n", cor);
    saveScore(user, cor, "add");

    system("pause");
    menu2(user);
}

int minus(char user[]){
    int a, b, ans, cor = 0;

    system("cls");

    while(1){
        a = rand() % 20 + 1;
        b = rand() % 20 + 1;

        if(b > a){
            int temp = a;
            a = b;
            b = temp;
    }

        printf("\n%d - %d = ", a, b);
        scanf("%d", &ans);

        if(ans == a - b){
            printf("Correct!\n");
            cor++;
        } else {
            printf("Wrong! Answer: %d\n", a - b);
            break;
        }
    }

    printf("\nScore: %d\n", cor);
    saveScore(user, cor, "minus");

    system("pause");
    menu2(user);
}

int times(char user[]){
    int a, b, ans, cor = 0;

    system("cls");

    while(1){
        a = rand() % 12 + 1;
        b = rand() % 12 + 1;

        printf("\n%d * %d = ", a, b);
        scanf("%d", &ans);

        if(ans == a * b){
            printf("Correct!\n");
            cor++;
        } else {
            printf("Wrong! Answer: %d\n", a * b);
            break;
        }
    }

    printf("\nScore: %d\n", cor);
    saveScore(user, cor, "times");

    system("pause");
    menu2(user);
}

int divide(char user[]){
    int a, b, ans, cor = 0;

    system("cls");

    while(1){
        b = rand() % 9 + 1;
        a = b * (rand() % 10 + 1);

        printf("\n%d / %d = ", a, b);
        scanf("%d", &ans);

        if(ans == a / b){
            printf("Correct!\n");
            cor++;
        } else {
            printf("Wrong! Answer: %d\n", a / b);
            break;
        }
    }

    printf("\nScore: %d\n", cor);
    saveScore(user, cor, "divide");

    system("pause");
    menu2(user);
}
#define MAX_PLAYERS 10

void sortScores(char filename[], char name[], int score){
    FILE *fp = fopen(filename, "r");

    char names[100][100];
    int scores[100];
    int count = 0;
    int found = 0;

    if(fp != NULL){
        while(fscanf(fp, "%s %d", names[count], &scores[count]) != EOF){
            count++;
        }
        fclose(fp);
    }

    for(int i = 0; i < count; i++){
        if(strcmp(name, names[i]) == 0){
            if(score > scores[i]){
                scores[i] = score;
            }
            found = 1;
            break;
        }
    }

    if(!found){
        strcpy(names[count], name);
        scores[count] = score;
        count++;
    }

    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - i - 1; j++){
            if(scores[j] < scores[j + 1]){
                int tempScore = scores[j];
                char tempName[100];

                strcpy(tempName, names[j]);

                scores[j] = scores[j + 1];
                strcpy(names[j], names[j + 1]);

                scores[j + 1] = tempScore;
                strcpy(names[j + 1], tempName);
            }
        }
    }

    if(count > MAX_PLAYERS){
        count = MAX_PLAYERS;
    }

    fp = fopen(filename, "w");
    if(fp == NULL){
        printf("File error.\n");
        return;
    }

    for(int i = 0; i < count; i++){
        fprintf(fp, "%s %d\n", names[i], scores[i]);
    }

    fclose(fp);
}
void saveScore(char user[], int score, char mode[]){
    char filename[100];
    strcpy(filename, mode);
    strcat(filename, ".txt");
    
    FILE *fp = fopen(filename, "a+");
    if(fp == NULL){
        printf("File error.\n");
        return;
    }
    
    fclose(fp);
     
    sortScores(filename, user, score);
    
    printf("Score saved and sorted!\n");
}
void leaderboard(char user[]){
    int choice;

    system("cls");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Overall Top 10\n"); 
    printf("6. Back\n");
    printf("\nChoice: ");
    scanf("%d", &choice);

    char filename[100];
    char mode[20];

    switch(choice){
        case 1:
            strcpy(mode, "Addition");
            strcpy(filename, "add.txt");
            break;
        case 2:
            strcpy(mode, "Subtraction");
            strcpy(filename, "minus.txt");
            break;
        case 3:
            strcpy(mode, "Multiplication");
            strcpy(filename, "times.txt");
            break;
        case 4:
            strcpy(mode, "Division");
            strcpy(filename, "divide.txt");
            break;
        case 5:
            overallLeaderboard();
            return;
        case 6:
            menu2(user);
            return;
        default:
            printf("Invalid input.\n");
            system("pause");
            leaderboard(user);
            return;
    }

    system("cls");
    printf("\t%s Leaderboard\n\n", mode);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("No scores yet.\n");
        system("pause");
        leaderboard(user);
        return;
    }

    char name[100];
    int score;
    int rank = 1;

    while(fscanf(fp, "%s %d", name, &score) != EOF && rank <= 10){
        printf("%d. %-10s %d\n", rank, name, score);
        rank++;
    }

    fclose(fp);

    printf("\n");
    system("pause");
    leaderboard(user); 
}
void overallLeaderboard(){
    system("cls");

    char names[200][100];
    int scores[200];
    char modes[200][20];
    int count = 0;

    char *files[] = {"add.txt", "minus.txt", "times.txt", "divide.txt"};
    char *labels[] = {"Addition", "Subtraction", "Multiplication", "Division"};

    FILE *fp;

    // Read all files
    for(int f = 0; f < 4; f++){
        fp = fopen(files[f], "r");
        if(fp != NULL){
            while(fscanf(fp, "%s %d", names[count], &scores[count]) != EOF){
                strcpy(modes[count], labels[f]);
                count++;
            }
            fclose(fp);
        }
    }

    if(count == 0){
        printf("No scores yet.\n");
        system("pause");
        return;
    }
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - i - 1; j++){
            if(scores[j] < scores[j + 1]){
                int tempScore = scores[j];
                char tempName[100], tempMode[20];

                strcpy(tempName, names[j]);
                strcpy(tempMode, modes[j]);

                scores[j] = scores[j + 1];
                strcpy(names[j], names[j + 1]);
                strcpy(modes[j], modes[j + 1]);

                scores[j + 1] = tempScore;
                strcpy(names[j + 1], tempName);
                strcpy(modes[j + 1], tempMode);
            }
        }
    }

    printf("\tOVERALL TOP 10 PLAYERS\n\n");
    printf("Rank  Name       Score   Mode\n");

    for(int i = 0; i < count && i < 10; i++){
        printf("%-5d %-10s %-7d %s\n", i + 1, names[i], scores[i], modes[i]);
    }

    printf("\n");
    system("pause");
}