//Library files :
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of node :
struct node
{
    int age;
    int date;
    char month[50];
    char name[50];
    char pName[50];
    int pAge;
    char email[50];
    char password[50];
    char fromLoc[50];
    char toLoc[50];
    char mode[50];
    char meal[50];

    int distance;
    int pass_added;
    int ticket_cancelled;
    int pass_ticket_cancelled;
    int book;

    int delbyAdmin;

    int can_cancel;

    struct node *next;
};

// Registration Code for new Users :
struct node *registeration(struct node *head)
{
    printf("\nEnter the details for registration : \n");
    printf("------------------------------------\n");
    struct node *temp = head;
    struct node *User = (struct node *)malloc(sizeof(struct node));
    char scanner[51];

    // Initially the flag is set to 0 if user cancle's the ticket the falg becomes 1 & he is unable to book the ticket.
    User->ticket_cancelled = 0;
    User->pass_ticket_cancelled = 0;
    User->pass_added = 0; // Initially pass added is 0;
    User->book = 0;       // Initially user is set to no booking status.
    User->can_cancel = 0;
    User->delbyAdmin = 0;

    printf("\nEnter Your Name: ");
    fflush(stdin);   
    fgets(scanner, 50, stdin);
    strcpy(User->name, scanner);

    printf("\nEnter Your Age : ");
    scanf("%d", &User->age);

a:
    printf("\nEnter Your Email Id: ");
    fflush(stdin);
    fgets(scanner, 50, stdin);
    strcpy(User->email, scanner);
    int go = 1;
    while (temp != NULL)
    {
        go = strcmp(User->email, temp->email);
        if (go == 0)
        {
            printf("\n\033[1;31mThis user is already registered \nPlease enter a new email Id \033[0m\n");
            goto a;
        }
        temp = temp->next;
    }

    printf("\nEnter Your Password: ");
    fgets(scanner, 50, stdin);
    strcpy(User->password, scanner);

    printf("\n|---------------------------------|\n");
    printf("|     Your filled details are:    |\n\n");
    printf("| name    : %s", User->name);
    printf("| age     : %d", User->age);
    printf("\n| email   : %s", User->email);
    printf("| password: %s", User->password);
    printf("|---------------------------------|\n");

    User->next = head;
    head = User;
    return head;
}

// Booking panel code for logged in users :
struct node *bookTicket(struct node *head, char email[])

{
    struct node *user = head;

    char eml[50];
    strcpy(eml, email);
    int comparedEmail;
    while (user != NULL)
    {
        comparedEmail = strcmp(user->email, eml);
        if (comparedEmail == 0)
        {
            user->distance = 0;
            user->book = 1;

            int mode;
            printf("------------------------------\n");
            printf("1 Train \n2 Flight\n3 Bus\n");
            printf("your choice here : ");
            scanf("%d", &mode);
            switch (mode)
            {
            case 1:
                strcpy(user->mode, "Train");
                break;
            case 2:
                strcpy(user->mode, "Flight");
                break;
            case 3:
                strcpy(user->mode, "Bus");
                break;
            }
            char scanner[51];
            printf("------------------------------");

            printf("\nEnter From Location : ");
            fflush(stdin);
            fgets(scanner, 50, stdin);
            strcpy(user->fromLoc, scanner);

            printf("\nEnter To Location : ");
            fflush(stdin);
            fgets(scanner, 50, stdin);
            strcpy(user->toLoc, scanner);

            int mon;
            printf("\nEnter Month : \nPlease enter a value b/w 1 to 12 \n");
        // here goto is used to jump from invalid month
        m:
            scanf("%d", &mon);
            if (mon > 12 || mon < 1)
            {
                printf("\n\033[1;31mPlease enter a valid month : \033[0m");
                goto m;
            }
            switch (mon)
            {
            case 1:
                strcpy(user->month, "January");
                break;
            case 2:
                strcpy(user->month, "February");
                break;
            case 3:
                strcpy(user->month, "March");
                break;
            case 4:
                strcpy(user->month, "April");
                break;
            case 5:
                strcpy(user->month, "May");
                break;
            case 6:
                strcpy(user->month, "June");
                break;
            case 7:
                strcpy(user->month, "July");
                break;
            case 8:
                strcpy(user->month, "August");
                break;
            case 9:
                strcpy(user->month, "September");
                break;
            case 10:
                strcpy(user->month, "October");
                break;
            case 11:
                strcpy(user->month, "November");
                break;
            case 12:
                strcpy(user->month, "December");
                break;
            }

            printf("\nEnter Date : ");
            int date;
        dates:
            scanf("%d", &date);
            if (date > 31 || date < 1)
            {
                printf("\n\033[1;31mPlease enter a valid date : \033[0m");
                goto dates;
            }
            user->date = date;

            printf("\nEnter your journey dist. in KM's : ");
            scanf("%d", &user->distance);

            int meal = 0;
            printf("Enter your preferred meal : \n");
            printf("1 Veg. \n2 Non-Veg. \n3 None \n");

        Meal:
            printf("Enter your meal type : ");
            scanf("%d", &meal);
            switch (meal)
            {
            case 1:
                strcpy(user->meal, "Veg.");
                break;
            case 2:
                strcpy(user->meal, "Non - Veg.");
                break;
            case 3:
                strcpy(user->meal, "None");
                break;
            default:
                printf("\033[1;31mPlease enter a ideal choice. \033[0m\n");
                goto Meal;
            }

            printf("------------------------------\n\n");
            user->can_cancel = 1;
        }
        user = user->next;
    }
    return head;
}

