#include <iostream>
#include<algorithm>
using namespace std;

/*--------------函数声明--------------*/
void disp(int n, int a[]);//输出函数
void quick(int a[], int low, int high);
void Merge(int* numbers, int start, int mid, int end);
void MergeSort(int* numbers, int start, int end);
void insert(int n, int a[]);
void select(int n, int a[]);
void bucket(int n, int a[]);
void radix(int n, int a[]);
void countsort(int n, int a[]);
void heapSort(int a[], int n,int size);
void maxHeap(int a[], int n,int size);
void buildMaxHeap(int a[], int n,int size);

//输出函数
void disp(int n, int a[])
{
	for (int z = 0; z < n; z++)
		cout << a[z] << " ";//数字+空格}
	cout << endl;
}

int main()
{
	int group = 5;//测试组数
	for (int m = 0; m < group; m++)
	{
		//输入数据
		int n;
		cout << "请输入数据个数：" << endl;
		cin >> n;

		int data[20];
		cout << "请输入数据：" << endl;
		for (int i = 0; i < n; i++)
			cin >> data[i];

		int mod;
		cout << "请输入排序方式编号:" << endl;
		cout << "1-快速排序" << endl;
		cout << "2-归并排序" << endl;
		cout << "3-插入排序" << endl;
		cout << "4-选择排序" << endl;
		cout << "5-桶排序" << endl;
		cout << "6-基数排序" << endl;
		cout << "7-计数排序" << endl;
		cout << "8-堆排序" << endl;
		cin >> mod;

		if (n == 1)//如果只有一个数，直接输出
			cout << data[0] << endl;
		else
		{
			switch (mod)
			{
				//快速排序	
			case 1:
			{
				quick(data, 0, n - 1);
				cout << "快速排序结果：" << endl;
				disp(n, data);
				break;
			}
			//归并排序
			case 2:
			{
				cout << "归并排序结果：" << endl;
				MergeSort(data, 0, n - 1);
				disp(n, data);
				break;
			}
			//插入排序
			case 3:
			{
				cout << "插入排序结果：" << endl;
				insert(n, data);
				disp(n, data);
				break;
			}
			//选择排序
			case 4:
			{
				cout << "选择排序结果：" << endl;
				select(n, data);
				disp(n, data);
				break;
			}
			//桶排序
			case 5:
			{
				cout << "桶排序结果：" << endl;
				bucket(n, data);
				break;
			}
			//基数排序
			case 6:
			{
				cout << "基数排序结果：" << endl;
				radix(n, data);
				disp(n, data);
				break;
			}
			//计数排序
			case 7:
			{
				cout << "计数排序结果：" << endl;
				countsort(n, data);
				disp(n, data);
				break;
			}
			//堆排序
			case 8:
			{
				cout << "堆排序结果：" << endl;
				heapSort(data, n, n);
				disp(n, data);
				break;
			}
			default:
				cout << "Worry input!(maybe)" << endl;
			}
		}

	}
	return 0;
}

//快速排序
void quick(int a[], int low ,int high)
{	
	if (low < high)//判断是否需要排序
	{
		int i = low;
		int j = high;
		int x = a[low];//保存基准数
		while (i < j)
		{
			//j先从右往左找
			while (i < j&&a[j] >= x)
				j--;//a[j]大于x符合条件,到下一个
					//不符合则说明找到了用于交换的数
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			
			//i从左往右
			while (i < j&&a[i] <= x)
				i++;//a[i]小于x符合条件,到下一个
					//不符合则说明找到了用于交换的数
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}			
		}
		a[i] = x;
		
		//递归
		quick(a, low, i - 1);//排i左边
		quick(a, i + 1, high);//排i右边
	}				
}

//归并排序
void Merge(int* numbers, int start, int mid, int end) 
{
	int* temp = new int[end - start + 1];	//第一步，申请空间，大小为两个排序序列之和
	int fistSectionIndex = start;			//第二步，设定两个待排序列的起始位置的索引
	int secondSectionIndex = mid + 1;
	int tempIndex = 0;	//所申请空间的索引

	while (fistSectionIndex <= mid && secondSectionIndex <= end) {	//直到两个序列中有一个到达终止位置
		if (numbers[fistSectionIndex] <= numbers[secondSectionIndex])//在左右两组中挑选小的放入结果
			temp[tempIndex++] = numbers[fistSectionIndex++];
		else
			temp[tempIndex++] = numbers[secondSectionIndex++];
	}

	while (fistSectionIndex <= mid)
		temp[tempIndex++] = numbers[fistSectionIndex++];

	while (secondSectionIndex <= end)
		temp[tempIndex++] = numbers[secondSectionIndex++];

	for (int j = 0; j < tempIndex; ++j)		//将合并且排序好的元素，复制到原来的数组中，释放临时数组空间
		numbers[start + j] = temp[j];

	delete[] temp;
}

