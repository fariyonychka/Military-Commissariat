#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef MILITARYCOMMISSARIAT_H
#define MILITARYCOMMISSARIAT_H
#include <iostream>
#include <cstring> 
#include <memory>
#include <limits>

using namespace std;

// ���� ��� ������
class CAdress {
private:
    char* street;         // ������
    char* houseNumber;    // ����� �������

public:
    // ����������� �� �������������
    CAdress() : street(nullptr), houseNumber(nullptr) {}

    // ����������� � �����������
    CAdress(const char* inputStreet, const char* inputHouseNumber)
        : street(nullptr), houseNumber(nullptr) {
        allocateMemoryForStreet(strlen(inputStreet));
        strcpy(street, inputStreet);
        allocateMemoryForHouseNumber(strlen(inputHouseNumber));
        strcpy(houseNumber, inputHouseNumber);
    }

    // ������� �����������
    CAdress(const CAdress& other)
        : street(nullptr), houseNumber(nullptr) {
        allocateMemoryForStreet(strlen(other.street));
        strcpy(street, other.street);
        allocateMemoryForHouseNumber(strlen(other.houseNumber));
        strcpy(houseNumber, other.houseNumber);
    }

    // �������� ���������
    CAdress& operator=(const CAdress& other) {
        if (this == &other) {
            return *this;  // �������� �� �������������
        }

        // ������� ������ ��������
        allocateMemoryForStreet(strlen(other.street));
        strcpy(street, other.street);

        allocateMemoryForHouseNumber(strlen(other.houseNumber));
        strcpy(houseNumber, other.houseNumber);

        return *this;
    }

    // �������������� �����������
    CAdress(CAdress&& other) noexcept
        : street(other.street), houseNumber(other.houseNumber) {
        other.street = nullptr;
        other.houseNumber = nullptr;
    }

    // ����������
    ~CAdress() {
        delete[] street;
        delete[] houseNumber;
    }

    // ������ ��� �������� ���'��
    void allocateMemoryForStreet(size_t length) {
        delete[] street;  // ��������� ���������� ������� ���'���
        street = new char[length + 1];
    }

    void allocateMemoryForHouseNumber(size_t length) {
        delete[] houseNumber;  // ��������� ���������� ������� ���'���
        houseNumber = new char[length + 1];
    }

    // ������� �� �������
    void setStreet(char* inputStreet) {
        allocateMemoryForStreet(strlen(inputStreet));
        strcpy(street, inputStreet);
    }
    const char* getStreet() const { return street; }  

    void setHouseNumber( char* inputHouseNumber) {
        allocateMemoryForHouseNumber(strlen(inputHouseNumber));
        strcpy(houseNumber, inputHouseNumber);
    }
    const char* getHouseNumber() const { return houseNumber; }  
};

//���� ����������
class CMillitaryCommissariat {
private:
    char* name;
    CAdress adress;
    int numberOfEmployees;
    int numberOfAssigned;
    int costsPerEmployee;

public:
    // ����������� �� �������������
    CMillitaryCommissariat() : name(nullptr), numberOfAssigned(0), numberOfEmployees(0), costsPerEmployee(0) {}

    // ����������� � �����������
    CMillitaryCommissariat( char* inputName,  char* inputStreet,  char* inputHouseNumber, int _numberOfEmployees, int _numberOfAssigned, int _costsPerEmployee)
        : name(nullptr), numberOfAssigned(_numberOfAssigned), numberOfEmployees(_numberOfEmployees), costsPerEmployee(_costsPerEmployee) {
        allocateMemoryForName(strlen(inputName));
        strcpy(name, inputName);
        adress.setStreet(inputStreet);
        adress.setHouseNumber(inputHouseNumber);
    }

    CMillitaryCommissariat(const CMillitaryCommissariat& other)
        : name(nullptr), numberOfEmployees(other.numberOfEmployees), numberOfAssigned(other.numberOfAssigned), costsPerEmployee(other.costsPerEmployee) {
        allocateMemoryForName(strlen(other.name));
        strcpy(name, other.name);
        adress = other.adress;  
    }

    // �������� ���������
    CMillitaryCommissariat& operator=(const CMillitaryCommissariat& other) {
        if (this == &other) {
            return *this;  // �������� �� �������������
        }

        // ������� ������ ��������
        numberOfEmployees = other.numberOfEmployees;
        numberOfAssigned = other.numberOfAssigned;
        costsPerEmployee = other.costsPerEmployee;

        // ������� ��'�
        allocateMemoryForName(strlen(other.name));
        strcpy(name, other.name);

        // ������� ������
        adress = other.adress;

        return *this;
    }

    // �������������� �����������
    CMillitaryCommissariat(CMillitaryCommissariat&& other) noexcept
        : name(other.name), adress(std::move(other.adress)), numberOfEmployees(other.numberOfEmployees),
        numberOfAssigned(other.numberOfAssigned), costsPerEmployee(other.costsPerEmployee) {
        other.name = nullptr;
        other.numberOfEmployees = 0;
        other.numberOfAssigned = 0;
        other.costsPerEmployee = 0;
    }

    // ����������
    ~CMillitaryCommissariat() {
        delete[] name;
    }

    // ��������� �����/������
    friend istream& operator>>(istream& in, CMillitaryCommissariat& commissariat);
    friend ostream& operator<<(ostream& out, const CMillitaryCommissariat& commissariat);

    // ������ ��� �������� ���'��
    void allocateMemoryForName(size_t length) {
        delete[] name;
        name = new char[length + 1];
    }

    // ������� �� �������
    void setName(const char* inputName) {
        allocateMemoryForName(strlen(inputName));
        strcpy(name, inputName);
    }
    char* getName() { return name; }

