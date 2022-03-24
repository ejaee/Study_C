/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_5_searchkey.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:35:34 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/08 14:48:05 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int findKey(char *str, char *key){
	int SIdx = 0;
	int KIdx;

	while (str[SIdx]){
		KIdx = 0;
		while (str[SIdx + KIdx] == key[KIdx]){
			KIdx++;
		}
		if(key[KIdx] == 0)
			return (SIdx);
		SIdx++;
	}
	return (-1);
}

#include <stdio.h>

int	main(){
	char *str = "how long did it take you to learn to make furniture like this?";
	char *key = "like";
	int idx;

	idx = findKey(str, key);
	printf("%d\n", idx);
	printf("%s\n", &str[idx]);


	return 0;
}
