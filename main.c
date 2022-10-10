#include <stdio.h>
#include <string.h>

int main1() {

    //面试题
    //数组名表示 首元素地址  除了sizeof(a)和&a 此时表示整个数组

    //一维数组
    int a[] = {1, 2, 3, 4};
    printf("%p\n",a);
    printf("%p\n",&a);
    printf("%d \n", sizeof(a));    //16
    printf("%d \n", sizeof(a + 0));  //4/8  首元素地址
    printf("%d \n", sizeof(*a));   //4  首元素地址解引用为首元素 Int
    printf("%d \n", sizeof(a + 1));  //4/8  第二个元素地址
    printf("%d \n", sizeof(a[1])); //4
    printf("%d \n", sizeof(&a));   //&a 是一个指针 4/8
    printf("%d \n", sizeof(*&a)); //16 整个数组 相当于a
    printf("%d \n", sizeof(&a + 1));  //&a+1跳过整个数组 但还是整个数组 4/8
    printf("%d \n", sizeof(&a[0]));//4/8 第一个元素地址
    printf("%d \n", sizeof(&a[0] + 1)); //4/8  第二个元素地址


    printf("\n\n\n\n");

    //字符数组
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%d \n", sizeof(arr));      //6
    //地址的大小是不分类型的 4/8   arr+0还是首元素地址
    printf("%d \n", sizeof(arr + 0));    //4/8 首元素地址
    printf("%d \n", sizeof(*arr));  //1  *arr 首元素
    printf("%d \n", sizeof(arr[1])); //1
    printf("%d \n", sizeof(&arr)); //4/8 整个数组的地址
    printf("%d \n", sizeof(&arr + 1)); //4/8
    printf("%d \n", sizeof(&arr[0] + 1)); //4/8 第二个元素地址
    printf("\n\n\n---------------\n");


    //strlen(); 数组长度 \0之前
    printf("%d \n", strlen(arr));      //随机值
    printf("%d \n", strlen(arr + 0));   //随机值
    printf("%d \n", strlen(*arr)); //'a' -97 非法访问
    printf("%d \n", strlen(arr[1])); //strlen('b') 非法访问
    printf("%d \n", strlen(&arr)); //随机值
    printf("%d \n", strlen(&arr + 1));//随机值-6（跳过整个数组）
    printf("%d \n", strlen(&arr[0] + 1)); // 随机-1 (第二个元素开始)

    return 0;
}

int main2() {
    char arr[] = "abcdef";
    printf("%d \n", sizeof(arr)); //7个
    printf("%d \n", sizeof(arr + 0)); //首元素地址+0   4/8
    printf("%d \n", sizeof(*arr)); //'a' = 1
    printf("%d \n", sizeof(arr[1]));//1
    printf("%d \n", sizeof(&arr)); //整个数组的地址 4/8
    printf("%d \n", sizeof(&arr + 1)); // 跳过当前数组的地址  4/8
    printf("%d \n", sizeof(&arr[0] + 1));// 第二个元素地址  4/8
}

int main3() {
    char arr[] = "abcdef";
    printf("%d \n", strlen(arr));     //6
    printf("%d \n", strlen(arr + 0));   //6
//    printf("%d \n",strlen(*arr));  //'a' 非法
//    printf("%d \n",strlen(arr[1])); //'b' = 98  非法
    printf("%d \n", strlen(&arr)); //整个数组 6
    printf("%d \n", strlen(&arr + 1)); // 随机值
    printf("%d \n", strlen(&arr[0] + 1)); //第二个元素开始 5
}

