#include "pch.h"
#include "../BSTIterator/TreeNode.h"
#include "../BSTIterator/BinSTree.h"

// author: �������� �����
// ������������ ������ ��������� ��� ��������� ������ ������

TreeNode<int>* createTree1() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* leftleaf, * rightleaf, * root;


    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    //�������� ��������� �� ���� ������ (��������� �� ����� � ������ ���� nullptr)
    leftleaf = new TreeNode<int>(10);

    //�������� ���� ������ � ����� ��������
    root = new TreeNode<int>(12, leftleaf, nullptr);

    // ��������� leftleaf ����������� �� ������ ��� ��������� ����
    leftleaf = root;
    rightleaf = new TreeNode<int>(24);

    //�������� ���� � ����� � ������ ��������
    root = new TreeNode<int>(22, leftleaf, rightleaf);
    rightleaf = root;
    leftleaf = new TreeNode<int>(4);

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(5, leftleaf, rightleaf);

    return root;
}

// ����������� ������
TreeNode<int>* createTree2() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* rightleaf, * root;


    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

    //�������� ��������� �� ���� ������ (��������� �� ����� � ������ ���� nullptr)
    rightleaf = new TreeNode<int>(33);

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(30, nullptr, rightleaf);

    // ��������� rightleaf ����������� �� ������ ��� ��������� ����
    rightleaf = root;

    //�������� ���� � ������ ��������
    root = new TreeNode<int>(19, nullptr, rightleaf);
    rightleaf = root;

    //�������� ���� ������ � ������ ��������
    root = new TreeNode<int>(10, nullptr, rightleaf);

    return root;
}

// ����������� �����
TreeNode<int>* createTree3() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* leftleaf, * root;


    //       60
    //       /  
    //      54   
    //      /   
    //     14      



    //�������� ����
    root = new TreeNode<int>(14);

    // ��������� rightleaf ����������� �� ������ ��� ��������� ����
    leftleaf = root;

    //�������� ���� � ����� ��������
    root = new TreeNode<int>(54, leftleaf, nullptr);
    leftleaf = root;

    //�������� ���� ������ � ����� ��������
    root = new TreeNode<int>(60, leftleaf, nullptr);

    return root;
}

// ����������� ������
TreeNode<int>* createTree4() {

    // �������� ��������� �� ���� ������ 
    TreeNode<int>* rightleaf, * leftleaf, * root;


    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5        

    rightleaf = new TreeNode<int>(3);
    leftleaf = new TreeNode<int>(1);


    root = new TreeNode<int>(2, leftleaf, rightleaf);

    leftleaf = new TreeNode<int>(5);
    rightleaf = new TreeNode<int>(7, leftleaf, nullptr);

    root = new TreeNode<int>(4, root, rightleaf);

    leftleaf = new TreeNode<int>(9);
    rightleaf = new TreeNode<int>(30);

    rightleaf = new TreeNode<int>(10, leftleaf, rightleaf);

    root = new TreeNode<int>(8, root, rightleaf);

    return root;
}

// ������������ ������ begin (���������� ������� ������)
TEST(TestBSTIterator, TestBegin) {

    // �������� ������
    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10
    TreeNode<int>* root1 = createTree1();
    BinSTree<int> tr1(root1);

    BinSTree<int>::BinSTreeIterator<int> it1 = tr1.begin();
    EXPECT_EQ(*it1, 4);


    // ����������� ������
    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33
    TreeNode<int>* root2 = createTree2();
    BinSTree<int> tr2(root2);

    BinSTree<int>::BinSTreeIterator<int> it2 = tr2.begin();
    EXPECT_EQ(*it2, 10);

    // ����������� �����
    //       60
    //       /  
    //      54   
    //      /   
    //     14 
    TreeNode<int>* root3 = createTree3();
    BinSTree<int> tr3(root3);

    BinSTree<int>::BinSTreeIterator<int> it3 = tr3.begin();
    EXPECT_EQ(*it3, 14);

    // ����������� ������
    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5 
    TreeNode<int>* root4 = createTree4();
    BinSTree<int> tr4(root4);

    BinSTree<int>::BinSTreeIterator<int> it4 = tr4.begin();
    EXPECT_EQ(*it4, 1);

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    BinSTree<int> tr5(root5);

    BinSTree<int>::BinSTreeIterator<int> it5 = tr5.begin();
    EXPECT_EQ(it5, BinSTree<int>::BinSTreeIterator<int>(nullptr));

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    BinSTree<int> tr6(root6);

    BinSTree<int>::BinSTreeIterator<int> it6 = tr6.begin();
    EXPECT_EQ(*it6, 2);
}

