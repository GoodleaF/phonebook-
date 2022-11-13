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
//��ȣ�� ��ġ�ϴ� ��带 ã�� �Լ�
//struct PhoneNode* findNode(struct PhoneNode* phonenode, char phone_number) {
//phone_number ��� �ٸ� ������ ���ϸ� ���ϴ� ��带 ã�� �� �ִ�
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

struct tempchar {//�Է¹��� �������� �ӽ÷� ������ ����ü
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
	//���Ϸκ��� data�� �Է� �޾� insert �Լ��� �̿��Ͽ� �����Ѵ�
	while (n){
		scanf("%s", *str);
		switch (*str)
		{
		case 'IP'://������ �Է�
			//insert �Լ��� �̿��Ͽ� ��忡 ���� ����
			printf("������ �Է��ϼ���\n");
			scanf("%s %s %s %s %s", tempc.tname, tempc.tphone_number, 
				tempc.tgroup, tempc.tbirth, tempc.temail);
			//����ü tempchar�� �Է� ���� ������ �����Ѵ�
			insert(tempc.tname, tempc.tphone_number, tempc.tgroup, 
				tempc.tphone_number, tempc.temail);
			//�Է� ���� ������ ��忡 �Է��Ѵ�
			printf("�ش� ������ insert �Ǿ����ϴ�\n");
			break;
		case 'PA'://�Էµ� ��� ������ ����ϰ� ���Ͽ� ����
			//������ ���� ����� �������� �Է� �� ����
			fp = fopen("samplein.txt", "w");
			while (temp) {
				printf("%s %s %s %s %s\n", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				//��忡 ����� �������� ����Ѵ�
				fprintf(fp, "%s %s %s %s %s", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				//��忡 ����� �������� ���Ͽ� �����Ѵ�
				temp = temp->next;
			}
			fclose(fp);
			break;
		case 'DP'://�ش� ��ȣ�� ������ ����
			//�ش� ��ȣ�� ������ �Էµ� ��带 ���� �� ������ ��带 ���� ���Ͽ� �����Ѵ�
			//�ش� ��ȣ�� �Է� �޾� �ش� ��ȣ�� ���� ��带 ã�´�.
			printf("������ ��ȣ�� �Է��ϼ���:");
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
			//�ش� ��ȣ�� ���� ��带 �����Ѵ�
			//������ ��带 ���Ͽ� �����Ѵ�
			fp = fopen("samplein.txt", "w");
			while (temp) {
				fprintf(fp, "%s %s %s %s %s", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				temp = temp->next;
			}
			fclose(fp);
			printf("��ȣ�� �����Ǿ����ϴ�.\n");
			break;
		case 'DG'://�ش� �׷��� ������ ����
			//�ش� �׷��� ������ �Էµ� ��带 ���� �� ������ ��带 ���� ���Ͽ� �����Ѵ�
			//�ش� �׷��� �Է� �޾� �ش� �׷쿡 ���� ��带 ã�Ƴ���
			//�ش� �׷��� ���� ������ �����Ѵ�
			printf("������ �׷��� �Է��ϼ���:");
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
			//������ ������ ���Ͽ� �Է��Ѵ�
			fp = fopen("samplein.txt", "w");
			while (temp) {
				fprintf(fp, "%s %s %s %s %s\n", temp->name, temp->phone_number,
					temp->group, temp->birth, temp->email);
				temp = temp->next;
			}
			fclose(fp);
			break;
		case 'SN'://�ش� �̸��� ������ ���
			//�ش� �̸��� ������ �Էµ� ��带 ã�´�
			printf("�˻��� �̸��� �Է��ϼ���:");
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
			//�ش� ����� ������ ����Ѵ�

			break;
		case 'SG'://�ش� �׷��� ������ ���
			//�ش� �׷��� ���� ������ ã�´�
			printf("�˻��� �׷��� �Է��ϼ���:");
			scanf("%s", tempc.tgroup);
			//�ش� ������ ������ ����Ѵ�
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
			printf("�߸��� �Է��Դϴ�\n");
			break;
		}
		
	}
//	phonetype = (PhoneType*)malloc(sizeof(PhoneType));
//	phonetype->head = NULL;
//	//���Ϸκ��� data�� �Է� �޾� insert �Լ��� �̿��Ͽ� �����Ѵ�
//	insert("����", "01011111111", "�����þ�", "19800101", "dking@gmail.com");
//	insert("�ٸ��콺", "01022222222", "�켭��", "19700202", "ngen@gmail.com");
//	insert("���̸ӵ���", "01088888888", "��Ʈ����", "19500808", "pmadsc@gmail.com");
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
//	insert(&node1, "����", "01011111111", "�����þ�", "19800101", "dking@gmail.com");
//	insert(&node2, "�ٸ��콺", "01022222222", "�켭��", "19700202", "ngen@gmail.com");
//	insert(&node3, "���̸ӵ���", "01088888888", "��Ʈ����", "19500808", "pmadsc@gmail.com");
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