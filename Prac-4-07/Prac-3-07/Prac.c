#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);// ǰ��++ --��ı�ֵ
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3); // cpp[-2]==*(cpp-2)
	printf("%s\n", cpp[-1][-1] + 1);//cpp[-1][-1]==*(*(cpp-1)-1)
	return 0;
}
//int main()
//{
//	char* a[] = { "work","at","alibaba" };//ָ�����飬ÿ��Ԫ����char*�ͣ�
//	char** pa = a;// ����ָ�룬��a�ĵ�ַ�ŵ�pa����ʱpaָ���һ��char*
//	pa++;// pa+1,��ʱ pa ָ��ڶ���char*
//	printf("%s\n", *pa);//��pa�����ã��ҵ��ڶ���char*,�ڶ���char*ָ��at����ʼλ�ã����ӡ��at
//	return 0;
//}
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);//&aa+1��ȡ��������ά����ĵ�ַ��������һ����ά����Ĳ�����ָ���ά����֮���Ԫ��
//	int* ptr2 = (int*)(*(aa + 1));//aa�Ƕ�ά������Ԫ�ص�ַ����һ��һά���飬+1����˼������һ��һά����Ĳ�����ָ���һ��֮���Ԫ��
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));//��ʱptr1��ptr2��ǿ������ת��Ϊint* ��ָ�룬+1 -1��Ϊ����1��int�͵Ĳ���
//	return 0;
//}
//int main()
//{
//	int a[5][5];//
//	int(*p)[4];
//	p = a;//a��ʾ��Ԫ�ص�ַ��������int(*)[5]��ÿ�η���5���ֽڣ�p�Ǹ�ָ�룬������int(*)[4],pÿ�η���4���ֽ�
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	//��ַ������õ��Ľ�����м�Ԫ�صĸ�����������С���󣬵õ��Ľ����һ��������-4
//	// -4 ��%d��ӡ������-4����%p��ӡ�������ǽ�-4�Ĳ��밴��16���ƴ�ӡ����
//	//p �� a��
//	return 0;
//}
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };// ���ű��ʽ��������int a[3][2] = { 1,3,5 };
//	int* p;
//	p = a[0];// a[0]�ǵ�һ�е�����������������ʾ��Ԫ�ص�ַ����a[0][0]�ĵ�ַ
//	printf("%d", p[0]);//p�Ǹ�����ָ��  p[0]=*(p+0)
//	return 0;
//}
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);//&a+1��Ϊָ�������ĵ�ַ��ǿ��ת����int*�󸳸�ptr1����ptr1ָ�������ĵ�ַ
//	int* ptr2 = (int*)((int)a + 1);//(int)a��aǿ��ת��Ϊint�ͣ��൱��ת����һ�������ټ���1����Ϊֱ��+1��
//	//��(int)a+1ǿ��ת��Ϊ int* ����Ϊ��(int)a+1���ֵת��Ϊ��ַ�����ptr2��Ϊָ��ԭʼ����a�ĵ�ַ����ƶ�һ���ֽڵĵ�ַ
//	printf("%x,%x", ptr1[-1], *ptr2);//ptr1[-1]==*(ptr1+(-1))==*(ptr1-1),��Ϊptr1ָ��ĵ�ַ�����ƶ�4���ֽڣ������õ���˼�ǣ���ָ����ָ�ĵ�ַ����ʼ��������4���ֽڣ����Ϊ00000004
//	// *ptr2 ��Ϊ��ptr2��ָ�ĵ�ַ����ʼ����4���ֽڽ����ã�ptr2ָ��ĵ�ַ������a���׵�ַ����ƶ�һ���ֽڵ�λ��
//	// �����ü����� 00 00 00 02����ΪΪС�˴洢�����Խ�Ӧ�õ�ֵ��16����Ϊ02000000
//	return 0;
//}

