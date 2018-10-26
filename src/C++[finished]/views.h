/**
 * Project-name    : account-book
 * Project-author  : Q17010123 Q17010122 Q17010125
 * Name            : views.h
 * Module-author   : Q17010122
 * License         : MIT
 * Version         : 1.0.0
 * Description     : views module
 */

#ifndef VIEWS_H
#define VIEWS_H

#include "models.h"
#include "controller.h"

class Views {
private:
    void showMenu();
    void showTipsOfAddDate();
    void showTipsOfAddName(Item &);
    void showTipsOfAddAmount();
    void showTipsOfAddType();
    void showTipsOfAddRemark();
    void showTipsOfSearch();
    void showTipsOfSearchById();
    void showTipsOfSearchByDate();
    void showTipsOfSearchByName(DataSet &);
    void showTipsOfUpdate();
    void showTipsOfDelete();
    void display(DataSet &controller);
    void showTipsOfDatesCalculateModelsMin(string, string);
    void showTipsOfDatesCalculateModelsMax(string, string);
    void showSaveDone();
public:
    static void showWelcome();
    void watch(DataSet &controller);
    void showTips(int tipId);
};
#endif
