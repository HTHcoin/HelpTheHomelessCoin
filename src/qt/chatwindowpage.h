/*Copyright (C) 2009 Cleriot Simon
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2.1 of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA*/

#ifndef CHATWINDOWPAGE_H
#define CHATWINDOWPAGE_H

#include <QtGui>
#include <QtNetwork>
#include "clientmodel.h"
#include "serveur.h"



namespace Ui
{
    class ChatWindowPage;
}

class ChatWindowPage : public QWidget
{
    Q_OBJECT

public:
    ChatWindowPage(QWidget *parent = 0);
    ~ChatWindowPage();
    void setModel(ClientModel *model);
    Serveur * currentTab();
	Q_SIGNALS:
		void changeTab();

	public Q_SLOTS:
		void sendCommande();
        void connecte();
		void closeTab();

		void tabChanged(int index);

		void tabJoined();
		void tabJoining();
        void disconnectFromServer();
        void tabClosing(int index);


private:
	Ui::ChatWindowPage *ui;
    ClientModel *model;
    QMap<QString,Serveur *> serveurs;
	bool joining;
	void closeEvent(QCloseEvent *event);
	void on_pushButton_WebChat_clicked();

};

#endif // CHATWINDOWPAGE_H