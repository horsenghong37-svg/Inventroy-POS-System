#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Product{
    int id;
    string name;
    string categroy;
    float price;
    int stock;
};

struct Sale{
    int product_id;
    int qty;
    float discount; 
};

const int Max = 100;

Sale sale[Max];
int sale_count = 0;
int cart_start = 0; 

Product product[Max];
int product_count = 0;

int option, up, sell;
int option_sale;
char add;

void add_product(){
    cout << "============= [[ Add Product ]] ===============\n";
    product[product_count].id = product_count + 1;
    cout << "    ==> ID Product (auto): " << product[product_count].id << endl;
    cout << "[+] ==> Name of Product: "; getline(cin, product[product_count].name);
    cout << "[+] ==> Categroy of Product: "; getline(cin, product[product_count].categroy);

    while(1){ 
        cout << "[+] ==> Price of Prduct ($): "; cin >> product[product_count].price;
        if(product[product_count].price < 0){
            cout << "\n[ERROR] Price can't be negative, try again\n\n";
            continue;
        }
        break;
    }
    while(1){ 
        cout << "[+] ==> Stock of Product (qty): "; cin >> product[product_count].stock;
        if(product[product_count].stock < 0){
            cout << "\n[ERROR] Stock can't be negative, try again\n\n";
            continue;
        }
        break;
    }

    cout << "\n [SUCCESS] Product Added in system\n";
    system("pause");

    product_count++;
} 

void show_product(){
    if(product_count == 0){
        cout << "\n\t[!] Don't have Product in Stock!\n";
        return;
    }
    cout << "    ============= [[ Show All Product ]] ===============\n";
    cout << "------------------------------------------------------------\n";
    cout << left << setw(8) << "ID"
                 << setw(20) << "Name Product"
                 << setw(15) << "Categroy"
                 << setw(10) << "Price"
                 << setw(10) << "Stock" << endl;
    cout << "------------------------------------------------------------\n";
    for(int i = 0; i < product_count; i++){
    cout << left << setw(8) << product[i].id
                 << setw(20) << product[i].name
                 << setw(15) << product[i].categroy
                 << setw(10) << product[i].price
                 << setw(10) << product[i].stock << endl;
    }
    cout << "------------------------------------------------------------\n";
}

void delete_product(){
    if(product_count == 0){
        cout << "\n\t[!] Don't have Product in Stock!\n";
        system("pause");
        return;
    }

    show_product();

    int del;
    cout << "[+] Enter ID Product to Delete: "; cin >> del;
    cin.ignore();

    bool found = false;
    for(int i = 0; i < product_count; i++){
        if(del == product[i].id){
            for(int j = i; j < product_count - 1; j++){
               product[j] = product[j + 1];
            }   
            cout << "\n\t[SUCCESS] Delete ID Product Already\n";
            system("pause");
            product_count--;

            found = true;
            break;  
        }
    }
    if(!found){
        cout << "\n\t[!] ID Product " << del << " Can't found in system\n";
        system("pause");
    }
}

void search_ID(){
    if(product_count == 0){
        cout << "\n\t[!] Don't have Product in Stock!\n";
        system("pause");
        return;
    }

    int search;
    cout << "[+] Enter ID Product Would you like to research: "; cin >> search;
    cin.ignore();

    bool found = false;
    for(int i = 0; i < product_count; i++){
        if(search == product[i].id){
            cout << "\t[SUCCESS] ID Produce funnd in system\n";
            cout << "````````````````````````````````````````````````````````````````````````````````````````````````````````\n";
            cout << "ID Product : " << product[i].id;
            cout << "   |   Product Name: " << product[i].name;
            cout << "   |   Categroy: " << product[i].categroy;
            cout << "   |   Price : $" << product[i].price;
            cout << "   |   Stock : " << product[i].stock << endl;
            cout << "````````````````````````````````````````````````````````````````````````````````````````````````````````\n";
            found = true;
            break;
        }
    }
    if(!found){
        cout << "\n\t[!] Can't found ID Product in system\n";
        system("pause");
    }
}

