/**
 * Project-name    : account-book
 * Project-author  : Q17010123 Q17010122 Q17010125
 * Name            : controller.h
 * Module-author   : Q17010123
 * License         : MIT
 * Version         : 1.0.0
 * Description     : controller module
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <set>
#include <vector>

using namespace std;

class DataSet {
private:
    set <Item> dataContainner_;
    int max_id_;
public:
    DataSet();
    ~DataSet();
    int idAllocator();
    set <Item> getAllData();
    Item getDataById(int);
    set <Item> getDataByDate(string, string);
    set <Item> getDataByName(string);
    set <Item> getDataByType(int);
    set <Item> getDataByAmount(int, int);
    bool setDateById(int, string);
    bool setNameById(int, string);
    bool setTypeById(int, int);
    bool setAmountById(int, int);
    bool setRemarkById(int, string);
    bool addItem(Item item);
    bool deleteItem(int id);
    bool readData();
    bool saveData();
    int sumByDate(string, string);
    vector <Item> getSortedData(int);
};

#endif
