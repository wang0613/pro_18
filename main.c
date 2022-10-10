#include <stdio.h>
#include <string.h>

int main1() {

    //������
    //��������ʾ ��Ԫ�ص�ַ  ����sizeof(a)��&a ��ʱ��ʾ��������

    //һά����
    int a[] = {1, 2, 3, 4};
    printf("%p\n",a);
    printf("%p\n",&a);
    printf("%d \n", sizeof(a));    //16
    printf("%d \n", sizeof(a + 0));  //4/8  ��Ԫ�ص�ַ
    printf("%d \n", sizeof(*a));   //4  ��Ԫ�ص�ַ������Ϊ��Ԫ�� Int
    printf("%d \n", sizeof(a + 1));  //4/8  �ڶ���Ԫ�ص�ַ
    printf("%d \n", sizeof(a[1])); //4
    printf("%d \n", sizeof(&a));   //&a ��һ��ָ�� 4/8
    printf("%d \n", sizeof(*&a)); //16 �������� �൱��a
    printf("%d \n", sizeof(&a + 1));  //&a+1������������ �������������� 4/8
    printf("%d \n", sizeof(&a[0]));//4/8 ��һ��Ԫ�ص�ַ
    printf("%d \n", sizeof(&a[0] + 1)); //4/8  �ڶ���Ԫ�ص�ַ


    printf("\n\n\n\n");

    //�ַ�����
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%d \n", sizeof(arr));      //6
    //��ַ�Ĵ�С�ǲ������͵� 4/8   arr+0������Ԫ�ص�ַ
    printf("%d \n", sizeof(arr + 0));    //4/8 ��Ԫ�ص�ַ
    printf("%d \n", sizeof(*arr));  //1  *arr ��Ԫ��
    printf("%d \n", sizeof(arr[1])); //1
    printf("%d \n", sizeof(&arr)); //4/8 ��������ĵ�ַ
    printf("%d \n", sizeof(&arr + 1)); //4/8
    printf("%d \n", sizeof(&arr[0] + 1)); //4/8 �ڶ���Ԫ�ص�ַ
    printf("\n\n\n---------------\n");


    //strlen(); ���鳤�� \0֮ǰ
    printf("%d \n", strlen(arr));      //���ֵ
    printf("%d \n", strlen(arr + 0));   //���ֵ
    printf("%d \n", strlen(*arr)); //'a' -97 �Ƿ�����
    printf("%d \n", strlen(arr[1])); //strlen('b') �Ƿ�����
    printf("%d \n", strlen(&arr)); //���ֵ
    printf("%d \n", strlen(&arr + 1));//���ֵ-6�������������飩
    printf("%d \n", strlen(&arr[0] + 1)); // ���-1 (�ڶ���Ԫ�ؿ�ʼ)

    return 0;
}

int main2() {
    char arr[] = "abcdef";
    printf("%d \n", sizeof(arr)); //7��
    printf("%d \n", sizeof(arr + 0)); //��Ԫ�ص�ַ+0   4/8
    printf("%d \n", sizeof(*arr)); //'a' = 1
    printf("%d \n", sizeof(arr[1]));//1
    printf("%d \n", sizeof(&arr)); //��������ĵ�ַ 4/8
    printf("%d \n", sizeof(&arr + 1)); // ������ǰ����ĵ�ַ  4/8
    printf("%d \n", sizeof(&arr[0] + 1));// �ڶ���Ԫ�ص�ַ  4/8
}

int main3() {
    char arr[] = "abcdef";
    printf("%d \n", strlen(arr));     //6
    printf("%d \n", strlen(arr + 0));   //6
//    printf("%d \n",strlen(*arr));  //'a' �Ƿ�
//    printf("%d \n",strlen(arr[1])); //'b' = 98  �Ƿ�
    printf("%d \n", strlen(&arr)); //�������� 6
    printf("%d \n", strlen(&arr + 1)); // ���ֵ
    printf("%d \n", strlen(&arr[0] + 1)); //�ڶ���Ԫ�ؿ�ʼ 5
}

