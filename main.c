#include "phonebook.h"

PhoneNode* head = NULL;
PhoneType* phonetype;

void insert(char name[20], char phone_number[20], char group[10], char birth[20], char email[30]) {
	PhoneNode* temp = (PhoneNode*)malloc(sizeof(PhoneNode));
	strcpy(temp->name, name);
	strcpy(temp->phone_number, phone_number);
	strcpy(temp->group, group);
	strcpy(temp->birth, birth);
	strcpy(temp->email, email);
	temp->next = NULL;

	if (phonetype->head == NULL) {
		phonetype->head = temp;
		phonetype->tail = phonetype->head;
	}
	else {
		phonetype->tail->next = temp;
		phonetype->tail = phonetype->tail->next;
	}
} 

void deletenumber(char *data) {
	if (head == NULL) {
		return;
	}
	PhoneNode* cursor = head;
	if (cursor->phone_number == data) {
		free(cursor);
		return;
	}
	while (cursor->next != NULL) {
		if (cursor->next->phone_number == data) {
			PhoneNode* deletenumber = cursor->next;
			if (deletenumber->next != NULL) {
				cursor->next = deletenumber->next;
			}
			else {
				cursor->next = NULL;
			}
			free(deletenumber);
			return;
		}
		cursor = cursor->next;
	}
}

void deletegroup(char* data) {
	if (head == NULL) {
		return;
	}
	PhoneNode* cursor = head;
	if (cursor->group == data) {
		free(cursor);
		return;
	}
	while (cursor->next != NULL) {
		if (cursor->next->group == data) {
			PhoneNode* deletegroup = cursor->next;
			if (deletegroup->next != NULL) {
				cursor->next = deletegroup->next;
			}
			else {
				cursor->next = NULL;
			}
			free(deletegroup);
			return;
		}
		cursor = cursor->next;
	}
}
//번호가 일치하는 노드를 찾는 함수
//struct PhoneNode* findNode(struct PhoneNode* phonenode, char phone_number) {
//phone_number 대신 다른 값들을 비교하면 원하는 노드를 찾을 수 있다
//	if (phonenode == NULL) {
//		return NULL;
//	}
//	struct PhoneNode* cursor = phonenode->next;
//	while (cursor != NULL) {
//		if (cursor->phone_number == phone_number)
//			return cursor;
//		cursor = cursor->next;
//	}
//	return NULL;
//}

struct tempchar {//입력받은 정보들을 임시로 저장할 구조체
	char tname[20];
	char tphone_number[20];
	char tgroup[10];
	char tbirth[20];
	char temail[30];
};

