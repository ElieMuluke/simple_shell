#include "main.h"

/**
 * main - the entry of the shell program interpreter
 * @argc: number of arguments typed
 * @argv: array pointing to arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	/**
	 * here is where function per case will be called
	 * eg. ctrl + c, ctrl + d, exit, env, etc.
	 * return (0);
	 * or if the command is not found
	 * call the function that will execute the command
	 * then we check for the return of the function
	*/
	print(argv, argc);
	return (0);
}
