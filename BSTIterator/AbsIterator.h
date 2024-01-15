#pragma once
//author: �������� �������

template <typename T>
// ����������� ����� ���������
class AbsIterator
{
public:
    // �������� �������� �� ��������� �������
    virtual AbsIterator<T>& operator++() = 0;
    //virtual void operator++(int) const {};
    // �������� ��������� ������ �� ��������
    virtual T operator*() const = 0;
    // ��������� ���������
    virtual bool operator==(const AbsIterator& o) const = 0;
    virtual bool operator!=(const AbsIterator& o) const = 0;

};
