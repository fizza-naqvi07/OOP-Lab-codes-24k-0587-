#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Logger
{
private:
    vector<string> logs;
    static const int MAX_LOGS = 1000;

    string format(string severity, string module, string msg)
    {
        return "(" + severity + ") (" + module + ") " + msg;
    }

    void store(const string &log)
    {
        if (logs.size() >= MAX_LOGS)
        {
            logs.erase(logs.begin());
        }
        logs.push_back(log);
    }

public:
    void log(const string &severity, const string &module, const string &msg)
    {
        string entry = format(severity, module, msg);
        store(entry);
    }

    void logInfo(const string &module, const string &msg)
    {
        log("INFO", module, msg);
    }

    void logWarn(const string &module, const string &msg)
    {
        log("WARN", module, msg);
    }

    void logError(const string &module, const string &msg)
    {
        log("ERROR", module, msg);
    }

    friend class Auditor;
};

class Auditor
{
private:
    string password = "admin123";

public:
    vector<string> getLogs(const Logger &logger, const string &pass)
    {
        if (pass != password)
        {
            cout << "Unauthorized access denied." << endl;
            return {};
        }
        return logger.logs;
    }
};

int main()
{
    Logger logger;

    logger.logInfo("Network", "Connected to server.");
    logger.logWarn("Database", "Query execution slow.");
    logger.logError("Auth", "Invalid login attempt.");
    logger.logInfo("UI", "User clicked login.");

    Auditor auditor;
    cout << "\nTrying to access logs with wrong password:\n";
    auto failedLogs = auditor.getLogs(logger, "wrongpass");
    
    cout << "\nAccessing logs with correct password:\n";
    auto logs = auditor.getLogs(logger, "admin123");
    for (const auto &log : logs)
    {
        cout << log << endl;
    }

    return 0;
}
