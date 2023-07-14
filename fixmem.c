/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the previous memory block
 * @old_size: the old size of the block
 * @new_size: the new size of the block
 *
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
		return (NULL);
	if (ptr == NULL)
	{
		fill_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		copy_memory(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * _memset - fills a memory block with a constant byte
 * @s: pointer to the memory block
 * @n: number of bytes to fill
 * @byt: constant byte to fill the block with
 *
 * Return: pointer to the memory block
 */
char *_memset(char *s, char byt, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = byt;
	}
	return (s);
}

/**
 * free_data - frees the memory allocated for data
 * @data: pointer to the data structure
 *
 * Return: 0 on success, -1 on failure
 */
int free_data(sh_t *data)
{
	free(data->line);
	data->line = NULL;
	free(data->args);
	data->args = NULL;
	free(data->cmd);
	data->cmd = NULL;
	free(data->error_msg);
	data->error_msg = NULL;
	return (0);
}

/**
 * _memcpy - copies a memory area from source to destination
 * @dest: pointer to the destination memory area
 * @src: pointer to the source memory area
 * @n: number of bytes to copy
 *
 * Return: pointer to the destination memory area
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
