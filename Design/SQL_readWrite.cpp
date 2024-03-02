#include <iostream>
#include <mysql_connection.h>
#include <mysql_driver.h>

using namespace std;

int main() {
    try {
        // Create a MySQL Connector/C++ driver instance
        sql::mysql::MySQL_Driver *driver;
        driver = sql::mysql::get_mysql_driver_instance();

        // Establish a connection to the MySQL database
        sql::Connection *con;
        con = driver->connect("tcp://localhost:3306", "username", "password"); // Replace with actual host, username, and password
        con->setSchema("example"); // Replace with actual database name

        // Create a statement
        sql::Statement *stmt;
        stmt = con->createStatement();

        // Create a table (if not exists)
        stmt->execute("CREATE TABLE IF NOT EXISTS users (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), age INT)");

        // Insert data into the table
        stmt->execute("INSERT INTO users (name, age) VALUES ('John', 30), ('Jane', 25), ('Doe', 40)");

        // Query data from the table
        sql::ResultSet *res;
        res = stmt->executeQuery("SELECT * FROM users");
        while (res->next()) {
            cout << "ID: " << res->getInt("id");
            cout << ", Name: " << res->getString("name");
            cout << ", Age: " << res->getInt("age") << endl;
        }

        // Close resources
        delete res;
        delete stmt;
        delete con;
    } catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    return 0;
}
