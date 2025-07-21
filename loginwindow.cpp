#include "LoginWindow.h"
#include "MainAccount.h"
#include "SavingsAccount.h"
#include "NonProfitAccount.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent), adminDashboard(nullptr), customerDashboard(nullptr) {
    ui.setupUi(this);
    loadSampleData();
    connect(ui.loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
}

LoginWindow::~LoginWindow() {}

void loadSampleData() {
    Admin* admin = new Admin("Ali", "Ahmadi", "1234567890", 35, "admin", "admin123");
    Customer* cust = new Customer("Sara", "Karimi", "1112223334", 28, "sara", "pass123");

    MainAccount* acc = new MainAccount("1111222233334444", "IR123456789012345678901234", "ACC10001", "111", QDate::currentDate().addYears(3), 5000000, "1234", "2222");
    cust->addAccount(acc);

    users.insert(admin->getUsername(), admin);
    users.insert(cust->getUsername(), cust);
}

void handleLogin() {
    QString username = ui.usernameEdit->text();
    QString password = ui.passwordEdit->text();

    if (!users.contains(username)) return;

    User* user = users[username];
    if (user->getPassword() != password) return;

    if (user->getRole() == "Admin") {
        adminDashboard = new AdminDashboard(static_cast<Admin*>(user), users);
        adminDashboard->show();
    } else {
        customerDashboard = new CustomerDashboard(static_cast<Customer*>(user));
        customerDashboard->show();
    }

    this->close();
}