// ������������ ��������� * � ++
TEST(TestBSTIterator, TestData) {

    // �������� ������
    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10
    TreeNode<int>* root1 = createTree1();
    BinSTree<int> tr1(root1);

    std::vector<int> arr, arr1 = { 4 , 5, 10, 12, 22, 24 };

    for (BinSTree<int>::BinSTreeIterator<int> it1 = tr1.begin(); it1 != tr1.end(); ++it1) {
        arr.push_back(*it1);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();

    // ����������� ������
    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33
    TreeNode<int>* root2 = createTree2();
    BinSTree<int> tr2(root2);

    arr1 = { 10 , 19, 30, 33 };

    for (BinSTree<int>::BinSTreeIterator<int> it2 = tr2.begin(); it2 != tr2.end(); ++it2) {
        arr.push_back(*it2);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();

    // ����������� �����
    //       60
    //       /  
    //      54   
    //      /   
    //     14 
    TreeNode<int>* root3 = createTree3();
    BinSTree<int> tr3(root3);

    arr1 = { 14,54,60 };

    for (BinSTree<int>::BinSTreeIterator<int> it3 = tr3.begin(); it3 != tr3.end(); ++it3) {
        arr.push_back(*it3);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();

    // ����������� ������
    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5 
    TreeNode<int>* root4 = createTree4();
    BinSTree<int> tr4(root4);

    arr1 = { 1,2,3,4,5,7,8,9,10,30 };

    for (BinSTree<int>::BinSTreeIterator<int> it4 = tr4.begin(); it4 != tr3.end(); ++it4) {
        arr.push_back(*it4);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    BinSTree<int> tr5(root5);

    arr1 = {  };

    for (BinSTree<int>::BinSTreeIterator<int> it5 = tr5.begin(); it5 != tr5.end(); ++it5) {
        arr.push_back(*it5);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();


    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    BinSTree<int> tr6(root6);

    arr1 = { 2 };

    for (BinSTree<int>::BinSTreeIterator<int> it6 = tr6.begin(); it6 != tr6.end(); ++it6) {
        arr.push_back(*it6);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();

}

// ������������ ��������� == � !=
TEST(TestBSTIterator, TestEqual) {

    // �������� ������
    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10
    TreeNode<int>* root1 = createTree1();
    BinSTree<int> tr1(root1);

    BinSTree<int>::BinSTreeIterator<int> it1 = tr1.begin();
    BinSTree<int>::BinSTreeIterator<int> it2 = tr1.begin();
    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);

    // ����������� ������
    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33
    TreeNode<int>* root2 = createTree2();
    BinSTree<int> tr2(root2);

    it1 = tr2.begin();
    it2 = tr2.begin();
    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);

    // ����������� �����
    //       60
    //       /  
    //      54   
    //      /   
    //     14 
    TreeNode<int>* root3 = createTree3();
    BinSTree<int> tr3(root3);

    it1 = tr3.begin();
    it2 = tr3.begin();
    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);

    // ����������� ������
    //          8
    //       /    \
    //      4      10
    //    /   \    / \
    //   2     7   9   30
    //  / \    /       
    // 1   3  5 
    TreeNode<int>* root4 = createTree4();
    BinSTree<int> tr4(root4);

    it1 = tr4.begin();
    it2 = tr4.begin();
    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);

    // ������ ������
    TreeNode<int>* root5 = nullptr;
    BinSTree<int> tr5(root5);

    it1 = tr5.begin();
    it2 = tr5.begin();
    EXPECT_TRUE(it1 == it2);

    // ������ � ����� �����
    TreeNode<int>* root6 = new TreeNode<int>(2);
    BinSTree<int> tr6(root6);

    it1 = tr6.begin();
    it2 = tr6.begin();
    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);

}