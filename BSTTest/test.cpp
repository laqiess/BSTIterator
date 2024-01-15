#include "pch.h"
#include "../BSTIterator/TreeNode.h"
#include "../BSTIterator/BinSTree.h"

// author: Ключерев Артем
// тестирование класса итератора для бинарного дерева поиска

TreeNode<int>* createTree1() {

    // создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * rightleaf, * root;


    //       5
    //      / \
    //     4   22
    //        / \
    //       12  24
    //      /
    //     10

    //создаётся указатель на лист дерева (указатели на левый и правый узлы nullptr)
    leftleaf = new TreeNode<int>(10);

    //создаётся узел только с левым потомком
    root = new TreeNode<int>(12, leftleaf, nullptr);

    // указатель leftleaf переносится на только что созданный узел
    leftleaf = root;
    rightleaf = new TreeNode<int>(24);

    //создаётся узел с левым и правым потомком
    root = new TreeNode<int>(22, leftleaf, rightleaf);
    rightleaf = root;
    leftleaf = new TreeNode<int>(4);

    //создаётся узел только с правым потомком
    root = new TreeNode<int>(5, leftleaf, rightleaf);

    return root;
}

// вырожденное вправо
TreeNode<int>* createTree2() {

    // создаётся указатели на узлы дерева 
    TreeNode<int>* rightleaf, * root;


    //       10
    //        \
    //         19
    //          \
    //           30
    //            \
    //             33

    //создаётся указатель на лист дерева (указатели на левый и правый узлы nullptr)
    rightleaf = new TreeNode<int>(33);

    //создаётся узел только с правым потомком
    root = new TreeNode<int>(30, nullptr, rightleaf);

    // указатель rightleaf переносится на только что созданный узел
    rightleaf = root;

    //создаётся узел с правым потомком
    root = new TreeNode<int>(19, nullptr, rightleaf);
    rightleaf = root;

    //создаётся узел только с правым потомком
    root = new TreeNode<int>(10, nullptr, rightleaf);

    return root;
}

// вырожденное влево
TreeNode<int>* createTree3() {

    // создаётся указатели на узлы дерева 
    TreeNode<int>* leftleaf, * root;


    //       60
    //       /  
    //      54   
    //      /   
    //     14      



    //создаётся узел
    root = new TreeNode<int>(14);

    // указатель rightleaf переносится на только что созданный узел
    leftleaf = root;

    //создаётся узел с левым потомком
    root = new TreeNode<int>(54, leftleaf, nullptr);
    leftleaf = root;

    //создаётся узел только с левым потомком
    root = new TreeNode<int>(60, leftleaf, nullptr);

    return root;
}

// законченное дерево
TreeNode<int>* createTree4() {

    // создаётся указатели на узлы дерева 
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

// тестирование метода begin (наименьший элемент дерева)
TEST(TestBSTIterator, TestBegin) {

    // создаётся дерево
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


    // вырожденное вправо
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

    // вырожденное влево
    //       60
    //       /  
    //      54   
    //      /   
    //     14 
    TreeNode<int>* root3 = createTree3();
    BinSTree<int> tr3(root3);

    BinSTree<int>::BinSTreeIterator<int> it3 = tr3.begin();
    EXPECT_EQ(*it3, 14);

    // завершённое дерево
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

    // пустое дерево
    TreeNode<int>* root5 = nullptr;
    BinSTree<int> tr5(root5);

    BinSTree<int>::BinSTreeIterator<int> it5 = tr5.begin();
    EXPECT_EQ(it5, BinSTree<int>::BinSTreeIterator<int>(nullptr));

    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    BinSTree<int> tr6(root6);

    BinSTree<int>::BinSTreeIterator<int> it6 = tr6.begin();
    EXPECT_EQ(*it6, 2);
}

// тестирование оператора * и ++
TEST(TestBSTIterator, TestData) {

    // создаётся дерево
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

    // вырожденное вправо
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

    // вырожденное влево
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

    // завершённое дерево
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

    // пустое дерево
    TreeNode<int>* root5 = nullptr;
    BinSTree<int> tr5(root5);

    arr1 = {  };

    for (BinSTree<int>::BinSTreeIterator<int> it5 = tr5.begin(); it5 != tr5.end(); ++it5) {
        arr.push_back(*it5);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();


    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    BinSTree<int> tr6(root6);

    arr1 = { 2 };

    for (BinSTree<int>::BinSTreeIterator<int> it6 = tr6.begin(); it6 != tr6.end(); ++it6) {
        arr.push_back(*it6);
    }
    EXPECT_EQ(arr, arr1);
    arr.clear(); arr1.clear();

}

// тестирование оператора == и !=
TEST(TestBSTIterator, TestEqual) {

    // создаётся дерево
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

    // вырожденное вправо
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

    // вырожденное влево
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

    // завершённое дерево
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

    // пустое дерево
    TreeNode<int>* root5 = nullptr;
    BinSTree<int> tr5(root5);

    it1 = tr5.begin();
    it2 = tr5.begin();
    EXPECT_TRUE(it1 == it2);

    // дерево с одним узлом
    TreeNode<int>* root6 = new TreeNode<int>(2);
    BinSTree<int> tr6(root6);

    it1 = tr6.begin();
    it2 = tr6.begin();
    EXPECT_TRUE(it1 == it2);
    ++it1;
    EXPECT_TRUE(it1 != it2);

}