#include <iostream>
#include<algorithm>
using namespace std;

/*--------------��������--------------*/
void disp(int n, int a[]);//�������
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

//�������
void disp(int n, int a[])
{
	for (int z = 0; z < n; z++)
		cout << a[z] << " ";//����+�ո�}
	cout << endl;
}

int main()
{
	int group = 5;//��������
	for (int m = 0; m < group; m++)
	{
		//��������
		int n;
		cout << "���������ݸ�����" << endl;
		cin >> n;

		int data[20];
		cout << "���������ݣ�" << endl;
		for (int i = 0; i < n; i++)
			cin >> data[i];

		int mod;
		cout << "����������ʽ���:" << endl;
		cout << "1-��������" << endl;
		cout << "2-�鲢����" << endl;
		cout << "3-��������" << endl;
		cout << "4-ѡ������" << endl;
		cout << "5-Ͱ����" << endl;
		cout << "6-��������" << endl;
		cout << "7-��������" << endl;
		cout << "8-������" << endl;
		cin >> mod;

		if (n == 1)//���ֻ��һ������ֱ�����
			cout << data[0] << endl;
		else
		{
			switch (mod)
			{
				//��������	
			case 1:
			{
				quick(data, 0, n - 1);
				cout << "������������" << endl;
				disp(n, data);
				break;
			}
			//�鲢����
			case 2:
			{
				cout << "�鲢��������" << endl;
				MergeSort(data, 0, n - 1);
				disp(n, data);
				break;
			}
			//��������
			case 3:
			{
				cout << "������������" << endl;
				insert(n, data);
				disp(n, data);
				break;
			}
			//ѡ������
			case 4:
			{
				cout << "ѡ����������" << endl;
				select(n, data);
				disp(n, data);
				break;
			}
			//Ͱ����
			case 5:
			{
				cout << "Ͱ��������" << endl;
				bucket(n, data);
				break;
			}
			//��������
			case 6:
			{
				cout << "������������" << endl;
				radix(n, data);
				disp(n, data);
				break;
			}
			//��������
			case 7:
			{
				cout << "������������" << endl;
				countsort(n, data);
				disp(n, data);
				break;
			}
			//������
			case 8:
			{
				cout << "����������" << endl;
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

//��������
void quick(int a[], int low ,int high)
{	
	if (low < high)//�ж��Ƿ���Ҫ����
	{
		int i = low;
		int j = high;
		int x = a[low];//�����׼��
		while (i < j)
		{
			//j�ȴ���������
			while (i < j&&a[j] >= x)
				j--;//a[j]����x��������,����һ��
					//��������˵���ҵ������ڽ�������
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			
			//i��������
			while (i < j&&a[i] <= x)
				i++;//a[i]С��x��������,����һ��
					//��������˵���ҵ������ڽ�������
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}			
		}
		a[i] = x;
		
		//�ݹ�
		quick(a, low, i - 1);//��i���
		quick(a, i + 1, high);//��i�ұ�
	}				
}

//�鲢����
void Merge(int* numbers, int start, int mid, int end) 
{
	int* temp = new int[end - start + 1];	//��һ��������ռ䣬��СΪ������������֮��
	int fistSectionIndex = start;			//�ڶ������趨�����������е���ʼλ�õ�����
	int secondSectionIndex = mid + 1;
	int tempIndex = 0;	//������ռ������

	while (fistSectionIndex <= mid && secondSectionIndex <= end) {	//ֱ��������������һ��������ֹλ��
		if (numbers[fistSectionIndex] <= numbers[secondSectionIndex])//��������������ѡС�ķ�����
			temp[tempIndex++] = numbers[fistSectionIndex++];
		else
			temp[tempIndex++] = numbers[secondSectionIndex++];
	}

	while (fistSectionIndex <= mid)
		temp[tempIndex++] = numbers[fistSectionIndex++];

	while (secondSectionIndex <= end)
		temp[tempIndex++] = numbers[secondSectionIndex++];

	for (int j = 0; j < tempIndex; ++j)		//���ϲ�������õ�Ԫ�أ����Ƶ�ԭ���������У��ͷ���ʱ����ռ�
		numbers[start + j] = temp[j];

	delete[] temp;
}

void MergeSort(int* numbers, int start, int end) 
{
	if (numbers == NULL || start >= end)
		return;

	int mid = (start + end) / 2;

	MergeSort(numbers, start, mid);		//�ݹ�����numbers[start,mid](���ȴ������µݹ�ֽ⵽��ײ�Ԫ�ظ���Ϊ1�����)
	MergeSort(numbers, mid + 1, end);	//�ݹ�����numbers[mid + 1,end](���ȴ������µݹ�ֽ⵽��ײ�Ԫ�ظ���Ϊ1�����)

	Merge(numbers, start, mid, end);	//Ȼ��ݹ�Ĵ������Ϻϲ�����
}

//��������
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

//ѡ������
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

//Ͱ����
void bucket(int n,int a[])
{
	const int x = 10;//0~10��������
	int t,data[11];//11Ϊx+1

	//��ʼ������Ϊ0
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
		for (int j = 1; j <= data[i]; j++)//����0��������м�����������Σ�a[i]Ϊ0˵��û�����ֵ����
			cout << i << " ";
		cout << endl;
	}	
}

//��������
void radix(int n, int a[])
{
	//�ȼ���λ��
	int sum=0;
	int left;//������10
	
	for (int i = 0; i < n; i++)
	{
		int temp = 1;			
		left = a[i] / 10;
		while (left >0)//��������С��
		{
			temp++;//λ��+1
			left /= 10;			
		}
		//a[i]λ��������ϣ���sum�Ƚϣ�sumС���滻		
		if (sum < temp)
			sum = temp;		
	}	
	
	//����
	int* tmp = new int[n];//���Ҫ���Ƹ�a[]
	int count[10]; //Ͱ
	int i, j, k;
	int radix = 1;//���ڵ�����
	for (i = 1; i <= sum; i++) //����sum������
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //ÿ�η���ǰ��ռ�����

		for (j = 0; j < n; j++)
		{
			k = (a[j] / radix) % 10; //����a[],ͳ��ÿ��ֵ�ĳ��ִ���
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //����β��Ϊiʱ���ұ߽磬����count��,��ʱ��count�Ѿ�����������������
		for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
		{
			k = (a[j] / radix) % 10;
			tmp[count[k] - 1] = a[j];//��ʱ����Ϊ�����������ı߽�-1
			count[k]--;//β��ȡk�ĸ�������һ��
		}
		for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
			a[j] = tmp[j];
		radix = radix * 10;
	}	
	delete[] tmp;
}

//��������
void countsort(int n, int a[])
{
	//�����ֵ
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	
	//����
	int* tmp = new int[n];//�����aһ����
	int* count = new int[max+1];//����max+1
	int i, j, k;

	for ( i = 0; i <= max; ++i)//û��ʼ���ᱨ��
		count[i] = 0;
			
	for (j = 0; j < n; j++)
	{
		k = a[j]; //����a[],ͳ��ÿ��ֵ�ĳ��ִ���
		count[k]++;
	}
	for (j = 1; j <= max; j++)
		count[j] = count[j - 1] + count[j]; //����β��Ϊiʱ���ұ߽磬����count��,��ʱ��count�Ѿ�����������������
	for (j = n - 1; j >= 0; j--) //������Ͱ�м�¼�����ռ���tmp��
	{
		k = a[j];
		tmp[count[k] - 1] = a[j];//��ʱ����Ϊ�����������ı߽�-1
		count[k]--;//β��ȡk�ĸ�������һ��
		}
	for (j = 0; j < n; j++) //����ʱ��������ݸ��Ƶ�data��
		a[j] = tmp[j];

	delete[] tmp;
	delete[] count;
}

//������
void heapSort(int a[], int n,int size)
{
	int i;
	buildMaxHeap(a, n,size);
	for (i = size; i > 1; i--)
	{
		swap(a[0], a[i - 1]);//�������ֵ��ĩβ
		size = size - 1;//��������Ĵ�С-1
		maxHeap(a, 1,size);//��ʣ�µ��������������������ֵ
	}
}
//�ֽڵ�
void buildMaxHeap(int a[], int n,int size)
{
	int i = n / 2;//iΪ����֧�ڵ���
	for (i; i > 0; i--)//ѭ��ÿ���ڵ㣬��ÿ���ڵ��滻Ϊ��֧�����ֵ����������
		maxHeap(a, i,size);
}
//��ÿ���ڵ��滻Ϊ��֧�����ֵ
void maxHeap(int a[], int n,int size)
{
	int leftChild, rightChild, largest;
	leftChild = 2 * n;
	rightChild = 2 * n + 1;	
	if (leftChild <= size && a[leftChild - 1] > a[n - 1])//������Ӵ��ڣ���ֵ���ڸ��ڵ㣬�򽻻�
		largest = leftChild;
	else
		largest = n;
	if (rightChild <= size && a[rightChild - 1] > a[largest - 1])//������Ӵ��ڣ���ֵ���ڵ�ǰ���ֵ���򽻻�
		largest = rightChild;
	if (largest != n)//������ֵ��λ�ò��ڴ���ڵ�λ�ã��򽻻���
	{
		swap(a[n - 1], a[largest - 1]);
		maxHeap(a, largest,size); //�ݹ鵽���ڽ�����ֵԭ����λ�ü����ж�,��������
	}
}




