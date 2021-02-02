/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 07:21:17 by mazoukni          #+#    #+#             */
/*   Updated: 2021/02/01 17:28:16 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void exit_error(int o)
{
    if (o > 11)
        error_definition(o); 
    else if (o == 1)
        printf("\n Error: \n missing extension .cub");
    else if (o == 2)
        printf("\n Error: \n");
    else if (o == 3)
        printf("\n Error: \n");
    else if (o == 4)
        printf("\n Error: \n");
    else if (o == 5)
        printf("\n Error: \n");
    else if (o == 6)
        printf("\n Error: \n");
    else if (o == 7)
        printf("\n Error: \n");
    else if (o == 8)
        printf("\n Error: \n");
    else if (o == 9)
        printf("\n Error: \n");
    else if (o == 10)
        printf("\n Error: \n");
    else if (o == 11)
        printf("\n Error: \n");
    
}

static void error_definition(int o)
{
    if (o > 20)
        error_indefined(o);
    else if ()
}

static void error_indefined(int o)
{
    if (o == 22)
    else if (o == 23)
    else if (o == 23)
    else if (o == 23)
    else if (o == 23)
    else if (o == 23)
}

static void exit_game(t_cub *cub, int o)
{
    if (o > 1 && o < 25)
        exit_error(o);
}