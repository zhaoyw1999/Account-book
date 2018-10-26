/**
 * Project-name    : account-book
 * Project-author  : Q17010123 Q17010122 Q17010125
 * Name            : models.h
 * Module-author   : Q17010125
 * License         : MIT
 * Version         : 1.0.0
 * Description     : models module
 */

#ifndef MODEL_H
#define MODEL_H

#define INCOME 1
#define EXPENSE 0
#include <string>

using namespace std;

struct Item{
    int id_;
    string date_;
    string name_;
    int type_;
    int amount_;
    string remark_;

    Item(int cId = 0, string cDate_ = "", string cName_ = "", int cType_ = 0, int cAmount_ = 0, string cRemark_ = "");
    ~Item();
    void setDate(string x);
    friend bool operator < (const Item &it_1, const Item &it_2);
};

inline bool compareById(const Item &it_1, const Item &it_2);

inline bool compareByDate(const Item &it_1, const Item &it_2);

inline bool compareByAmount(const Item &it_1, const Item &it_2);

#endif
