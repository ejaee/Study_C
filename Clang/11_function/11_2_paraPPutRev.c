/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_2_paraPPutRev.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:49:24 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/08 13:54:02 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	main(){
	char *arr = "print rev";

	for(int idx = 0; idx < strlen(arr); idx++){
		printf("%c ", arr[strlen(arr) - (idx+1)]);
	}
	return 0;
}