void update_product(){
    if(product_count == 0){
        cout << "\n [!] Don't have Product in stock\n";
        system("pause"); 
        return;
    }
    show_product();

    int update; 
    cout << "[+] Enter the ID Product to update: "; cin >> update;
    cin.ignore();

    bool found = false;
    for(int i = 0; i < product_count; i++){
        if(update == product[i].id){
            found = true;
            cout << "\n\t[SUCCESE] ID Product found in system\n";
            cout << "\n\t::::: [[ Would you like to Update ]]::::::\n";
            do{
                cout << "-----------------------------------------------------------------------------------------------------\n";
                cout << "ID : " << product[i].id << "   |   Product Name : " << product[i].name << "   |   Categroy : " << product[i].categroy;
                cout << "   |   Price : $" << product[i].price << "   |   Stock : " << product[i].stock << endl;
                cout << "-----------------------------------------------------------------------------------------------------\n";
                cout << "==> 1. Update New Product Name\n";
                cout << "==> 2. Update New Categroy\n";
                cout << "==> 3. Update New Price\n";
                cout << "==> 4. Update New Stock\n";
                cout << "==> 5. Updaye New ID Product\n";
                cout << "==> 6. Exit to Update Product\n";
                cout << "`````````````````````````````````````````````\n";
                cout << "[+] Would you like to Update Product: "; cin >> up;
                cin.ignore();

                system("cls");
                switch (up){
                    case 1:{
                        cout << "[+] Enter New Name of Product: "; getline(cin, product[i].name);
                        cout << "\n[SUCCESS] Update Name of Product Ready\n";
                        break;
                    }
                    case 2:{
                        cout << "[+] Enter New Categroy of Product: "; getline(cin, product[i].categroy);
                        cout << "\n[SUCCESS] Update Name of Product Ready\n";
                        break;
                    }
                    case 3:{
                        while(1){
                            cout << "[+] Enter New Price of Product: $"; cin >> product[i].price;
                            if(product[i].price < 0){
                                cout << "\n[ERROR] Invaild Input,Pls try Again\n\n";
                                continue;
                            }else{
                                cout << "\n[SUCCESS] Update price of Product Ready\n";
                            }
                            break;
                        }
                        break;
                    }
                    case 4:{
                        while(1){
                            cout << "[+] Enter New Quantity in Stock: "; cin >> product[i].stock;
                            if(product[i].stock <= 0){
                                cout << "\n[ERROR] Invaild Input,Pls try Again\n\n";
                                continue;
                            }
                            else{
                                cout << "\n[SUCCESS] Update Stock of Product Ready\n";
                            }
                            break;
                        }                       
                        break;
                    }
                    case 5:{
                        while(1){
                            cout << "[+] Enter New ID of Product: "; cin >> product[i].id;
                            if(product[i].id <= 0){
                                cout << "\n[ERROR] Invalid Input, Pld try again\n\n";
                                continue;
                            }
                            else{
                                cout << "\n[SUCCESS] Update ID of Product Ready.\n";
                            }
                            break;
                        }
                    }
                    case 6:{
                        cout << "\n\t[SUCCESS] Update Product Readly\n";
                        show_product();
                        break;
                    }
                    default:
                    cout << "\n\t[ERROR] Pls Input only (1-5)! Try Agina!\n\n";
                    system("pause"); 
                }

            }while(up != 6);
            break; 
        }
    }
    if(!found){
        cout << "\n\t[ERROR] ID Prdouct " << update << " Can't found in Product\n\n";
        system("pause");
    }   
}

void Input_inventroy(){
    cout << "\n========================================\n";
    cout << "|   POS System   |   Input Inventroy   |" << endl;
    cout << "========================================\n";
    cout << "=> 1. Add Product\n";
    cout << "=> 2. Show ALL Product\n";
    cout << "=> 3. Delete Product\n";
    cout << "=> 4. Search ID Product\n";
    cout << "=> 5. Update Product in inventroy\n";
    cout << "=> 6. Exit Input Inventroy\n";
    cout << "--------------------------------------------\n";
    cout << "[+] Enter the Option: "; cin >> option;
    cin.ignore();

    system("cls");
    switch(option){
        case 1: {
            add_product();
            break;
        }
        case 2:{
            show_product();
            system("pause");
            break;
        }
        case 3:{
            delete_product();
            break;
        }
        case 4:{
            search_ID();
            break;
        }
        case 5:{
            update_product();
            break;
        }
        case 6:{
            cout << "\n\t==> You have Exited Input Inventroy\n";
            system("pause");
            break;
        }
        default:
        cout << "\n\t[!] Pls input only (1-6)! Try again!\n\n";
        system("pause");
    }
}