void main() {
	FILE* fp;
	char str[2] = {0};
	int n = 1;
	phonetype = (PhoneType*)malloc(sizeof(PhoneType));
	phonetype->head = NULL;
	PhoneNode* temp = phonetype->head;

	PhoneNode* cur = phonetype->cursor;
	struct tempchar tempc;
	//파일로부터 data를 입력 받아 insert 함수를 이용하여 저장한다
	while (n){
		scanf("%s", *str);
		switch (*str)
		{
		case 'IP'://정보를 입력
			//insert 함수를 이용하여 노드에 정보 저장
			printf("정보를 입력하세요\n");
			scanf("%s %s %s %s %s", tempc.tname, tempc.tphone_number, 
				tempc.tgroup, tempc.tbirth, tempc.temail);
			//구조체 tempchar에 입력 받은 정보를 저장한다
			insert(tempc.tname, tempc.tphone_number, tempc.tgroup, 
				tempc.tphone_number, tempc.temail);
			//입력 받은 정보를 노드에 입력한다
			printf("해당 정보가 insert 되었습니다\n");
			break;
		case 'PA'://입력된 모든 정보를 출력하고 파일에 저장
			//파일을 열고 노드의 정보들을 입력 후 저장
			fp = fopen("samplein.txt", "w");
			while (temp) {
				printf("%s %s %s %s %s\n", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				//노드에 저장된 정보들을 출력한다
				fprintf(fp, "%s %s %s %s %s", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				//노드에 저장된 정보들을 파일에 저장한다
				temp = temp->next;
			}
			fclose(fp);
			break;
		case 'DP'://해당 번호의 정보를 삭제
			//해당 번호의 정보가 입력된 노드를 삭제 후 나머지 노드를 새로 파일에 저장한다
			//해당 번호를 입력 받아 해당 번호를 가진 노드를 찾는다.
			printf("삭제할 번호를 입력하세요:");
			scanf("%s", tempc.tphone_number);
			while (temp) {
				if (temp->phone_number == tempc.tphone_number) {
					deletenumber(tempc.tphone_number);
					temp = temp->next;
				}
				else {
					temp = temp->next;
				}
			}
			//해당 번호를 가진 노드를 삭제한다
			//나머지 노드를 파일에 저장한다
			fp = fopen("samplein.txt", "w");
			while (temp) {
				fprintf(fp, "%s %s %s %s %s", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				temp = temp->next;
			}
			fclose(fp);
			printf("번호가 삭제되었습니다.\n");
			break;
		case 'DG'://해당 그룹의 정보를 삭제
			//해당 그룹의 정보가 입력된 노드를 삭제 후 나머지 노드를 새로 파일에 저장한다
			//해당 그룹을 입력 받아 해당 그룹에 속한 노드를 찾아낸다
			//해당 그룹을 가진 노드들을 삭제한다
			printf("삭제할 그룹을 입력하세요:");
			scanf("%s", tempc.tgroup);
			while (temp) {
				if (temp->group == tempc.tgroup) {
					deletegroup(tempc.tgroup);
					temp = temp->next;
				}
				else {
					temp = temp->next;
				}
			}
			//나머지 노드들을 파일에 입력한다
			fp = fopen("samplein.txt", "w");
			while (temp) {
				fprintf(fp, "%s %s %s %s %s\n", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				temp = temp->next;
			}
			fclose(fp);
			break;
		case 'SN'://해당 이름의 정보를 출력
			//해당 이름의 정보가 입력된 노드를 찾는다
			printf("검색할 이름을 입력하세요:");
			scanf("%s", tempc.tname);
			while (temp) {
				if (temp->name == tempc.tname) {
					printf("%s %s %s %s %s\n", temp->name, temp->phone_number,
						temp->group, temp->birth, temp->email);
					temp = temp->next;
				}
				else {
					temp = temp->next;
				}
			}
			//해당 노드의 정보를 출력한다

			break;
		case 'SG'://해당 그룹의 정보를 출력
			//해당 그룹을 가진 노드들을 찾는다
			printf("검색할 그룹을 입력하세요:");
			scanf("%s", tempc.tgroup);
			//해당 노드들의 정보를 출력한다
			while (temp) {
				if (temp->group == tempc.tgroup) {
					printf("%s %s %s %s %s\n", temp->name, temp->phone_number,
						temp->group, temp->birth, temp->email);
					temp = temp->next;
				}
				else {
					temp = temp->next;
				}
			}
			break;
		case 'EX':
			n = 0;
			break;
		default:
			printf("잘못된 입력입니다\n");
			break;
		}
		
	}
//	phonetype = (PhoneType*)malloc(sizeof(PhoneType));
//	phonetype->head = NULL;
//	//파일로부터 data를 입력 받아 insert 함수를 이용하여 저장한다
//	insert("가렌", "01011111111", "데마시아", "19800101", "dking@gmail.com");
//	insert("다리우스", "01022222222", "녹서스", "19700202", "ngen@gmail.com");
//	insert("하이머딩거", "01088888888", "필트오버", "19500808", "pmadsc@gmail.com");
//
//	PhoneNode* temp = phonetype->head;
//	while (temp) {
//		printf("%s %s %s %s %s\n", temp->name, temp->phone_number,
//			temp->group, temp->birth, temp->email);
//		temp = temp->next;
//	}
//	PhoneNode node1;
//	PhoneNode node2;
//	PhoneNode node3;
//	insert(&node1, "가렌", "01011111111", "데마시아", "19800101", "dking@gmail.com");
//	insert(&node2, "다리우스", "01022222222", "녹서스", "19700202", "ngen@gmail.com");
//	insert(&node3, "하이머딩거", "01088888888", "필트오버", "19500808", "pmadsc@gmail.com");
//	printf("%s %s %s %s %s\n", node1.name, node1.phone_number,
//		node1.group, node1.birth, node1.email);
//	
//	node1.next = &node2;
//	printf("%s %s %s %s %s\n", node1.next->name, node1.next->phone_number,
//		node1.next->group, node1.next->birth, node1.next->email);
//	
//	node2.next = &node3;
//	printf("%s %s %s %s %s\n", node1.next->next->name, node1.next->next->phone_number, 
//		node1.next->next->group, node1.next->next->birth, node1.next->next->email);

}