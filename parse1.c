/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:01:35 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/20 18:28:31 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void *ft_free_all(char **arr)
{
    int i;

    i = 0;
    while (arr[i] != NULL)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
    return (NULL);
}

int tab_len(char **tab)
{
    int count;

    count = 0;
    while (tab[count] != NULL)
        count++;
    return (count);
}

void print_tab(char **tab)
{
    int i;
    int j;
    if (!tab)
    {
        ft_printf("The array is null");
        return;
    }
    i = 0;
    j = 0;
    while (tab[i] != NULL)
    {
        j = 0;
        while (tab[i][j] != '\0')
        {
            ft_printf("%c", tab[i][j]);
            j++;
        }
        //write(1, "\n", 1);
        i++;
    }
}

int name_extension_check(char *filename)
{
    char **tab;

    tab = ft_split(filename, '.');
    if (tab_len(tab) != 2)
    {

        ft_printf("Error1");
        return (1);
    }
    if (ft_strlen(tab[1]) != 3)
    {
        ft_printf("Error2");
        return (1);
    }
    if (ft_strncmp(tab[1], "ber", 3) != 0)
    {
        ft_printf("Error3");
        return (1);
    }
    ft_free_all(tab);
    return (0);
}

static int lines_count(char *file_path)
{
    char *line;
    int count;
    int fd;
    
    count = 0;
    
    fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        count++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (count);
}
static void check(char **map)
{
    check_invalid_characters(map);
    check_is_rectangular(map);
}
static char **get_map(int fd, char *file_path)
{
    char *line;
    char **result;
    int i;

    i = 0;
    result = (char **)malloc(lines_count(file_path) * sizeof(char *) + 1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        if (ends_with_new_line(line))
            result[i] = ft_substr(line, 0, ft_strlen(line) - 1);
        else
            result[i] = ft_strdup(line);
        free(line);
        i++;
        line = get_next_line(fd);
    }
    result[i] = NULL;
    check(result);
    return (result);
}

char **file_to_map(char *filename)
{
    int fd;
    char *file_path;
    char **result;

    file_path = ft_strjoin("maps/", filename);
    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        free(file_path);
        perror(filename);
        exit(1);
    }
    result = get_map(fd, file_path);
    free(file_path);
    return (result);
}
