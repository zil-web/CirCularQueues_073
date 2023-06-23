#include <iostream>
using namespace std;

class queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter the number: ";
		cin >> num;
		cout << endl;

		// cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
			cout << "\n Queue overflow\n";
		return;

		// cek apakah antrian kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			// jika REAR beada di posisi terakhir maka array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR = 1;
		}
		queue_array[REAR] = num;

	}

	void remove() {
		// cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "queue underflow\n";
			return;
		}
		cout << "\nTHe elemant deleted from the queue is: " << queue_array[FRONT] << "\n";

		//cek jika antrian  hanya memiliki satu elemen
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			// jika elemen yang di hapus berada di posisi terakhir array, kembali ke awal
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		// cek apakah antrian kosong 
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}
		cout << "\nElements in the queue are ..\n";

		// jika FRONT_position <= REAR_position, iterasi dari FRONT hingga REAR
		if (FRONT_position <= REAR_position) {
			cout << "queue is empty\n";
			return;
		}

		cout << "\nelements in the queue are..\n";

		// jika FRONT_position > REAR_position, iterasi dari FRONT hingga akhir array 
		while (FRONT_position <= REAR_position){
			cout << queue_array[FRONT_position] << "  ";
			FRONT_position++;
		}
		cout << endl;
	}
};

int main() {
	queues q;
	char ch;

	while (true) {
		try {
			cout << "menu" << endl;
			cout << "1. implement insert operation" << endl;
			cout << "2. implement delete operation" << endl;
			cout << "3. Display values" << endl;
			cout << "4. exit" << endl;
			cout << "Enter your choice (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {

				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3' : {
						q.display();
				break;
			}
			case '4': {
			return 0;				
			}

			default: {
				cout << "invalid option@@" << endl;
				break;	
			}
			}
		}
		catch (exception& e) {
			cout << "check for the values entered " << endl;
		}
	}
	return 0;
}