void sale_product(){
    if(product_count == 0){
        cout << "````````````````````````````````````````````\n";
        cout << "\t[ERROR] Product can't have in Stock\n";
        cout << "\t[!] You can go to input Product\n";
        cout << "````````````````````````````````````````````\n";
        system("pause");
        return;
    }
    cout << "\n\t========================================\n";
    cout << "\t|   POS System   |   Sale Inventroy   |" << endl;
    cout << "\t========================================\n";

    cart_start = sale_count; 

    while(1){
        show_product();
        cout << "[+] Enter ID Prdouct would like to Sell in Stock: "; cin >> sell;
        cin.ignore();
        bool found = false;
        for(int i = 0; i < product_count; i++){
            if(sell == product[i].id){
                cout << "\n\t[SUCCESS] ID Product found in system\n";
                found = true;
                cout << "=============----------------------------------=================\n";
                cout << "  ID Product : " << product[i].id;
                cout << "   |   Product Name : " << product[i].name;
                cout << "   |   Price : $" << product[i].price << endl;
                cout << "\t::::: [[ Product have in Stock : " << product[i].stock << " ]]::::::\n";
                cout << "=============----------------------------------=================\n";

                int qty;
                while(1){
                    cout << "[+] Enter the Quantity: "; cin >> qty;
                    cin.ignore();
                    if(qty <= 0){ 
                        cout << "\n[ERROR] Quantity must be greater than 0\n";
                        continue;
                    }
                    if(qty > product[i].stock){
                        cout << "\n[ERROR] Product in stock isn't enough\n";
                        continue;
                    }
                    product[i].stock -= qty;
                    break;
                }

                sale[sale_count].product_id = product[i].id;
                sale[sale_count].qty = qty;
                sale_count++;

                cout << "``````````````````````````````````````````````\n";
                cout << "==> You have bought: " << product[i].name << "  |  Qty : " << qty << endl;
                cout << "==> Categroy of Product : " << product[i].categroy << endl;
                cout << "==> Price of a product : $" << product[i].price << endl;
                cout << "``````````````````````````````````````````````\n";
                cout << endl;
                cout << "==> Product Remaining in Stock: " << product[i].stock  << endl;
                system("pause");
                break; 
            }
        }
        if(!found){
            cout << "\n[ERROR] ID Product " << sell << " Can't found in Prduct!\n";
            system("pause");
        }

        cout << endl;
        cout << "==> [?] Would like you to need Product else (Y/N): "; cin >> add;
        if(add == 'y' || add == 'Y'){
            cout << endl;
            continue;
        }else if(add == 'n' || add == 'N'){
            break;
        }
    }

    float discount;
    while(1){
        cout << "[+] Enter Discount of Product(0-100): "; cin >> discount;
        cin.ignore();
        if(discount < 0 || discount > 100){
            cout << "\n\t[ERROR] Pls inputer again!" << endl;
            cout << "[!] Discount don't less than Zreo or Biger than 100!\n\n";
            continue;
        }else{
            cout << "\n\t[SUCCESS] Product Discount(" << discount << "%)" << endl;
        }
        system("pause");
        break;
    }
    sale[cart_start].discount = discount; 
}

void reception_product(){
    if(cart_start == sale_count){ // FIX: check if this transaction actually has items
        cout << "\n\t[!] Product Don't have Pre_Order to Customer!\n\n";
        system("pause");
        return;
    }
    cout << "\n========================================\n";
    cout << "|   POS System   |     RECEPTION       |" << endl;
    cout << "========================================\n";

    float final_total = 0; 
    cout << "---------------------------------------------------------------------------------\n";
    cout << left << setw(8) << "ID"
                 << setw(17) << "Product Name"
                 << setw(15) << "Categroy"
                 << setw(10) << "Qty"
                 << setw(10) << "Price"
                 << setw(10) << "Total" << endl;
    cout << "---------------------------------------------------------------------------------\n";
    for(int j = cart_start; j < sale_count; j++){
        for(int i = 0; i < product_count; i++){
           if(sale[j].product_id == product[i].id){
            float total = product[i].price * sale[j].qty;
            cout << left << setw(8) << product[i].id
                 << setw(17) << product[i].name
                 << setw(15) << product[i].categroy
                 << setw(10) << sale[j].qty
                 << setw(10) << product[i].price
                 << setw(10) << total << endl;
            
                 final_total += total;
            break;
           } 
        }
    }
    cout << "---------------------------------------------------------------------------------\n";
    for(int s = cart_start; s < sale_count; s++){ // FIX: only loop over THIS transaction's items
        for(int i = 0; i < product_count; i++){
            if(sale[s].product_id == product[i].id){ // FIX: match the actual product sold
                cout << "------------------------------------\n";
                cout << "|==> ID Product : #" << product[i].id << endl;
                cout << "------------------------------------\n";
                cout << "+ Product Name : " << product[i].name << endl;
                cout << "+ Categroy Product : " << product[i].categroy << endl;
                cout << "+ " << product[i].name << " = " << sale[s].qty << " x $" << product[i].price << endl;

                float item_total = product[i].price * sale[s].qty;
                cout << "+ The Total : $" << item_total << endl;
                cout << "------------------------------------\n";

                final_total += item_total;
                break;
            }
        }
    }

    float discount = sale[cart_start].discount;
    float discount_per = final_total * (discount / 100);
    float grand_final = final_total - discount_per;

    cout << "+ Discount (%) : " << discount << endl;
    cout << "------------------------------------\n";
    cout << "[+] The Subtotal : $" << final_total << endl;
    cout << "[+] Discount (%): -$" << discount_per << endl;
    cout << "------------------------------------\n";
    cout << "[+] Final Total : $" << grand_final << endl;
    cout << "------------------------------------\n";

    float paid;
    while(1){
        cout << "[+] Paid Money ($): "; cin >> paid;
        if(paid < grand_final){
            cout << "\n---------------------------------------------\n";
            cout << "[ERROR] Sorry,Money Paid not Enough!\n";
            cout << "[-] Pls paid Money again!\n";
            cout << "[-] Remaining Money: $" << (grand_final -= paid) << endl;
            cout << "---------------------------------------------\n";
            continue;
        }
        else{
            cout << "\n---------------------------------------------\n";
            cout << "[SUCCESS] Paid Money Successfully\n";
            cout << "[+] Change Money : $" << (paid - grand_final) << endl;
            cout << "[+] Thank you for shopping.\n";
            cout << "---------------------------------------------\n";
        }
        break;
    }
    system("pause");
}