////���ڻ�ûѧϰ�ṹ�壬�����֪�ṹ��Ĵ�С��20���ֽ�;��x86ƽ̨�£�Ҳ����32λƽ̨��
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p=(struct Test*)0x100000;//pǰ���*����˼�������ﶨ����һ���ṹ��ָ�����p��������ָ������ṹ��ָ��
////����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
////��֪���ṹ��Test���͵ı�����С��20���ֽ�
//int main()
//{
//	printf("%p\n", p + 0x1);//p�ǽṹ�����ͣ�0x1����1���ṹ�����͵�p+0x1����p+1����˼�������һ���ṹ�壬��0x100000+20��ֵת��Ϊʮ��������0x00100014
//	printf("%p\n", (unsigned long)p + 0x1);//�Ƚ�pǿ������ת��Ϊ���Σ����μ�1�����Ƕ�Ӧ��ʮ��������1048576+1�����Ϊ1048577����ת��Ϊʮ�����ƣ�0x100001
//	printf("%p\n", (unsigned int*)p + 0x1);//��pת��Ϊ�޷������ε�ָ�룬+1����˼������һ�����εĴ�С��Ҳ���Ǽ�4���ֽڣ���0x100000+4�����Ϊ0x100004
//	return 0;
//}
//int main()
//{
//	//����Ľ����ʲô��  2,5
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);// &a+1�������������飬ǿ������ת��ֻ�����ͷ����˱仯��ֵû�б�
//	//ptr ������&a+1�ĵ�ַ��������int*
//	printf("%d,%d", *(a + 1), *(ptr - 1));// ptr-1��Ϊ����ָ����ǰŲ����һ���ֽڣ�ָ����5���Ԫ�صĵ�ַ�������÷�����5���Ԫ��
//	return 0;
//}
//int main()
//{
//	//��ά����
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48 ��ʱ��������ʾ��������ĵ�ַ3*4*4
//	printf("%d\n", sizeof(a[0][0]));//4 ��һ�е�һ�е�Ԫ��
//	printf("%d\n", sizeof(a[0]));//16  a[0]��ʲô����-��ʾ��һ�е�һά�������������a[0]��������sizeof�ڲ�����ʾ��һ�е�����һά����
//	printf("%d\n", sizeof(a[0] + 1));//4��8  ��ʱa[0]û�е�������sizeof�ڲ������a[0]��ʾ��һ�е�һά�������Ԫ�ص�ַ����a[0][0],a[0]+1Ϊa[0][1]d�ĵ�ַ
//	printf("%d\n", sizeof(*(a[0] + 1)));//4 a[0]+1Ϊa[0][1]d�ĵ�ַ,���������ã����ʵ�a[0][1]��ָ��Ԫ��
//	printf("%d\n", sizeof(a + 1));//4����8  a+1��ʾʲô����
//	// a��Ȼ��ʾ��ά����ĵ�ַ����û�е�������sizeof�ڲ���Ҳû��ȡ��ַ
//	//���a��ʾ��Ԫ�صĵ�ַ����ά�������Ԫ����һ��һά���飬���a��ʾ��ά����ĵ�һ�����һά����ĵ�ַ
//	//a+1 ��ʾ������һ�У���Ϊ�ڶ������һά����ĵ�ַ
//	printf("%d\n", sizeof(*(a + 1)));//16 ��a+1�����ã���Ϊ���ʵڶ�������һά����
//	printf("%d\n", sizeof(&a[0] + 1));// 4��8 a[0]�ǵ�һ�е���������&a[0]Ϊȡ����һ�еĵ�ַ��&a[0]+1Ϊ�ڶ��еĵ�ַ
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16 �Եڶ��еĵ�ַ�����ã����ʵڶ�����������
//	printf("%d\n", sizeof(*a));//16 ��ʱ��a��ʾ��ά�������Ԫ�ص�ַ��������������Ϊ���ʵ�һ����������
//	printf("%d\n", sizeof(a[3]));//16 sizeof�������;Ϳ���֪����ռ�ռ��С��û����������a[3]�����Ǵ�����֪���˿ռ��С
//	return 0;
//}
//int main()
//{
//	char* p = "abcdef";//-"abcdef"�����ַ������������Ϊ��a�ĵ�ַ�ŵ�ָ����� p ���棬pָ��a�ĵ�ַ
//	printf("%d\n", sizeof(p));//4����8 p��ָ�����
//	printf("%d\n", sizeof(p + 1));//4����8 p+1��Ϊ�����һ���ֽڣ����ǵ�ַ
//	printf("%d\n", sizeof(*p));//1 ���ʵ���a
//	printf("%d\n", sizeof(p[0]));//1 p[0]�ȼ���*(p+0)��*p
//	printf("%d\n", sizeof(&p));// 4����8 ����ָ�룬���ǵ�ַ
//	printf("%d\n", sizeof(&p + 1));// 4����8 
//	printf("%d\n", sizeof(&p[0] + 1));// 4����8 ���ǵ�ַ
//	printf("%d\n", strlen(p));//6  ����strlen����a�ĵ�ַ����Ϊ��a��ʼ������
//	printf("%d\n", strlen(p + 1));// 5
//	printf("%d\n", strlen(*p));// ���� ����strlen����a
//	printf("%d\n", strlen(p[0]));//���� p[0]==a,ͬ��
//	printf("%d\n", strlen(&p));// ���ֵ ��p�ĵ�ַ����strlen�����������ַ����޹أ����������\0��ȷ��
//	printf("%d\n", strlen(&p + 1));// ���ֵ ��p��ʼ������һ���ֽ�
//	printf("%d\n", strlen(&p[0] + 1));// 5 ��Ϊ��b��ʼ������
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";//  a b c d e f \0
//	printf("%d\n", sizeof(arr));//7 �����������һ��\0��������7��Ԫ�أ�ÿ��Ԫ��1���ֽ�
//	printf("%d\n", sizeof(arr + 0));//4����8 �˴�arr+0��ʾ��Ԫ�ص�ַ���ǵ�ַ
//	printf("%d\n", sizeof(*arr));//1 ��ַ�����þ��Ƿ���Ԫ��
//	printf("%d\n", sizeof(arr[1]));//1 �ڶ���Ԫ��
//	printf("%d\n", sizeof(&arr));// 4����8
//	printf("%d\n", sizeof(&arr + 1));//4��8 ���ǵ�ַ
//	printf("%d\n", sizeof(&arr[0] + 1));// 4��8 ���ǵ�ַ
//	printf("%d\n", strlen(arr));//6 strlen�����ַ������ȣ���\0��ͣ�������������\0֮ǰ�ַ��ĸ�����sizeofֻ��עռ�ÿռ��С�����ں��ڴ��зŵ���ʲô
//	printf("%d\n", strlen(arr + 0));//6 
//	printf("%d\n", strlen(*arr));// ����
//	printf("%d\n", strlen(arr[1]));//����
//	printf("%d\n", strlen(&arr));//6 ȡ����������arr�ĵ�ַ��strlen������strlen��˵�����Ǵ���Ԫ�ص�ַ��ʼ������
//	printf("%d\n", strlen(&arr + 1));//���ֵ &arr + 1����\0֮����
//	printf("%d\n", strlen(&arr[0] + 1));//5 �൱�ڴӵڶ���Ԫ�صĵ�ַ��ʼ������������\0ͣ����
//	return 0;
//}
//int main ()
//{
//	/*�ַ�����*/
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));// 6  �����������������ռ�ռ��С
//	printf("%d\n", sizeof(arr + 0));//4��8 arr+0 ��ʾ��Ԫ�ص�ַ
//	printf("%d\n", sizeof(*arr));// 1 *arr ����������Ԫ�ش�С��char�ͣ���1���ֽ�
//	printf("%d\n", sizeof(arr[1]));// 1 ���ʵڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&arr));//4����8 ȡ��������ĵ�ַ
//	printf("%d\n", sizeof(&arr + 1));//4����8 ���ǵ�ַ��������6���ַ���С��ĵ�ַ
//	printf("%d\n", sizeof(&arr[0] + 1));//4����8 �ǵڶ���Ԫ�صĵ�ַ
//	// strlen() �����ַ������ȣ�Ҫ��ע \0������strlen��Ӧ���ǵ�ַ
//	printf("%d\n", strlen(arr));// ���ֵ arr��ʾ��Ԫ�ص�ַ arrû��\0 
//	printf("%d\n", strlen(arr + 0));//���ֵ arr+0������Ԫ�ص�ַ
//	printf("%d\n", strlen(*arr));//���򱨴�  �ȼ��� strlen('a') ��strlen(97),97�������Ǹ�Ұָ�� 97��Щ���ڱ�������˵�ǳ�Σ�գ� ���������ں�ʹ�õ�
//	printf("%d\n", strlen(arr[1]));//ͬ��
//	printf("%d\n", strlen(&arr));// ���ֵ ͬ1��ȡ����������ĵ�ַ������ĵ�ַ�Ǵ���Ԫ�ؿ�ʼ
//	printf("%d\n", strlen(&arr + 1));//���ֵ �����-6
//	printf("%d\n", strlen(&arr[0] + 1));//���ֵ ���ϵ�-1
//}
//int main()
//{//һά����
//	int a[] = { 1,2,3,4 };//��������-����4������Ԫ��
//	printf("%d\n", sizeof(a));  // 16 ��������ʱ��ʾ�������飬���������������Ĵ�С����λ���ֽ�
//	printf("%d\n", sizeof(a + 0));//4����8����ƽ̨������������ʱ��ʾ��Ԫ�ص�ַ����Ϊ�У�������+0��;aû�е�������sizeof()�ڲ���Ҳû��ȡ��ַ��a+0������Ԫ�ص�ַ
//	printf("%d\n", sizeof(*a));//4 a��ʱ��ʾ��Ԫ�ص�ַ��a==&a[0],��a�����ã��൱�ڵ�����&������*a��ʾ��������Ԫ�أ���a[0]
//	printf("%d\n", sizeof(a + 1));//4��8  a��ʱ��ʾ��Ԫ�ص�ַ��+1��ʾ����һ������,a+1��ʾ�ڶ���Ԫ�صĵ�ַ������Ϊһ����ַ�Ĵ�С
//	printf("%d\n", sizeof(a[1]));// 4 ����ĵڶ���Ԫ�صĴ�С
//	printf("%d\n", sizeof(&a));// 4����8  &aȡ����������ĵ�ַ��Ҳ�Ǹ���ַ��ֻҪ�ǵ�ַ������������ĵ�ַ��������Ԫ�صĵ�ַ����ռ�ռ��С��һ����
//	printf("%d\n", sizeof(*&a));//16 &a��ʾ��ȡ����������ĵ�ַ��������int(*)[4]-����ָ�룬����ָ���ٽ����ã���ʾ��������ĵ�ַ�����������飬����Ϊ��������Ĵ�С
//	// *& �������Ϊ ������
//	printf("%d\n", sizeof(&a + 1));//4����8 &a������ĵ�ַ���õ���������ָ�룬&a+1��Ϊ����һ���ĸ�����Ԫ�ص����飬����һ����ַ��ֻҪ�ǵ�ַ...
//	printf("%d\n", sizeof(&a[0]));//4����8  ������ǵ�һ��Ԫ�ص�ַ�Ĵ�С
//	printf("%d\n", sizeof(&a[0] + 1));//4����8  ������ǵڶ���Ԫ�صĵ�ַ
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
//	//����
//	for (i = 0; i < sz - 1; i++)
//	{
//		int flag = 1;//�ӿ���̣�Ӧ���Ѿ��ź�������
//		int j = 0;
//		//һ��ð������
//		for (j = 0; j < sz - 1; j++)
//		{
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)//�ж��Ƿ���Ҫ����
//			{
//				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);// ����-�Լ�д�Ľ�������
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
//	//ʹ��qsort������ṹ������
//	struct stu s[] = { {"lisa",18},{"ajen",25},{"jordan",33} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_struct_byname);//����������
//	qsort(s, sz, sizeof(s[0]), cmp_struct_byage);//����������
//}
//int main()
//{
//	test();
//	return 0;
//}

