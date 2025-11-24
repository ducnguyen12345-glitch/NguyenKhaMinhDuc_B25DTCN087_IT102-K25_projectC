#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 100

struct Room {
	char roomId[5];
	int type; //Loai phòng (1: Ðon, 2: Ðôi).
	double price;
	int status; // Trang thái (0: Trong, 1: Ðang o, 2: Bao tri)
};

struct Booking {
	char bookId[20];
	char room[5];
	char customerName[50];
	int days;
	double totalCost;
};

struct Room rooms[MAX];
int roomCount = 0;

struct Booking bookings[MAX];
int bookingCount = 0;

void addRoom();
void updateRoom();
void lockRoom();
void displayRoom();
void searchRoom();
void sortRoomByPrice();
void checkIn();
void bookingHistory();

int findRoomIndex(char roomId[]);
void pauseConsole();

int main() {
	int choice;
	do {
		printf("\n==========MENU==========\n");
		printf("1. Them phong moi");
		printf("\n2. Cap nhat phong");
		printf("\n3. Bao tri phong");
		printf("\n4. Hien thi danh sach");
		printf("\n5. Tim kiem");
		printf("\n6. Sap xep danh sach phong");
		printf("\n7. Check-in");
		printf("\n8. Lich su thue");
		printf("\n0. Thoat");
		printf("\nChon chuc nang: ");
		scanf("%d", &choice);
		getchar();
		
		switch(choice) {
			case 1:
				addRoom();
				break;
			case 2:
				updateRoom();
				break;
			case 3:
				
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:
				
				break;
			case 7:
				
				break;
			case 8:
				
				break;
			case 0:
				printf("Thoat chuong trinh!\n");
				break;
			default: 
				printf("Lua chon khong hop le!\n");
		}
	}while(choice != 0);
	return 0;
}

int findRoomIndex(char roomId[]) {
	for(int i=0; i<roomCount; i++) {
		if(strcmp(rooms[i].roomId,roomId)==0) {
			return i;
		}
	}
	return -1;
}

void addRoom() {
	printf("\n-----Them phong moi-----\n");
	
	if(roomCount > MAX) {
		printf("Khong the them phong! Danh sach da day");
		return;
	}
	struct Room newRoom;
    printf("Nhap so phong: ");
    scanf("%s", newRoom.roomId);
    getchar();

    if (strlen(newRoom.roomId) == 0) {
        printf("So phong trong! Vui long nhap so phong\n");
        return;
    }
    if (findRoomIndex(newRoom.roomId) != -1) {
        printf("So phong da ton tai!\n");
        return;
    }

    printf("Nhap loai phong (1: Don, 2: Doi): ");
    scanf("%d", &newRoom.type);

    printf("Nhap gia phong: ");
    scanf("%lf", &newRoom.price);

    newRoom.status = 0; //Mac dinh la phong trong, hien tai phong chua duoc dat

    rooms[roomCount++] = newRoom;

    printf("Them phong thanh cong!\n");
}

void updateRoom() {
	printf("\n-----Cap nhat phong-----\n");
	
	char findRoom[5];
	printf("Nhap so phong can cap nhat: ");
	scanf("%s", findRoom);
	getchar();
	
	int index = findRoomIndex(findRoom);
	if(index==-1) {
		printf("Khong tim thay phong!\n");
		return;
	}
	
	struct Room *room = &rooms[index];
	
	printf("Thong tin hien tai cua phong %s\n", room->roomId);
	printf("Loai phong: %d (1: Don, 2: Doi)\n", room->type);
	printf("Gia phong: %.2lf", room->price);
	printf("Trang thai: ");
	switch(room->status) {
		case 0:
			printf("Trong\n");
			break;
		case 1:
			printf("Dang o\n");
			break;
		case 3:
			printf("Bao tri\n");
			break;
	}
	printf("\nCap nhat loai phong(1: Don, 2: Doi): ");
	scanf("%d", &room->type);
	
	printf("Cap nhat gia phong: ");
	scanf("%lf", room->price);
	
	printf("Cap nhat thanh cong!");
	
}