// Code to Edit jouney detail's :
struct node *editJourneyDetails(struct node *head, char email[])
{
    struct node *user = head;
    struct node *user1 = head;
    char eml[50];
    strcpy(eml, email);
    int comparedEmail;
    int compForEditORnot = strcmp(user->email, eml);

    while (user1 != NULL)
    {
        compForEditORnot = strcmp(user1->email, eml);
        if (compForEditORnot == 0)
        {
            if (user1->book == 0)
            {
                printf("\n\033[1;31mPlease book ticket first to edit\033[0m\n\n");
                return head;
            }
        }
        user1 = user1->next;
    }

    while (user != NULL)
    {
        int opt;

        printf("Enter options to edit : \n");
        printf("1 Month \n2 Date \n3 Meal \n");
        scanf("%d", &opt);
        int meal = 0;
        switch (opt)
        {
        case 1:
            comparedEmail = strcmp(user->email, eml);
            if (comparedEmail == 0)
            {

                char scanner[51];
                printf("------------------------------");

                int mon;
                printf("\nEnter Month : \nPlease enter a value b/w 1 to 12 \n");
            // here goto is used to jump from invalid month
            m:
                scanf("%d", &mon);
                if (mon > 12 || mon < 1)
                {
                    printf("\n\033[1;31mPlease enter a valid month : \033[0m");
                    goto m;
                }
                switch (mon)
                {
                case 1:
                    strcpy(user->month, "January");
                    break;
                case 2:
                    strcpy(user->month, "February");
                    break;
                case 3:
                    strcpy(user->month, "March");
                    break;
                case 4:
                    strcpy(user->month, "April");
                    break;
                case 5:
                    strcpy(user->month, "May");
                    break;
                case 6:
                    strcpy(user->month, "June");
                    break;
                case 7:
                    strcpy(user->month, "July");
                    break;
                case 8:
                    strcpy(user->month, "August");
                    break;
                case 9:
                    strcpy(user->month, "September");
                    break;
                case 10:
                    strcpy(user->month, "October");
                    break;
                case 11:
                    strcpy(user->month, "November");
                    break;
                case 12:
                    strcpy(user->month, "December");
                    break;
                }
                break;
            }

        case 2:
            printf("\nEnter Date : ");
            int date;
        dates:
            scanf("%d", &date);
            if (date > 31 || date < 1)
            {
                printf("\n\033[1;31mPlease enter a valid date : \033[0m");
                goto dates;
            }
            user->date = date;
            break;

        case 3:

            printf("Enter your preferred meal : \n");
            printf("1 Veg. \n2 Non-Veg. \n3 None \n");

        Meal:
            scanf("%d", &meal);
            switch (meal)
            {
            case 1:
                strcpy(user->meal, "Veg.");
                break;
            case 2:
                strcpy(user->meal, "Non - Veg.");
                break;
            case 3:
                strcpy(user->meal, "None");
                break;
            default:
                printf("\033[1;31mPlease enter a ideal choice. \033[0m\n");
                goto Meal;
            }
            break;
        }

        printf("------------------------------\n\n");

        user = user->next;
    }