////qosrt������ʹ���ߵ�ʵ��һ���ȽϺ���
//int int_cmp(const void* p1, const void* p2)
//{
//	return (*(int*)p1 - *(int*)p2);// void* ����ֱ�ӽ����ã���Ҫǿ��ת��һ��
//	// ˼��������Ҫ���� ���� 0 ���� ��ʱ����������
//}
//int main()
//{
//	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//	int i = 0;
//
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), int_cmp);//qsort����int_cmp���ص�������ʵ��qsort����
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
//	char* pa = &a;//������������
//	void* pa = &a;//������û�о���
//	// void* ���޾������͵�ָ�룬 ���Խ����������͵ĵ�ַ
//	// ����Ҫע�� void* ���͵�ָ�벻�ܽ��н����ò�����Ҳ���� +-����
//	return 0;
//}
//void meu()
//{
//	printf("************************\n");
//	printf("******   ������   ******\n");
//	printf("******   1. add   ******\n");
//	printf("******   2. sub   ******\n");
//	printf("******   3. mul   ******\n");
//	printf("******   4. div   ******\n");
//	printf("******   0.excit  ******\n");
//	printf("******   ��ѡ��   ******\n");
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
//	int(*pf[5])(int, int) = { 0,add,sub,mul,div };//ת�Ʊ�-����ָ�������
//	do
//	{
//		meu();
//		scanf("%d", &input);
//		if (input >0 && input <= 4)
//		{
//			printf("������Ҫ���������ֵ>:");
//				int i = 0;
//				int j = 0;
//			scanf("%d %d", &i, &j);
//			int ret=pf[input](i,j);//ͨ����ַ���ʺ���
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�������");
//		}
//		else
//		{
//			printf("����������������룡\n");
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
//	//����ָ��pfun
//	void (*pfun)(const char*) = test;
//	//����ָ�������pfunArr
//	void (*pfunArr[5])(const char* str);
//	pfunArr[0] = test;
//	//ָ����ָ������pfunArr��ָ��ppfunArr
//	void (*(*ppfunArr)[5])(const char*) = &pfunArr;//&pfunArr-�Ѻ���ָ������ĵ�ַȡ��������Ҫ��ŵ�ָ������
//	//(*ppfunArr) �Ƚ��˵����ָ�룬�ٽ��[5]˵�������飬ʣ�µ�void (*)(const char*)��һ������ָ�����ͣ�˵��������ŵ�Ԫ�������Ǻ���ָ��
//	return 0;
//}

