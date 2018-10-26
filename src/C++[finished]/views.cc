/**
 * Project-name    : account-book
 * Project-author  : Q17010123 Q17010122 Q17010125
 * Name            : views.cc
 * Module-author   : Q17010122
 * License         : MIT
 * Version         : 1.0.0
 * Description     : views module
 */

#include "views.h"
#include <set>
#include <string>
#include "controller.h"
#include "models.h"
#include <cstdio>
#include <iostream>
#include <stdlib.h>

using namespace std;

void Views::showWelcome() {
    printf("  -------------------------------------------------  \n");
    printf("||Now get prepared to learn how poor you really are!||\n");
    printf("  -------------------------------------------------  \n\n\n");
}

void Views::showMenu() {
    printf("  -------------------------------------------------- \n");
    printf("||             1.Add an account detail              ||\n");
    printf("||             2.Search by factors                  ||\n");
    printf("||             3.Update account details             ||\n");
    printf("||             4.Delete account details             ||\n");
    printf("||             5.Display all details                ||\n");
    printf("||             6.Sum by dates                       ||\n");
    printf("||             7.Save all changes                   ||\n");
    printf("||             8.Sort                               ||\n");
    printf("||             9.Exit                               ||\n");
    printf("  -------------------------------------------------- \n");
}

void Views::showTipsOfAddDate() {
    printf("               Please type in the date of the new detail\n");
}

void Views::showTipsOfAddName(Item &it) {
    int option;
    printf(" Please type in the number of the name of the new detail\n");
    printf(" 1.Food             2.Transportation         3.Wage\n");
    printf(" 4.Clothing         5.Daily expenses         6.Health\n");
    printf(" 7.Communications   8.Education              9.Entertainment\n");
    printf(" 10.Investments     11.Insurance             12.Gifts\n");
    printf(" 13.Charities       14.Debt                  15.Others\n");
    cin >> option;
    switch (option) {
    case 1:
        it.name_ = "Food";
        break;
    case 2:
        it.name_ = "Transportation";
        break;
    case 3:
        it.name_ = "Wage";
        break;
    case 4:
        it.name_ = "Clothing";
        break;
    case 5:
        it.name_ = "Daily expenses";
        break;
    case 6:
        it.name_ = "Health";
        break;
    case 7:
        it.name_ = "Communications";
        break;
    case 8:
        it.name_ = "Education";
        break;
    case 9:
        it.name_ = "Entertainment";
        break;
    case 10:
        it.name_ = "Investments";
        break;
    case 11:
        it.name_ = "Insurance";
        break;
    case 12:
        it.name_ = "Gifts";
        break;
    case 13:
        it.name_ = "Charities";
        break;
    case 14:
        it.name_ = "Debt";
        break;
    case 15:
        it.name_ = "Others";
        break;
    }
}

void Views::showTipsOfAddAmount() {
    printf("               Please type in the amount of the new detail\n");
}

void Views::showTipsOfAddType() {
    printf("               1.It is an income.\n");
    printf("               2.It is an expense.\n");
}

void Views::showTipsOfAddRemark() {
    printf("               Please type in the remark of the new detail\n");
}

void Views::showTipsOfSearch() {
    printf("               1.Search by id\n");
    printf("               2.Search by date\n");
    printf("               3.Search by name\n");
}

void Views::showTipsOfSearchById() {
    printf("            Please type in the id\n");
}

void Views::showTipsOfSearchByDate() {
    printf("            Please type in the date\n");
}

void Views::showTipsOfSearchByName(DataSet &controller) {
    int option;
    printf(" Please type in the number of the name of the expected detail\n");
    printf(" 1.Food             2.Transportation         3.Wage\n");
    printf(" 4.Clothing         5.Daily expenses         6.Health\n");
    printf(" 7.Communications   8.Education              9.Entertainment\n");
    printf(" 10.Investments     11.Insurance             12.Gifts\n");
    printf(" 13.Charities       14.Debt                  15.Others\n");
    cin >> option;
    set <Item> s;
    switch (option) {
    case 1:
        s = controller.getDataByName("Food");
        break;
    case 2:
        s = controller.getDataByName("Transportation");
        break;
    case 3:
        s = controller.getDataByName("Wage");
        break;
    case 4:
        s = controller.getDataByName("Clothing");
        break;
    case 5:
        s = controller.getDataByName("Daily expenses");
        break;
    case 6:
        s = controller.getDataByName("Health");
        break;
    case 7:
        s = controller.getDataByName("Communications");
        break;
    case 8:
        s = controller.getDataByName("Education");
        break;
    case 9:
        s = controller.getDataByName("Entertainment");
        break;
    case 10:
        s = controller.getDataByName("Investments");
        break;
    case 11:
        s = controller.getDataByName("Insurance");
        break;
    case 12:
        s = controller.getDataByName("Gifts");
        break;
    case 13:
        s = controller.getDataByName("Charities");
        break;
    case 14:
        s = controller.getDataByName("Debt");
        break;
    case 15:
        s = controller.getDataByName("Others");
        break;
    }
    for (auto const &x : s) {
        printf("              ID: %d\n", x.id_);
        printf("              Date: %s\n", &x.date_[0]);
        printf("              Name: %s\n", &x.name_[0]);
        printf("              Amount: ");
        if (x.type_ == 1)
            printf("+");
        if (x.type_ == 2)
            printf("-");
        printf("%d\n", x.amount_);
        printf("              Remark: %s\n", &x.remark_[0]);
    }
    if (s.size() == 0) printf("           Now such detail could be located\n");
}

