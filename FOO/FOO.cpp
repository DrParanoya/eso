#include <deque>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, const char **argv)
{
    if (argc < 1) {
        std::cout << "FOO interpreter by DrParanoya\nUsage: ./foo <inputFile>\n";
        return 1;
    }

    std::string filepath;
    for (size_t i = 1; i < argc; ++i)
        filepath += argv[i];

    std::ifstream file{ filepath };
    if (!file.is_open()) {
        std::cerr << "ERROR: Couldn't open " << filepath << " !\n";
        return -1;
    }
    std::deque<char> mem;
    char in = '!';
    auto size = std::filesystem::file_size(filepath);
    std::string content(size, '\0');
    file.read(&content[0], size);

    for (size_t i = 0; i < size; ++i) {
        switch (content[i]) {
        case 'A': {
            if (i == size - 1) {
                std::cerr << "ERROR: Expected an expression after \'A\'!\n";
                return -2;
            }
            if (content[i + 1] != '\\')
                in = content[i + 1];
            mem.push_back(in);
            ++i;
            break;
        }

        case 'B': {
            char c = 0;
            c = getchar();
            mem.push_back(c);
            break;
        }

        case 'C': {
            if (i == size - 1) {
                std::cerr << "ERROR: Expected an expression after \'C\'!\n";
                return -2;
            }
            if (!mem.empty())
                if (content[i + 1] == mem.back())
                    mem.push_back(content[i + 1]);
            ++i;
            break;
        }

        case 'D': {
            if (i == size - 1) {
                std::cerr << "ERROR: Expected an expression after \'D\'!\n";
                return -2;
            }
            if (!mem.empty())
                if (content[i + 1] == mem.back())
                    i += 3;
            ++i;
            break;
        }

        case 'E': {
            i = -1;
            break;
        }

        case 'F': {
            if (!mem.empty())
                mem.pop_back();
            break;
        }

        case 'G': {
            if (!mem.empty()) {
                mem.push_back(mem.front());
                mem.pop_front();
            }
            break;
        }
        }
    }
    for (const char c : mem)
        putchar(c);
}