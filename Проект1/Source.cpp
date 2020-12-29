#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double read_file_w(double weight[5]) {
	ifstream in("weight.txt");
	if (in.is_open())
	{

		//������� ������� �� �����
		for (int i = 0; i < 5; i++)
			in >> weight[i];

		cout << "\t";
		//������� �������
		for (int i = 0; i < 5; i++)
		{
			cout << weight[i] << "\t\t";
		}
		cout << endl << "   -------------------------------------------------------------------------------" << endl;
		in.close();//��� ����� ������� �����
		return *weight;
	}
	else
	{
		//���� �������� ����� ������ �� �������
		cout << "���� �� ��������.";
		return *weight;
	}
}

char read_file_r(int ranks[5][5], char hotels[5]) {
	ifstream in("ranks.txt");
	if (in.is_open())
	{

		//������� ������� �� �����
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				in >> ranks[i][j];
			}
		}
		
		//������� �������
		for (int i = 0; i < 5; i++) {
			cout << "\t";
			for (int j = 0; j < 5; j++) {
				cout << ranks[i][j] << "\t\t";
			}
			cout << "|\t" << hotels[i] << endl;
		}
		cout << endl << endl;
		in.close();//��� ����� ������� �����
		return **ranks;
	}
	else
	{
		//���� �������� ����� ������ �� �������
		cout << "���� �� ��������.";
		return **ranks;
	}
}

double multiplying(double weight[5], int ranks[5][5], double mult[5][5], char hotels[5]) {
	
	cout << endl << endl << "����������� ���� � ������, �� '�' - ����������� ��� ������� ���������:\n\n";
	for (int i = 0; i < 5; i++) {
		cout << hotels[i] << "\t | \t";
		for (int j = 0; j < 5; j++) {
			mult[i][j] = weight[j] * ranks[i][j];
			cout << mult[i][j] << "\t";
		}
		cout << endl;
	}
	cout <<"-----------------------------------------------------"<< endl;
	return **mult;
}

double param_max(double mult[5][5]) {
	double max[5] = { 0,0,0,0,0 };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (max[j] < mult[i][j]) {
				max[j] = mult[i][j];
			}
		}
	}

	cout << "E\t | \t";
	for (int i = 0; i < 5; i++) {
		cout << max[i] <<"\t" ;
	}
	cout << endl << endl;
	return 0;
}

double result(double mult[5][5], char hotels[5]) {
	double sum[5] = { 0,0,0,0,0 };
	double max=0;
	//int k = 0;

	cout << "\n\n���� '���' ��������i� ��� ������� ��'����:" << endl << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			sum[i] = sum[i] + mult[i][j];
		}
		cout << sum[i] << "\t";
	}
	cout << endl <<"-------------------------------------" << endl;

	for (int i = 0; i < 5; i++) {
		cout << hotels[i] << "\t";
	}

	cout << endl << endl;
	for (int i = 0; i < 5; i++) {
		if (max < sum[i]) {
			max = sum[i];
		}
	}

	cout << "\n����i���� ���� '���' ��������i� ��'���i� ��������� - " << max << endl << endl << endl;
	return 0;
}

void main() {
	setlocale(LC_ALL, "Ukrainian");
	double weight[5];
	int ranks[5][5];
	double mult[5][5];
	char hotels[5] = { 'A', '�' ,'�' , '�' , '�' };

	cout << "�����i��� �i� ���\t����\t\t�������i�\t�i��\t\t�-�� �����i�\n";

	read_file_w(weight);
	read_file_r(ranks, hotels);
	multiplying(weight, ranks, mult, hotels);
	param_max(mult);
	result(mult, hotels);

	system("pause");
	//system("pause");
}