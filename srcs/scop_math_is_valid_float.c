/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop_math_is_valid_float.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:13:50 by cledant           #+#    #+#             */
/*   Updated: 2017/03/06 16:26:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		scop_math_is_valid_float(const float nbr)
{
	int		test_error;

	if (nbr == HUGE_VAL || nbr == HUGE_VALF || nbr == HUGE_VALL)
		return (0);
	test_error = fpclassify(nbr);
	if (test_error == FP_NAN || test_error == FP_INFINITE ||
			test_error = FP_SUBNORMAL)
		return (0);
	return (1);
}
