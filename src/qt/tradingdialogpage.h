
#ifndef TRADINGDIALOGPAGE_H
#define TRADINGDIALOGPAGE_H

#include <QDialog>
#include <QObject>
#include <stdint.h>
#include "ui_tradingdialogpage.h"
#include "clientmodel.h"
#include "walletmodel.h"

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include <QJsonObject>
#include <QJsonArray>

namespace Ui {
class tradingDialogPage;
}
class WalletModel;

class TradingDialogPage : public QDialog
{
    Q_OBJECT

public:
    explicit TradingDialogPage(QWidget *parent = 0);
    ~TradingDialogPage();

    void setModel(WalletModel *model);

private Q_SLOTS:

    void InitTrading();
    void on_TradingTabWidget_tabBarClicked(int index);
    void ParseAndPopulateOrderBookTables(QString Response);
    void ParseAndPopulateMarketHistoryTable(QString Response);
    void ParseAndPopulateAccountHistoryTable(QString Response);
    void ParseAndPopulateOpenOrdersTable(QString Response);
    void UpdaterFunction();
    void CreateOrderBookTables(QTableWidget& Table,QStringList TableHeader);
    void DisplayBalance(QLabel &BalanceLabel,QLabel &Available, QLabel &Pending, QString Currency,QString Response);
    void DisplayBalance(QLabel &BalanceLabel, QLabel &BalanceLabel2, QString Response, QString Response2);
    void DisplayBalance(QLabel &BalanceLabel, QString Response);
    void ActionsOnSwitch(int index);
    void CancelOrderSlot(int row, int col);
    void on_UpdateKeys_clicked(bool Save=false, bool Load=false);
    void on_LoadKeys_clicked();
    void on_SaveKeys_clicked();
    void on_GenDepositBTN_clicked();

    void CalculateBuyCostLabel();
    void on_Buy_Max_Amount_clicked();
    void on_BuyBidcomboBox_currentIndexChanged(const QString &arg1);
    void on_UnitsInput_textChanged(const QString &arg1);
    void on_BuyBidPriceEdit_textChanged(const QString &arg1);
    void on_BuyTX_clicked();

    void CalculateSellCostLabel();
    void on_Sell_Max_Amount_clicked();
    void on_SellBidcomboBox_currentIndexChanged(const QString &arg1);
    void on_UnitsInputTX_textChanged(const QString &arg1);
    void on_SellBidPriceEdit_textChanged(const QString &arg1);
    void on_SellTXBTN_clicked();

    void CalculateCSReceiveLabel();
    void on_CSUnitsInput_textChanged(const QString &arg1);
    void on_CSUnitsBtn_clicked();
    void on_CS_Max_Amount_clicked();

    void on_Withdraw_Max_Amount_clicked();
    void on_WithdrawUnitsBtn_clicked();

    void on_KeyPasteButton_clicked();
    void on_SecretPasteButton_clicked();
    void on_CSPasteButton_clicked();
    void on_WithdrawPasteButton_clicked();
    void on_DepositCopyButton_clicked();

    int SetExchangeInfoTextLabels();

    QString BittrexTimeStampToReadable(QString DateTime);
    QString CancelOrder(QString Orderid);
    QString BuyTX(QString OrderType, double Quantity, double Rate);
    QString SellTX(QString OrderType, double Quantity, double Rate);
    QString Withdraw(double Amount, QString Address, QString Coin);
    QString GetMarketHistory();
    QString GetMarketSummary();
    QString GetOrderBook();
    QString GetOpenOrders();
    QString GetAccountHistory();
    QString GetBalance(QString Currency);
    QString GetDepositAddress();
    QString HMAC_SHA512_SIGNER(QString UrlToSign,QString Secretkey);
    QString sendRequest(QString url);
    QString encryptDecrypt(QString toEncrypt, QString password);
    QJsonObject GetResultObjectFromJSONObject(QString response);
    QJsonObject GetResultObjectFromJSONArray(QString response);
    QJsonArray  GetResultArrayFromJSONObject(QString response);

public Q_SLOTS:


private:
    Ui::TradingDialogPage *ui;
    //Socket *socket;
    int timerid;
    QTimer *timer;
    QString ApiKey;
    QString SecretKey;
    WalletModel *model;


};

#endif // TRADINGDIALOGPAGE_H