    return head;
}

// Code to view User & Passenger ticket :
struct node *viewTicket(struct node *head, char email[])
{
    struct node *user = head;

    if (user->book == 0)
    {
        printf("\n\033[1;31mPlease book ticket first to view. \033[0m\n\n");
        return head;
    }

    char eml[50];

    strcpy(eml, email);
    int comparedEmail;

    while (user != NULL)
    {
        comparedEmail = strcmp(user->email, eml);
        if (comparedEmail == 0)
        {
            // User booking details print
            if (user->ticket_cancelled == 1)
            {
                printf("\n------------------------------\n");
                printf("\n\033[1;31mYour ticket has been cancelled \033[0m\n");
                printf("\n------------------------------\n");
                return head;
            }

            printf("\n\n");
            printf("------------------------------\n");
            printf("Your Ticket Booking Details are:");
            printf("\n\n");
            printf("\tUser name: %s", user->name);
            printf("\tMode :%s \tMeal : %s", user->mode, user->meal);

            int mode_train, mode_flight, mode_bus, total_fare, fare_type;

            mode_train = strcmp(user->mode, "Train");
            mode_flight = strcmp(user->mode, "Flight");
            mode_bus = strcmp(user->mode, "Bus");
            if (mode_train == 0)
            {
                printf("\n\tFare : %d", user->distance * 9);
                fare_type = 1;
            }
            if (mode_flight == 0)
            {
                printf("\n\tFare : %d", user->distance * 15);
                fare_type = 2;
            }
            if (mode_bus == 0)
            {
                printf("\n\tFare : %d", user->distance * 7);
                fare_type = 3;
            }

            printf("\n\tDate  : %d", user->date);
            printf("\n");
            printf("\tMonth : %s", user->month);
            printf("\n\tFrom  : %s", user->fromLoc);
            printf("\tTo    : %s", user->toLoc);
            printf("------------------------------");
            printf("\n");

            // Passenger booking details print
            if (user->pass_ticket_cancelled == 1)
            {
                printf("\n\t Passenger ticket has been cancelled \n\n");
                return head;
            }
            if (user->pass_added == 1)
            {
                printf("\n");
                printf("------------------------------\n");
                printf("\n\n\t\033[1;34mPassenger's Ticket Booking Details are:\033[0m\n");
                printf("\n\n");
                printf("\n\tPassenger name : %s", user->pName);
                printf("\tAge  : %d", user->pAge);
                printf("\n\tMode :%s \tMeal : %s", user->mode, user->meal);
                if (mode_train == 0)
                {
                    printf("\n\tFare : %d", user->distance * 9);
                }
                if (mode_flight == 0)
                {
                    printf("\n\tFare : %d", user->distance * 15);
                }
                if (mode_bus == 0)
                {
                    printf("\n\tFare : %d", user->distance * 7);
                }
                printf("\n\tDate  : %d", user->date);
                printf("\n");
                printf("\tMonth : %s", user->month);
                printf("\n\tFrom  : %s", user->fromLoc);
                printf("\tTo    : %s", user->toLoc);
                printf("------------------------------");

                if (user->pass_added == 1)
                {
                    if (fare_type == 1)
                    {
                        printf("\n\tTotal Fare = %d", user->distance * 9 * 2);
                    }
                    else if (fare_type == 2)
                    {
                        printf("\n\tTotal Fare = %d", user->distance * 15 * 2);
                    }
                    if (fare_type == 3)
                    {
                        printf("\n\tTotal Fare = %d", user->distance * 7 * 2);
                    }
                    printf("\n------------------------------");
                }

                printf("\n\n");
            }
        }
        user = user->next;
    }
    return head;
}