void MergeSort(int* numbers, int start, int end) 
{
	if (numbers == NULL || start >= end)
		return;

	int mid = (start + end) / 2;

	MergeSort(numbers, start, mid);		//递归排序numbers[start,mid](首先从上往下递归分解到最底层元素个数为1的情况)
	MergeSort(numbers, mid + 1, end);	//递归排序numbers[mid + 1,end](首先从上往下递归分解到最底层元素个数为1的情况)

	Merge(numbers, start, mid, end);	//然后递归的从下往上合并排序
}

//插入排序
void insert(int n, int a[])
{
	for (int i = 1; i < n; i++)
	{
		int itemp = i;
		for (int j = i - 1; j >= 0; j--)
		{			
			if (a[itemp] < a[j])
			{
				int temp = a[itemp];
				a[itemp] = a[j];
				a[j] = temp;
				itemp--;
			}
			else break;
		}
		disp(n, a);
	}
}

//选择排序
void select(int n, int a[])
{
	for (int i = 0; i < n - 1; i++)
	{
		for(int j=i+1;j<n;j++)
			if (a[j] < a[i])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			else continue;
	}
}

//桶排序
void bucket(int n,int a[])
{
	const int x = 10;//0~10以内数字
	int t,data[11];//11为x+1

	//初始化数组为0
	for (int i = 0; i <= x; i++)
		data[i] = 0;
			
	for (int i = 0; i < n; i++)
	{
		t=a[i];
		data[t]++;
	}
	disp(n, data);
	for (int i = 0; i <= x; i++)
	{
		for (int j = 1; j <= data[i]; j++)//大于0才输出，有几个就输出几次，a[i]为0说明没有这个值出现
			cout << i << " ";
		cout << endl;
	}	
}

//基数排序
void radix(int n, int a[])
{
	//先计算位数
	int sum=0;
	int left;//用来除10
	
	for (int i = 0; i < n; i++)
	{
		int temp = 1;			
		left = a[i] / 10;
		while (left >0)//除法舍弃小数
		{
			temp++;//位数+1
			left /= 10;			
		}
		//a[i]位数计算完毕，与sum比较，sum小则替换		
		if (sum < temp)
			sum = temp;		
	}	
	
	//排序
	int* tmp = new int[n];//最后要复制给a[]
	int count[10]; //桶
	int i, j, k;
	int radix = 1;//用于当除数
	for (i = 1; i <= sum; i++) //进行sum次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器

		for (j = 0; j < n; j++)
		{
			k = (a[j] / radix) % 10; //遍历a[],统计每个值的出现次数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //计算尾数为i时的右边界，存在count里,此时的count已经不是用来计数的了
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];//此时索引为上面计算出来的边界-1
			count[k]--;//尾数取k的个数少了一个
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到data中
			a[j] = tmp[j];
		radix = radix * 10;
	}	
	delete[] tmp;
}

//计数排序
void countsort(int n, int a[])
{
	//找最大值
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	
	//排序
	int* tmp = new int[n];//申请和a一样大
	int* count = new int[max+1];//申请max+1
	int i, j, k;

	for ( i = 0; i <= max; ++i)//没初始化会报错
		count[i] = 0;
			
	for (j = 0; j < n; j++)
	{
		k = a[j]; //遍历a[],统计每个值的出现次数
		count[k]++;
	}
	for (j = 1; j <= max; j++)
		count[j] = count[j - 1] + count[j]; //计算尾数为i时的右边界，存在count里,此时的count已经不是用来计数的了
	for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
	{
		k = a[j];
		tmp[count[k] - 1] = a[j];//此时索引为上面计算出来的边界-1
		count[k]--;//尾数取k的个数少了一个
		}
	for (j = 0; j < n; j++) //将临时数组的内容复制到data中
		a[j] = tmp[j];

	delete[] tmp;
	delete[] count;
}

//堆排序
void heapSort(int a[], int n,int size)
{
	int i;
	buildMaxHeap(a, n,size);
	for (i = size; i > 1; i--)
	{
		swap(a[0], a[i - 1]);//交换最大值到末尾
		size = size - 1;//无序数组的大小-1
		maxHeap(a, 1,size);//对剩下的无序数组再来查找最大值
	}
}
//分节点
void buildMaxHeap(int a[], int n,int size)
{
	int i = n / 2;//i为二分支节点数
	for (i; i > 0; i--)//循环每个节点，把每个节点替换为分支下最大值，从右往左
		maxHeap(a, i,size);
}
//把每个节点替换为分支下最大值
void maxHeap(int a[], int n,int size)
{
	int leftChild, rightChild, largest;
	leftChild = 2 * n;
	rightChild = 2 * n + 1;	
	if (leftChild <= size && a[leftChild - 1] > a[n - 1])//如果左子存在，且值大于父节点，则交换
		largest = leftChild;
	else
		largest = n;
	if (rightChild <= size && a[rightChild - 1] > a[largest - 1])//如果右子存在，且值大于当前最大值，则交换
		largest = rightChild;
	if (largest != n)//如果最大值的位置不在传入节点位置，则交换，
	{
		swap(a[n - 1], a[largest - 1]);
		maxHeap(a, largest,size); //递归到用于交换的值原来的位置继续判断,从上往下
	}
}




