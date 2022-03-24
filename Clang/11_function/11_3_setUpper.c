/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_3_setUpper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choiejae <ejchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:10:22 by choiejae          #+#    #+#             */
/*   Updated: 2022/02/08 14:29:00 by choiejae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int	*n1, int *n2){
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

void	Upper(int *arr, int size){
	int min;
	int idx, jdx;

	min = 0;
	idx = 0;
	while(idx < size-1){
		jdx = idx+1;
		while(jdx < size){
			if (arr[idx] >= arr[jdx])
				ft_swap(&arr[idx], &arr[jdx]);
			jdx++;	
		}
		idx++;
	}
}

int	main(){
	int arr[] = {12, 32, 43, 2, 40};
	int idx = 0;
	int size = sizeof(arr)/sizeof(int);
	
	Upper(arr, size);
	while (size--){
		printf("%d ", arr[idx]);
		idx++;
	}
	return 0;
}