// Code to cancel passenger ticket :
struct node *cancelTicket(struct node *head, char email[])
{
    struct node *user = head;
    char eml[50];
    strcpy(eml, email);
    int comparedEmail;

    while (user != NULL)
    {
        comparedEmail = strcmp(user->email, eml);
        if (comparedEmail == 0)
        {
            if (user->can_cancel == 0)
            {
                printf("\n\033[1;31mPlease book the ticket first\033[0m\n\n");
                return head;
            }
            int choice;
            printf("\nEnter choice to cancel ticket : ");
            printf("\n\tUser : 1");
            printf("\n\tpassanger : 2");
            printf("\n\tYour choice here : ");
            scanf("%d", &choice);
            printf("\n");
            if (choice == 1)
            {
                user->ticket_cancelled = 1;
            }
            else if (choice == 2)
            {
                user->pass_ticket_cancelled = 1;
            }
        }
        user = user->next;
    }

    return head;
}

// Code for Adding a Passenger :
struct node *addPassenger(struct node *head, char email[])
{
    char scanner[51];
    struct node *user = head;
    char eml[50];
    strcpy(eml, email);
    int comparedEmail;
    user->pass_added = 1;

    while (user != NULL)
    {
        comparedEmail = strcmp(user->email, eml);
        if (comparedEmail == 0)
        {

            printf("------------------------------");
            printf("\nPlease enter passenger name: \n");

            fflush(stdin);
            fgets(scanner, 50, stdin);
            strcpy(user->pName, scanner);

            printf("\nEnter the passenger Age : ");
            scanf("%d", &user->pAge);

            int meal = 0;
            printf("Enter your preferred meal : \n");
            printf("1 Veg. \n2 Non-Veg. \n3 None \n");

        Meal:
            scanf("%d", &meal);
            switch (meal)
            {
            case 1:
                strcpy(user->meal, "Veg.");
                break;
            case 2:
                strcpy(user->meal, "Non - Veg.");
                break;
            case 3:
                strcpy(user->meal, "None");
                break;
            default:
                printf("\033[1;31mPlease enter a ideal choice. \033[0m\n");
                goto Meal;
            }

            printf("\n\n");
            printf("------------------------------\n");
            printf("Passenger's Ticket Booking Details are:");
            printf("\n\n");
            printf("\n\tPassenger name : %s", user->pName);
            printf("\n\tAge  : %d", user->pAge);
            printf("\n\tMode :%s \tMeal : %s", user->mode, user->meal);
            printf("\n\tDate  : %d", user->date);
            printf("\n");
            printf("\tMonth : %s", user->month);
            printf("\n\tFrom  : %s", user->fromLoc);
            printf("\tTo    : %s", user->toLoc);
            printf("------------------------------");
            printf("\n\n");

            return head;
        }

        user = user->next;
    }
    return head;
}

// Operations panel for logged in users :
struct node *operations(struct node *head, char email[])
{
    int opern;
    char eml[50];
    strcpy(eml, email);
    struct node *temp = head;
    do
    {
        printf("Please choose an option:\n");
        printf("\t1 Book Ticket\n");
        printf("\t2 Edit Journey Details\n");
        printf("\t3 View Ticket's\n");
        printf("\t4 Add Passenger\n");
        printf("\t5 Cancel Ticket's\n");
        printf("\nEnter 0 to exit\n");
        printf("------------------------------");
        printf("\nYour choice here : ");
        scanf("%d", &opern);
        switch (opern)
        {
        case 1:
            head = bookTicket(head, eml);
            continue;
        case 2:
            head = editJourneyDetails(head, eml);
            continue;
        case 3:
            head = viewTicket(head, eml);
            continue;
        case 4:
            head = addPassenger(head, eml);
            continue;
        case 5:
            head = cancelTicket(head, eml);
            continue;
        }
    } while (opern != 0);
    printf("\nThank you \nYou have been successfully Logged out");
    return head;
}

