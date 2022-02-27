// Dynamic list library for c
// Written by luke_
// 22/02/2022

#pragma once
#include <stdio.h>
#include <stdlib.h>

#define dlist_each(index, array) \
(int index = 0; index < array.length; index++)

#define dlist_create(type) \
internal_dlist_create(sizeof(type))

#define dlist_create_back(list, type, item)\
{\
	type* allocated_item_buffer = malloc(sizeof(type));\
	allocated_item_buffer[0] = item;\
	internal_dlist_add_back(&list, allocated_item_buffer);\
}

#define dlist_create_back_many(list, type, items, n)\
{\
	type* allocated_item_buffer = malloc(sizeof(type) * n);\
	allocated_item_buffer = items;\
	for (int i = 0; i < n; i++) {\
		internal_dlist_add_back(&list, allocated_item_buffer+ i);\
	}\
}

typedef struct {
	size_t length;
	size_t capacity;
	size_t element_size;
	float growth_factor;
	void** items;
} dlist;

// Creation of a new dynamic list
dlist internal_dlist_create(size_t element_size) {
	dlist ret = { 0 };

	ret.length = 0;
	ret.capacity = 100;
	ret.element_size = element_size;
	ret.growth_factor = 1.5;
	ret.items = malloc(element_size * 100);

	return ret;
}

// Clear all elements out of the dynamic list
void dlist_clear(dlist* list) {
	list->length = 0;
	list->capacity = 100;
	list->items = realloc(list->items, list->element_size * 100);
}

// Add an element to the end of the dynamic list
void internal_dlist_add_back(dlist* list, void* element_ptr) {
	list->items[list->length] = element_ptr;
	++list->length;
}

// Get an item from the dynamic list
void* dlist_get(dlist* list, size_t i) {
	return list->items[i];
}