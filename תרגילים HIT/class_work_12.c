#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct clients {
    char ID[10];
    char name[30];
    double total;
} Client;

typedef struct clientsBIN {
    char ID[10];
    char name[30];
    double total;
} ClientBIN;

int updateClientMoney_txt(char* filename, char IDstr[], double newBuy);
void createBinaryFromText(char* filename, char* filenameBIN);
int updateClientMoney_bin(char* filename, char IDstr[], double newBuy);
void printBinaryFile(char* filename);

int main (){

    char IDstr[10] = "330578795";
    double newBuy = 200.10;
    updateClientMoney_txt("Files/class_work_12_files/client_money.txt", IDstr, newBuy);

    createBinaryFromText("Files/class_work_12_files/client_money.txt", "Files/class_work_12_files/client_money.bin");

    char IDstrBIN[10] = "330578795";
    double newBuyBIN = 200.10;
    updateClientMoney_bin("Files/class_work_12_files/client_money.bin", IDstrBIN, newBuyBIN);

    printBinaryFile("Files/class_work_12_files/client_money.bin");

    return 0;
}


int updateClientMoney_txt(char* filename, char IDstr[], double newBuy) {

    Client* clients = (Client*)malloc(sizeof(Client) * 3);
    if (clients == NULL) {
        printf("Memory allocation error!");
        return -1;
    }
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return FALSE;
    }
    for (int i = 0; i < 3; i++) {
        fscanf(file, "%9s %30s %lf", clients[i].ID, clients[i].name, &clients[i].total);
    }
    fclose(file);
    // check if clients array really full
    for (int i = 0; i < 3; i++) {
        printf("ID: %9s, Name: %30s, total: %8.2lf\n", clients[i].ID, clients[i].name, clients[i].total);
    }
    file = fopen("Files/class_work_12_files/client_money.txt", "w");
    for (int i = 0; i < 3; i++) {
        if (strcmp(clients[i].ID, IDstr) == 0) {
            printf("ID: %s, is found!\n", clients[i].ID);
            clients[i].total += newBuy;
            for (int j = 0; j < 3; j++) {
                fprintf(file, "%9s %30s %8.2lf\n", clients[j].ID, clients[j].name, clients[j].total);
            }
            printf("File updated successfully\n");
            fclose(file);
            free(clients);
            return TRUE;
        }
    }
    fclose(file);
    free(clients);
    return FALSE;
}

void createBinaryFromText(char* filename, char* filenameBIN) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    FILE* fileBIN = fopen(filenameBIN, "wb");
    if (fileBIN == NULL) {
        printf("Error opening file %s\n", filenameBIN);
        return;
    }
    for (int i = 0; i < 3; i++) {
        Client client;
        if (fscanf(file, "%9s %30s %lf", client.ID, client.name, &client.total) != 3) {
            printf("Error reading line %d from text file. Skipping.\n", i + 1);
            continue;
        }
        fwrite(&client, sizeof(Client), 1, fileBIN);
    }
    fclose(file);
    fclose(fileBIN);
}

int updateClientMoney_bin(char* filename, char IDstr[], double newBuy) {

    Client client;
    FILE* file = fopen(filename, "r+b");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return FALSE;
    }
    int index = 0;
    while (fread(&client, sizeof(Client), 1, file)) {
        if (strcmp(client.ID, IDstr) == 0) {
            client.total += newBuy;
            fseek(file, index * sizeof(Client), SEEK_SET);
            fwrite(&client, sizeof(Client), 1, file);
            printf("Updated client: %s\n", client.ID);
            fclose(file);
            return TRUE;
        }
        index++;
    }
    fclose(file);
    return FALSE;
}

void printBinaryFile(char* filename) {

    Client client;
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }
    printf("now printing binary client: \n");
    while (fread(&client, sizeof(Client), 1, file) == 1) {
        printf("%9s %30s %8.2lf\n", client.ID, client.name, client.total);
    }
    fclose(file);
}