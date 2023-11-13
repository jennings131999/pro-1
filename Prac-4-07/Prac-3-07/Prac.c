#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);// 前置++ --会改变值
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3); // cpp[-2]==*(cpp-2)
	printf("%s\n", cpp[-1][-1] + 1);//cpp[-1][-1]==*(*(cpp-1)-1)
	return 0;
}
//int main()
//{
//	char* a[] = { "work","at","alibaba" };//指针数组，每个元素是char*型，
//	char** pa = a;// 二级指针，将a的地址放到pa，此时pa指向第一个char*
//	pa++;// pa+1,此时 pa 指向第二个char*
//	printf("%s\n", *pa);//对pa解引用，找到第二个char*,第二个char*指向at的起始位置，则打印出at
//	return 0;
//}
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);//&aa+1是取出整个二维数组的地址，再跳过一个二维数组的步长，指向二维数组之后的元素
//	int* ptr2 = (int*)(*(aa + 1));//aa是二维数组首元素地址，是一个一维数组，+1的意思是跳过一个一维数组的步长，指向第一行之后的元素
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//此时ptr1与ptr2被强制类型转换为int* 型指针，+1 -1均为跳过1个int型的步长
//	return 0;
//}
//int main()
//{
//	int a[5][5];//
//	int(*p)[4];
//	p = a;//a表示首元素地址，类型是int(*)[5]，每次访问5个字节；p是个指针，类型是int(*)[4],p每次访问4个字节
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//地址相减，得到的结果是中间元素的个数，本题是小减大，得到的结果是一个负数，-4
//	// -4 按%d打印出来是-4，按%p打印出来，是将-4的补码按照16进制打印出来
//	//p 与 a的
//	return 0;
//}
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };// 逗号表达式！！！，int a[3][2] = { 1,3,5 };
//	int* p;
//	p = a[0];// a[0]是第一行的数组名，数组名表示首元素地址，即a[0][0]的地址
//	printf("%d", p[0]);//p是个整形指针  p[0]=*(p+0)
//	return 0;
//}
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);//&a+1意为指向数组后的地址，强制转换成int*后赋给ptr1，则ptr1指向数组后的地址
//	int* ptr2 = (int*)((int)a + 1);//(int)a将a强制转换为int型，相当于转换成一个数，再加上1，意为直接+1，
//	//把(int)a+1强制转换为 int* ，意为把(int)a+1这个值转换为地址，因此ptr2意为指向原始数组a的地址向后移动一个字节的地址
//	printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1]==*(ptr1+(-1))==*(ptr1-1),意为ptr1指向的地址向左移动4个字节，解引用的意思是，从指针所指的地址处开始，向后访问4个字节，结果为00000004
//	// *ptr2 意为对ptr2所指的地址处开始向后的4个字节解引用，ptr2指向的地址是数组a的首地址向后移动一个字节的位置
//	// 解引用即访问 00 00 00 02，因为为小端存储，所以解应用的值的16进制为02000000
//	return 0;
//}

