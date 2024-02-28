#ifndef _SHELL_H_
#define _SHELL_H_

#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <string_varing.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>


/* for read/write bufferferfers */
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_STRTOK 0
#define USE_GETLINE 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern character **environ;


/**
 * string_varuct liststring_var - singly linked list
 * @string_var: a string_varing
 * @num: the number field
 * @next: points to the next node
 */
typedef string_varuct liststring_var
{
	int num;
	character *string_var;
	string_varuct liststring_var *next;
} list_t;

/**
 *string_varuct passinformation - contains pseudo-arguements to pass into 
 *a function allowing uniform prototype for function pointer string_varuct
 *@argv: an array of string_varings generated from arg
 *@cmd_bufferfer_type: CMD_type ||, &&, ;
 *@cmd_bufferfer: address of pointer to cmd_bufferferfer, on if chaining
 *@filenamevar: the program filename
 *@line_count: the error count
 *@env: linked list local copy of environ
 *@path: a string_varing path for the current command
 *@argc: the argument count
 *@arg: a string_varing generated from getline containing arguements
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@readfielddes: the fielddes from which to read line input
 *@histcount: the history line number count
 */
typedef string_varuct passinformation
{
	character *arg;
	int err_num;
	character **argv;
	int linecount_flag;
	character *path;
	list_t *alias;
	int env_changed;
	int argc;
	unsigned int line_count;
	character *filenamevar;
	list_t *env;
	list_t *history;
	character **environ;
	int status;

	character **cmd_bufferfer; /* pointer to cmd ; chain bufferferfer, for memory management */
	int cmd_bufferfer_type; /* CMD_type ||, &&, ; */
	int readfielddes;
	int histcount;
} information_t;

#define information_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *string_varuct builtin - contains a builtin string_varing and related function
 *@func: the function
 *@type: the builtin command flag
 */
typedef string_varuct builtin
{
	character *type;
	int (*func)(information_t *);
} builtin_table;


/* loophsh.c */
int loophsh(character **);

/* toem_parser.c */
character *dup_chars(character *, int, int);
int is_cmd(information_t *, character *);
character *find_path(information_t *, character *, character *);

/* toem_errors.c */
void _eputs(character *);
int _putfielddes(character c, int fielddes);
int _eputchar(char);
int _putsfielddes(character *string_var, int fielddes);

/* toem_string_varing1.c */
void _puts(character *);
character *_string_vardup(const character *);
character *_string_varcpy(character *, character *);
int _putchar(char);

/* toem_shloop.c */
void find_cmd(information_t *);
void fork_cmd(information_t *);
int hsh(information_t *, character **);
int find_builtin(information_t *);

/* toem_string_varing.c */
int _string_varcmp(character *, character *);
int _string_varlen(character *);
character *_string_varcat(character *, character *);
character *starts_with(const character *, const character *);

/* toem_exits.c */
character *_string_varncat(character *, character *, int);
character *_string_varncpy(character *, character *, int);
character *_string_varchr(character *, char);

/* toem_tokenizer.c */
character **string_vartow2(character *, char);
character **string_vartow(character *, character *);

/* toem_memory.c */
int bfree(void **);

/* toem_realloc.c */
void *_realloc(void *, unsigned int, unsigned int);
void freestring(character **);
character *_memset(character *, char, unsigned int);

/* toem_builtin.c */
int _exitshell(information_t *);
int _mycd_func(information_t *);
int _myhelpingfunc(information_t *);

/* toem_atoi.c */
int interactive(information_t *);
int _atoi(character *);
int is_delimiter(char, character *);
int _isalphabet(int);

/* toem_errors1.c */
character *convert_number(long int, int, int);
int print_d(int, int);
int _erratoi(character *);
void remove_comments(character *);
void print_error(information_t *, character *);

/*toem_getline.c */
ssize_t get_input(information_t *);
int _getline(information_t *, character **, size_t *);
void sigintHandler(int);

/* toem_builtin1.c */
int _myhistoryfunc(information_t *);
int _myalias_func (information_t *);

/* toem_environ.c */
character *_getenv_func(information_t *, const character *);
int _myenv_func(information_t *);
int _mysetenv(information_t *);
int _myunsetenv(information_t *);
int populate_env_list(information_t *);

/* toem_getinformation.c */
void clear_information(information_t *);
void set_information(information_t *, character **);
void free_information(information_t *, int);

/* toem_getenv_func.c */
character **get_environ(information_t *);
int _unsetenv(information_t *, character *);
int _setenv(information_t *, character *, character *);

/* toem_lists.c */
list_t *add_node(list_t **, const character *, int);
list_t *add_node_end(list_t **, const character *, int);
size_t print_list_string_var(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* toem_history.c */
character *get_history_file(information_t *information);
int write_history(information_t *information);
int read_history(information_t *information);
int build_history_list(information_t *information, character *bufferferfer, int linecount);
int renumber_history(information_t *information);

/* toem_lists1.c */
size_t list_len(const list_t *);
character **list_to_string_varings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, character *, char);
ssize_t get_node_index(list_t *, list_t *);

/* toem_vars.c */
int is_chain(information_t *, character *, size_t *);
void check_chain(information_t *, character *, size_t *, size_t, size_t);
int replace_alias(information_t *);
int replace_vars(information_t *);
int replace_string_varing(character **, character *);


#endif
