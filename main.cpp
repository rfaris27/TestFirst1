#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

int main()
{
    try
    {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        // 1. Create a connection
        driver = sql::mysql::get_mysql_driver_instance();
        // Use the host and port from your tutorial: host.docker.internal:3333
        con = driver->connect("tcp://host.docker.internal:3333", "root", "a");

        // 2. Connect to the 'Rama' database
        con->setSchema("Rama");

        // 3. Execute the query
        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT * FROM person");

        // 4. Loop through results and print like the Console.WriteLine in the video
        while (res->next())
        {
            std::cout << res->getString("name") << " "
                      << res->getInt("age") << std::endl;
        }

        // Clean up
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}