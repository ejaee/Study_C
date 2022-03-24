/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_2.5_paraPSetRev.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:54:35 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/08 14:00:22 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*SetRev(char *arr){
	int idx = 0;
	int rev = strlen(arr)-1;
	char *dest;

	dest = malloc(sizeof(char)*strlen(arr)+1);
	while (rev < 0){
		*dest = arr[rev];
		dest++;
		rev--;
	}
	*dest = '\0';
	return (dest);
}

int	main(){
	char *arr = "set rev";

	arr = SetRev(arr);
	printf("%s", arr);
	return 0;
}
