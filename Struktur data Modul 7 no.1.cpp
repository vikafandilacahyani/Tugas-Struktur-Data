#include <iostream>
#define MAX 20
using namespace std;

struct Queue {
	int head, tail, data[MAX];
}Queue;

bool isFull() {
	return Queue.tail == MAX;
}

bool isEmpty() {
	return Queue.tail == 0;
}

void printQueue() {
	if (isEmpty()) {
    cout << "Antrian kosong"<<endl;
	}
	else {
		cout << "QUEUE : ";
		for (int i = Queue.head; i < Queue.tail; i++)
			cout << Queue.data[i] << " " ;
		cout << endl;
  }
}

void enqueue() {
	if (isFull())
	{
		cout << "Antrian penuh!"<<endl;
	}
	else {
		int data;
		cout << "Masukkan Data : ";cin >> data;
		Queue.data[Queue.tail] = data;
		Queue.tail++;
		cout << "Data ditambahkan\n";
		printQueue();
	}
}

void operasidata(int pill){

 int jum=0;
 int b=Queue.tail+1;

 float avg;

 if(isEmpty()==0){
 for(int i=Queue.head;i<=Queue.tail;i++){
 jum=jum+Queue.data[i];
 }
 avg=jum/b;
 switch(pill){
 case 1:
 cout<<"jumlah datanya ="<<jum;
 break;
 case 2:
 cout<<"Rata-rata datanya ="<<avg;
 break;
 case 3:
 cout<<"banyak datanya ="<<Queue.tail+1;
 break;
 default:
 break;
 }
 }else{
 cout<<"data kosong!\n";
 }
}

void dequeue() {
	if (isEmpty())
	{
		cout << "Antrian masih kosong"<<endl;
	}
	else{
		cout << "Mengambil data \"" << Queue.data[Queue.head] << "\"..." << endl;
		for (int i = Queue.head; i < Queue.tail; i++)
        Queue.data[i] = Queue.data[i + 1];
		Queue.tail--;
		printQueue();
	}
}

void clear(){
    Queue.tail=Queue.head=-1;
    cout<<"Data dihapus";
}

int main() {
	int choose;
	do
	{
		cout <<"**********************\n"
			<< "   Menu Antrian\n"
			<< "**********************\n"
			<< " [1] Enqueue \n"
			<< " [2] Dequeue\n"
			<< " [3] Display\n"
			<< " [4] Clear\n"
			<< " [5] Banyak Data\n"
			<< " [6] Jumlah Data\n"
			<< " [7] Rata rata\n"
			<< " [8] Keluar \n\n"
			<< "**********************\n"
			<< "Masukkan pilihan : "; cin >> choose;
		switch (choose)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
        case 3:
			printQueue();
			break;
        case 4:
			clear();
			break;
        case 5:
			operasidata(3);
			break;
        case 6:
			operasidata(1);
			break;
        case 7:
			operasidata(2);
			break;
        case 8:
			dequeue();
			break;
		default:
			cout << "Pilihan tidak tersedia";
			break;
		}
	} while (choose !=8);
	return 0;
}
