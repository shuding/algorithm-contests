/*
* Copyright (C) 2012 All rights reserved.
* File name:  E.cpp
* Author:     Parabola_ds
* Creat time: 2012.05.29
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

char s[200];
int len;

bool typeJava(){
	rep(i, len)
		if(s[i - 1] == '_') return 0;
	if(s[0] >= 'A' && s[0] <= 'Z') return 0;
	return 1;
}

bool typeCpp(){
	rep(i, len){
		if(s[i - 1] >= 'A' && s[i - 1] <= 'Z') return 0;
		if(s[i - 1] == '_'){
			if(i == 1 || i == len) return 0;
			if(s[i - 2] == '_' || s[i] == '_') return 0;
		}
	}
	return 1;
}

int main(){
	while(scanf("%s", s) != EOF){
		len = strlen(s);
		if(typeJava()){
			int st = 0;
			while(st < len){
				if(s[st] >= 'a' && s[st] <= 'z')
					printf("%c", s[st]);
				else
					printf("_%c", s[st] - 'A' + 'a');
				st++;
			}
			puts("");
		} else
		if(typeCpp()){
			int st = 0;
			while(st < len){
				if(s[st] != '_')
					printf("%c", s[st]);
				else
					printf("%c", s[++st] - 'a' + 'A');
				st++;
			}
			puts("");
		}
		else
			puts("Error!");
		}
	return 0;
}

