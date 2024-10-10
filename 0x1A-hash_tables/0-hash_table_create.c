#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table
 * @size: Size of the array
 *
 * Return: Pointer to the newly created hash table,
 * or NULL if something went wrong.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *new_table;
unsigned long int i;

/* Allocate memory for the hash table structure */
new_table = malloc(sizeof(hash_table_t));
if (new_table == NULL)
return (NULL);

/* Allocate memory for the array of pointers */
new_table->array = malloc(sizeof(hash_node_t *) * size);
if (new_table->array == NULL)
{
free(new_table);
return (NULL);
}

/* Initialize each pointer in the array to NULL */
for (i = 0; i < size; i++)
new_table->array[i] = NULL;

/* Set the size of the hash table */
new_table->size = size;

return (new_table);
}
