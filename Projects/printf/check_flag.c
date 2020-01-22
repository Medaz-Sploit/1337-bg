/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 20:19:16 by mazoukni          #+#    #+#             */
/*   Updated: 2020/01/21 04:02:58 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_flags(char const format, t_data my_data, va_list argp)
{
    int i;
    i = 0;
    
    while (format[i] == '-' || format[i] == '.' || format[i] == '*' || format[i] == '0')
    {
        if (format == '-')
            my_data.flags = '-';
        if (format == '.')
            my_data.flags = '.';
        if (format == '0')
            my_data.flags = '0';
        if (format == '*')
            my_data.flags = '*';
        my_data.total++;
        i++;    
    }
}