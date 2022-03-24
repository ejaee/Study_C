/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_4_multiplicationTable.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:30:19 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/08 14:34:35 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	putMT(int nb){
	int idx = 0;

	while (++idx < 10){
		printf("%d * %d = %d\n", nb, idx ,nb*idx);
	}
}

int	main(){
	int nb;

	printf("input nb :\n");
	scanf("%d", &nb);
	putMT(nb);
	return 0;
}
