#include "shell.h"

/**
 *  * @information: Structure containing potential arguments. Used to maintain
 *   *          constant function prototype
 *    * _exitshell- exits the shell
 *     *  Return: will exit with a given exit status
 *      *         (0) if information.argv[0] != "exit"
 *       */
int _exitshell(information_t *information)
{
		int exitcheck;

			if (information->argv[1])  /* If there is an exit arguement */
					{
								exitcheck = _erratoi(information->argv[1]);
										if (exitcheck == -1)
													{
																	information->status = 2;
																				print_error(information, "Illegal number: ");
																							_eputs(information->argv[1]);
																										_eputchar('\n');
																													return (1);
																															}
												information->err_number= _erratoi(information->argv[1]);
														return (-2);
															}
				information->err_number= -1;
					return (-2);
}

/**
 *  * _mycd_func - changes the current directory of the process
 *   * @information: Structure containing potential arguments. Used to maintain
 *    * constant function prototype.
 *     *  Return: Will always return 0
 *      */
int _mycd_func(information_t *information)
{
		character *s, *dir, bufferferfer[1024];
			int chdir_ret;

				s = getcwd(bufferferfer, 1024);
					if (!s)
								_puts("TODO: >>getcwd failure emsg here<<\n");
						if (!information->argv[1])
								{
											dir = _getenv_func(information, "HOME=");
													if (!dir)
																	chdir_ret = /* TODO: what should this be? */
																						chdir((dir = _getenv_func(information, "PWD=")) ? dir : "/");
															else
																			chdir_ret = chdir(dir);
																}
							else if (_string_varcmp(information->argv[1], "-") == 0)
									{
												if (!_getenv_func(information, "OLDPWD="))
															{
																			_puts(s);
																						_putchar('\n');
																									return (1);
																											}
														_puts(_getenv_func(information, "OLDPWD=")), _putchar('\n');
																chdir_ret = /* TODO: what should this be? */
																				chdir((dir = _getenv_func(information, "OLDPWD=")) ? dir : "/");
																	}
								else
											chdir_ret = chdir(information->argv[1]);
									if (chdir_ret == -1)
											{
														print_error(information, "can't cd to ");
																_eputs(information->argv[1]), _eputchar('\n');
																	}
										else
												{
															_setenv(information, "OLDPWD", _getenv_func(information, "PWD="));
																	_setenv(information, "PWD", getcwd(bufferferfer, 1024));
																		}
											return (0);
}

/**
 *  * _myhelpingfunc - changes the current directory of the process
 *   * @information: Structure containing potential arguments. Used to maintain
 *    *          constant function prototype.
 *     *  Return: Will always return 0
 *      */
int _myhelpingfunc(information_t *information)
{
		character **arg_array;

			arg_array = information->argv;
				_puts("help call works. Function not yet implemented \n");
					if (0)
								_puts(*arg_array); /* temp att_unused workaround */
						return (0);
}