void Views::showTipsOfUpdate() {
    printf("         Please type in the id of detail\n");
}

void Views::showTipsOfDelete() {
    printf("   Please type in the id of the unwanted detail\n");
}

void Views::display(DataSet &controller) {
    set <Item> info = controller.getAllData();
    for (auto const &x : info) {
        printf("              ID: %d\n", x.id_);
        printf("              Date: %s\n", &x.date_[0]);
        printf("              Name: %s\n", &x.name_[0]);
        printf("              Amount: ");
        if (x.type_ == 1)
            printf("+");
        else if (x.type_ == 2)
            printf("-");
        printf("%d\n", x.amount_);
        printf("              Remark: %s\n", &x.remark_[0]);
    }
}

void Views::showTipsOfDatesCalculateModelsMin(string minDate, string maxDate) {
    printf("       Please type in the beginning date\n");
}

void Views::showTipsOfDatesCalculateModelsMax(string minDate, string maxDate) {
    printf("       Please type in the ending date\n");
}

void Views::showSaveDone() {
    printf("            Save successful\n");
}

void Views::watch(DataSet &controller) {
    int inputNumber;
    int searchNumber, searchamount = 0;
    int idForSearch;
    int updateNumber;
    int sum;
    int newAmount, newType;
    string dateForSearch1, dateForSearch2, nameForSearch, newDate, newName, newRemark, dateForSum1, dateForSum2;
    Item temp;
    while (true) {
        showMenu();
        scanf("%d", &inputNumber);
        switch (inputNumber) {
        case 1: {
            // system("cls");
            showTipsOfAddDate();
            //scanf("%s",&temp.date_[0]);
            cin >> temp.date_;
            showTipsOfAddName(temp);
            //scanf("%s",&temp.name_[0]);
            //cin >> temp.name_;
            showTipsOfAddType();
            //scanf("%d",&temp.type_);
            cin >> temp.type_;
            temp.id_ = controller.idAllocator();
            showTipsOfAddAmount();
            //scanf("%d",&temp.amount_);
            cin >> temp.amount_;
            showTipsOfAddRemark();
            //scanf("%s",&temp.remark_);
            cin >> temp.remark_;
            if(controller.addItem(temp));
            else printf("              Adding failed");
        };
        break;
        case 2: {
            showTipsOfSearch();
            scanf("%d", &searchNumber);
            if(searchNumber == 1) {
                searchamount = 0;
                // system("cls");
                showTipsOfSearchById();
                scanf("%d", &idForSearch);
                temp = controller.getDataById(idForSearch);
                if(temp.id_ == -1) {
                    printf("      Input error, id not included.\n");
                    break;
                }
                printf("               ID: %d\n", temp.id_);
                printf("               Date: %s\n", &temp.date_[0]);
                printf("               Name: %s\n", &temp.name_[0]);
                printf("               Amount: ");
                if (temp.type_ == 1)
                    printf("+");
                else if (temp.type_ == 2)
                    printf("-");
                searchamount++;
                printf("%d\n", temp.amount_);
                printf("               Remark: %s\n", &temp.remark_[0]);
                if (searchamount == 0) printf("           Now such detail could be located\n");
            }
            if(searchNumber == 2) {
                // system("cls");
                showTipsOfSearchByDate();
                printf("Please type in the beginning date and the ending date.\n    (type in same dates if only one day is needed)\n");
                printf("            The beginning date:\n");
                //scanf("%s",&dateForSearch1[0]);
                cin >> dateForSearch1;
                printf("            The ending date:\n");
                //scanf("%s",&dateForSearch2[0]);
                cin >> dateForSearch2;
                set <Item> s = controller.getDataByDate(dateForSearch1, dateForSearch2);
                searchamount = 0;
                for (auto const &x : s) {
                    searchamount++;
                    printf("              ID: %d\n", x.id_);
                    printf("              Date: %s\n", &x.date_[0]);
                    printf("              Name: %s\n", &x.name_[0]);
                    printf("              Amount: ");
                    if (x.type_ == 1)
                        printf("+");
                    else if (x.type_ == 2)
                        printf("-");
                    printf("%d\n", x.amount_);
                    printf("              Remark: %s\n", &x.remark_[0]);
                }
                if (searchamount == 0) printf("           Now such detail could be located\n");
            }
            if(searchNumber == 3) {
                searchamount = 0;
                // system("cls");
                showTipsOfSearchByName(controller);
                //scanf("%s",&nameForSearch);
                //cin >> nameForSearch;

            }
        };
        break;
        case 3: {
            // system("cls");
            showTipsOfUpdate();
            scanf("%d", &idForSearch);
            printf("          1.change the date\n");
            printf("          2.change the name\n");
            printf("          3.change the amount\n");
            printf("          4.change the type\n");
            printf("          5.change the remark\n");
            scanf("%d", &updateNumber);

            if (updateNumber == 1) {
                printf("        Please type in the new date:\n");
                //scanf("%s",&newDate[0]);
                cin >> newDate;
                if(controller.setDateById(idForSearch, newDate));
                else printf("        Update error, please check the id\n");
            }
            if (updateNumber == 2) {
                int option;
                printf("          Please type in the new number of the name\n");
                printf("          1.Food             2.Transportation         3.Wage\n");
                printf("          4.Clothing         5.Daily expenses         6.Health\n");
                printf("          7.Communications   8.Education              9.Entertainment\n");
                printf("          10.Investments     11.Insurance             12.Gifts\n");
                printf("          13.Charities       14.Debt                  15.Others\n");
                //scanf("%s",&newName[0]);
                cin >> option;
                switch (option) {
                case 1:
                    newName = "Food";
                    break;
                case 2:
                    newName = "Transportation";
                    break;
                case 3:
                    newName = "Wage";
                    break;
                case 4:
                    newName = "Clothing";
                    break;
                case 5:
                    newName = "Daily expenses";
                    break;
                case 6:
                    newName = "Health";
                    break;
                case 7:
                    newName = "Communications";
                    break;
                case 8:
                    newName = "Education";
                    break;
                case 9:
                    newName = "Entertainment";
                    break;
                case 10:
                    newName = "Investments";
                    break;
                case 11:
                    newName = "Insurance";
                    break;
                case 12:
                    newName = "Gifts";
                    break;
                case 13:
                    newName = "Charities";
                    break;
                case 14:
                    newName = "Debt";
                    break;
                case 15:
                    newName = "Others";
                    break;
                }
                if(controller.setNameById(idForSearch, newName));
                else printf("          Update error, please check the id\n");
            }
            if (updateNumber == 3) {
                printf("          Please type in the new amount:\n");
                //scanf("%s",&newAmount[0]);
                cin >> newAmount;
                if(controller.setAmountById(idForSearch, newAmount));
                else printf("          Update error, please check the id\n");
            }
            if (updateNumber == 4) {
                printf("          Please type in the new type:\n");
                printf("          1.It is an income.\n");
                printf("          2.It is an expense.\n");
                //scanf("%s",&newType[0]);
                cin >> newType;
                if(controller.setTypeById(idForSearch, newType));
                else printf("          Update error, please check the id\n");
            }
            if (updateNumber == 5) {
                printf("          Please type in the new remark:\n");
                //scanf("%s",&newRemark[0]);
                cin >> newRemark;
                if(controller.setRemarkById(idForSearch, newRemark));
                else printf("          Update error, please check the id\n");
            }
        };
        break;
        case 4: {
            // system("cls");
            showTipsOfDelete();
            scanf("%d", &idForSearch);
            if(controller.deleteItem(idForSearch))
                printf("          Deletion successful\n");
            else printf("          Deletion failed\n");
        };
        break;
        case 5: {
            // system("cls");
            display(controller);
        };
        break;
        case 6: {
            // system("cls");
            printf("  Please type in the beginning date and the ending date\n   (type in the same date if only one certain day is required)\n");
            printf("    Please type in the beginning date\n");
            //scanf("%s",&dateForSum1[0]);
            cin >> dateForSum1;
            printf("    Please type in the ending date\n");
            //scanf("%s",&dateForSum2[0]);
            cin >> dateForSum2;
            sum = controller.sumByDate(dateForSum1, dateForSum2);
            printf("    The general income is as followed: %d\n", sum);
        };
        break;
        case 7: {
            // system("cls");
            if(controller.saveData())
                showSaveDone();
            else
                printf("          Save failed\n");
        };
        break;
        case 8: {
            int SortNumber;
            printf("Please choose the way in which you wish to sort: \n");
            printf("1. Sort by ID   2. Sort by dates  3. Sort by amount\n");
            scanf("%d", &SortNumber);
            vector <Item> v = controller.getSortedData(SortNumber);
            for (unsigned i = 0; i < v.size(); ++i) {
                printf("              Sorted ID:%d\n", i);
                printf("              ID: %d\n", v[i].id_);
                printf("              Date: %s\n", &v[i].date_[0]);
                printf("              Name: %s\n", &v[i].name_[0]);
                printf("              Amount: ");
                if (v[i].type_ == 1)
                    printf("+");
                else if (v[i].type_ == 2)
                    printf("-");
                printf("%d\n", v[i].amount_);
                printf("              Remark: %s\n", &v[i].remark_[0]);
            }
        };
        break;
        case 9: {
            // system("cls");
            return;
        };
        break;
        }
        system("pause");
        system("cls");
    }
}
