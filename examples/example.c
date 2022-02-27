#include "../dlist.h"
#include <stdio.h>

// Record of the the object we want to store
typedef struct {
    int id;
    char* first_name;
    char* last_name;
    int age;
} user;

int main() {
    // Create a new dlist for users
    dlist users = dlist_create(user);
    
    // Add 5 new users to the reserved memory
    user new_users[] = {
        { .id = 0, .first_name = "Billy", .last_name = "Bonka", .age = 22 },
        { .id = 0, .first_name = "Billy", .last_name = "Bonka", .age = 23 },
        { .id = 0, .first_name = "Billy", .last_name = "Bonka", .age = 24 },
        { .id = 0, .first_name = "Billy", .last_name = "Bonka", .age = 25 },
        { .id = 0, .first_name = "Billy", .last_name = "Bonka", .age = 26 }
    };

    // Add a new items to the array
    dlist_create_back_many(users, user, new_users, 5);

    // Loop over each user
    for dlist_each(index, users) {
        user* usr = dlist_get(&users, index);
        printf("%s %s = %d years old\n", usr->first_name, usr->last_name, usr->age);
    }

    return 0;
}