////���ú���ָ���������֪ʶ��ʵ�ּ�����
//void meu()
//{
//	printf("************************\n");
//	printf("******   ������   ******\n");
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
//	printf("������Ҫ���������ֵ>:");
//	int i = 0;
//	int j = 0;
//	scanf("%d %d", &i, &j);
//	int(*pf[5])(int, int) = { 0,add,sub,mul,div };//ת�Ʊ�
//	int ret = pf[input](i,j);//����ָ����÷�
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
//			printf("���Ϊ%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("�˳�������");
//		}
//		else
//		{
//			printf("����������������룡\n");
//		}
//	} while (input);
//	return 0;
//}
//typedef unsigned int uint;//typedef�ĳ����÷�
//typedef void(*pf_t)(int);//typedef ���ں���ָ�룬��Ϊ��void(*)(int)������Ϊpf_t
//int main()
//{
//	void(*signal(int, void(*)(int)))(int);
//	void(*)(int)-����ָ������
// signal�ȸ��������Ž�ϣ��������Ǻ���������2��������һ��int��һ������ָ��
//	��signal(int, void(*)(int))�ó�����ʣ��һ������ָ������-void(*)(int)
//	˵��signal��������ķ�������Ҳ��һ������ָ������
//	 ��ˣ����Ϻ�����һ�κ���������
//	������signal�����ĵ�һ������������int���ڶ������������Ǻ���ָ�룬�ú���ָ��ָ��ĺ���������int���ͣ�����ֵ��void����
//	signal�����ķ��������Ǻ���ָ�룬�ú���ָ��ָ��Ĳ�����int���ͣ����ص���void����
//	return 0;
//}
//int main()
//{
//	(*(void(*)())0)();// ��������һ�κ������ã����õ���0��Ϊ��ַ���ĺ���
//	//void(*)()-����ָ������
//	//(void(*)())0-ǿ������ת������0(int��)ǿ��ת��Ϊ�޲��ҷ�������Ϊvoid�ĺ����ĵ�ַ
//	// (*)(...)������0��ַ���������
//	// ������԰�0����һ����ַ��ǿ��ת��Ϊ����һ����ַ�������ַ�Ǻ����ĵ�ַ�������һ�ε���
//	return 0;
//}
//int Add(int x, int y)
//{
//    return x + y;
//}
//int main()
//{
//    int (*pf)(int, int) = &Add;
//    int ret=(*pf)(2, 3);// ͨ��������ַ���ú���
//    int ret = pf(2, 3);//* ���Բ�д
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
//	//&������-ȡ��������ĵ�ַ
//	int(*p)[5] = &arr;//����ָ��
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
////test1�����ܽ���ʲô������
//void test2(char* p)
//{}
////test2�����ܽ���ʲô������
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
//	//һ��ָ��p����������
//	print(p, sz);
//	return 0;
//}
//void test(int arr[3][5])//ok�� ��
//{}
//void test(int arr[][])//ok�� ���ԣ��Ա���һ��
//{}
//void test(int arr[][5])//ok�� ��
//{}
////�ܽ᣺��ά���鴫�Σ������βε����ֻ��ʡ�Ե�һ��[]�����֡�
////��Ϊ��һ����ά���飬���Բ�֪���ж����У����Ǳ���֪��һ�ж���Ԫ�ء�
////�����ŷ������㡣
//void test(int* arr)//ok�����ԣ�
//{}
//void test(int* arr[5])//ok�����ԣ�
//{}
//void test(int(*arr)[5])//ok�� ��
//{}
//void test(int** arr)//ok�����ԣ�����ָ�����������һ��ָ�������ַ��
//{}
//int main()
//{
//	int arr[3][5] = { 0 };
//	test(arr);/// ����Ԫ�ص�ַ��arr�Ƕ�ά���飬��������ʾ��һ�еĵ�ַ
//}
//void test(int arr[])//ok? ��
//{}
//void test(int arr[10])//ok? ��
//{}
//void test(int* arr)//ok?  ��
//{}
//void test2(int* arr[20])//ok? �� �����������ʽ
//{}
//void test2(int** arr)//ok? �� �ö���ָ�������һ��ָ������ĵ�ַ
//{}
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//}

//void print1(int arr[3][5], int x, int y)//���鴫��-���������
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
//void print2(int(*p)[5], int x, int y)// ������ָ�����
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
//	print1(arr, 3, 5);// arr-������������Ԫ�ص�ַ 
//	//���ڶ�ά���飬��һ�������һ��Ԫ�أ�
//	//�ڶ�ά�����У�����������ʾ��һ�еĵ�ַ������һ����һ��һά����
//	//�����ﴫ�� ������ָ��������
//	print2(arr, 3, 5);
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//	int (*pa)[10] = &arr;// ����ָ��
//
//	return 0;
//}