////由于还没学习结构体，这里告知结构体的大小是20个字节;在x86平台下，也就是32位平台下
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p=(struct Test*)0x100000;//p前面加*，意思是在这里定义了一个结构体指针变量p，他可以指向这个结构体指针
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	printf("%p\n", p + 0x1);//p是结构体类型，0x1就是1，结构体类型的p+0x1就是p+1，意思是向后跳一个结构体，即0x100000+20，值转换为十六进制是0x00100014
//	printf("%p\n", (unsigned long)p + 0x1);//先将p强制类型转换为整形，整形加1，就是对应的十进制数字1048576+1，结果为1048577，再转换为十六进制，0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);//将p转换为无符号整形的指针，+1的意思是跳过一个整形的大小，也就是加4个字节，即0x100000+4，结果为0x100004
//	return 0;
//}
//int main()
//{
//	//程序的结果是什么？  2,5
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);// &a+1跳过了整个数组，强制类型转换只是类型发生了变化，值没有变
//	//ptr 接收了&a+1的地址，类型是int*
//	printf("%d,%d", *(a + 1), *(ptr - 1));// ptr-1意为整形指针向前挪动了一个字节，指向了5这个元素的地址，解引用访问了5这个元素
//	return 0;
//}
//int main()
//{
//	//二维数组
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48 此时数组名表示整个数组的地址3*4*4
//	printf("%d\n", sizeof(a[0][0]));//4 第一行第一列的元素
//	printf("%d\n", sizeof(a[0]));//16  a[0]是什么？？-表示第一行的一维数组的数组名，a[0]单独放在sizeof内部，表示第一行的整个一维数组
//	printf("%d\n", sizeof(a[0] + 1));//4或8  此时a[0]没有单独放在sizeof内部，因此a[0]表示第一行的一维数组的首元素地址，即a[0][0],a[0]+1为a[0][1]d的地址
//	printf("%d\n", sizeof(*(a[0] + 1)));//4 a[0]+1为a[0][1]d的地址,对他解引用，访问到a[0][1]所指的元素
//	printf("%d\n", sizeof(a + 1));//4或者8  a+1表示什么？？
//	// a虽然表示二维数组的地址，但没有单独放在sizeof内部，也没有取地址
//	//因此a表示首元素的地址，二维数组的首元素是一个一维数组，因此a表示二维数组的第一行这个一维数组的地址
//	//a+1 表示跳过第一行，意为第二行这个一维数组的地址
//	printf("%d\n", sizeof(*(a + 1)));//16 对a+1解引用，意为访问第二行整个一维数组
//	printf("%d\n", sizeof(&a[0] + 1));// 4或8 a[0]是第一行的数组名，&a[0]为取出第一行的地址，&a[0]+1为第二行的地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16 对第二行的地址解引用，访问第二行整个数组
//	printf("%d\n", sizeof(*a));//16 此时，a表示二维数组的首元素地址，对他解引用意为访问第一行整个数组
//	printf("%d\n", sizeof(a[3]));//16 sizeof根据类型就可以知道所占空间大小，没有真正访问a[3]，而是从类型知道了空间大小
//	return 0;
//}
//int main()
//{
//	char* p = "abcdef";//-"abcdef"常量字符串，此语句意为将a的地址放到指针变量 p 里面，p指向a的地址
//	printf("%d\n", sizeof(p));//4或者8 p是指针变量
//	printf("%d\n", sizeof(p + 1));//4或者8 p+1意为向后跳一个字节，还是地址
//	printf("%d\n", sizeof(*p));//1 访问的是a
//	printf("%d\n", sizeof(p[0]));//1 p[0]等价于*(p+0)即*p
//	printf("%d\n", sizeof(&p));// 4或者8 二级指针，还是地址
//	printf("%d\n", sizeof(&p + 1));// 4或者8 
//	printf("%d\n", sizeof(&p[0] + 1));// 4或者8 还是地址
//	printf("%d\n", strlen(p));//6  传给strlen的是a的地址，意为从a开始往后找
//	printf("%d\n", strlen(p + 1));// 5
//	printf("%d\n", strlen(*p));// 报错 传给strlen的是a
//	printf("%d\n", strlen(p[0]));//报错 p[0]==a,同上
//	printf("%d\n", strlen(&p));// 随机值 把p的地址传给strlen，跟给定的字符串无关，哪里会遇到\0不确定
//	printf("%d\n", strlen(&p + 1));// 随机值 从p开始往后跳一个字节
//	printf("%d\n", strlen(&p[0] + 1));// 5 意为从b开始往后找
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";//  a b c d e f \0
//	printf("%d\n", sizeof(arr));//7 此数组后面有一个\0，所以有7个元素，每个元素1个字节
//	printf("%d\n", sizeof(arr + 0));//4或者8 此处arr+0表示首元素地址，是地址
//	printf("%d\n", sizeof(*arr));//1 地址解引用就是访问元素
//	printf("%d\n", sizeof(arr[1]));//1 第二个元素
//	printf("%d\n", sizeof(&arr));// 4或者8
//	printf("%d\n", sizeof(&arr + 1));//4或8 还是地址
//	printf("%d\n", sizeof(&arr[0] + 1));// 4或8 还是地址
//	printf("%d\n", strlen(arr));//6 strlen是求字符串长度，有\0就停下来，计算的是\0之前字符的个数；sizeof只关注占用空间大小，不在乎内存中放的是什么
//	printf("%d\n", strlen(arr + 0));//6 
//	printf("%d\n", strlen(*arr));// 报错
//	printf("%d\n", strlen(arr[1]));//报错
//	printf("%d\n", strlen(&arr));//6 取出整个数组arr的地址给strlen，对于strlen来说，还是从首元素地址开始往后找
//	printf("%d\n", strlen(&arr + 1));//随机值 &arr + 1跳到\0之后了
//	printf("%d\n", strlen(&arr[0] + 1));//5 相当于从第二个元素的地址开始往后数，遇到\0停下来
//	return 0;
//}
//int main ()
//{
//	/*字符数组*/
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));// 6  计算的是整个数组所占空间大小
//	printf("%d\n", sizeof(arr + 0));//4或8 arr+0 表示首元素地址
//	printf("%d\n", sizeof(*arr));// 1 *arr 访问数组首元素大小，char型，是1个字节
//	printf("%d\n", sizeof(arr[1]));// 1 访问第二个元素的大小
//	printf("%d\n", sizeof(&arr));//4或者8 取出的数组的地址
//	printf("%d\n", sizeof(&arr + 1));//4或者8 还是地址，是跳过6个字符大小后的地址
//	printf("%d\n", sizeof(&arr[0] + 1));//4或者8 是第二个元素的地址
//	// strlen() 是求字符串长度，要关注 \0，传给strlen的应该是地址
//	printf("%d\n", strlen(arr));// 随机值 arr表示首元素地址 arr没有\0 
//	printf("%d\n", strlen(arr + 0));//随机值 arr+0还是首元素地址
//	printf("%d\n", strlen(*arr));//程序报错  等价于 strlen('a') 即strlen(97),97在这里是个野指针 97这些对于编译器来说非常危险， 这是留给内核使用的
//	printf("%d\n", strlen(arr[1]));//同上
//	printf("%d\n", strlen(&arr));// 随机值 同1，取出的是数组的地址，数组的地址是从首元素开始
//	printf("%d\n", strlen(&arr + 1));//随机值 上面的-6
//	printf("%d\n", strlen(&arr[0] + 1));//随机值 上上的-1
//}
//int main()
//{//一维数组
//	int a[] = { 1,2,3,4 };//整形数组-放了4个整形元素
//	printf("%d\n", sizeof(a));  // 16 数组名此时表示整个数组，计算的是整个数组的大小，单位是字节
//	printf("%d\n", sizeof(a + 0));//4或者8（看平台），数组名此时表示首元素地址，因为有（数组名+0）;a没有单独放在sizeof()内部，也没有取地址，a+0还是首元素地址
//	printf("%d\n", sizeof(*a));//4 a此时表示首元素地址，a==&a[0],对a解引用，相当于抵消了&，所有*a表示该数组首元素，即a[0]
//	printf("%d\n", sizeof(a + 1));//4或8  a此时表示首元素地址，+1表示跳过一个整形,a+1表示第二个元素的地址，所以为一个地址的大小
//	printf("%d\n", sizeof(a[1]));// 4 数组的第二个元素的大小
//	printf("%d\n", sizeof(&a));// 4或者8  &a取出的是数组的地址，也是个地址，只要是地址，无论是数组的地址，还是首元素的地址，所占空间大小是一样的
//	printf("%d\n", sizeof(*&a));//16 &a表示，取出整个数组的地址，类型是int(*)[4]-数组指针，数组指针再解引用，表示根据数组的地址访问整个数组，所以为计算数组的大小
//	// *& 可以理解为 抵消了
//	printf("%d\n", sizeof(&a + 1));//4或者8 &a是数组的地址，得到的是数组指针，&a+1意为跳过一个四个整形元素的数组，还是一个地址，只要是地址...
//	printf("%d\n", sizeof(&a[0]));//4或者8  计算的是第一个元素地址的大小
//	printf("%d\n", sizeof(&a[0] + 1));//4或者8  计算的是第二个元素的地址
//}
//void swap(char* buf1, char* buf2, int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char tmp = *buf1;
//		*buf1 = *buf2;
//		*buf2 = tmp;
//		buf1++;
//		buf2++;
//	}
//}
//int my_cmp(const void* e1, const void* e2)
//{
//	return(*(int*)e1 - *(int*)e2);
//}
//void bubble(void* base, int sz,int width, int(*cmp)(const void* e1, const void* e2))
//{
//	int i = 0;
//	//趟数
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//加快进程，应对已经排好序的情况
//		int j = 0;
//		//一趟冒泡排序
//		for (j = 0; j < sz - 1; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//判断是否需要交换
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);// 交换-自己写的交换函数
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//
//}
//int main()
//{
//	int arr[] = { 1,3,2,4,6,7,8,9,0 };
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), my_cmp);
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d,",arr[i]);
//	}
//	return 0;
//}
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp_struct_byname(const void* e1,const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//int cmp_struct_byage(const void* e1, const void* e2)
//{
//	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
//}
//void test()
//{
//	//使用qsort来排序结构体数据
//	struct stu s[] = { {"lisa",18},{"ajen",25},{"jordan",33} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_struct_byname);//按名字排序
//	qsort(s, sz, sizeof(s[0]), cmp_struct_byage);//按年龄排序
//}
//int main()
//{
//	test();
//	return 0;
//}

////qosrt函数的使用者得实现一个比较函数
//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);// void* 不能直接解引用，需要强制转换一下
//	// 思考！！需要返回 负数 0 正数 的时候，怎样最简便
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);//qsort调用int_cmp，回调函数来实现qsort函数
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	char* pa = &a;//编译器报警告
//	void* pa = &a;//编译器没有警告
//	// void* 是无具体类型的指针， 可以接收任意类型的地址
//	// 但需要注意 void* 类型的指针不能进行解引用操作，也不能 +-整数
//	return 0;
//}
//void meu()
//{
//	printf("************************\n");
//	printf("******   计算器   ******\n");
//	printf("******   1. add   ******\n");
//	printf("******   2. sub   ******\n");
//	printf("******   3. mul   ******\n");
//	printf("******   4. div   ******\n");
//	printf("******   0.excit  ******\n");
//	printf("******   请选择   ******\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//
//int main()
//{	
//	int input = 0;
//	int(*pf[5])(int, int) = { 0,add,sub,mul,div };//转移表-函数指针的数组
//	do
//	{
//		meu();
//		scanf("%d", &input);
//		if (input >0 && input <= 4)
//		{
//			printf("请输入要计算的两个值>:");
//				int i = 0;
//				int j = 0;
//			scanf("%d %d", &i, &j);
//			int ret=pf[input](i,j);//通过地址访问函数
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出！！！");
//		}
//		else
//		{
//			printf("输入错误，请重新输入！\n");
//		}
//	} while (input);
//	return 0;
//}
//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	//函数指针pfun
//	void (*pfun)(const char*) = test;
//	//函数指针的数组pfunArr
//	void (*pfunArr[5])(const char* str);
//	pfunArr[0] = test;
//	//指向函数指针数组pfunArr的指针ppfunArr
//	void (*(*ppfunArr)[5])(const char*) = &pfunArr;//&pfunArr-把函数指针数组的地址取出来，需要存放到指针里面
//	//(*ppfunArr) 先结合说明是指针，再结合[5]说明是数组，剩下的void (*)(const char*)是一个函数指针类型，说明此数组放的元素类型是函数指针
//	return 0;
//}

