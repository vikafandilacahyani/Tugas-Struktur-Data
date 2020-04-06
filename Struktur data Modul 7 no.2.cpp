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
		cout<< "**********************************\n"
			<< "   Antrian Parkiran Mobil\n"
			<< "**********************************\n"
			<< " [1] Antrian Parkir Mobil \n"
			<< " [2] Keluarkan Mobil\n"
			<< " [3] Tampilkan Antrian Mobil\n"
			<< " [4] Exit \n\n"
			<< "**********************************\n"
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
			dequeue();
			break;
		default:
			cout << "Pilihan tidak tersedia";
			break;
		}
	} while (choose !=4);
	return 0;
}