void histroy_product(){
    if(sale_count == 0){ 
        cout << "\n\t[!] Product Don't have Pre_Order to Customer!\n\n";
        system("pause");
        return;
    }
    cout << "\n\t========================================\n";
    cout << "\t|   POS System   |     Histroy         |" << endl;
    cout << "\t========================================\n";
    cout << "-----------------------------------------------------------------------\n";
    cout << left << setw(6) << "ID" << setw(18) << "Product" << setw(16) << "Categroy"
         << setw(8) << "Qty" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout << "-----------------------------------------------------------------------\n";

    for(int s = 0; s < sale_count; s++){ 
        for(int i = 0; i < product_count; i++){
            if(sale[s].product_id == product[i].id){
                float item_total = product[i].price * sale[s].qty;
                cout << left << setw(6) << product[i].id << setw(18) << product[i].name
                     << setw(16) << product[i].categroy << setw(8) << sale[s].qty
                     << setw(10) << product[i].price << setw(10) << item_total << endl;
                break;
            }
        }
    }
    cout << "--------------------------------------------------------------------------------------\n";
    system("pause");
}

void Sell_inventroy(){
    cout << "\n========================================\n";
    cout << "|   POS System   |    SEll Inventroy   |" << endl;
    cout << "========================================\n";
    cout << "\t=> 1. Sale Product\n";
    cout << "\t=> 2. Reception Product\n";
    cout << "\t=> 3. Histroy Sale of All Product\n";
    cout << "\t=> 4. Exit Sell Inventroy\n";
    cout << "---------------------------------------------------\n";
    cout << "[+] Enter the Option: "; cin >> option_sale;
    cin.ignore(); 

    system("cls");
    switch(option_sale){
        case 1:{
            sale_product();
            break;
        }
        case 2:{
            reception_product();
            break;
        }
        case 3: {
            histroy_product();
            break;
        }
        case 4:{
            cout << "\n\t==> You Have Exited Sell Inventroy\n";
            system("pause");
            break;
        }
        default:
        cout << "\n\t[!] Pls input only (1-4)! Try again!\n";
        system("pause");
    }
}

int main(){

    int choice;

    system("cls");
    do{
        cout << "========================================\n";
        cout << "|   POS System   |     Main Option     |" << endl;
        cout << "========================================\n";
        cout << "=> 1. Input Inventroy\n";
        cout << "=> 2. Sale Inventroy\n";
        cout << "=> 3. Exit\n";
        cout << "-----------------------------------\n";
        cout << "[+] Chosse one: "; cin >> choice;
        cin.ignore();

        system("cls");
        switch(choice){
            case 1:{
                do{
                    Input_inventroy(); 

                }while(option != 6);
                break;
            }
            case 2:{
                do{
                    Sell_inventroy();

                }while(option_sale != 4);
                break;
            }
            case 3:{
                cout << "\n====== [[ Goodbye,Thank you for using system ]] ========\n";
                break;
            }
            default:
            cout << "\n\t[ERROR] Pls input again!\n";
            system("pause");
        }
    }while(choice !=3);

    return 0;
}