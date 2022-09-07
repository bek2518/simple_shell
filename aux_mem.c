#include "main.h"

/**
 * _memcpt - copies information
 * @newptr: destination pointer
 * @ptr: source pointer
 * @size: size of new pointer
 */
void _memcpy(void *newptr,const  void *ptr, unsigned int size)
{
	char *ptr_c = (char *)ptr;
	char *newptr_c = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; size++)
		newptr_c[i] = ptr_c[i];
}

/**
 * _realloc - reallocates the memory block
 * @ptr: pointer to memory previously allocated
 * @old_size: size in byte
 * @new_size: new size to be allocated in byte
 * Return: ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);
	newptr = malloc(new_size);
	if (newptr == NULL)
		return(NULL);
	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);
	free(ptr);
	return (newptr);
}
