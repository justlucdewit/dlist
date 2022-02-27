# dlist

dlist.h is a single header library for C, which you can use
to dynamically store structures

this 'dynamic list' (or dlist for short) automatically handles
the memory management of the list. dlist.h also provides a series
of functions which you can use to perform common operations on
the list like adding items, removing items, clearning the list
and itterating over items.

### Creation of dlists:
```c
typedef struct {
    ...
} users;

dlist users = create(users);
```

### Adding new item(s) to dlist
```c
// Adding a single users
user u1 = { .first_name = "jack" };
dlist_create_back(users, user, u1);

// Adding multiple users
user usrs[] = {
    { .first_name = "jack" },
    { .first_name = "bob" },
    { .first_name = "joseph" }
};

dlist_create_back_many(users, user, usrs, 3);
```

### Clearing the entire dlist
```c
dlist_clear(users);
```

### Getting an item by index
```c
user* u = dlist_get(users, index);
```

### Looping over all items
```c
for dlist_each(idx, users) {
    user* u = dlist_get(users, idx);
    printf("name = %s\n", u->first_name);
}
```