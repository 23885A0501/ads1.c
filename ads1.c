#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define K 2 // Number of hash tables
#define MAX_RETRIES 10
// Hash function 1unsigned int hash_function_1(int key) {
 return key % TABLE_SIZE;
}
// Hash function 2
unsigned int hash_function_2(int key) {
 return (key / TABLE_SIZE) % TABLE_SIZE;
}
// Initialize hash tables
int table[K][TABLE_SIZE];
// Function to insert a key into the hash tables
int insert(int key) {
 int retries = 0;
 
 while (retries < MAX_RETRIES) {
 for (int i = 0; i < K; i++) {
 // Calculate hash positions using two hash functions
 unsigned int hash_pos_1 = hash_function_1(key);
P a g e | 9
 unsigned int hash_pos_2 = hash_function_2(key);
 if (table[i][hash_pos_1] == 0) {
 // If the position in the current table is empty, insert the key
 table[i][hash_pos_1] = key;
 return 1; // Success
 } else {
 // Evict the existing key and insert the new key
 int evicted_key = table[i][hash_pos_1];
 table[i][hash_pos_1] = key;
 // Try to insert the evicted key into the other table
 key = evicted_key;
 }
 }
 retries++;
 }
 // Resizing needed if maximum retries reached
 return 0; // Failure, need resizing
}
// Function to check if a key is present in the hash tables
int lookup(int key) {
 for (int i = 0; i < K; i++) {
 unsigned int hash_pos_1 = hash_function_1(key);
 if (table[i][hash_pos_1] == key) {
 printf("Key %d found in table %d\n", key, i);
 return 1; // Key found
 }
P a g e | 10
 }
 printf("Key %d not found\n", key);
 return 0; // Key not found
}
// Function to print the hash tables
void print_tables() {
 for (int i = 0; i < K; i++) {
 printf("Table %d: ", i);
 for (int j = 0; j < TABLE_SIZE; j++) {
 printf("%d\t", table[i][j]);
 }
 printf("\n");
 }
}
int main() {
 // Initialize hash tables
 for (int i = 0; i < K; i++) {
 for (int j = 0; j < TABLE_SIZE; j++) {
 table[i][j] = 0;
 }
 }
 // Insert keys
 insert(10);
 insert(20);
 insert(30);
 insert(25);
 
P a g e | 11
insert(35);
 // Print hash tables
 printf("After Insertion:\n");
 print_tables();
 // Lookup keys
 lookup(20);
 lookup(25);
 lookup(40);
 return 0;
