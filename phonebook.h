#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PhoneNode {//각 정보를 저장
	char name[20];
	char phone_number[20];
	char group[10];
	char birth[20];
	char email[30];

	struct PhoneNode* next;
}PhoneNode;

typedef struct PhoneType {
	PhoneNode* head;
	PhoneNode* tail;
	PhoneNode* cursor;
}PhoneType;