int main4() {
    char *p = "abcdef";  //��a�ĵ�ַ
    printf("%d \n", sizeof(p));  //��ַ 4/8
    printf("%d \n", sizeof(p + 1));  // b��ָ�� 4/8
    printf("%d \n", sizeof(*p));  //sizeof('a')= 1
    //arr[0] == *(arr+0)
    printf("%d \n", sizeof(p[0]));//1
    printf("%d \n", sizeof(&p)); //4/8
    printf("%d \n", sizeof(&p + 1)); //������ǰ���� �ĵ�ַ 4/8
    printf("%d \n", sizeof(&p[0] + 1));  //4/8  b

    printf("\n-----------------------\n");

    printf("%d \n", strlen(p)); //6
    printf("%d \n", strlen(p + 1)); //5
//    printf("%d \n", strlen(*p));//'a'  err
//    printf("%d \n", strlen(p[0]));//'a' err
    printf("%d \n", strlen(&p));//���ֵ
    printf("%d \n", strlen(&p + 1));//���ֵ(������ǰ����)
    printf("%d \n", strlen(&p[0] + 1)); //5
}
int main5()
{
    int a[3][4] = {0};
    printf("%d\n",sizeof(a)); //16*3 = 48
    printf("%d\n",sizeof(a[0][0])); //4
    printf("%d\n",sizeof(a[0])); //16 ��һ��һά�����������

    //a[0] ��һ�е���������������������Ԫ�صĵ�ַ����ʵ���ǵ�һ�е�һ��Ԫ�صĵ�ַ
    printf("%d\n",sizeof(a[0]+1)); //��Ԫ�ص�ַ��a[0][0]+1 �൱��a[0][1]�ĵ�ַ  4/8

    printf("%d\n",sizeof(*(a[0]+1))); //a[0][1]��ַ�Ľ����� = int 4���ֽ�

    //a�Ƕ�ά�������������a����Ԫ�ص�ַ ��a[0]+1=a[1] ���Ƕ�ά����ڶ��еĵ�ַ
    printf("%d\n",sizeof(a+1)); //��Ԫ�ص�ַa[0]+1 = a[1]�ĵ�ַ ��ַ����4/8
    printf("%d\n",sizeof(*(a+1))); //a[2]������  = 16


    printf("%d\n",sizeof( &a[0]+1) );//��ַ+1 = a[1]�ĵ�ַ 4/8
    printf("%d\n",sizeof( *(&a[0]+1)) ); //16
    printf("%d\n",sizeof( *a )); //��Ԫ�ص�ַa[0] 16
    printf("%d\n",sizeof( a[3])); //16


}
//ָ�������
int main6()

{
    int a[5] = {1,2,3,4,5};
    int* ptr =(int*)(&a+1); //&a����������ĵ�ַ+1 ������ǰ���� = 6

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
}*p; //�ṹ��ָ�� p
int main7()
{
    //����Test���͵ı�����СΪ20���ֽڣ�p��ֵΪ0x100000�������б��ʽ��
    p = (struct Test*)0x100000;

    //�ṹ��+1 ����һ���ṹ��
    printf("%p\n",p+0x1); //0x100014  16���Ʊ�ʾ

    //100000 = 1048576������ +1 == 101048577
    //0x100000 +1 = 0x100001
    printf("%p\n",(unsigned long)p+0x1); //0x100001

//    1048576 + 4  = 0x100004 ����һ��int* 4/8���ֽ�
    printf("%p\n",(unsigned int*)p+0x1); //0x100004

    return 0;
}
int main8()
{
    int a[4] = {1,2,3,4};
    int* ptr1 = (int*)(&a+1);  //������������
    int* ptr2 = (int*)((int)a+1);  //+1����4���ֽڣ�00020000


    //ptr1[-1] == *(ptr1+(-1)) ָ�����һ��λ��-1 �������һ��
    printf("%x��%x",ptr1[-1],*ptr2); //������ 4���ֽ�00020000


    return 0;


}
int main9()
{
    //���ű��ʽ��ִ֮�н��Ϊ���һ��  1
    int a[3][2] = {(0,1),(2,3),(4,5)};
    int* p;
    p = a[0]; //��һ��Ԫ�� 1

    printf("%d",p[0]); //1
    return 0;
}
int main10()
{
    int a[5][5];
    int (*p)[4]; //����ָ��
    p = a; //������ ��Ԫ�ص�ַ
    //fffffffffffffffc,-4


    //p[4][2] == *(p[4] + 2) == *(*(p+4)+2)
    //(p+4)����4�����ε�ַ    *(p+4)+2���������ֽ�

    //ָ��-ָ�� �õ�����ָ��֮���Ԫ�ظ��� С-�� �Ǹ��� -4
    printf("%p,%d\n",&p[4][2]-&a[4][2],&p[4][2]-&a[4][2]);

    return 0;
}
int main11()
{
    int aa[2][5] = {1,2,3,4,5,6,7,8,9,10};
    int * ptr1 = (int* )(&aa+1);  //&����������������  ptr���һ��Ԫ�غ���ĵ�ַ
    int * ptr2 = (int*)(*(aa+1)); //aa+1 == a[0]+1 ��Ԫ�ص�ַ+1    a[1][0]�ĵ�ַ

    //ptr-1�������һ��Ԫ�صĵ�ַ
    //ptr2-1 ����a[0][4]�ĵ�ַ
    printf("%d,%d",*(ptr1-1),*(ptr2-1)); //10   5
    return 0;
}
int main12()
{
    //"w" "a" "a"
    char* a[] = {"work","at","alibaba"}; //�ַ�ָ�� �洢����
    char** pa = a;  //��Ԫ�ص�ַ a[0]

    pa++; //a++    a[1]
    printf("%s",*pa); //at
    return 0;

}
int main()
{
    char* c[] = {"ENTER","NEW","POINT","FIRST"};
    char** cp[] = {c+3,c+2,c+1,c};   //c����Ԫ�ص�ַ

    char*** cpp = cp;

    printf("%s\n",**++cpp); //point
    printf("%s\n",*--*++cpp+3); //er
    printf("%s\n",*cpp[-2]+3); //st
    printf("%s\n",cpp[-1][-1]+1);//ew

    return 0;



}