    void setAdress(const CAdress& inputAdress) {
        adress = inputAdress;
    }
    const CAdress& getAdress() const { return adress; }  // ������ ��� ������
    CAdress& setAdress()  { return adress; }

    void setNumberOfEmployees(int a) { numberOfEmployees = a; }
    int getNumberOfEmployees() { return numberOfEmployees; }

    void setNumberOfAssigned(int a) { numberOfAssigned = a; }
    int getNumberOfAssigned() { return numberOfAssigned; }

    void setCostsPerEmployee(int a) { costsPerEmployee = a; }
    int getCostsPerEmployee() { return costsPerEmployee; }
};

// �������� >> ��� �����
istream& operator>>(istream& in, CMillitaryCommissariat& commissariat) {
    char buffer[256]; // ���������� ����� ��� ���������� �����
    in.getline(buffer, 256);
    commissariat.allocateMemoryForName(strlen(buffer));
    strcpy(commissariat.name, buffer);

    memset(buffer, 0, sizeof(buffer));
    in.getline(buffer, 256); // ������� ������
    commissariat.adress.setStreet(buffer);

    memset(buffer, 0, sizeof(buffer));
    in.getline(buffer, 256); // ������� ����� �������
    commissariat.adress.setHouseNumber(buffer);

    in >> commissariat.numberOfEmployees;
    in >> commissariat.numberOfAssigned;
    in >> commissariat.costsPerEmployee;

    in.ignore(10000, '\n');
    return in;
}

// �������� << ��� ������
ostream& operator<<(ostream& out, const CMillitaryCommissariat& commissariat) {
    out << "�����: " << commissariat.name << endl;
    out << "������: " << commissariat.adress.getStreet() << endl;
    out << "����� �������: " << commissariat.adress.getHouseNumber() << endl;
    out << "ʳ������ ����������: " << commissariat.numberOfEmployees << endl;
    out << "ʳ������ ����������: " << commissariat.numberOfAssigned << endl;
    out << "������� �� ����������: " << commissariat.costsPerEmployee << endl;
    return out;
}

//������� ����������� ������� ������
double DefineAvarageCost(vector<CMillitaryCommissariat>& array)
{
    double sum = 0;
    int size = array.size();  // �������� ����� �������
    for (int i = 0; i < size; i++)
    {
        sum += array[i].getCostsPerEmployee();
    }
    return (size > 0) ? (sum / size) : 0;  // �������� �� �������� �����
}


// ������� ��� ������ ���� ������ �������
void merge(vector<CMillitaryCommissariat>& commissariats, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<CMillitaryCommissariat> leftVec(n1), rightVec(n2);

    for (int i = 0; i < n1; ++i)
        leftVec[i] = commissariats[left + i];
    for (int i = 0; i < n2; ++i)
        rightVec[i] = commissariats[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftVec[i].getNumberOfEmployees() <= rightVec[j].getNumberOfEmployees()) {
            commissariats[k++] = leftVec[i++];
        }
        else {
            commissariats[k++] = rightVec[j++];
        }
    }

    while (i < n1) {
        commissariats[k++] = leftVec[i++];
    }

    while (j < n2) {
        commissariats[k++] = rightVec[j++];
    }
}

// ��������� ���������� �������
void mergeSort(vector<CMillitaryCommissariat>& commissariats, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(commissariats, left, mid);
        mergeSort(commissariats, mid + 1, right);
        merge(commissariats, left, mid, right);
    }
}

//������� ���������� �����������, � ���� ���������� ����� 50% �� ������� ����������.
void getLessAssignThanEmpl(vector<CMillitaryCommissariat>& commissariats, vector<char*>& true_comm)
{
    for (auto it = commissariats.begin(); it != commissariats.end(); ++it) {

        if (it->getNumberOfAssigned() / 2 > it->getNumberOfEmployees())
        {
            true_comm.push_back(it->getName());
        }
    }
}

//������� ���������� �����������, � ���� ������� �� ���������� ����� �� ������ �� ��� ������������
void getMoreCostsPerEmplCommissar(vector<CMillitaryCommissariat>& commissariats, vector<char*>& true_comm) {
    double average = DefineAvarageCost(commissariats);
    for (auto it = commissariats.begin(); it != commissariats.end(); ++it) {

        if (it->getCostsPerEmployee() > average)
        {
            true_comm.push_back(it->getName());
        }
    }
}

//������� ���������� 4 �����������, � ���� ������� ����������  ����� ��������, ����� ������� �� ���������� ����� ������
void getMoreAssigAndLessCosts(vector<CMillitaryCommissariat>& commissariats, vector<char*>& true_comm) {
    int sum = 0;
    for (int i = 0; i < commissariats.size(); i++)
    {
        sum += commissariats[i].getNumberOfAssigned();
    }
    sum = sum / commissariats.size();  // �������� �� �������� �����
    double average = DefineAvarageCost(commissariats);
    for (auto it = commissariats.begin(); it != commissariats.end(); ++it) {

        if (it->getNumberOfAssigned() > sum && it->getCostsPerEmployee() < average && true_comm.size() < 4)
        {
            true_comm.push_back(it->getName());
        }
    }


}

//������� ���������� ���� ��������� ������ �� ��� ������������, �������� ������� ���������� �� �������� ������� ����������
void getGeneralInfo(vector<CMillitaryCommissariat>& commissariats, int* allcosts, int* allemployers, int* allassignment)
{
    for (auto it = commissariats.begin(); it != commissariats.end(); ++it) {
        (*allcosts) += it->getCostsPerEmployee();
        (*allassignment) += it->getNumberOfAssigned();
        (*allemployers) += it->getNumberOfEmployees();
    }
}


#endif // !MILITARYCOMMISSARIAT_H

