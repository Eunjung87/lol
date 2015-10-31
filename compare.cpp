#include <iostream>
using namespace std;

int ExchangeCnt=0;
int MergeCnt=0;
int QuickCnt=0;
int exArr[10];
int quArr[11];
int merArr1[10];
int merArr2[10];

void swap(int a[],int i, int j){
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int partition(int a[], int p, int r){
    int i = p;
    int x = a[p];
    int j = r;
    while(1){
        
    	while(a[i]<= x){QuickCnt++;i++;}
    	while(a[j]>x){QuickCnt++;j--;}
    	if(i<j)
    		swap(a[i],a[j]);
        else break;    	
    }
    a[p]=a[j];
    a[j]=x;
    return j;
}

void quickSort(int a[], int p, int r){
	int q;
	if(p < r){
		q = partition(a,p,r);
		quickSort(a,p,q-1);      //왼쪽부분 정렬  
		quickSort(a,q+1,r);      // 오른쪽부분 정렬
	}

}

void bubbleSort(int a[],int n){
	int last;
	for(last = n; last > 1; last--){ // n-1 번 돈다.
		for(int i = 0; i < last-1 ; i++){ 
			ExchangeCnt++;
			if (a[i] < a[i+1]){swap(a,i,i+1);}
		}// last-1 번 만큼 돈다.
	}
}

void merge(int low, int mid, int high){
	int h = low;
	int i = low;
	int j = mid+1;

	while(h <= mid && j <= high){
		MergeCnt++;
		if(merArr1[h] <= merArr1[j])
			{merArr2[i]= merArr1[h]; h++;}
		else
			{merArr2[i]= merArr1[j]; j++;}
		i++;
	}
	if( h > mid)
		for(int k=j;k<=high;k++){merArr2[i]=merArr1[k];i++;}
	else
		for(int k=h;k<=mid;k++){merArr2[i]=merArr1[k];i++;}
    for(int k=low;k<=high;k++){merArr1[k]=merArr2[k];}
	
}

void mergeSort(int low, int high){
	int mid;

	if( low < high){
		mid = (low + high)/2;
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merge(low, mid, high);
	}
}

int main(){
    int n=0;
    int exAve,quAve,merAve;
    while(n<20){

    for(int i=0 ; i < 10;i++){
    	cin >> exArr[i];
    	quArr[i] = exArr[i];
    	merArr1[i] = exArr[i];
    	merArr2[i] = exArr[i];
    }
    quArr[10]=200;
    bubbleSort(exArr,10);
    mergeSort(0,9);
    quickSort(quArr,0,10);
    
    n++;
    }

    exAve  = ExchangeCnt/20;
    quAve  = QuickCnt/20;
    merAve = MergeCnt/20;

    cout << "Average # of comparisons for Exchange Sort: " << exAve << endl;
    cout << "Average # of comparisons for merge Sort: " << merAve << endl;
    cout << "Average # of comparisons for Quick Sort: " << quAve << endl;

    return 0;
}