// Login page code for Registered users :
struct node *login(struct node *head)
{
    printf("------------------------------\n");
    printf("Enter details for login :\n");
    struct node *temp = head;
    int loggedIn = 0;
    char email[51];
    char password[51];
    printf("Email Id: ");
    fflush(stdin);
    fgets(email, 50, stdin);
    printf("password: ");
    fgets(password, 50, stdin);
    while (temp != NULL)
    {
        int compared_eml, compared_pwd;
        compared_eml = strcmp(temp->email, email);
        compared_pwd = strcmp(temp->password, password);
        if (compared_eml == 0 && compared_pwd == 0)
        {
            loggedIn = 1;
            int to_do;
            printf("\n-------------------------------");
            printf("\nWELCOME Mr. %s", temp->name);
            head = operations(head, temp->email);
            return head;
        }
        temp = temp->next;
    }

    if (loggedIn == 0)
    {
        printf("\nPlease enter a valid user id and password\n\n");
    }
    return head;
}

// Admin code to view all user's :
void *ViewAllUser(struct node *head)
{

    struct node *user = head;
    int i = 1;
    printf("\n-----------------------------------");
    printf("\nConfidential Data Here : \n");
    while (user != NULL)
    {

        printf("\n%d) User Name   :%s User Password : %s", i, user->name, user->password);
        user = user->next;
        i++;
    }
    printf("\n-----------------------------------");
}

// Code for Admin panel :
struct node *Admin(struct node *head)
{
    char password[] = "admin";
    char inputPassword[50];
    int incorrect = 0;
retry:
    printf("Enter Admin Password: ");
    scanf("%s", inputPassword);

    if (inputPassword == "3")
    {
        return head;
    }
    // Compare the entered password with the predefined password
    if (strcmp(password, inputPassword) == 0)
    {
        printf("\nLogin successful! You have access.\n");
    }
    else
    {
        printf("Login failed! Incorrect password.\n\n");
        if (incorrect >= 2)
        {
            return head;
        }
        incorrect++;
        goto retry;
    }

    int opern;
    struct node *admin = head;
    printf("Please choose an option:\n");
    printf("\n\t1 View All User\n");
    printf("\nEnter 0 to exit\n");
    printf("------------------------------");
    printf("\nYour choice here : ");
    scanf("%d", &opern);
    switch (opern)
    {
    case 1:
        ViewAllUser(head);
        return head;
        break;
    }
    printf("------------------------------");
}

// Driver code :
int main()
{
    int choice;
    int regn = 0;
    struct node *head = NULL;

    do
    {
        printf("\n\n\t\033[1;34m<<------------------------------>>\033[0m\n");                 // Blue
        printf("\t\033[1;34m||====== \033[1;36mExpress Travel's\033[1;34m ======||\033[0m\n"); // Blue and Cyan
        printf("\t\033[1;34m<<------------------------------>>\033[0m\n\n");                   // Blue

        printf("\t\t\033[1;32m1 Register\033[0m\n");                                  // Green
        printf("\t\t\033[1;32m2 Login\033[0m\n");                                     // Green
        printf("\t\t\033[1;32m3 Admin\033[0m\n");                                     // Green
        printf("\033[1;31mPress 0 to exit\033[0m\n");                                 // Red
        printf("\033[1;30m-----------------------------------------------\033[0m\n"); // White
        printf("\033[1;30mYour choice here : \033[0m");                               // White
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            head = registeration(head);
            regn = 1;
            continue;
        case 2:
            if (regn == 0)
            {
                printf("\033[1;31m|--------------------------------|\033[0m");
                printf("\n\033[1;31m| Please Register Yourself First |\033[0m\n");
                printf("\033[1;31m|--------------------------------|\033[0m");
                continue;
            }
            head = login(head);
            break;
        case 3:
            head = Admin(head);
            continue;
        }
    } while (choice != 0);

    return 0;
}