////利用函数指针数组相关知识点实现计算器
//void meu()
//{
//	printf("************************\n");
//	printf("******   计算器   ******\n");
//	printf("******   1. add   ******\n");
//	printf("******   2. sub   ******\n");
//	printf("******   3. mul   ******\n");
//	printf("******   4. div   ******\n");
//	printf("******   0.excit  ******\n");
//	printf("************************\n");
//}
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x * y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//int running(int input)
//{
//	printf("请输入要计算的两个值>:");
//	int i = 0;
//	int j = 0;
//	scanf("%d %d", &i, &j);
//	int(*pf[5])(int, int) = { 0,add,sub,mul,div };//转移表
//	int ret = pf[input](i,j);//函数指针的用法
//	return ret;
//}
//int main()
//{
//	
//	int input = 0;
//	
//	do
//	{
//		meu();
//		scanf("%d", &input);
//		if (input >0 && input <= 4)
//		{
//			int ret=running(input);
//			printf("结果为%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出！！！");
//		}
//		else
//		{
//			printf("输入错误，请重新输入！\n");
//		}
//	} while (input);
//	return 0;
//}
//typedef unsigned int uint;//typedef的常规用法
//typedef void(*pf_t)(int);//typedef 用于函数指针，意为将void(*)(int)重命名为pf_t
//int main()
//{
//	void(*signal(int, void(*)(int)))(int);
//	void(*)(int)-函数指针类型
// signal先跟后面括号结合，所以他是函数名，有2个参数，一个int，一个函数指针
//	将signal(int, void(*)(int))拿出来，剩下一个函数指针类型-void(*)(int)
//	说明signal这个函数的返回类型也是一个函数指针类型
//	 因此，以上函数是一次函数声明，
//	声明的signal函数的第一个参数类型是int，第二个参数类型是函数指针，该函数指针指向的函数参数是int类型，返回值是void类型
//	signal函数的返回类型是函数指针，该函数指针指向的参数是int类型，返回的是void类型
//	return 0;
//}
//int main()
//{
//	(*(void(*)())0)();// 本质上试一次函数调用，调用的是0作为地址处的函数
//	//void(*)()-函数指针类型
//	//(void(*)())0-强制类型转换，把0(int型)强制转换为无参且返回类型为void的函数的地址
//	// (*)(...)最后调用0地址处这个函数
//	// 这里可以把0当成一个地址，强制转换为另外一个地址，这个地址是函数的地址，最后来一次调用
//	return 0;
//}
//int Add(int x, int y)
//{
//    return x + y;
//}
//int main()
//{
//    int (*pf)(int, int) = &Add;
//    int ret=(*pf)(2, 3);// 通过函数地址调用函数
//    int ret = pf(2, 3);//* 可以不写
//    /*int ret=Add(2, 3);*/ 
//    printf("%d\n", ret);
//}
//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	return 0;
//}
//int main()
//{
//	int arr[5] = { 0 };
//	//&数组名-取的是数组的地址
//	int(*p)[5] = &arr;//数组指针
//	return 0;
//}
//void test(char** p)
//{
//
//}
//int main()
//{
//	char c = 'b';
//	char* pc = &c;
//	char** ppc = &pc;
//	char* arr[10];
//	test(&pc);
//	test(ppc);
//	test(arr);//Ok?
//	return 0;
//}
//void test(int** ptr)
//{
//	printf("num = %d\n", **ptr);
//}
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	test(pp);
//	test(&p);
//	return 0;
//}
//void test1(int* p)
//{}
////test1函数能接收什么参数？
//void test2(char* p)
//{}
////test2函数能接收什么参数？
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", *(p + i));
//	}
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//一级指针p，传给函数
//	print(p, sz);
//	return 0;
//}
//void test(int arr[3][5])//ok？ 对
//{}
//void test(int arr[][])//ok？ 不对，对比下一个
//{}
//void test(int arr[][5])//ok？ 对
//{}
////总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
////因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
////这样才方便运算。
//void test(int* arr)//ok？不对，
//{}
//void test(int* arr[5])//ok？不对，
//{}
//void test(int(*arr)[5])//ok？ √
//{}
//void test(int** arr)//ok？不对，二级指针是用来存放一级指针变量地址的
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);/// 传首元素地址，arr是二维数组，数组名表示第一行的地址
//}
//void test(int arr[])//ok? √
//{}
//void test(int arr[10])//ok? √
//{}
//void test(int* arr)//ok?  √
//{}
//void test2(int* arr[20])//ok? √ 这是数组的形式
//{}
//void test2(int** arr)//ok? √ 用二级指针来存放一级指针变量的地址
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}

//void print1(int arr[3][5], int x, int y)//数组传参-用数组接收
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int(*p)[5], int x, int y)// 用数组指针接收
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			/*printf("%d ", p[i][j]);
//			pritf("%d ", *(p[i] + j));*/
//			/*printf("%d ", *(*(p + i) + j));*/
//			printf("%d ", (*(p + i))[j]);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);// arr-数组名，是首元素地址 
//	//对于二维数组，把一行想象成一个元素，
//	//在二维数组中，数组名，表示第一行的地址，而第一行是一个一维数组
//	//在这里传参 可以用指针来接收
//	print2(arr, 3, 5);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//	int (*pa)[10] = &arr;// 数组指针
//
//	return 0;
//}