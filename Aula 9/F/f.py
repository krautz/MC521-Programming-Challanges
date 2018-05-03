#!/usr/bin/env python3
# -*- coding: utf-8 -*-


while(1):
	t = int(input())
	if t == 0:
		break
	l = list(map(int, input().split()))
	
	acc = 0
	for i in range(t):
		acc = acc ^ l[i]
		
	if acc == 0:
		print('No')
	else:
		print('Yes')
