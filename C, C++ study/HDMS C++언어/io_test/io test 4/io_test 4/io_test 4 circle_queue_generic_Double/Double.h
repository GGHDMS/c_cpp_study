#pragma once
#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>

void doubleMemcpy(void *p1, void *p2); // p2�� ����Ű�� double������ p1�� ����Ű�� ������ ����
void doubleClear(void *p); //�ΰ� �޸� ������
void doublePrint(void *p); //doulb �� ����� ��
int doubleCompare(void *p1, void *p2); // �� ���Ͽ� p1�� ����Ű�� ���� ũ�� 1 ������ 0 ������ -1