int main4() {
    char *p = "abcdef";  //将a的地址
    printf("%d \n", sizeof(p));  //地址 4/8
    printf("%d \n", sizeof(p + 1));  // b的指针 4/8
    printf("%d \n", sizeof(*p));  //sizeof('a')= 1
    //arr[0] == *(arr+0)
    printf("%d \n", sizeof(p[0]));//1
    printf("%d \n", sizeof(&p)); //4/8
    printf("%d \n", sizeof(&p + 1)); //跳过当前数组 的地址 4/8
    printf("%d \n", sizeof(&p[0] + 1));  //4/8  b

    printf("\n-----------------------\n");

    printf("%d \n", strlen(p)); //6
    printf("%d \n", strlen(p + 1)); //5
//    printf("%d \n", strlen(*p));//'a'  err
//    printf("%d \n", strlen(p[0]));//'a' err
    printf("%d \n", strlen(&p));//随机值
    printf("%d \n", strlen(&p + 1));//随机值(跳过当前数组)
    printf("%d \n", strlen(&p[0] + 1)); //5
}
int main5()
{
    int a[3][4] = {0};
    printf("%d\n",sizeof(a)); //16*3 = 48
    printf("%d\n",sizeof(a[0][0])); //4
    printf("%d\n",sizeof(a[0])); //16 第一行一维数组的数组名

    //a[0] 第一行的数组名，数组名就是首元素的地址，其实就是第一行第一个元素的地址
    printf("%d\n",sizeof(a[0]+1)); //首元素地址啊a[0][0]+1 相当于a[0][1]的地址  4/8

    printf("%d\n",sizeof(*(a[0]+1))); //a[0][1]地址的解引用 = int 4个字节

    //a是二维数组的数组名，a是首元素地址 即a[0]+1=a[1] 就是二维数组第二行的地址
    printf("%d\n",sizeof(a+1)); //首元素地址a[0]+1 = a[1]的地址 地址都是4/8
    printf("%d\n",sizeof(*(a+1))); //a[2]解引用  = 16


    printf("%d\n",sizeof( &a[0]+1) );//地址+1 = a[1]的地址 4/8
    printf("%d\n",sizeof( *(&a[0]+1)) ); //16
    printf("%d\n",sizeof( *a )); //首元素地址a[0] 16
    printf("%d\n",sizeof( a[3])); //16


}
//指针笔试题
int main6()

{
    int a[5] = {1,2,3,4,5};
    int* ptr =(int*)(&a+1); //&a是整个数组的地址+1 跳过当前数组 = 6

    printf("%d,%d",*(a+1),*(ptr-1)); //2    5
    return 0;
}
struct Test
{
    int num;
    char* pcName;
    short sDate;
    char cha[2];
    short sBa[4];
}*p; //结构体指针 p
int main7()
{
    //假设Test类型的变量大小为20个字节，p的值为0x100000，求下列表达式？
    p = (struct Test*)0x100000;

    //结构体+1 跳过一个结构体
    printf("%p\n",p+0x1); //0x100014  16进制表示

    //100000 = 1048576二级制 +1 == 101048577
    //0x100000 +1 = 0x100001
    printf("%p\n",(unsigned long)p+0x1); //0x100001

//    1048576 + 4  = 0x100004 跳过一个int* 4/8个字节
    printf("%p\n",(unsigned int*)p+0x1); //0x100004

    return 0;
}
int main8()
{
    int a[4] = {1,2,3,4};
    int* ptr1 = (int*)(&a+1);  //跳过整个数组
    int* ptr2 = (int*)((int)a+1);  //+1跳过4个字节，00020000


    //ptr1[-1] == *(ptr1+(-1)) 指向最后一个位置-1 就是最后一个
    printf("%x，%x",ptr1[-1],*ptr2); //解引用 4个字节00020000


    return 0;


}
int main9()
{
    //逗号表达式：之执行结果为最后一个  1
    int a[3][2] = {(0,1),(2,3),(4,5)};
    int* p;
    p = a[0]; //第一行元素 1

    printf("%d",p[0]); //1
    return 0;
}
int main10()
{
    int a[5][5];
    int (*p)[4]; //数组指针
    p = a; //数组名 首元素地址
    //fffffffffffffffc,-4


    //p[4][2] == *(p[4] + 2) == *(*(p+4)+2)
    //(p+4)跳过4个整形地址    *(p+4)+2跳过两个字节

    //指针-指针 得到的是指针之间的元素个数 小-大 是负数 -4
    printf("%p,%d\n",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);

    return 0;
}
int main11()
{
    int aa[2][5] = {1,2,3,4,5,6,7,8,9,10};
    int * ptr1 = (int* )(&aa+1);  //&数组名是整个数组  ptr最后一个元素后面的地址
    int * ptr2 = (int*)(*(aa+1)); //aa+1 == a[0]+1 首元素地址+1    a[1][0]的地址

    //ptr-1数组最后一个元素的地址
    //ptr2-1 就是a[0][4]的地址
    printf("%d,%d",*(ptr1-1),*(ptr2-1)); //10   5
    return 0;
}
int main12()
{
    //"w" "a" "a"
    char* a[] = {"work","at","alibaba"}; //字符指针 存储的是
    char** pa = a;  //首元素地址 a[0]

    pa++; //a++    a[1]
    printf("%s",*pa); //at
    return 0;

}
int main()
{
    char* c[] = {"ENTER","NEW","POINT","FIRST"};
    char** cp[] = {c+3,c+2,c+1,c};   //c是首元素地址

    char*** cpp = cp;

    printf("%s\n",**++cpp); //point
    printf("%s\n",*--*++cpp+3); //er
    printf("%s\n",*cpp[-2]+3); //st
    printf("%s\n",cpp[-1][-1]+1);//ew

    return 0;



}


